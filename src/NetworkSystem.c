#include <winsock2.h>
#include <string.h>
#include "Generic_GameLibrary.h"

#pragma warning(disable : 4996)

/***********************************************************
 * GglNetwork_Startup�֐� 
 * Winsock2�����������܂�
 *
 * �߂�l�FGglBoolean(�u�[���l)
 * �����@�F�Ȃ�
*/
GglBoolean GglNetwork_Initialize(void)
{
	WSADATA wsaData;
	int exception = 0;

	exception = WSAStartup(MAKEWORD(2,0), &wsaData);
	
	if(exception != 0)
	{
		GglDebug_PrintExceptionLine();
		GglNetwork_Winsock2PrintErrorSelect(exception);
		return GglFalse;
	}

	return GglTrue;
}

/***********************************************************
 * GglNetwork_Shutdown�֐� 
 * Winsock2���I�����܂�
 *
 * �߂�l�FGglBoolean(�u�[���l)
 * �����@�F�Ȃ�
*/
GglBoolean GglNetwork_Shutdown(void)
{
	int exception;

	exception = WSACleanup();

	if(exception != 0)
	{
		GglDebug_PrintExceptionLine();
		GglNetwork_Winsock2PrintErrorSelect(exception);
		return GglFalse;
	}

	return GglTrue;
}

/***********************************************************
 * GglNetwork_GetIpAddress�֐� 
 * ���g��IP�A�h���X���擾���܂�
 *
 * �߂�l�FGglString(typedef char*, ������)
 * �����@�F�Ȃ�
*/
void GglNetwork_GetIpAddress(GglString out_ipAddr)
{
	char		ipAddress[256];
	PHOSTENT	pHostent;
	IN_ADDR		address;
	
	if(gethostname(ipAddress, sizeof(ipAddress)) != 0)
	{
		GglDebug_PrintExceptionLine();
		GglNetwork_PrintError();
		*out_ipAddr = 0;
		return ;
	}

	pHostent = gethostbyname(ipAddress);

	if(pHostent == NULL)
	{
		GglDebug_PrintExceptionLine();
		*out_ipAddr = 0;
		return ;
	}

	memcpy(&address, pHostent->h_addr_list[0], 4);
	strncpy(out_ipAddr, inet_ntoa(address), 256);

	*out_ipAddr = 0;
	return ;
}

/************************************************************************************
 * GglNetwork_MakeSocket�֐� 
 * Winsock2�ɂ�Socket���쐬���܂�
 * �T�[�o�ƃN���C�A���g�A
 * �����̓z�X�g�ƃQ�X�g��Make�ɂ��Ή����Ă��܂����A
 * �T�[�o�ƃz�X�g��Make����ꍇ�͑�3������
 * "127.0.0.1"�A�����́uGglNetwork_USE_LOCALHOST�v��n���Ă�������
 *
 * �߂�l�FGglBoolean				��������GglTrue���A���s����GglFalse��Ԃ��܂�
 * �����@�F
 * 1. GglSocket*	_pModule		�ڑ��p�̃\�P�b�g�A�A�h���X����ێ�����\����
 * 3. GglString			_addressString	�ڑ���̃A�h���X�ł�
 * 4. int				_usePort		�g�p����|�[�g�ԍ��ł�
*/
GglBoolean GglNetwork_MakeSocket(GglSocketNode* _pModule,
								 GglString _addressString,
								 int _usePort)
{
	// Make Socket
	_pModule->socket = (GglSocket)socket(AF_INET, SOCK_STREAM, 0);

	// �\�P�b�g��Make�Ɏ��s�����ꍇ�̓G���[�s�ƃG���[���R��printf����Make�I��
	if(_pModule->socket == (GglSocket)INVALID_SOCKET)
	{
		GglDebug_PrintExceptionLine();
		GglNetwork_PrintError();
		return GglFalse;
	}

	// Definition a host Address
	_pModule->address.sin_family	= AF_INET;
	_pModule->address.sin_port		= htons(_usePort);

	if( strcmp(_addressString, "127.0.0.1")				== 0 ||
		strcmp(_addressString, "0.0.0.0")				== 0 ||
		strcmp(_addressString, GglNetwork_USE_LOCALHOST)== 0 )
	{
		_pModule->address.sin_addr.S_un.S_addr = INADDR_ANY;

		// �z�X�g��IP�ƃ\�P�b�g���֘A�t��
		if( bind( (SOCKET)_pModule->socket, (SOCKADDR*)&_pModule->address, sizeof(_pModule->address) ) != 0 )
		{
			GglDebug_PrintExceptionLine();
			GglNetwork_PrintError();
			return GglFalse;
		}

		printf("bind Entered...\n");
	}
	else
	{
		_pModule->address.sin_addr.S_un.S_addr = inet_addr(_addressString);
		
		if( connect( (SOCKET)_pModule->socket, (SOCKADDR*)&_pModule->address, sizeof(_pModule->address) ) == SOCKET_ERROR )
		{
			GglDebug_PrintExceptionLine();
			GglNetwork_PrintError();
			return GglFalse;
		}
	}

	return GglTrue;
}

