/***************************************************************************************
 *
 * Generic_GameLibrary for Windows Version 1.0.0.private alpha
 *
 * Generic_GameLibrary��OpenGL���g�p�����Q�[�����C�u�����ł��B
 * �J���ҁFCocoalix
 *
***************************************************************************************/
#ifndef Generic_GameLibrary_H
#define Generic_GameLibrary_H

#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glut32.lib")

#ifdef _DEBUG

//#pragma comment(lib, "glpngd.lib")
#pragma comment(lib, "libpngd.lib")
#pragma comment(lib, "libpng15d.lib")
#pragma comment(lib, "zlibd.lib")
#pragma comment(lib, "zlib1d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_core240d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_highgui240d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_video240d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_ml240d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_legacy240d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_imgproc240d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_objdetect240d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_features2d240d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_contrib240d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_calib3d240d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_flann240d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_gpu240d.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\common\\tbb\\lib\\ia32\\vc9\\tbb_debug.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\common\\tbb\\lib\\ia32\\vc9\\tbb_preview_debug.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\common\\tbb\\lib\\ia32\\vc9\\tbbmalloc_debug.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\common\\tbb\\lib\\ia32\\vc9\\tbbmalloc_proxy_debug.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\common\\tbb\\lib\\ia32\\vc9\\tbbproxy_debug.lib")

#else

//#pragma comment(lib, "glpng.lib")
#pragma comment(lib, "libpng.lib")
#pragma comment(lib, "libpng15.lib")
#pragma comment(lib, "zlib.lib")
#pragma comment(lib, "zlib1.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_core240.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_highgui240.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_video240.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_ml240.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_legacy240.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_imgproc240.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_objdetect240.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_features2d240.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_contrib240.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_calib3d240.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_flann240.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\x86\\vc9\\lib\\opencv_gpu240.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\common\\tbb\\lib\\ia32\\vc9\\tbb.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\common\\tbb\\lib\\ia32\\vc9\\tbb_preview.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\common\\tbb\\lib\\ia32\\vc9\\tbbmalloc.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\common\\tbb\\lib\\ia32\\vc9\\tbbmalloc_proxy.lib")
#pragma comment(lib, "C:\\Program Files (x86)\\opencv\\build\\common\\tbb\\lib\\ia32\\vc9\\tbbproxy.lib")

#endif

#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "glew.h"
#include "glut.h"
#include "glext.h"
//#include "glpng.h"
#include "wglew.h"
#include "Ggl_Keys.h"
#include "png.h"
#include "zlib.h"

/********************************************* �ʖ���` *********************************************/
typedef char*			GglString;		// ������^
typedef char			GglByte;		// �o�C�g�^(1byte)
typedef unsigned char	GglUByte;		// �����Ȃ��o�C�g�^(1byte)
typedef void*			GglObject;		// �I�u�W�F�N�g�^(���ӁA�ėp�|�C���^(void*)�ł�)
typedef unsigned int	GglSize;		// �T�C�Y�^ 32bit�}�V���ł�size_t�Ɠ���
typedef clock_t			GglClock;		// �N���b�N�^ Windows��clock_t�Ɠ���
typedef unsigned int*	GglSocket;

/*
**************** �萔 ****************
*/
#define GGL_SYSTEMVER					("1.0.0.PrivateBeta")	// �V�X�e���o�[�W����������

#define GGL_PI							(3.14159265358979)		// �~����
#define GGL_GRAVITY_FACTOR				(-0.098)				// �d��
#define GglNetwork_USE_LOCALHOST		("localhost")			// �l�b�g���[�N�p��IP������

#define GGL_FILE_READ_MODE				("r")
#define GGL_FILE_WRITE_MODE				("w")
#define GGL_FILE_ADD_MODE				("a")
#define GGL_FILE_READ_PLUS				("r+")
#define GGL_FILE_WRITE_PLUS				("w+")
#define GGL_FILE_ADD_PLUS				("a+")

#define GGL_FILE_READ_BINALY			("rb")
#define GGL_FILE_WRITE_BINALY			("wb")
#define GGL_FILE_ADD_BINALY				("ab")
#define GGL_FILE_READ_BINPLUS			("rb+")
#define GGL_FILE_WRITE_BINPLUS			("wb+")
#define GGL_FILE_ADD_BINPLUS			("ab+")

// Link.h
#define GglLinkList_MAXTASK			(1024)					// �^�X�N�o�^�ő吔

// Graphic.h
#define GglGraphic_PERS_WIDTH			(800.0)					//
#define GglGraphic_PERS_HEIGHT			(600.0)
#define GglGraphic_PERS_ZNEAR			(0.0)

#define GglGraphic_PERS_ZFAR			(100.0)
#define GglGraphic_PERS_FOVY			(60.0)

#define GglGraphic_ORTHO_TOP			(0.0)
#define GglGraphic_ORTHO_BOTTOM			(103.9231)
#define GglGraphic_ORTHO_LEFT			(0.0)

#define GglGraphic_ORTHO_RIGHT			(103.9231)
#define GglGraphic_ORTHO_ZNEAR			(0.0)
#define GglGraphic_ORTHO_ZFAR			(100.0)

// Fps.h
#define GglFps_ONE_FRAME_FOR_SIXTY		((GglClock)14)			// FPS60�p
#define GglFps_ONE_FRAME_FOR_THIRTY		((GglClock)25)			// FPS30�p
#define GglFps_ONE_FRAME_FOR_FIFTEEN	((GglClock)60)			// FPS15�p

#define GGL_MAX_STRING_LENGTH			(256)


/*
**************** �}�N�� ***************
*/
// Debug Tools
#ifdef GGL_USE_DEBUG

#define GglDebug_PrintExceptionLine()					printf("\n**********iiCatch Exception!!**********\nfrom : %s [L%d]\n", __FILE__, __LINE__)
#define GglDebug_PrintAlertLine(str)					printf("\n*****iiALERT!!*****\nSummary : %s\nfrom : %s [L%d]\n", str, __FILE__, __LINE__)
#define GglDebug_PrintInformationLine(str)				printf("\n----- Information -----\nSummary : %s\n   from : %s [L%d]\n", str, __FILE__, __LINE__)

#else

#define GglDebug_PrintExceptionLine()
#define GglDebug_PrintAlertLine(str)
#define GglDebug_PrintInformationLine(str)

#endif

// ���Z�n
#define GGL_TORAD(x)									(x * GGL_PI / 180)					// �x�����烉�W�A����
#define GGL_TODEG(x)									(x * 180 / GGL_PI)					// ���W�A������x����
#define GGL_POW2(x)										(x * x)								// ���
#define GglColor_BYTE2FLOAT(x)							(x/255)								// �F��0~256����0.0~1.0�ɕ\������(Color.h)

// ���̑�
#define GglVector3f_Normal3(x, y, z)					GglVector3f_Set(x, y, z)				// �֐��ʖ�(GglVector3f.h)
#define GglVector3d_Normal3d(x, y, z)					GglVector3d_Set(x, y, z)			// �֐��ʖ�(Vector3d.h)

// Network
#define GglNetwork_CloseSocket(x)						closesocket(x)

// MultiThread
#define GglMultiThread_BeginThread(func, size, arg)		_beginthread(func, size, arg)			// �֐��ʖ� �X���b�h���쐬
#define GglMultiThread_EndThread()						_endthread()

#define GglMultiThread_CreateMutex(attr, owner, name)	CreateMutex(attr, owner, __name)
#define GglMultiThread_CloseMutex(x)					CloseHandle(x)

#define GglMultiThread_InitializeCriticalSection(x)		InitializeCriticalSection(x)
#define GglMultiThread_DeleteCriticalSection(x)			DeleteCriticalSection(x)
#define GglMultiThread_EnterCriticalSection(x)			EnterCriticalSection(x)

#define GglMultiThread_LeaveCriticalSection(x)			LeaveCriticalSection(x)

// InputDevice
#define GglInputDevice_KeyDown(x)						(g_inputDevice.keyState[x] & 0x80)

// foreach��
#define GGL_FOREACH(val, init, terms, cont)				if((init)!=NULL)	for((val)=(init);(val)!=(terms)&&(val)!=NULL;(val)=(val)->cont)

