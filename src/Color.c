#include "Generic_GameLibrary.h"

/*******************************************************************************
 * GglColor4_AssembleElements�֐�
 * �摜�ɕt������F��256�Ŏw�肵�āA�����GglColorRGBA�\���̂ɓ��ꂵ�ďo�͂��܂�
 *
 * �߂�l�FGglColor4�\���́i�F���j
 * �����F
 * 1.const int		in_r256		//�ԐF
 * 2.const int		in_g256		//�ΐF
 * 3.const int		in_b256		//�F
 * 4.const int		in_a256		//�A���t�@���
 * 5.GglColorRGBA	out_pColor	//GglColorRGBA�o��
*/
GglColor4 GglColor4_Initialize(const unsigned char in_r256, const unsigned char in_g256, const unsigned char in_b256, const unsigned char in_a256)
{
	GglColor4 c;

	c.array[0] = GglColor_BYTE2FLOAT(in_r256);
	c.array[1] = GglColor_BYTE2FLOAT(in_g256);
	c.array[2] = GglColor_BYTE2FLOAT(in_b256);
	c.array[3] = GglColor_BYTE2FLOAT(in_a256);

	return c;
}

GglColor4 GglColor4_LoadIdentity()
{
	return GglColor4_Initialize(0, 0, 0, 0);
}