// �}���`�X���b�h�ł̉^�p��O��Ƃ���
GglBoolean GglNetwork_HostServerWaitGuestClientOnce(GglObject _object)
{
	GglThread* pThread		= _object;
	GglSocketNode* nModule	= (GglSocketNode*)pThread->argument;
	GglSocketNode* toClient = (GglSocketNode*)GglMemory_New(sizeof(GglSocket));
	int addressLength		= sizeof(SOCKADDR_IN);

	printf("Begin Connect Wait...\n");

	//EnterCriticalSection(&nModule->criticalSection);

	//WaitForSingleObject(pThread->thread, INFINITE);

	GglDebug_PrintInformationLine("Enter Listen...\n");
	if( listen( (SOCKET)nModule->socket, SOMAXCONN ) != 0 )
	{
		GglDebug_PrintExceptionLine();
		GglNetwork_PrintError();
		//LeaveCriticalSection(&nModule->criticalSection);
		return GglFalse;
	}

	GglDebug_PrintInformationLine("Enter Accept...\n");
	toClient->socket = (GglSocket)accept( (SOCKET)nModule->socket , (SOCKADDR*)&toClient->address , &addressLength );

	if(toClient->socket == (GglSocket)INVALID_SOCKET)
	{
		GglDebug_PrintExceptionLine();
		GglNetwork_PrintError();
		//LeaveCriticalSection(&nModule->criticalSection);
		return GglFalse;
	}

	GglNetworkList_AddElement(toClient);

	//LeaveCriticalSection(&nModule->criticalSection);

	GglDebug_PrintInformationLine("Success Accept!!\n");

	GglMultiThread_AddNewThread(GglNetwork_ReceiveData, 1, toClient);
	//GglMultiThread_AddNewThread(GglNetwork_SendData, 1, toClient);

	return GglTrue;
}

void GglNetwork_ReceiveData(GglObject _object)
{
	int result;
	GglThread*	_this			= _object;
	GglSocketNode* nModule	= _this->argument;
	char a[256] = "\0";

	while(1)
	{
		memset(a, 0, 1);
		if(nModule->maxDataSize <= 0)
		{
			GglDebug_PrintExceptionLine();
			break;
		}

		//EnterCriticalSection(&nModule->criticalSection);

		result = recv((SOCKET)nModule->socket, a, 256, 0);


		if(nModule->recvDataUsedFlag == GglTrue)
		{
			strncpy(nModule->recvObject, a, strlen(a));
			nModule->recvDataUsedFlag = GglFalse;
		}

		//nModule->recvObject = a;
		//strncpy(&g_recvData, &a, strlen(&a));
		//printf("result = %d\n", a);

		//LeaveCriticalSection(&nModule->criticalSection);

		if(result == SOCKET_ERROR)
		{
			GglDebug_PrintExceptionLine();
			GglNetwork_PrintError();
			break;
		}
		else if(result == 0)
		{
			GglDebug_PrintInformationLine("��M�X���b�h�I����");
			break;
		}
	}
	return ;
}

