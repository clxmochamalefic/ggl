#include "Generic_GameLibrary.h"
#include <math.h>

#pragma warning(disable : 4090)

/******************************************************
 * GglMatrix4x4_Add�֐�		�����Z
 * GglMatrix4x4_Sub�֐�		�����Z
 * GglMatrix4x4_Mul�֐�		�|���Z
 * �s��̌v�Z���s���֐��Q
 *
 * �߂�l�F�Ȃ�
 * �����F
 * 1.GglMatrix4x4*			out_m	�s��̉��Z���ʂ��o��
 * 2.const GglMatrix4x4*	in_pM1	���Z���������s��P
 * 3.const GglMatrix4x4*	in_pM2	���Z���������s��Q
 * �Ȃ��A�s��̊|���Z�ɉ����Ă�in_pM1��in_pM2��
 * �����s�񂪔��΂��ƌ��ʂ��W�����邱�Ƃɗ��ӂ����
*/

// �����Z
void GglMatrix4x4_Add(GglMatrix4x4* out_pM, const GglMatrix4x4* in_pM1, const GglMatrix4x4* in_pM2)
{
	GglMatrix4x4 mat;
	double* i;
	double* j;
	double* k;

	// �o�b�t�@�I�[�o�[�����̉\������
	for(i = &mat._11, j = &in_pM1->_11, k = &in_pM2->_11; i < &mat._11 + 16; i++, j++, k++)
		*i = *j + *k;

	*out_pM = mat;
	return ;
}

// �����Z
void GglMatrix4x4_Sub(GglMatrix4x4* out_pM, const GglMatrix4x4* in_pM1, const GglMatrix4x4* in_pM2)
{
	GglMatrix4x4 mat;
	double* i;
	double* j;
	double* k;

	// �o�b�t�@�I�[�o�[�����̉\������
	for(i = &mat._11, j = &in_pM1->_11, k = &in_pM2->_11; i < &mat._11 + 16; i++, j++, k++)
		*i = *j - *k;

	*out_pM = mat;
	return ;
}

// �|���Z
void GglMatrix4x4_Mul(GglMatrix4x4* out_pM, const GglMatrix4x4* in_pM1, const GglMatrix4x4* in_pM2)
{
	GglMatrix4x4	mat;
	double*	w1;
	double*	w2;
	double*	pO = &mat._11;

	GglByte	i,j,k;
	double	f = 0;

	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			w1 = &in_pM1->_11 + (sizeof(double*) * i);
			w2 = &in_pM2->_11 + j;

			for(k=0; k<4; k++)
			{
				f += (*w1 * *w2);
				w1++;
				w2 += sizeof(double*);
			}

			*pO = f;
			pO++;
			f = 0;
		}
	}

	for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			out_pM->array[i][j] = mat.array[i][j];
		}
	}
	return ;
}

/******************************************************
 * GglMatrix4x4_AddF�֐�		�����Z
 * GglMatrix4x4_SubF�֐�		�����Z
 * GglMatrix4x4_MulF�֐�		�|���Z
 * �s��̌v�Z���s���֐��Q
 *
 * �߂�l�F�Ȃ�
 * �����F
 * 1.double* out_pMFAdr			�s��̉��Z���ʂ��o��
 * 2.const double* in_pMFAdr1	���Z���������s��P
 * 3.const double* in_pMFAdr2	���Z���������s��Q
 * �Ȃ��A�s��̊|���Z�ɉ����Ă�in_pM1��in_pM2��
 * �����s�񂪔��΂��ƌ��ʂ��W�����邱�Ƃɗ��ӂ����
*/

// �����Z
void GglMatrix4x4_AddF(double* out_pMFAdr, const double* in_pMFAdr1, const double* in_pMFAdr2)
{
	GglMatrix4x4 mat;
	double* matAdr;
	GglByte i;

	// �o�b�t�@�I�[�o�[�����̉\������
	for(i=0, matAdr = &mat._11; i<16; i++, matAdr++)
		*matAdr = *(in_pMFAdr1 + i) + *(in_pMFAdr2 + i);

	for(i=0, matAdr = &mat._11; i<16; i++, matAdr++, out_pMFAdr++)
		*out_pMFAdr = *matAdr;

	return ;
}