// New
#define GGL_NEW(type,cnt)			(type*)GglMemory_New(sizeof(type)*cnt)

#define GglBoolean_NEW(cnt)			GGL_NEW(GglBoolean,cnt)
#define GglLinkStatus_NEW(cnt)		GGL_NEW(GglLinkStatus,cnt)
#define GglLinkPriority_NEW(cnt)	GGL_NEW(GglLinkPriority,cnt)

#define GglVector2f_NEW(cnt)		GGL_NEW(GglVector2f,cnt)
#define GglVector2d_NEW(cnt)		GGL_NEW(GglVector2d,cnt)
#define GglVector2i_NEW(cnt)		GGL_NEW(GglVector2i,cnt)

#define GglVector3f_NEW(cnt)		GGL_NEW(GglVector3f,cnt)
#define GglVector3d_NEW(cnt)		GGL_NEW(GglVector3d,cnt)
#define GglVector3i_NEW(cnt)		GGL_NEW(GglVector3i,cnt)

#define GglVector4f_NEW(cnt)		GGL_NEW(GglVector4f,cnt)
#define GglVector4d_NEW(cnt)		GGL_NEW(GglVector4d,cnt)
#define GglVector4i_NEW(cnt)		GGL_NEW(GglVector4i,cnt)

#define GglColor3_NEW(cnt)			GGL_NEW(GglColor3,cnt)
#define GglColor4_NEW(cnt)			GGL_NEW(GglColor4,cnt)
#define GglFps_NEW(cnt)				GGL_NEW(GglFps,cnt)

#define GglRectangle_NEW(cnt)		GGL_NEW(GglRectangle,cnt)
#define GglHit_NEW(cnt)				GGL_NEW(GglHit,cnt)
#define GglImage_NEW(cnt)			GGL_NEW(GglImage,cnt)

#define GglInputDevice_NEW(cnt)		GGL_NEW(GglInputDevice,cnt)
#define GglMatrix3x3_NEW(cnt)		GGL_NEW(GglMatrix3x3,cnt)
#define GglMatrix4x4_NEW(cnt)		GGL_NEW(GglMatrix4x4,cnt)

#define GglMemory_NEW(cnt)			GGL_NEW(GglMemory,cnt)
#define GglMemoryList_NEW(cnt)		GGL_NEW(GglMemoryList,cnt)
#define GglMaterialList_NEW(cnt)	GGL_NEW(GglMaterialList,cnt)

#define GglPolygonFace_NEW(cnt)		GGL_NEW(GglPolygonFace,cnt)
#define GglVertex_NEW(cnt)			GGL_NEW(GglVertex,cnt)
#define GglFace_NEW(cnt)			GGL_NEW(GglFace,cnt)

#define GglMaterial_NEW(cnt)		GGL_NEW(GglMaterial,cnt)
#define GglModel_NEW(cnt)			GGL_NEW(GglModel,cnt)
#define GglThread_NEW(cnt)			GGL_NEW(GglThread,cnt)

#define GglMultiThreadList_NEW(cnt)	GGL_NEW(GglMultiThreadList,cnt)
#define GglLink_NEW(cnt)			GGL_NEW(GglLink,cnt)
#define GglLinkList_NEW(cnt)		GGL_NEW(GglLinkList,cnt)

#define GglSocketNode_NEW(cnt)		GGL_NEW(GglSocketNode,cnt)
#define GglNetworkList_NEW(cnt)		GGL_NEW(GglNetworkList,cnt)


// Vector���Z
// ������
#define GglVector2_Set(_tgt, _x, _y)				((_tgt).x=(_x));((_tgt).y=(_y))
#define GglVector3_Set(_tgt, _x, _y, _z)			((_tgt).x=(_x));((_tgt).y=(_y));((_tgt).z=(_z))
#define GglVector4_Set(_tgt, _x, _y, _z, _q)		((_tgt).x=(_x));((_tgt).y=(_y));((_tgt).z=(_z));((_tgt).q=(_q))

#define GglVector2_SetInitialize(_out)				GglVector2_Set(_out, 0.0, 0.0)
#define GglVector3_SetInitialize(_out)				GglVector3_Set(_out, 0.0, 0.0, 0.0)
#define GglVector4_SetInitialize(_out)				GglVector4_Set(_out, 0.0, 0.0, 0.0, 0.0)

#define GglVector2_SetEqual(_x, _y)					{(_x), (_y)}
#define GglVector3_SetEqual(_x, _y, _z)				{(_x), (_y), (_z)}
#define GglVector4_SetEqual(_x, _y, _z, _q)			{(_x), (_y), (_z), (_q)}

#define GglVector2_SetInitializeEqual()				GglVector2_SetEqual(0.0, 0.0)
#define GglVector3_SetInitializeEqual()				GglVector3_SetEqual(0.0, 0.0, 0.0)
#define GglVector4_SetInitializeEqual()				GglVector4_SetEqual(0.0, 0.0, 0.0, 0.0)

// ���Z
#define GglVector2_Add(_out, _a, _b)				GglVector2_Set(_out, (_a).x+(_b).x, (_a).y+(_b).y)
#define GglVector3_Add(_out, _a, _b)				GglVector3_Set(_out, (_a).x+(_b).x, (_a).y+(_b).y, (_a).z+(_b).z)
#define GglVector4_Add(_out, _a, _b)				GglVector4_Set(_out, (_a).x+(_b).x, (_a).y+(_b).y, (_a).z+(_b).z, (_a).q+(_b).q)

#define GglVector2_AddEqual(_a, _b)					GglVector2_SetEqual((_a).x+(_b).x, (_a).y+(_b).y)
#define GglVector3_AddEqual(_a, _b)					GglVector3_SetEqual((_a).x+(_b).x, (_a).y+(_b).y, (_a).z+(_b).z)
#define GglVector4_AddEqual(_a, _b)					GglVector4_SetEqual((_a).x+(_b).x, (_a).y+(_b).y, (_a).z+(_b).z, (_a).q+(_b).q)

// ���Z
#define GglVector2_Sub(_out, _a, _b)				GglVector2_Set(_out, (_a).x-(_b).x, (_a).y-(_b).y)
#define GglVector3_Sub(_out, _a, _b)				GglVector3_Set(_out, (_a).x-(_b).x, (_a).y-(_b).y, (_a).z-(_b).z)
#define GglVector4_Sub(_out, _a, _b)				GglVector4_Set(_out, (_a).x-(_b).x, (_a).y-(_b).y, (_a).z-(_b).z, (_a).q-(_b).q)

#define GglVector2_SubEqual(_a, _b)					GglVector2_SetEqual((_a).x-(_b).x, (_a).y-(_b).y)
#define GglVector3_SubEqual(_a, _b)					GglVector3_SetEqual((_a).x-(_b).x, (_a).y-(_b).y, (_a).z-(_b).z)
#define GglVector4_SubEqual(_a, _b)					GglVector4_SetEqual((_a).x-(_b).x, (_a).y-(_b).y, (_a).z-(_b).z, (_a).q-(_b).q)

// ����
#define GglVector2_Dot(_a, _b)						(((_a).x*(_b).x)+((_a).y*(_b).y))
#define GglVector3_Dot(_a, _b)						(((_a).x*(_b).x)+((_a).y*(_b).y)+((_a).z*(_b).z))
#define GglVector4_Dot(_a, _b)						(((_a).x*(_b).x)+((_a).y*(_b).y)+((_a).z*(_b).z)+((_a).q*(_b).q))

// �O��
#define GglVector2_Cross(_a, _b)					((_a.x*_b.y)-(_a.y*_b.x))
#define GglVector3_Cross(_out, _a, _b)				GglVector3_Set((_out), ((_a).y*(_b).z-(_a).z*(_b).y), ((_a).z*(_b).x-(_a).x*(_b).z), ((_a).x*(_b).y-(_a).y*(_b).x))
#define GglVector3_CrossEqual(_a, _b)				GglVector3_SetEqual(((_a).y*(_b).z-(_a).z*(_b).y), ((_a).z*(_b).x-(_a).x*(_b).z), ((_a).x*(_b).y-(_a).y*(_b).x))
//#define GglVector4_Cross(_out, _a, _b)		