void GglNetwork_SendData(GglObject _object)
{
	int result;
	GglThread*	_this			= _object;
	GglSocketNode* nModule	= _this->argument;
	char a;

	while(1)
	{
		if(nModule->maxDataSize <= 0)
		{
			GglDebug_PrintExceptionLine();
			break;
		}

		//EnterCriticalSection(&nModule->criticalSection);

		printf("Begin Send\n");

		printf("send data = %c", (char)nModule->sendObject);
		printf("send size = %d", nModule->maxDataSize);

		a = (char)nModule->sendObject;

		result = send((SOCKET)nModule->socket, &a, 1, 0);

		printf("sended\n");

		//LeaveCriticalSection(&nModule->criticalSection);

		if(result == SOCKET_ERROR)
		{
			GglDebug_PrintExceptionLine();
			GglNetwork_PrintError();
			break;
		}
	}
	return ;
}

/**************************************************************
 * GglNetwork_PrintError�֐� 
 * Winsock2�ł̃G���[��GglNetwork_Winsock2PrintErrorSelect�o�R��
 * printf�ŕ`�悵�܂�
 *
 * �߂�l�F�Ȃ�
 * �����@�F�Ȃ�
*/
void GglNetwork_PrintError(void)
{
	int error = WSAGetLastError();
	GglNetwork_Winsock2PrintErrorSelect(error);

	return ;
}

