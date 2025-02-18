#include "Generic_GameLibrary.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>

//#include <ctype.h>

#pragma warning(disable : 4996)

/**
 * GglModel_Initialize
 * ���f���f�[�^������������
 * @return	�������������f���f�[�^��Ԃ�
 * @param	�������������f���f�[�^��n��
*/
GglModel* GglModel_Initialize(GglModel* out_model)
{
	GglModel* model = (GglModel*)GglMemory_New(sizeof(GglModel));
	
	model->face.index			= NULL;
	model->face.max				= 0;
	model->material.index		= NULL;
	model->material.max			= 0;
	model->name					= NULL;
	model->face.normals			= NULL;
	model->useSkinAnimationFlag	= GglFalse;
	model->vertex.color			= NULL;
	model->vertex.index			= NULL;
	model->vertex.max			= 0;

	if(out_model)
	{
		model = out_model;
	}

	return model;
}

/**
 * GglModel_LoadModel�֐�
 * ���f���f�[�^���g���q���画�ʂ��ēǂݍ��ފ֐�
 * @return	�ǂݍ��񂾃��f���f�[�^��Ԃ�
 * @param	�t�@�C����
 * @param	�ǂݍ��񂾃��f���f�[�^��n��
*/
GglModel* GglModel_LoadModel(const GglString in_fileName, GglModel* out_model)
{
	GglModel* model = GglModel_Initialize(NULL);

	if(strstr(in_fileName, ".x") != NULL)
	{
		GglModel_LoadModel2X(in_fileName, model);
	}
	else if(strstr(in_fileName, ".mqo") != NULL)
	{
		GglModel_LoadModel2X(in_fileName, model);
	}
	else
	{
		out_model = NULL;
		return NULL;
	}

	if(out_model)
	{
		out_model = model;
	}

	return model;
}


GglBoolean GglModel_LoadModel2X(const GglString in_fileName, GglModel* _pModel)
{
	FILE*			pFile;
	char			buffer[256];
	int				num						= 0;
	GglSize			deleteSize				= 0;
	GglSize			nameLength				= 0;
	
	//long			meshAddressPos;
	//long			materialListAddressPos;
	long			meshNormalsPos			= -1;
	long			meshTextureCoordsPos	= -1;

	/* X�t�@�C���̓ǂݍ��݊J�n */
	pFile = fopen(in_fileName, "r");
	if(pFile == NULL)
	{
		GglDebug_PrintExceptionLine();
		printf("Failed File Open...\n");
		_pModel->name = "null\0";
		return GglFalse;
	}

	//while( fgets(buffer, 256, pFile) != NULL)
	for(fgets(buffer, 256, pFile); feof(pFile) == GglFalse; fgets(buffer, 256, pFile))
	{
		if(strstr(buffer,"template") != NULL)
		{
			continue;																		// �e���v���[�g�ǂݔ�΂�
		}
		
		if(strstr(buffer,"Mesh ") != NULL)														
		{
			GglModel_LoadModel2X_ReadMesh(pFile, _pModel, buffer);
		}
		else if(strstr(buffer, "MeshMaterialList ") != NULL)
		{
			GglModel_LoadModel2X_ReadMaterialList(pFile, _pModel);
		}
		else if(strstr(buffer, "MeshVertexColors") != NULL)
		{
			GglModel_LoadModel2X_ReadMeshVertexColors(pFile, _pModel);
		}
		else if(strstr(buffer, "MeshNormals") != NULL)
		{
			GglModel_LoadModel2X_ReadMeshNormals(pFile, _pModel, &meshNormalsPos);
		}
		else if(strstr(buffer, "MeshTextureCoords") != NULL)
		{
			GglModel_LoadModel2X_ReadMeshTextureCoords(pFile, _pModel, &meshTextureCoordsPos);
		}
	}

	//if(meshNormalsPos != -1)
	//{
	//	GglModel_LoadModel2X_ReadMeshNormals(pFile, _pModel, &meshNormalsPos);
	//}

	//if(meshTextureCoordsPos != -1)
	//{
	//	GglModel_LoadModel2X_ReadMeshTextureCoords(pFile, _pModel, &meshTextureCoordsPos);
	//}

	fclose(pFile);
	return GglTrue;
}