// �x�N�g���X�J���[�{
#define GglVector2_MulScalar(_vec, _out, _scl)		((_out).x)=((_vec).x)*(_scl); ((_out).y)=((_vec).y)*(_scl)
#define GglVector3_MulScalar(_vec, _out, _scl)		((_out).x)=((_vec).x)*(_scl); ((_out).y)=((_vec).y)*(_scl); ((_out).z)=((_vec).z)*(_scl)
#define GglVector4_MulScalar(_vec, _out, _scl)		((_out).x)=((_vec).x)*(_scl); ((_out).y)=((_vec).y)*(_scl); ((_out).z)=((_vec).z)*(_scl); ((_out).q)=((_vec).q)*(_scl)

// �o�[�e�N�X�ݒ�
#define GglVector2_Vertex2dv(_src, _type)			(glVertex2##_type##v(_src))
#define GglVector3_Vertex3dv(_src, _type)			(glVertex3##_type##v(_src))

// �@���ݒ�
#define GglVector2_Normal2(_src, _type)				(glNormal2##_type(((_src).x), ((_src).y)))
#define GglVector3_Normal3(_src, _type)				(glNormal3##_type(((_src).x), ((_src).y)))
#define GglVector_Normalv(_src, _dim, _type)		(glNormal##_dim##_type(_src))

// ���s�ړ�
#define GglVector_Translate(_src, _type)			(glTranslate##_type(((_src).x), ((_src).y), ((_src).z)))
#define GglVector_Translatev(_src, _type)			(glTranslate##_type##d(_src))

// ���K��
#define GglVector2_Normalize(_src, _out)			{double s = sqrt(GGL_POW2((_src).x)+GGL_POW2((_src).y)); (_out).x=(_src).x/s; (_out).y=(_src).y/s;}
#define GglVector3_Normalize(_src, _out)			{double s = sqrt(GGL_POW2((_src).x)+GGL_POW2((_src).y)+GGL_POW2((_src).z)); (_out).x=(_src).x/s; (_out).y=(_src).y/s; (_out).z=(_src).z/s;}
#define GglVector4_Normalize(_src, _out)			{double s = sqrt(GGL_POW2((_src).x)+GGL_POW2((_src).y)+GGL_POW2((_src).z)+GGL_POW2((_src).q)); (_out).x=(_src).x/s; (_out).y=(_src).y/s; (_out).z=(_src).z/s; (_out).q=(_src).q/s;}

// �x�N�g������
#define GglVector2_GetLength(_vec)					(sqrt(GGL_POW2((_vec).x)+GGL_POW2((_vec).y)))
#define GglVector3_GetLength(_vec)					(sqrt(GGL_POW2((_vec).x)+GGL_POW2((_vec).y)+GGL_POW2((_vec).z)))

// �����x
#define GglVector_Accel(_vi, _accl, _time)			((_vi)+(_accl)*(_time))

// �d�͉����x
#define GglVector_GravityAccel(_vi, time)			((_vi)*(_time)+(GGL_GRAVITY_FACTOR/2)*(GGL_POW2((_time))))


/********************************************* �񋓒�` *********************************************/

/****
 * GglBoolean�񋓑�
 * �u�[���A��������
**********************************************************/
enum GglBoolean			// �u�[���A��
{
	GglFalse,			// �U(=0)
	GglTrue				// �^(=1)

}typedef GglBoolean;

/****
 * GglLinkStatus�񋓑�
 * �I�u�W�F�N�g�̏�Ԃ�\������
************************************************************/
enum GglLinkStatus
{
	StatusDelete,	//�I�u�W�F�N�g�폜
	StatusSleep,	//�I�u�W�F�N�g�͎��s����O����邪�폜����Ȃ�
	StatusLive		//�I�u�W�F�N�g���s

}typedef GglLinkStatus;

/****
 * GglLinkPriority�񋓑�
 * �I�u�W�F�N�g�̕`�揇�Ԃ�\������
************************************************************/
enum GglLinkPriority
{
	PrioLinkHead,		// LinkTask��Head��\��	��ɐ擪
	PrioEmergency,		// �ً}��\�� �v���C���[���������������������Ɏg��
	PrioPlayer,			// ��{�I�Ƀv���C���[�I�u�W�F�N�g��\��
	PrioCharactor,		// �v���C���[�ȊO�̃L�����N�^�[�I�u�W�F�N�g
	PrioObject,			// ���ʂ̃I�u�W�F�N�g
	PrioBackground,		// �w�i�ȂǁA�o�b�N�O���E���h�V�X�e���Ȃǂ�
	PrioOther,			// ���̑��̃I�u�W�F�N�g
	PrioLinkTail		// LinkTask��Tail		��ɍŌ�

}typedef GglLinkPriority;





/**************************************** �\����(���p��)��` ****************************************/

/*********************************************************************************
								�x�N�g���֌W
*********************************************************************************/

/****
 * GglVector2f���p��
 * �x�N�g����\�����p��
**********************************************************/
union GglVector2f
{
	struct
	{
		float x;	// X���W
		float y;	// Y���W
	};

	float array[2];	// �z��([0] = x, [1] = y)

}typedef GglVector2f;

/****
 * GglVector2d���p��
 * �x�N�g����\�����p��
**********************************************************/
union GglVector2d
{
	struct
	{
		double x;			// X���W
		double y;			// Y���W
	};

	double array[2];		// �z��([0] = x, [1] = y)

}typedef GglVector2d;

/****
 * GglVector2i���p��
 * �x�N�g����\�����p��
**********************************************************/
union GglVector2i
{
	struct
	{
		int x;		// X���W
		int y;		// Y���W
	};

	int array[2];	// �z��([0] = x, [1] = y)

}typedef GglVector2i;




/****
 * GglVector3f���p��
 * �x�N�g����\�����p��
 * typedef�ɂ���Ė@�������\��
**********************************************************/
union GglVector3f
{
	struct
	{
		float x;	// x���W
		float y;	// y���W
		float z;	// z���W
	};

	float array[3];	// �z��([0] = x, [1] = y, [2] = z)

}typedef GglVector3f, GglNormal3f;

/****
 * GglVector3d���p��
 * �x�N�g����\�����p��
 * typedef�ɂ���Ė@�������\��
**********************************************************/
union GglVector3d
{
	struct
	{
		double x;		// x���W
		double y;		// y���W
		double z;		// z���W
	};

	double array[3];	// �z��([0] = x, [1] = y, [2] = z)

}typedef GglVector3d, GglNormal3d;

/****
 * GglVector3i���p��
 * �x�N�g����\�����p��
 * typedef�ɂ���Ė@�������\��
**********************************************************/
union GglVector3i
{
	struct
	{
		int x;		// x���W
		int y;		// y���W
		int z;		// z���W
	};

	int array[3];	// �z��([0] = x, [1] = y, [2] = z)

}typedef GglVector3i, GglNormal3i;



/****
 * GglVector4f���p��
 * �x�N�g����\�����p��
**********************************************************/
union GglVector4f
{
	struct
	{
		float x;	// x���W
		float y;	// y���W
		float z;	// z���W
		
		float q;	// �N�I�[�^�j�I����
	};

	float array[4];	// �z��([0] = x, [1] = y, [2] = z, [3] = q)

}typedef GglVector4f;

/****
 * GglVector4d���p��
 * �x�N�g����\�����p��
**********************************************************/
union GglVector4d
{
	struct
	{
		double x;		// x���W
		double y;		// y���W
		double z;		// z���W
		
		double q;		// �N�I�[�^�j�I����

	};

	double array[4];	// �z��([0] = x, [1] = y, [2] = z, [3] = q)

}typedef GglVector4d;

/****
 * GglVector4i���p��
 * �x�N�g����\�����p��
**********************************************************/
union GglVector4i
{
	struct
	{
		int x;		// x���W
		int y;		// y���W
		int z;		// z���W
		
		int q;		// �N�I�[�^�j�I����
	};

	int array[4];	// �z��([0] = x, [1] = y, [2] = z, [3] = q)

}typedef GglVector4i;



/****
 * GglColor3���p��
 * �F����32bit�J���[�œZ�߂��Ă���
**********************************************************/
union GglColor3
{
	struct
	{
		float r;	// Red
		float g;	// Green
		float b;	// Blue
	};

	float array[3];	// �z��([0] = red, [1] = green, [2] = blue)

}typedef GglColor3;