// �����Z
void GglMatrix4x4_SubF(double* out_pMFAdr, const double* in_pMFAdr1, const double* in_pMFAdr2)
{
	GglMatrix4x4 mat;
	double* matAdr;
	GglByte i;

	// �o�b�t�@�I�[�o�[�����̉\������
	for(i=0, matAdr = &mat._11; i<16; i++, matAdr++)
		*matAdr = *(in_pMFAdr1 + i) - *(in_pMFAdr2 + i);

	for(i=0, matAdr = &mat._11; i<16; i++, matAdr++, out_pMFAdr++)
		*out_pMFAdr = *matAdr;

	return ;
}

// �|���Z
void GglMatrix4x4_MulF(double* out_pMFAdr, const double* in_pMFAdr1, const double* in_pMFAdr2)
{
	GglMatrix4x4	mat;
	double*	w1;
	double*	w2;
	double*	pO = &mat._11;

	GglByte	i,j,k;
	double	f = 0;

	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			w1 = in_pMFAdr1 + (sizeof(double*) * i);
			w2 = in_pMFAdr2 + j;

			for(k=0; k<4; k++){
				f += (*w1 * *w2);
				w1++;
				w2 += sizeof(double*);
			}

			*pO = f;
			pO++;
			f = 0;
		}
	}

	for(i=0, pO = &mat._11; i<16; i++, pO++, out_pMFAdr++)
		*out_pMFAdr = *pO;

	return ;
}

/*****************************************************************
 * GglMatrix4x4_DotScalar�֐�
 * �s��̃X�J���[�{�̌��ʂ��s��ŏo�͂��܂�
 *
 * �߂�l�F�Ȃ�
 * �����F
 * 1.GglMatrix4x4* out_pMat			���Z���ʂ��i�[
 * 2.const GglMatrix4x4* in_pMat	���Z����s��
 * 3.const double in_scalar			�X�J���[�l
*/
void GglMatrix4x4_DotScalar(GglMatrix4x4* out_pMat, const GglMatrix4x4* in_pMat, const double in_scalar)
{
	GglByte i;
	GglMatrix4x4 mat;
	double* j = &mat._11;

	for(i=0; i<16; i++)
		*j = (in_pMat->_11 + i) * in_scalar;

	*out_pMat = mat;
	return ;
}

/**************************************************************
 * GglMatrix4x4_DotVector�֐�
 * �s��ƃx�N�g���̉��Z���s���܂�
 *
 * �߂�l�F�Ȃ�
 * �����F
 * 1.GglMatrix4x4* out_pMat			���Z���ʂ��i�[
 * 2.const GglMatrix4x4* in_pMat	���Z�Ώۂ̍s��
 * 3.const GglVector3f* in_pVec		���Z�Ώۂ̃x�N�g��
*/
void GglMatrix4x4_DotVector(GglVector3f* out_pVec, const GglMatrix4x4* in_pMat, const GglVector3f* in_pVec)
{
	GglVector3f	vec = GglVector3_SetInitializeEqual();
	GglByte	i,j;
	double*	pO = (double*)&vec.x;
	double*	pV = (double*)&in_pVec->x;
	double*	pM = &in_pMat->_11;

	for(i=0; i<3; i++){
		for(j=0; j<4; j++){
			if(j%4 != 0)
				*pO += (*pV) * (*pM);
			pM++;
		}

		pV++;
		pO++;
	}

	*out_pVec = vec;
	return ;
}