static void GglModel_LoadModel2X_ReadMesh(FILE* _pFile, GglModel* _pModel, GglString _buffer)
{
	char		buffer[256];
	GglString	pBuf = &buffer[0];
	int			i;
	int			nameLength;
	GglBoolean	useNameFlag	= GglFalse;

	memset(buffer, '\0', 256);
	strncpy(buffer, _buffer, strlen(_buffer));

	GglString_EraseFirst((int)strlen(" Mesh "), pBuf);

	nameLength = (unsigned int)strlen( strtok(buffer, " {") ) + 1;

	if(nameLength <= 2)
	{
		nameLength	= 10;
		useNameFlag	= GglFalse;
	}
	else
	{
		useNameFlag = GglTrue;
	}

	// ��؂蕶���܂Ŕ����o��
	_pModel->name = GglString_MakeString(useNameFlag ? buffer : "Anonymous\0", useNameFlag ? strlen(buffer) : 10);

	// �����_���l��
	fgets(buffer, 256, _pFile);
	_pModel->vertex.max = atoi( strtok( buffer, ";" ) );	// ������𐔒l�Ƃ��đ��

	// ���_���W�擾
	_pModel->vertex.index = (GglVector3d*)GglMemory_New(sizeof(GglVector3d) * _pModel->vertex.max);	// �i�[���铮�I�z��m��
	for(i=0; i<(int)_pModel->vertex.max; i++)
	{
		fgets(buffer, 256, _pFile);	// 1�s�i�߂�
		_pModel->vertex.index[i].x = atof( strtok(buffer, ";") );
		_pModel->vertex.index[i].y = atof( strtok(NULL, ";") );
		_pModel->vertex.index[i].z = atof( strtok(NULL, ";") );
	}

	// ���ʐ��擾
	fgets(buffer, 256, _pFile);
	_pModel->face.max	= atoi( strtok(buffer, ";") );
	_pModel->face.index	= (GglPolygonFace*)GglMemory_New(sizeof(GglPolygonFace) * _pModel->face.max);			// �i�[���铮�I�z��m��

	// �ʃC���f�b�N�X�擾
	for(i=0; i<(int)_pModel->face.max; i++)
	{
		fgets(buffer, 256, _pFile);	// �P�s�i�߂�
		_pModel->face.index[i].useFourPolygon = (atoi( strtok(buffer, ";") ) == 3) ? GglFalse : GglTrue;	// �擪�̃|���S������\��������̎擾

		if(_pModel->face.index[i].useFourPolygon == GglFalse)
		{
			_pModel->face.index[i].index[0] = atoi( strtok(NULL, ",") );
			_pModel->face.index[i].index[1] = atoi( strtok(NULL, ",") );
			_pModel->face.index[i].index[2] = atoi( strtok(NULL, ";") );
		}
		else if(_pModel->face.index[i].useFourPolygon == GglTrue)
		{
			_pModel->face.index[i].index[0] = atoi( strtok(NULL, ",") );
			_pModel->face.index[i].index[1] = atoi( strtok(NULL, ",") );
			_pModel->face.index[i].index[2] = atoi( strtok(NULL, ",") );
			_pModel->face.index[i].index[3] = atoi( strtok(NULL, ";") );
		}
	}

	return ;
}

static void GglModel_LoadModel2X_ReadMaterialList(FILE* _pFile, GglModel* _pModel)
{
	int i;
	int stringLength;
	char buffer[256];
	GglString	pBuf = &buffer[0];

	memset(buffer, '\0', 256);

	// �}�e���A���̑������擾
	fgets(buffer, 256, _pFile);
	_pModel->material.max	= atoi( strtok(buffer, ";") );	// �}�e���A�������𐮐��Ƃ��đ��

	// �}�e���A��������Ƃ�
	if(_pModel->material.max)
	{
		_pModel->material.index			= (GglMaterialList*)GglMemory_New(sizeof(GglMaterialList) * _pModel->material.max);
		fgets(buffer, 256, _pFile);
	}
	else	// �Ȃ��Ƃ�
	{
		fgets(buffer, 256, _pFile);
		_pModel->material.max	= atoi( strtok(buffer, ";") );
		_pModel->material.index	= (GglMaterialList*)GglMemory_New( sizeof(GglMaterialList) * _pModel->material.max );
	}

	// �}�e���A���C���f�b�N�X�擾
	for(fgets(buffer, 256, _pFile), i=0; (unsigned int)i<_pModel->face.max; i++, fgets(buffer, 256, _pFile))
	{
		_pModel->face.index[i].materialIndex = atoi( strtok(buffer, ",") );
	}

	// �}�e���A���擾
	for(i=0; i<(int)_pModel->material.max; i++)
	{
		for(;strstr(buffer, " Material ") == NULL;)
		{
			fgets(buffer, 256, _pFile);
		}

		// �g�U���i�f�B�t���[�Y�j�擾
		fgets(buffer, 256, _pFile);
		_pModel->material.index[i].colorType.array[0] = atof( strtok(buffer, ";") );
		_pModel->material.index[i].colorType.array[1] = atof( strtok(NULL, ";") );
		_pModel->material.index[i].colorType.array[2] = atof( strtok(NULL, ";") );
		_pModel->material.index[i].colorType.array[3] = atof( strtok(NULL, ";;") );

		// ���ʌ��w���擾
		fgets(buffer, 256, _pFile);
		_pModel->material.index[i].lightPower = atoi( strtok(buffer, ";") );

		// ���ʌ��i�X�y�L�����j�擾
		fgets(buffer, 256, _pFile);
		_pModel->material.index[i].specularColor.array[0] = atof( strtok(buffer, ";") );
		_pModel->material.index[i].specularColor.array[1] = atof( strtok(NULL, ";") );
		_pModel->material.index[i].specularColor.array[2] = atof( strtok(NULL, ";") );
		_pModel->material.index[i].specularColor.array[3] = 1;

		// ���ˋP�x�i���Ȕ����j
		fgets(buffer, 256, _pFile);
		_pModel->material.index[i].emissionColor.array[0] = atof( strtok(buffer, ";") );
		_pModel->material.index[i].emissionColor.array[1] = atof( strtok(NULL, ";") );
		_pModel->material.index[i].emissionColor.array[2] = atof( strtok(NULL, ";") );
		_pModel->material.index[i].emissionColor.array[3] = 1.0f;
		fgets(buffer, 256, _pFile);
		fgets(buffer, 256, _pFile);

		if(strstr(buffer, "TextureFilename") != NULL)
		{
			fgets(buffer, 256, _pFile);
			pBuf			= GglString_EraseFirst(5, buffer);
			stringLength	= (int)strlen( strtok(pBuf, "\"") )+1;
			_pModel->material.index[i].textureName = (GglString)GglMemory_New( sizeof(char) * stringLength );
			strcpy(_pModel->material.index[i].textureName, buffer);
		}
		else
		{
			_pModel->material.index[i].textureName = NULL;
		}

	}

	return ;
}