/****
 * GglColor4���p��
 * �F����32bit�J���[�œZ�߂��Ă���
**********************************************************/
union GglColor4
{
	struct
	{
		float r;	// Red
		float g;	// Green
		float b;	// Blue
		float a;	// Alpha
	};

	float array[4];	// �z��([0] = red, [1] = green, [2] = blue, [3] = alpha)

}typedef GglColor4;




/****
 * GglFps�\����
 * ��ʍX�V���ԏ����܂Ƃ߂Ă���
**********************************************************/
struct GglFps
{
	GglClock	countMode;			// �P�b�Ԃɉ��x�X�V���邩��ۑ�����
	GglClock	leaveTime;			// �O��̍X�V�̎��Ԃ�ۑ�����
	GglClock	secondTime;			// �P�b�O�̍X�V�̎��Ԃ�ۑ�����
	int			nowCount	: 8;	// �P�b�Ԃɉ��xFps���X�V���������J�E���g����
	int			secondCount	: 8;	// �O��̂P�b�Ԃɂǂꂭ�炢�X�V���ꂽ����ۑ�����

}typedef GglFps;




/****
 * GglRectangle�\����
 * ��`��\���\����
**********************************************************/
union GglRectangle
{
	struct
	{
		int t;		// top		��
		int l;		// left		��
		int b;		// bottom	��
		int r;		// right	�E
	};

	int array[4];	// �z��([0] = top, [1] = left, [2] = bottom, [3] = right)

}typedef GglRectangle;




/****
 * GglHit�\����
 * �����蔻��ɕK�v�ȕϐ��A�֐��|�C���^������
**********************************************************/
struct GglHit
{
	GglBoolean		hitUse;								// �����蔻����g�p���邩�ǂ������t���O�Ƃ��Ĉ���
	GglBoolean		SphereUse;							// �~�`�A���`�����蔻����g�p���邩�ǂ������t���O�Ƃ��Ĉ���

	GglVector3f*	hitPosition;						// �C���X�^���X�̃|�W�V����
	float			hitRadius;							// �����蔻��̔��a�i�����蔻��͂��ׂĉ~�`�ōs���j
	GglRectangle	hitRect;							// �����蔻��̋�`

	GglObject*		(*HitEventArray)(GglObject, GglObject);	// �����蔻�莞�ɌĂ΂��֐��A���C
	int				HitEventFuncCount;					// �����蔻�莞�ɌĂ΂��֐��A���C�̃A���C�ő吔

}typedef GglHit;




/****
 * GglImage�\����
 * png�摜��RAW�ȂǁA�C���[�W��������
**********************************************************/
struct GglImage
{
	// �s�N�Z�����̐F���
	GglUByte*			rows;		// �摜���

	// �摜�̑傫��
	union
	{
		GglVector2i		size;
		unsigned int	array[2];
	};

	// �`�����l����(�O���[�X�P�[���ARGB�ARGBA�Aetc...
	char				depth;		// �F�[�x
	char				colorType;
	char				channles;	// �J���[�`�����l��

	// OpenGL�ɓo�^���ꂽ�e�N�X�`��ID
	int					id;

}typedef GglImage;




/****
 * GglInputDevice�\����
 * glutKeyboardFunc�ȂǂŎ擾�����L�[�{�[�h����
 * �}�E�X�̃{�^�����Ȃǂ��擾���܂�
**********************************************************/
struct GglInputDevice
{
	GglByte	keyState[256];	// �L�[�{�[�h�̓��͏���ێ����܂�
	int		mouseButton;	// �}�E�X�̓��͏���ێ����܂�
	int		mouseState;		// �}�E�X�̃{�^���̏�Ԃ�ێ����܂�
	int		mouseX;			// ���ꂼ��̑��쎞�̃}�E�X��X���W��ێ����܂�
	int		mouseY;			// ���ꂼ��̑��쎞�̃}�E�X��Y���W��ێ����܂�

}typedef GglInputDevice;




/****
 * GglMatrix3x3�\����
 * �s���\��
**********************************************************/
union GglMatrix3x3
{
	struct
	{
		double _11, _12, _13;	//[0a][0b][0c]
		double _21, _22, _23;	//[1a][1b][1c]
		double _31, _32, _33;	//[2a][2b][2c]
		double _41, _42, _43;	//[3a][3b][3c] ���̂悤��3x3�s��ł���
	};

	double array[3][3];

}typedef GglMatrix3x3;

/****
 * GglMatrix4x4�\����
 * �s���\��
**********************************************************/
union GglMatrix4x4
{
	struct
	{
		double _11, _12, _13, _14;	//[0a][0b][0c][0d]
		double _21, _22, _23, _24;	//[1a][1b][1c][1d]
		double _31, _32, _33, _34;	//[2a][2b][2c][2d]
		double _41, _42, _43, _44;	//[3a][3b][3c][3d] ���̂悤��4x4�s��ł���
	};

	double array[4][4];

}typedef GglMatrix4x4;




/****
 * GglMemory�\����
 * �������Ǘ��̃x�[�X�ƂȂ�\���̂ł���
**********************************************************/
struct GglMemory					// �������Ǘ��\����
{
	struct GglMemory*	next;		// ���̃��������Q��
	struct GglMemory*	prev;		// �O�̃��������Q��

	GglObject			object;		// �������Ǘ��Ƀq���t����I�u�W�F�N�g
	GglSize				memorySize;	// �����o�uobject�v�̃T�C�Y

}typedef GglMemory;

/****
 * GglMemoryList�\����
 * �������Ǘ��̒����ƂȂ�\����
**********************************************************/
struct GglMemoryList
{
	GglMemory*	head;		// �擪 
	GglMemory*	tail;		// �I�[

	GglSize		maxRegist;	// �������o�^��
	GglSize		memorySum;	// �o�^�������̗�

}typedef GglMemoryList;



/**************************************************************************************************************************
*
*	3D���f�����\������\���̌Q
**************************************************************************************************************************/

/****
 * GglMaterialList�\����
 * ��L�̃}�e���A���f�[�^���Ǘ�����\����
**********************************************************/
struct GglMaterialList			// 3D���f���p�}�e���A�����X�g
{
	GglColor4	colorType;		// �g�U���A���邢�͊���
	int			lightPower;		// ���ʌ��̎w��
	GglColor4	specularColor;	// ���ʌ�
	GglColor4	emissionColor;	// ���ˋP�x

	GglString	textureName;	// �e�N�X�`���摜��

}typedef GglMaterialList;

/****
 * GglPolygonFace�\����
 * �|���S���Ɩʏ�������
***********************************************************/
struct GglPolygonFace
{
	GglBoolean	useFourPolygon;	// �l�p�|���S���g�p�t���O
	GglBoolean	useTexture;		// �e�N�X�`���g�p�t���O
	int			index[4];		// �g�p����o�[�e�N�X���
	int			materialIndex;	// �ʂɑΉ�����}�e���A���̃C���f�b�N�X���iGglModel.fMax���瓮�I�m�ہj
	GglVector2d	uv;				// uv���W���

}typedef GglPolygonFace;

/**
 * GglVertex�\����
 * �o�[�e�N�X(���_)��������
*/
struct GglVertex
{
	unsigned int	max;	// �o�[�e�N�X���ő吔
	GglVector3d*	index;	// �o�[�e�N�X���{��(���I�z��)
	GglColor4*		color;	// �o�[�e�N�X�J���[���(���I�z�� NULL�ŕs�g�p)

}typedef GglVertex;

/**
 * GglFace�\����
 * �t�F�C�X(��)��������
*/
struct GglFace
{
	unsigned int	max;		// �ˍő吔
	GglPolygonFace*	index;		// �ˏ��{��(���I�z��)
	GglNormal3d*	normals;	// �@�����(���I�z��)

}typedef GglFace;

/**
 * GglMaterial�\����
 * �}�e���A����������
*/
struct GglMaterial
{
	unsigned int		max;			// �}�e���A�����ő吔(-1�ŕs�g�p)
	GglMaterialList*	index;			// �}�e���A�����X�g�{��

}typedef GglMaterial;

/**
 * GglModel
 * 3D���f�����
************************************************************/
struct GglModel
{
	GglString		name;					// ���f���̖��O