/***********************************************************
 * GglNetwork_Winsock2PrintErrorSelect�֐�
 * �����Ŏw�肳�ꂽWinsock2�ł̃G���[��printf�ŕ`�悵�܂�
 *
 * �߂�l�F�Ȃ�
 * �����@�F
 * 1. int _exception	�G���[�ԍ�
*/
void GglNetwork_Winsock2PrintErrorSelect(int _exception)
{
	printf("Summary : ");
	switch(_exception)
	{
		case WSAEINTR:
			printf("connect�Ăяo�����Ɋ��荞�݂���(WSAEINTR)\n");
			break;

		case WSAEACCES:
			printf("�A�N�Z�X����(WSAEACCES)\n");
			break;

		case WSAEFAULT:
			printf("�s���ȃA�h���X�A�����͕s���ȃ|�C���^(WSAEFAULT)\n");
			break;

		case WSAEINVAL:
			printf("�����Ȉ���(WSAEINVAL)\n");
			break;

		case WSAEMFILE:
			printf("�t�@�C���J������(WSAEMFILE)\n");
			break;

		case WSAEWOULDBLOCK:
			printf("�ꎞ�I�Ƀ��\�[�X�g�p�s��(WSAEWOULDBLOCK)\n");
			break;

		case WSAEINPROGRESS:
			printf("���ݎ��s���̑���(WSAEINPROGRESS)\n");
			break;

		case WSAEALREADY:
			printf("���s�ς݂̑���(WSAEALREADY)\n");
			break;

		case WSAENOTSOCK:
			printf("�\�P�b�g�ɑ΂��ă\�P�b�g������s�Ȃ��Ă�������(WSAENOTSOCK)\n");
			break;

		case WSAEDESTADDRREQ:
			printf("���M��̃A�h���X���K�v(WSAEDESTADDRREQ)\n");
			break;

		case WSAEMSGSIZE:
			printf("3�s�ł���(WSAEMSGSIZE)\n");
			break;

		case WSAEPROTOTYPE:
			printf("�ʐM��\�P�b�g�ɑ΂���v���g�R���̕s��v(WSAEPROTOTYPE)\n");
			break;

		case WSAENOPROTOOPT:
			printf("�s���ȃv���g�R���I�v�V����(WSAENOPROTOOPT)\n");
			break;

		case WSAEPROTONOSUPPORT:
			printf("�T�|�[�g����Ă��Ȃ��v���g�R��(WSAEPROTONOSUPPORT)\n");
			break;

		case WSAESOCKTNOSUPPORT:
			printf("�T�|�[�g����Ă��Ȃ��\�P�b�g�̎��(WSAESOCKTNOSUPPORT)\n");
			break;

		case WSAEOPNOTSUPP:
			printf("�g�p�\�P�b�g�ŃT�|�[�g����Ă��Ȃ�����(WSAEOPNOTSUPP)\n");
			break;

		case WSAEPFNOSUPPORT:
			printf("�T�|�[�g����Ă��Ȃ��v���g�R���t�@�~��(WSAEPFNOSUPPORT)\n");
			break;

		case WSAEAFNOSUPPORT:
			printf("�v���g�R���t�@�~���̓A�h���X�t�@�~�����T�|�[�g���Ȃ�(WSAEAFNOSUPPORT)\n");
			break;

		case WSAEADDRINUSE:
			printf("�A�h���X�g�p��(WSAEADDRINUSE)\n");
			break;

		case WSAEADDRNOTAVAIL:
			printf("�v�����ꂽ�A�h���X�͊��蓖�Ă��Ȃ�(WSAEADDRNOTAVAIL)\n");
			break;

		case WSAENETDOWN:
			printf("�l�b�g���[�N�_�E���Ȃ�(WSAENETDOWN)\n");
			break;

		case WSAENETUNREACH:
			printf("ICMP�l�b�g���[�N�֓��B�ł��Ȃ�(WSAENETUNREACH)\n");
			break;

		case WSAENETRESET:
			printf("�l�b�g���[�N���Z�b�g�ɂ��ؒf(WSAENETRESET)\n");
			break;

		case WSAECONNABORTED:
			printf("�\�t�g�E�F�A�ɂ��ڑ��̒��~(WSAECONNABORTED)\n");
			break;

		case WSAECONNRESET:
			printf("Pear�ɂ��ڑ��̃��Z�b�g(WSAECONNRESET)\n");
			break;

		case WSAENOBUFS:
			printf("�T�|�[�g����Ă��Ȃ��o�b�t�@�̈�(WSAENOBUFS)\n");
			break;

		case WSAEISCONN:
			printf("�\�P�b�g�͊��ɐڑ��ς݂ł���(WSAEISCONN)\n");
			break;

		case WSAENOTCONN:
			printf("�\�P�b�g���ڑ�(WSAENOTCONN)\n");
			break;

		case WSAESHUTDOWN:
			printf("�\�P�b�g�̓V���b�g�_�E�����Ă���Ƃ����̂ɉ��𑗂낤�Ƃ��Ă���̂����H(WSAESHUTDOWN)\n");
			break;

		case WSAETIMEDOUT:
			printf("�ڑ��̃^�C���A�E�g(WSAETIMEDOUT)\n");
			break;

		case WSAECONNREFUSED:
			printf("�ڑ����ۂ���Ă���(WSAECONNREFUSED)\n");
			break;

		case WSAEHOSTDOWN:
			printf("�z�X�g�_�E�����Ă���Ēm���Ă��H(WSAEHOSTDOWN)\n");
			break;

		case WSAEHOSTUNREACH:
			printf("�z�X�g�ւ̃��[�g���炢�m�ۂ��Ƃ���c(WSAEHOSTUNREACH)\n");
			break;

		case WSAEPROCLIM:
			printf("�v���Z�X�����������^(WSAEPROCLIM)\n");
			break;

		case WSASYSNOTREADY:
			printf("�l�b�g���[�N�T�u�V�X�e�����p�s��(�������������Ă��Ȃ�)(WSASYSNOTREADY)\n");
			break;

		case WSAVERNOTSUPPORTED:
			printf("���̃o�[�W������Winsock.dll�̓T�|�[�g����Ă��Ȃ�(WSAVERNOTSUPPORTED)\n");
			break;

		case WSANOTINITIALISED:
			printf("WSAStartup�𐬌������Ă���܂����z�����������܂����q�l(WSANOTINITIALISED)\n");
			break;

		case WSAEDISCON:
			printf("����ȃV���b�g�_�E���������i�s��(WSAEDISCON)\n");
			break;

		case WSATYPE_NOT_FOUND:
			printf("���̎�ނ̃N���X��������Ȃ����Ă���(WSATYPE_NOT_FOUND)\n");
			break;

		case WSAHOST_NOT_FOUND:
			printf("�z�X�g��������Ȃ����Ă������A����ȃz�X�g�Ȃ��񂶂�ˁH�Ċm�F���(WSAHOST_NOT_FOUND)\n");
			break;

		case WSATRY_AGAIN:
			printf("�z�X�g��������Ȃ����Ă������A���̎荇���̌��������Ă�I���牞���Ȃ��񂾂��(WSATRY_AGAIN)\n");
			break;

		case WSANO_RECOVERY:
			printf("�N��AED�����Ă����I�I(�񕜕s�\�ȃG���[�̔���)(WSANO_RECOVERY)\n");
			break;

		case WSANO_DATA:
			printf("���O�͍����Ă�B���A����Ȏ�ނ̃f�[�^���R�[�h�͖���(WSANO_DATA)\n");
			break;

		case WSA_INVALID_HANDLE:
			printf("�w�肳�ꂽ�C�x���g�I�u�W�F�N�g�n���h����NULL�ł��˂����܂�Ă�񂶂�Ȃ����H(WSA_INVALID_HANDLE)\n");
			break;

		case WSA_INVALID_PARAMETER:
			printf("�n���ꂽ�p�����[�^�̊���͖��������B�u���[�N�|�C���g�u���Ċm�F�`(WSA_INVALID_PARAMETER)\n");
			break;

		case WSA_IO_INCOMPLETE:
			printf("�d������I/O�C�x���g�̓V�O�i������Ă��Ȃ�(WSA_IO_INCOMPLETE)\n");
			break;

		case WSA_IO_PENDING:
			printf("�d����������͌�Ɋ��������[(WSA_IO_PENDING)\n");
			break;

		case WSA_NOT_ENOUGH_MEMORY:
			printf("�������s�����Ă邼�B�]�v�ȃ\�t�g���Ƃ������������݂��邩�y�[�W���O�e�ʑ��₻����(WSA_NOT_ENOUGH_MEMORY)\n");
			break;

		case WSA_OPERATION_ABORTED:
			printf("�d����������������ꂿ������Ȃ�(WSA_OPERATION_ABORTED)\n");
			break;

		//case WSAINVALIDPROCTABLE:
		//	printf("�T�[�r�X�E�v���o�C�_����A���Ă����v���V�[�W���e�[�u��������(WSAINVALIDPROCTABLE)\n");
		//	break;

		//case WSAINVALIDPROVIDER:
		//	printf("�T�[�r�X�v���o�C�_�̃o�[�W�����ԍ�������(WSAINVALIDPROVIDER)\n");
		//	break;

		//case WSAPROVIDERFAILEDINIT:
		//	printf("�T�[�r�X�v���o�C�_�������s�\(WSAPROVIDERFAILEDINIT)\n");
		//	break;

		case WSASYSCALLFAILURE:
			printf("�V�X�e���R�[�����s�Ȃ�(WSASYSCALLFAILURE)\n");
			break;
	}

	printf("�G���[�^�C�v : Network - winsock2\n");
	printf("�G���[�R�[�h : %d\n\n", _exception);
	return ;
}

//#endif