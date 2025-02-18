#include "Generic_GameLibrary.h"
#include <math.h>

/************************************************************
 * GglHit_Circle�֐�
 * 3D�~�`�̓����蔻����s���܂�
 *
 * �߂�l�FGglBoolean		GglTrue = HIT, GglFalse = NOT HIT
 * �����F
 * 1.const GglVector3f* in_v1	����1�̈ʒu�x�N�g��
 * 2.const float in_r1	����1�̓����蔻�����锼�a
 * 3.const GglVector3f* in_v2	����2�̈ʒu�x�N�g��
 * 4.const float in_r2	����2�̓����蔻�����锼�a
*/
GglBoolean GglHit_CircleHit(GglVector3f* in_pV1, const float in_r1,
							GglVector3f* in_pV2, const float in_r2)
{
	GglVector3f vec		= GglVector3_SubEqual(*in_pV1, *in_pV2);
	float	length		= GglVector3_GetLength(vec);

	if(length <= -1)
	{
		length *= -1;
	}

	if( ( length - (in_r1 + in_r2) ) <= 0 )
	{
		return GglTrue;
	}

	return GglFalse;
}


/*****************************************************************************
 * GglHit_RectangleHit�֐�
 * ��`�����蔻����s���܂�
 * �������Ă����Ԃ��֐��ɂ��m�F����Ă���ꍇ�AGglTrue���A
 * �����łȂ��ꍇ��GglFalse��Ԃ��܂�
 *
 * �߂�l�FGglBoolean(bool�Ɠ���)
 * ���� :
 * 1. GglVector3f*		_v1		��r�Ώ�1�̈ʒu�x�N�g��
 * 2. GglRectangle	_r1		��r�Ώ�1�̋�`�T�C�Y
 * 3. GglVector3f*	_v1		��r�Ώ�2�̈ʒu�x�N�g��
 * 4. GglRectangle	_r1		��r�Ώ�2�̋�`�T�C�Y
*/
GglBoolean GglHit_RectangleHit(GglVector3f* _v1, GglRectangle _r1,
							   GglVector3f* _v2, GglRectangle _r2)
{
	if(  ( (_v1->x + _r1.r) >= (_v2->x + _r2.l) )    &&    ( (_v1->x + _r1.l) <= (_v2->x + _r2.l) )  )
	{
		if(  ( (_v1->y + _r1.b) >= (_v2->y + _r2.t) )    &&    ( (_v1->y + _r1.t) <= (_v2->y + _r2.t) )  )
		{
			return GglTrue;
		}
		else if(  ( (_v1->y + _r1.b) >= (_v2->y + _r2.b) )    &&    ( (_v1->y + _r1.t) <= (_v2->y + _r2.b) )  )
		{
			return GglTrue;
		}
	}
	else if(  ( (_v1->x + _r1.r) >= (_v2->x + _r2.r) )    &&    ( (_v1->x + _r1.l) <= (_v2->x + _r2.r) )  )
	{
		if(  ( (_v1->y + _r1.b) >= (_v2->y + _r2.t) )    &&    ( (_v1->y + _r1.t) <= (_v2->y + _r2.t) )  )
		{
			return GglTrue;
		}
		else if(  ( (_v1->y + _r1.b) >= (_v2->y + _r2.b) )    &&    ( (_v1->y + _r1.t) <= (_v2->y + _r2.b) )  )
		{
			return GglTrue;
		}
	}

	return GglFalse;
}

/***********************************************************
 * GglHit_CircleGetIncidence�֐�
 * 3D�~�`�����蔻��ɂ����āA�ʒuA�̕��̂�
 * �ʒuB�ɂ��镨�̂ɐi�����鎞�A
 * �ʒuB�̔��˃x�N�g����
 * �ʒuA�̔��˃x�N�g�����Z�o���܂�
 *
 * �߂�l�F�Ȃ�
 * �����F
 * const GglVector3f* in_pPosA	����A�̈ʒu�x�N�g��
 * const GglVector3f* in_pPosB	����B�̈ʒu�x�N�g��
 * const GglVector3f* in_pVecA	����A�̈ړ������x�N�g��
 * GglVector3f* out_pVA		����A�̔��˃x�N�g��
 * GglVector3f* out_pVA		����B�̔��˃x�N�g��
*/
void GglHit_CircleGetIncidenceReflex(GglVector3f* in_pPosA,
									 GglVector3f* in_pPosB,
									 GglVector3f* in_pVecA,
									 GglVector3f* out_pVA,
									 GglVector3f* out_pVB)
{
	GglVector3f vABsub		= GglVector3_SubEqual(*in_pPosA, *in_pPosB);		// vA��vB�̍����x�N�g��
	GglVector3f vABsubNormal;												// vA-vB Normalize
	GglVector3f vecANormal;													// in_pVecA Normalize
	GglVector3f vecAnDotvABsubNnormal;										// vVecAnDotvABsubNormal Normalize
	GglVector3f	subed;
	
	float	vVecAnDotvABsubN;											// vecANormal DOT vABsubNoraml
	float	vABdot		= (float)GglVector3_Dot(*in_pPosA, *in_pPosB);	// vA��vB�̓���
	float	vAvecLength	= (float)GglVector3_GetLength(*in_pVecA);		// vA�̈ړ������x�N�g���̑傫��

	// Normalize
	GglVector3_Normalize(vABsub, vABsub);
	GglVector3_Normalize(*in_pVecA, *in_pVecA);

	vVecAnDotvABsubN = (float)GglVector3_Dot(vecANormal, vABsubNormal);
	GglVector3_MulScalar(vABsubNormal, vecAnDotvABsubNnormal, 2.0 * vVecAnDotvABsubN);

	GglVector3_MulScalar(vABsubNormal, *out_pVB, vABdot * vAvecLength);

	//vector - float * vector
	//vector - (float * vector)
	//vector - vector
	//D3DXVector3Normalize(out,
	//	&(vVec - 2.0f * D3DXVector3Dot(&vNormal, &vVecNormalize) * vVecNormalize));

	// ����A���󂯂锽�˃x�N�g������
	GglVector3_Sub(subed, vABsub, vecAnDotvABsubNnormal);
	GglVector3_Normalize(subed, *out_pVB);

	return ;
}