	// Vertex�֘A���
	GglVertex		vertex;
	
	// Face�֘A���
	GglFace			face;

	// Material and VertexColor�֘A���
	GglMaterial		material;

	// SkinAnimation�֘A���
	GglBoolean		useSkinAnimationFlag;	// �X�L���A�j���[�V�����g�p�t���O

}typedef GglModel;


/****
 * GglThread�\����
 * �}���`�X���b�h���g�p���鎞�ɃX���b�h��ێ����邽�߂̍\����
 * ���X�g�\���ƂȂ�
************************************************************/
struct GglThread
{
	struct GglThread*	prev;		// ���X�g�̑O�ւ̃|�C���^
	struct GglThread*	next;		// ���X�g�̎��ւ̃|�C���^

	GglObject			thread;		// �X���b�h(�֐�)�ւ̃|�C���^
	GglObject			argument;	// �}���`�X���b�h�̊֐��ւ̈����|�C���^
	GglBoolean			loopFlag;	// ���[�v���甲���o���t���O False�Ń��[�v�I��

}typedef GglThread;

/****
 * GglMultiThreadList�\����
 * �쐬���ꂽ�X���b�h���Ǘ�����\����
************************************************************/
struct GglMultiThreadList
{
	GglThread*		head;				// ���X�g�̐擪��\���|�C���^
	GglThread*		tail;				// ���X�g�̖�����\���|�C���^

	GglObject*	array;				// ���X�g��z��

	int			count;				// ���X�g�o�^��
	GglBoolean	useMultiThreadFlag;	// �}���`�X���b�h�g�p�t���O

}typedef GglMultiThreadList;


/****
 * GglLink�\����
 * ����q����̃^�X�N�V�X�e�����\�z������\���̂ł���Ɠ�����
 * �O���I�u�W�F�N�g��GglObject�ɂ���ĕێ����邱�Ƃ��ł��A
 * �֐��|�C���^���������邱�ƂŊO���I�u�W�F�N�g�̎��s�ƊǗ���
 * �ȒP�ɂ��邱�Ƃ��ł���
 * C����Œ��ۉ������������AC++�ł����X�[�p�[�N���X�ɓ�����\����
 ************************************************************/
struct GglLink
{
	struct GglLink*		next;		// ���̃m�[�h���Q��
	struct GglLink*		prev;		// �O�̃m�[�h���Q��

	GglObject			object;		// �O���I�u�W�F�N�g
	GglString			name;		// �I�u�W�F�N�g�̖��O
	GglLinkStatus		status;		// �I�u�W�F�N�g�̏��
	GglLinkPriority	priority;	// �I�u�W�F�N�g�̕`�揇��
	GglHit				hit;		// �����蔻��@�\

	// �֐��|�C���^�A���ꂼ��object�̎��s�ƕ`����s��
	void				(*Update)(struct GglLink* io_pLink, GglObject io_object);
	void				(*Draw)(GglObject io_object);

}typedef GglLink;

/****
 * GglLinkList�\����
 * �����N���X�g���Ǘ�
************************************************************/
struct GglLinkList
{
	GglLink* head;		// ���X�g�̐擪
	GglLink* tail;		// ���X�g�̖���

	int count;			// ���X�g�o�^��

}typedef GglLinkList;




/****
 * GglSocketNode�\����
 * �l�b�g���[�N�̒ʐM�P�ʁA�\�P�b�g��ێ�����
************************************************************/
struct GglSocketNode
{
	struct GglSocketNode* next;				// ���X�g�̎���\���|�C���^
	struct GglSocketNode* prev;				// ���X�g�̑O��\���|�C���^

	GglSocket			socket;				// �\�P�b�g
	SOCKADDR_IN			address;			// �A�h���X
	CRITICAL_SECTION	criticalSection;	// �N���e�B�J���Z�N�V����

	GglSize				maxDataSize;		// �f�[�^�̃T�C�Y
	GglString			recvObject;			// ��M���
	GglString			sendObject;			// ���M���
	GglBoolean			recvDataUsedFlag;	// ��M�f�[�^���p�t���O

}typedef GglSocketNode;

/****
 * GglSocketList�\����
 * �\�P�b�g�̃��X�g
************************************************************/
struct GglNetworkList
{
	GglSocketNode*	head;				// �ʐM���X�g�̐�[
	GglSocketNode*	tail;				// �ʐM���X�g�̍Ō��

	GglSocketNode*	hostServerModule;	// �z�X�g�A���邢�̓T�[�o����������̃\�P�b�g

	unsigned int	count;				// �ʐM���Ă��鐔
	GglBoolean		useNetworkFlag;		// �l�b�g���[�N�g�p�t���O

}typedef GglNetworkList;


/*
**************** �֐� ****************
*/
// �摜�t���F�Z�b�g
GglColor4 GglColor4_Initialize(const unsigned char in_r256, const unsigned char in_g256, const unsigned char in_b256, const unsigned char in_a256);
GglColor4 GglColor4_LoadIdentity();

// ���݂̃J�E���g��ǉ�����
void GglFps_Initialize(const GglClock in_countMode);

// Fps�̃J�E���g���X�V����
GglBoolean GglFps_Update(void);

// �Q�[�����P�b�o�����Ƃ��̏���
void GglFps_OneSecond(void);

// ���݂�FPS���R���\�[���ɕ\��
void GglFps_ConsoleDraw(void);

// �~�`�����蔻��(3D)
GglBoolean GglHit_CircleHit(GglVector3f* in_pV1, const float in_r1, GglVector3f* in_pV2, const float in_r2);

// ��`�����蔻��(2D)
GglBoolean GglHit_RectangleHit(GglVector3f* _v1, GglRectangle _r1, GglVector3f* _v2, GglRectangle _r2);

// �~�`�����蔻��g�� ���ˊp�擾
void GglHit_CircleGetIncidenceReflex(GglVector3f* in_pPos1, GglVector3f* in_pPos2, GglVector3f* in_pVec1, GglVector3f* out_v1, GglVector3f* out_v2);

/*
	Image.c
*/
// PNG�C���[�W�ǂݍ���
GglImage* GglImage_LoadPng(GglImage* out_pImage, GglString in_fileName);
// PNG�ǂݍ��݃R�[���o�b�N
void GglImage_ReadPng(png_structp in_pPng, png_bytep out_data, png_size_t in_length);

//// �C���[�W�Z�b�g
//GglImage GglImage_AssembleElements(unsigned int* in_pImage, pngRawInfo* in_pInfo, GglImage* out_pImage);
//
////�C���[�W����o�^����֐�
//GglBoolean GglImage_RegistImage(GglImage* out_pImage, GglString in_string);


void GglInputDevice_GetKeyboardState(void);
void GglInputDevice_Mouse(int in_button, int in_state, int in_x, int in_y);

// Escape�L�[�ŃQ�[�����I��������֐�
void GglInputDevice_ShutDownKey(void);

// �V�X�e���N�����ɍs��g_inputDevice�̏������֐��Q
void GglInputDevice_MouseInit(void);
void GglInputDevice_AllInitialize(void);

/* �l�����Z */
void GglMatrix4x4_Add(GglMatrix4x4* out_pM, const GglMatrix4x4* in_pM1, const GglMatrix4x4* in_pM2);	// �����Z
void GglMatrix4x4_Sub(GglMatrix4x4* out_pM, const GglMatrix4x4* in_pM1, const GglMatrix4x4* in_pM2);	// �����Z
void GglMatrix4x4_Mul(GglMatrix4x4* out_pM, const GglMatrix4x4* in_pM1, const GglMatrix4x4* in_pM2);	// �|���Z

/* �l�����Z �擪�A�h���X�p */
void GglMatrix4x4_AddF(double* out_pMFAdr, const double* in_pMFAdr1, const double* in_pMFAdr2);
void GglMatrix4x4_SubF(double* out_pMFAdr, const double* in_pMFAdr1, const double* in_pMFAdr2);
void GglMatrix4x4_MulF(double* out_pMFAdr, const double* in_pMFAdr1, const double* in_pMFAdr2);


/* ���ꉉ�Z */
void GglMatrix4x4_DotVector(GglVector3f* out_pVec, const GglMatrix4x4* in_pMat, const GglVector3f* in_pVec);	// �X�J���[�{
void GglMatrix4x4_DotScalar(GglMatrix4x4* out_pMat, const GglMatrix4x4* in_pMat, const double in_scalar);	// �x�N�g���{