static void GglModel_LoadModel2X_ReadMeshVertexColors(FILE* _pFile, GglModel* _pModel)
{
	int			i, count;
	char buffer[256];
	GglString	pBuf = &buffer[0];

	memset(buffer, '\0', 256);

	// ���̎擾
	fgets(buffer, 256, _pFile);
	count = atoi( strtok(buffer, ";") );

	_pModel->vertex.color = (GglColor4*)GglMemory_New( sizeof(GglColor4) * count );

	// ���_�J���[�̎擾
	for(i=0; i<count; i++)
	{
		fgets(buffer, 256, _pFile);
		strtok(buffer, ";");

		_pModel->vertex.color[i].array[0] = atof( strtok(NULL, ";") );
		_pModel->vertex.color[i].array[1] = atof( strtok(NULL, ";") );
		_pModel->vertex.color[i].array[2] = atof( strtok(NULL, ";") );
		_pModel->vertex.color[i].array[3] = atof( strtok(NULL, ";;,") );
	}

	return ;
}

// ���_�̖@���x�N�g���擾
static void GglModel_LoadModel2X_ReadMeshNormals(FILE* _pFile, GglModel* _pModel, long* _pos)
{
	int			i;
	char		buffer[256];

	if(_pModel->vertex.max == 0)
	{
		*_pos = (long)_pFile;
		return ;
	}
	
	fgets(buffer, 256, _pFile);

	_pModel->face.normals = NULL;
	_pModel->face.normals = (GglNormal3d*)GglMemory_New(sizeof(GglNormal3d) * _pModel->vertex.max);

	for(i=0; i<(int)_pModel->vertex.max; i++)
	{
		fgets(buffer, 256, _pFile);

		_pModel->face.normals[i].x = atof( strtok(buffer, ";") );
		_pModel->face.normals[i].y = atof( strtok(NULL, ";") );
		_pModel->face.normals[i].z = atof( strtok(NULL, ";") );
	}

	return ;
}

// UV���W�擾
static void GglModel_LoadModel2X_ReadMeshTextureCoords(FILE* _pFile, GglModel* _pModel, long* _pos)
{
	int			i;
	char		buffer[256];

	if(_pModel->vertex.max == 0)
	{
		*_pos = (long)_pFile;
		return ;
	}

	fgets(buffer, 256, _pFile);

	for(fgets(buffer, 256, _pFile), i=0; i<(int)_pModel->face.max; fgets(buffer, 256, _pFile), i++)
	{
		_pModel->face.index[i].uv.x = atof( strtok(buffer, ";") );
		_pModel->face.index[i].uv.y = atof( strtok(NULL, ";") );
	}
}

// ���f���폜
void GglModel_DeleteModel(GglModel* _this)
{
	GglMemory_Delete(_this->face.normals);
	GglMemory_Delete(_this->face.index);
	GglMemory_Delete(_this->vertex.index);
	
	GglMemory_Delete(_this->name);
	GglMemory_Delete(_this->vertex.color);
	GglMemory_Delete(_this->vertex.index);
	GglMemory_Delete(_this->material.index);
	GglMemory_Delete(_this->material.index);

	return ;
}