/*****************************************************
 * GglWorldMatrixLoadIdentity�֐�
 * �Ώۂ̍s����������i�P�ʍs��㏑���j
 *
 * �߂�l�A�����F�Ȃ�
*/
void GglMatrix4x4_SetIdentity(GglMatrix4x4* out_pMat)
{
	//out_pMat->_11 = 1.0;
	//out_pMat->_12 = 0.0;
	//out_pMat->_13 = 0.0;
	//out_pMat->_14 = 0.0;

	//out_pMat->_21 = 0.0;
	//out_pMat->_22 = 1.0;
	//out_pMat->_23 = 0.0;
	//out_pMat->_24 = 0.0;

	//out_pMat->_31 = 0.0;
	//out_pMat->_32 = 0.0;
	//out_pMat->_33 = 1.0;
	//out_pMat->_34 = 0.0;

	//out_pMat->_41 = 0.0;
	//out_pMat->_42 = 0.0;
	//out_pMat->_43 = 0.0;
	//out_pMat->_44 = 1.0;

	double* pM = &out_pMat->_11;
	GglByte i;

	for(i=0; i<16; i++,pM++)
		if(i%5 == 0)
			*pM = 1.0f;
		else
			*pM = 0.0f;

	return ;
}

/***********************************************************
 * GglGetRotatePitchMatrix	�֐�
 * GglGetRotateYawMatrix	�֐�
 * GglGetRotateRollMatrix	�֐�
 * �����ɑ΂��Ă��ꂼ��AX���AY���AZ����]�s���Ԃ��܂�
 *
 * �߂�l�F	Matrix4x4			��]�s���Ԃ��܂�
 * �����F	const double in_rad	��]�����������W�A���p
*/
// X��
GglMatrix4x4 GglMatrix4x4_GetRotatePitch(const double in_rad)
{
	GglMatrix4x4 m;
	GglMatrix4x4_SetIdentity(&m);

	m._22 = cos(in_rad);
	m._23 = sin(in_rad);
	m._32 = -sin(in_rad);
	m._33 = cos(in_rad);

	return m;
}

// Y��
GglMatrix4x4 GglMatrix4x4_GetRotateYaw(const double in_rad)
{
	GglMatrix4x4 m;
	GglMatrix4x4_SetIdentity(&m);

	m._11 = cos(in_rad);
	m._13 = -sin(in_rad);
	m._31 = sin(in_rad);
	m._33 = cos(in_rad);

	return m;
}

// Z��
GglMatrix4x4 GglMatrix4x4_GetRotateRoll(const double in_rad)
{
	GglMatrix4x4 m;
	GglMatrix4x4_SetIdentity(&m);

	m._11 = cos(in_rad);
	m._12 = sin(in_rad);
	m._21 = -sin(in_rad);
	m._22 = cos(in_rad);

	return m;
}

/**************************************************
 * GglGetScaleMatrix�֐�
 * ���݂̍��W�ƃX�P�[���{������g�k�s����擾���܂�
 *
 * �߂�l�FGglMatrix4x4	�g��k����̍s���Ԃ�
 * �����F
 * 1.const GglVector3f* in_pV		���W
 * 2.const double	in_scale	�g��k���{��
*/
GglMatrix4x4 GglMatrix4x4_GetScale(const GglVector3d* in_pV)
{
	GglMatrix4x4 m = {	in_pV->x,	0.0,					0.0,					0.0,
						0.0,					in_pV->y,	0.0,					0.0,
						0.0,					0.0,					in_pV->z,	0.0,
						0.0,					0.0,					0.0,					1.0
	};

	return m;
}

/**************************************************************
 * GglGetTranslationMatrix�֐�
 * �x�N�g�����畽�s�ړ��s����擾���܂�
 *
 * �߂�l�F	GglMatrix4x4					���s�ړ���̍s���Ԃ�
 * �����F	const GglVector3f* in_pV	�w�肳�ꂽ�x�N�g��
*/
GglMatrix4x4 GglMatrix4x4_GetTranslation(const GglVector3d* in_pV)
{
	GglMatrix4x4 m;
	GglMatrix4x4_SetIdentity(&m);

	m._41 = in_pV->x;
	m._42 = in_pV->y;
	m._43 = in_pV->z;

	return m;
}