// ���[���h�s�񏉊���(�P�ʍs����㏑��)
void GglMatrix4x4_SetIdentity(GglMatrix4x4* out_pMat);

/* ��] */
GglMatrix4x4 GglMatrix4x4_GetRotatePitch(const double in_rad);	// X��
GglMatrix4x4 GglMatrix4x4_GetRotateYaw(const double in_rad);	// Y��
GglMatrix4x4 GglMatrix4x4_GetRotateRoll(const double in_rad);	// Z��

/* �g�k */
GglMatrix4x4 GglMatrix4x4_GetScale(const GglVector3d* in_pV);

/* ���s�ړ� */
GglMatrix4x4 GglMatrix4x4_GetTranslation(const GglVector3d* in_pV);

GglBoolean	GglMemory_Initialize(void);
GglBoolean	GglMemory_Shutdown(void);

GglObject	GglMemory_New(GglSize _size);
GglBoolean	GglMemory_Delete(GglObject _object);
GglBoolean	GglMemory_AllDelete(void);
GglBoolean	GglMemory_DeleteMemoryAndReconnect(GglMemory* _this);


void		GglMemory_ReconnectList(GglMemory* _first, GglMemory* _end);
GglMemory*	GglMemory_SearchNull2First(void);
GglMemory*	GglMemory_SearchNull2End(void);

GglModel* GglModel_Initialize(GglModel* out_model);		// ���f��������

// ���f�����[�h�֐��Q
GglModel*	GglModel_LoadModel(const GglString in_fileName, GglModel* out_model);	// ���f�����[�h
GglBoolean	GglModel_LoadModel2X(const GglString in_fileName, GglModel* _pModel);							// X�t�@�C�����[�h
void		GglModel_LoadModel2X_ReadMesh(FILE* _pFile, GglModel* _pModel, GglString _buffer);				// X�t�@�C�����b�V���f�[�^���[�h

void		GglModel_LoadModel2X_ReadMaterialList(FILE* _pFile, GglModel* _pModel);		// X�t�@�C���}�e���A�����X�g�f�[�^���[�h
//void		GglModel_LoadModel2X_ReadMaterial(FILE*_pFile, GglModel* _pModel);			// X�t�@�C���}�e���A���f�[�^���[�h
void		GglModel_LoadModel2X_ReadMeshVertexColors(FILE* _pFile, GglModel* _pModel);	// X�t�@�C���o�[�e�b�N�X�J���[�f�[�^���[�h

void		GglModel_LoadModel2X_ReadMeshNormals(FILE* _pFile, GglModel* _pModel, long* _pos);			// X�t�@�C�����b�V���m�[�}���f�[�^���[�h
void		GglModel_LoadModel2X_ReadMeshTextureCoords(FILE* _pFile, GglModel* _pModel, long* _pos);	// X�t�@�C���e�N�X�`���[�R�[�h�f�[�^���[�h

GglBoolean	GglModel_LoadModel2Mqo(const GglString in_fileName, GglModel** _pModel);						// MQO�t�@�C�����[�h

// ���̑�
void		GglModel_DeleteModel(GglModel* _this);		// ���f���폜

GglBoolean	GglMultiThread_Initialize(void);
void		GglMultiThread_Shutdown(void);

GglBoolean	GglMultiThread_AddThread(GglThread* _pThreadInst);
GglBoolean	GglMultiThread_AddNewThread(void(*_funcName)(GglObject), unsigned _stackSize, GglObject _argStructInstance);

GglBoolean	GglMultiThread_RemoveThread(GglThread* _pThreadInst);
GglBoolean	GglMultiThread_RemoveAllThread(void);
GglBoolean	GglMultiThread_LoopFlagSwitch(GglThread* _this);

GglBoolean	GglString_ExtractErase(const int ic_count, GglString o_str, const int tgtlen, const GglString ic_target, ...);
GglString	GglString_EraseFirst(int _eraseLength, GglString _target);
GglString	GglString_MakeString(GglString str, GglSize length);

// �摜�T�C�Y�A�͈̓Z�b�g
GglRectangle GglRectangle_Initialize(const int in_top, const int in_bottom, const int in_left, const int in_right);
GglRectangle GglRectangle_LoadIdentity();

//// GglRectangle����Vertex2d�Ȃǂ�臒l(0.0~1.0)�֕ϊ�����
//void GglRectangle_ExchangeIdentity(GglRectangle* out_pRect, const GglRectangle* in_pRect, const pngInfo* in_pInfo);



//// �x�N�g���Z�b�g
//GglVector2i GglVector2i_Set(const int in_x, const int in_y);
//GglVector2i GglVector2i_SetInitialize(void);
//
//// �����Z
//GglVector2i GglVector2i_Add(GglVector2i in_v1, GglVector2i in_v2);
//void GglVector2i_AddEquals(GglVector2i* io_pV1, GglVector2i in_v2);
//
//// �����Z
//GglVector2i GglVector2i_Sub(GglVector2i in_v1, GglVector2i in_v2);
//void GglVector2i_SubEquals(GglVector2i* io_pV1, GglVector2i in_v2);
//
//// ����
//int GglVector2i_Dot(GglVector2i in_v1, GglVector2i in_v2);
//
//int GglVector2i_Dotp(GglVector2i* in_v1, GglVector2i* in_v2);
//
//// �x�N�g���̑傫�����擾���܂�
//int GglVector2i_GetLength(GglVector2i* in_pV);
//
//// �x�N�g�����X�J���[�{���܂�
//void GglVector2i_SetMultipleScalar(GglVector2i* in_pV, const int in_scalar, GglVector2i* out_pV);
//
//void GglVector2i_Vertex2dv(GglVector2i* in_pV);
//
////���s�ړ�
//void GglVector2i_Translatef(GglVector2i* in_pVec);
//
//// �x�N�g�����K��
//void GglVector2i_Normalize3D(GglVector2i in_vec, GglVector2i* out_pv);
//
//// �����x�v�Z
//int GglVector2i_Accel(int in_vi,int in_accel, int in_time);
//
//// �d�͉����x�v�Z
//int GglVector2i_GravityAccel(int in_viy, int in_time);
//
//
//
//// �x�N�g���Z�b�g
//GglVector2f GglVector2fSet(const float in_x, const float in_y, const float in_z);
//GglVector2f GglVector2fSetInitialize(void);
//
//// �����Z
//GglVector2f GglVector2fAdd(GglVector2f in_v1, GglVector2f in_v2);
//void GglVector2fAddEquals(GglVector2f* io_pV1, GglVector2f in_v2);
//
//// �����Z
//GglVector2f GglVector2fSub(GglVector2f in_v1, GglVector2f in_v2);
//void GglVector2fSubEquals(GglVector2f* io_pV1, GglVector2f in_v2);
//
//// ����
//float GglVector2fDot(GglVector2f in_v1, GglVector2f in_v2);
//float GglVector2fDotp(GglVector2f* in_v1, GglVector2f* in_v2);
//
//// �x�N�g���̑傫�����擾���܂�
//float GglVector2fGetLength(GglVector2f* in_pV);
//
//// �x�N�g�����X�J���[�{���܂�
//void GglVector2fSetMultipleScalar(GglVector2f* in_pV, const float in_scalar, GglVector2f* out_pV);
//
//void GglVector2fVertex2dv(GglVector2f* in_pV);
//
////���s�ړ�
//void GglVector2fTranslatef(GglVector2f* in_pVec);
//
//// �x�N�g�����K��
//void GglVector2fNormalize3D(GglVector2f in_vec, GglVector2f* out_pv);
//
//// �����x�v�Z
//float GglVector2fAccel(float in_vi,float in_accel, int in_time);
//
//// �d�͉����x�v�Z
//float GglVector2fGravityAccel(float in_viy, float in_time);
//
//
//
//// �x�N�g���[��������
//GglVector2d GglVector2d_SetInitialize(void);
//
//// �x�N�g���Z�b�g
//GglVector2d GglVector2d_Set(const double in_x, const double in_y);
//
//// �����Z
//GglVector2d GglVector2d_Add(GglVector2d in_v1, GglVector2d in_v2);
//void GglVector2d_AddEquals(GglVector2d* io_pV1, GglVector2d in_v2);
//
//// �����Z
//GglVector2d GglVector2d_Sub(GglVector2d in_v1, GglVector2d in_v2);
//void GglVector2d_SubEquals(GglVector2d* io_pV1, GglVector2d in_v2);
//
//// ����
//double GglVector2d_Dot(GglVector2d in_v1, GglVector2d in_v2);
//double GglVector2d_Dotp(GglVector2d* in_v1, GglVector2d* in_v2);
//
//// �x�N�g���̑傫�����擾
//double GglVector2d_GetLength(GglVector2d* in_pV);
//
//// �x�N�g�����X�J���[�{
//void GglVector2d_SetMultipleScalar(GglVector2d* in_pV, double in_scalar, GglVector2d* out_pV);
//
///* GL�p�֐� */
//// �o�[�e�b�N�X�ݒ�
//void GglVector2d_Vertex2dv(GglVector2d* in_pV);
//
//// ���s�ړ�
//void GglVector2d_Translated(GglVector2d* in_pVec);
//
//
///* �Q�[���p�֐� */
//// �x�N�g�����K��
//void GglVector2d_Normalize3D(GglVector2d in_vec, GglVector2d* out_pv);
//
//// �����x�v�Z
//double GglVector2d_Accel(double in_vi,double in_accel, int in_time);
//
//// �d�͉����x�v�Z
//double GglVector2d_GravityAccel(double in_viy, double in_time);
//
//
//
//
//
//// �x�N�g���[��������
//GglVector3d GglVector3d_SetInitialize(void);
//
//// �x�N�g���Z�b�g
//GglVector3d GglVector3d_Set(const double in_x, const double in_y, const double in_z);
//
//// �����Z
//GglVector3d GglVector3d_Add(GglVector3d in_v1, GglVector3d in_v2);
//void GglVector3d_AddEquals(GglVector3d* io_pV1, GglVector3d in_v2);
//
//// �����Z
//GglVector3d GglVector3d_Sub(GglVector3d in_v1, GglVector3d in_v2);
//void GglVector3d_SubEquals(GglVector3d* io_pV1, GglVector3d in_v2);
//
//// ����
//double GglVector3d_Dot(GglVector3d in_v1, GglVector3d in_v2);
//double GglVector3d_Dotp(GglVector3d* in_v1, GglVector3d* in_v2);
//
//// �O��
//GglVector3d GglVector3d_Cross(GglVector3d in_v1, GglVector3d in_v2);
//
//// �x�N�g���̑傫�����擾
//double GglVector3d_GetLength(GglVector3d* in_pV);
//
//// �x�N�g�����X�J���[�{
//void GglVector3d_SetMultipleScalar(GglVector3d* in_pV, double in_scalar, GglVector3d* out_pV);
//
///* GL�p�֐� */
//// �o�[�e�b�N�X�ݒ�
//void GglVector3d_Vertex3dv(GglVector3d* in_pV);
//void GglVector3d_Vertex2dv(GglVector3d* in_pV);
//
//// �@���ݒ�
//void GglVector3d_Normal3dv(GglNormal3d* in_pN);
//
//// ���s�ړ�
//void GglVector3d_Translated(GglVector3d* in_pVec);
//
//
///* �Q�[���p�֐� */
//// �x�N�g�����K��
//void GglVector3d_Normalize3D(GglVector3d in_vec, GglVector3d* out_pv);
//
//// �����x�v�Z
//double GglVector3d_Accel(double in_vi,double in_accel, int in_time);
//
//// �d�͉����x�v�Z
//double GglVector3d_GravityAccel(double in_viy, double in_time);
//
//
//
//
//
//
//
//// �x�N�g���[��������
//GglVector3f GglVector3f_SetInitialize(void);
//
//// �x�N�g���Z�b�g
//GglVector3f GglVector3f_Set(const double in_x, const double in_y, const double in_z);
//
//// �����Z
//GglVector3f GglVector3f_Add(GglVector3f in_v1, GglVector3f in_v2);
//void GglVector3f_AddEquals(GglVector3f* io_pV1, GglVector3f in_v2);
//
//// �����Z
//GglVector3f GglVector3f_Sub(GglVector3f in_v1, GglVector3f in_v2);
//void GglVector3f_SubEquals(GglVector3f* io_pV1, GglVector3f in_v2);
//
//// ����
//double GglVector3f_Dot(GglVector3f in_v1, GglVector3f in_v2);
//double GglVector3f_Dotp(GglVector3f* in_v1, GglVector3f* in_v2);
//
//// �O��
//GglVector3f GglVector3f_Cross(GglVector3f in_v1, GglVector3f in_v2);
//
//// �x�N�g���̑傫�����擾
//float GglVector3f_GetLength(GglVector3f* in_pV);
//
//// �x�N�g�����X�J���[�{
//void GglVector3f_SetMultipleScalar(GglVector3f* in_pV, double in_scalar, GglVector3f* out_pV);
//
///* GL�p�֐� */
//// �o�[�e�b�N�X�ݒ�
//void GglVector3f_Vertex3dv(GglVector3f* in_pV);
//void GglVector3f_Vertex2dv(GglVector3f* in_pV);
//
//// �@���ݒ�
//void GglVector3f_Normal3dv(GglNormal3f* in_pN);
//
//// ���s�ړ�
//void GglVector3f_Translatef(GglVector3f* in_pVec);
//
//
///* �Q�[���p�֐� */
//// �x�N�g�����K��
//void GglVector3f_Normalize3D(GglVector3f in_vec, GglVector3f* out_pv);
//
//// �����x�v�Z
//double GglVector3f_Accel(double in_vi,double in_accel, int in_time);
//
//// �d�͉����x�v�Z
//double GglVector3f_GravityAccel(double in_viy, double in_time);
//
//
//
//// �x�N�g���Z�b�g
//GglVector3i GglVector3i_SetInitialize(void);
//
//// �x�N�g���Z�b�g
//GglVector3i GglVector3i_Set(const int in_x, const int in_y, const int in_z);
//
//// �����Z
//GglVector3i GglVector3i_Add(GglVector3i in_v1, GglVector3i in_v2);
//void GglVector3i_AddEquals(GglVector3i* io_pV1, GglVector3i in_v2);
//
//// �����Z
//GglVector3i GglVector3i_Sub(GglVector3i in_v1, GglVector3i in_v2);
//void GglVector3i_SubEquals(GglVector3i* io_pV1, GglVector3i in_v2);
//
//// ����
//double GglVector3i_Dot(GglVector3i in_v1, GglVector3i in_v2);
//double GglVector3i_Dotp(GglVector3i* in_v1, GglVector3i* in_v2);
//
//// �O��
//GglVector3i GglVector3i_Cross(GglVector3i in_v1, GglVector3i in_v2);
//
//// �x�N�g���̑傫�����擾���܂�
//float GglVector3i_GetLength(GglVector3i* in_pV);
//
//// �x�N�g�����X�J���[�{���܂�
//void GglVector3i_SetMultipleScalar(GglVector3i* in_pV, int in_scalar, GglVector3i* out_pV);
//
//// �o�[�e�b�N�X�ݒ�
//void GglVector3i_Vertex3dv(GglVector3i* in_pV);
//void GglVector3i_Vertex2dv(GglVector3i* in_pV);
//
//// �@���ݒ�
//void GglVector3i_Normal3dv(GglNormal3f* in_pN);
//
//// ���s�ړ�
//void GglVector3i_Translatef(GglVector3i* in_pVec);
//
//// �x�N�g�����K��
//void GglVector3i_Normalize3D(GglVector3i in_vec, GglVector3i* out_pv);
//
//// �����x�v�Z
//double GglVector3i_Accel(double in_vi,double in_accel, int in_time);
//
//// �d�͉����x�v�Z
//double GglVector3i_GravityAccel(double in_viy, double in_time);
//
//
//
//
//
//
//// �x�N�g���[��������
//GglVector4d GglVector4d_SetInitialize(void);
//
//// �x�N�g���Z�b�g
//GglVector4d GglVector4d_Set(const double in_x, const double in_y, const double in_z, const double in_q);
//
//// �����Z
//GglVector4d GglVector4d_Add(GglVector4d in_v1, GglVector4d in_v2);
//void GglVector4d_AddEquals(GglVector4d* io_pV1, GglVector4d in_v2);
//
//// �����Z
//GglVector4d GglVector4d_Sub(GglVector4d in_v1, GglVector4d in_v2);
//void GglVector4d_SubEquals(GglVector4d* io_pV1, GglVector4d in_v2);
//
//// ����
//double GglVector4d_Dot(GglVector4d in_v1, GglVector4d in_v2);
//double GglVector4d_Dotp(GglVector4d* in_v1, GglVector4d* in_v2);
//
//// �x�N�g���̑傫�����擾
//double GglVector4d_GetLength(GglVector4d* in_pV);
//
//// �x�N�g�����X�J���[�{
//void GglVector4d_SetMultipleScalar(GglVector4d* in_pV, double in_scalar, GglVector4d* out_pV);
//
//// �x�N�g�����K��
//void GglVector4d_Normalize4d(GglVector4d in_vec, GglVector4d* out_pv);
//
//
//
//
//
//
//
//
//// �x�N�g���[��������
//GglVector4f GglVector4f_SetInitialize(void);
//
//// �x�N�g���Z�b�g
//GglVector4f GglVector4f_Set(const float in_x, const float in_y, const float in_z, const float in_q);
//
//// �����Z
//GglVector4f GglVector4f_Add(GglVector4f in_v1, GglVector4f in_v2);
//void GglVector4f_AddEquals(GglVector4f* io_pV1, GglVector4f in_v2);
//
//// �����Z
//GglVector4f GglVector4f_Sub(GglVector4f in_v1, GglVector4f in_v2);
//void GglVector4f_SubEquals(GglVector4f* io_pV1, GglVector4f in_v2);
//
//// ����
//float GglVector4f_Dot(GglVector4f in_v1, GglVector4f in_v2);
//float GglVector4f_Dotp(GglVector4f* in_v1, GglVector4f* in_v2);
//
//
//// �x�N�g���̑傫�����擾
//float GglVector4f_GetLength(GglVector4f* in_pV);
//
//// �x�N�g�����X�J���[�{
//void GglVector4f_SetMultipleScalar(GglVector4f* in_pV, float in_scalar, GglVector4f* out_pV);
//
///* �Q�[���p�֐� */
//// �x�N�g�����K��
//void GglVector4f_Normalize3D(GglVector4f in_vec, GglVector4f* out_pv);
//
//
//
//
//
//
//// �x�N�g���Z�b�g
//GglVector4i GglVector4i_SetInitialize(void);
//
//// �x�N�g���Z�b�g
//GglVector4i GglVector4i_Set(const int in_x, const int in_y, const int in_z, const int in_q);
//
//// �����Z
//GglVector4i GglVector4i_Add(GglVector4i in_v1, GglVector4i in_v2);
//void GglVector4i_AddEquals(GglVector4i* io_pV1, GglVector4i in_v2);
//
//// �����Z
//GglVector4i GglVector4i_Sub(GglVector4i in_v1, GglVector4i in_v2);
//void GglVector4i_SubEquals(GglVector4i* io_pV1, GglVector4i in_v2);
//
//// ����
//double GglVector4i_Dot(GglVector4i in_v1, GglVector4i in_v2);
//double GglVector4i_Dotp(GglVector4i* in_v1, GglVector4i* in_v2);
//
//// �x�N�g���̑傫�����擾���܂�
//float GglVector4i_GetLength(GglVector4i* in_pV);
//
//// �x�N�g�����X�J���[�{���܂�
//void GglVector4i_SetMultipleScalar(GglVector4i* in_pV, int in_scalar, GglVector4i* out_pV);








//// 2D�`��
void GglGraphic2d_DrawSprite(GglImage* in_pImage, GglVector2i* in_pSize, GglRectangle* in_pRect, GglVector3f* in_pVec, GglColor4* in_pColor);
//
//// 2D���`��
//void GglGraphic2d_DrawLine2d(GglVector3f* in_pOrigin, GglVector3f* in_pEndPoint, GglColor4* in_pColor);

// �F�ݒ�
void GglGraphic2d_Color3dv(const GglColor4* in_pColor);	//�A���t�@����
void GglGraphic2d_Color4dv(const GglColor4* in_pColor);	//�A���t�@����

// �}�e���A���ݒ�
void GglGraphic2d_Materialfv(const GLenum in_targetFace, const GLenum in_lightingMaterial, const GglColor4* in_pColor);

// 3D�`��
void GglGraphic3d_Render(const GglModel* in_pModel, const GglVector3d* in_pTranslate, const GglVector3d* in_pRotate, const GglVector3d* in_pScale);

// �`�掋���Perspective�ɂ���
void GglGraphic_Perspective(void);

// �`�掋���Ortho2D�ɂ���
void GglGraphic_Ortho2d(void);

void GglGraphic_DrawSpriteBegin(void);
void GglGraphic_DrawSpriteEnd(void);


GglBoolean GglNetworkList_Initialize(void);
GglBoolean GglNetworkList_Shutdown(void);

GglBoolean GglNetworkList_AddElement(GglSocketNode* _this);
GglBoolean GglNetworkList_RemoveElement(GglSocketNode* _this);
GglBoolean GglNetworkList_RemoveElementAt(unsigned int _elements);
GglBoolean GglNetworkList_RemoveAllElements(void);

GglBoolean	GglNetwork_Initialize(void);		// ������
GglBoolean	GglNetwork_Shutdown(void);		// �I��

void		GglNetwork_GetIpAddress(GglString out_ipAddr);	// ����IP�擾
GglBoolean	GglNetwork_MakeSocket(GglSocketNode* _pModule, GglString _addressString, int _usePort);

//void		GglNetwork_HostServerWaitGuestClient(GglObject _object);
GglBoolean	GglNetwork_HostServerWaitGuestClientOnce(GglObject _object);

void		GglNetwork_ReceiveData(GglObject _object);
void		GglNetwork_SendData(GglObject _object);

/* Debug */
void		GglNetwork_PrintError(void);
void		GglNetwork_Winsock2PrintErrorSelect(int _exception);

void		GglSystem_Initialize(const GglString ic_windowName, void (*GameInit)(void));
void		GglSystem_Shutdown(void);
void		GglSystem_MainLoopUpdate(void);
void		GglSystem_MainLoopDraw(void);
void		GglSystem_WindowResize(const int _w, const int _h);

void		GglSystem_InitializeGlut(void);
void		GglSystem_InitializeSystem(void);
void		GglSystem_UnLoadContent(void);


// LinkTaskSystem �֐�
void		GglLinkList_Initialize(void);						//LinkTask�N��
void		GglLinkList_Shutdown(void);							//LinkTask�I��
GglBoolean	GglLinkList_AddElement(GglLink* _new);				//LinkTask�ɐV�����m�[�h��ǉ�
GglBoolean	GglLinkList_RemoveElement(GglLink* _del);			//LinkTask����w�肵���m�[�h���폜
GglBoolean	GglLinkList_RemoveElementAt(const int ic_element);	//LinkTask����w�肵���m�[�h���폜
void		GglLinkList_RemoveAllElements(void);					//LinkTask�ɓo�^����Ă���m�[�h�S�폜
void		GglLinkList_Update(void);							//LinkTask���ɓo�^����Ă���m�[�h�̎��s�֐����s
void		GglLinkList_Draw(void);								//LinkTask���ɓo�^����Ă���m�[�h�̕`��֐����s




/*
************************************  Global Variable  *****************************************
*/
extern GglInputDevice			g_inputDevice;		// ���̓f�o�C�X�Ǘ�
extern GglFps					g_fps;				// Fps�\���̂̃O���[�o���ϐ�
//extern GglImage*				g_imageArray;		// �C���[�W�f�[�^�i�[�z��

extern GglLinkList			g_linkList;		// �^�X�N�V�X�e��

extern GglMemoryList			g_memoryList;	// �������Ǘ����X�g
extern GglNetworkList		g_networkList;	// �l�b�g���[�N�p�\�P�b�g�\����
extern GglMultiThreadList	g_multiThread;		// �}���`�X���b�h�n���h�������N���X�g

//extern GglVector2d			g:

#endif