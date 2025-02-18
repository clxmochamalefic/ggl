#include "Generic_GameLibrary.h"
/*********************************************************************************
 * GglSetRect�֐�
 * �摜�̑S�̃T�C�Y�A�y�щ摜�̕`��̈���w�肵��GglRect�\���̂ɓ��ꂵ�ďo�͂��܂�
 * 
 * �߂�l�FGglRect�\���́i�摜�T�C�Y�A�̈���j
 * �����F
 * 1.const float*	in_top(in_pTop)			//��
 * 2.const float*	in_bottom(in_pBottom)	//��
 * 3.const float*	in_left(in_pLeft)		//��
 * 4.const float*	in_right(in_pRight)		//�E
*/
GglRectangle GglRectangle_Initialize( const int in_top,
											const int in_bottom,
											const int in_left,
											const int in_right)
{
	GglRectangle r;
	r.t	= in_top;
	r.b	= in_bottom;
	r.l	= in_left;
	r.r	= in_right;

	return r;
}

GglRectangle GglRectangle_LoadIdentity()
{
	return GglRectangle_Initialize(0, 0, 0, 0);
}

///****************************************************************
// * GglExchangeRect�֐�
// * GglRectangle����Vertex2d�Ȃǂ�臒l(0.0~1.0)�֕ϊ�����
// * 
// * �߂�l�F�Ȃ�
// * �����F
// * 1.GglRectangle*			out_pRect	�ϊ����GglRectangle���
// * 2.const GglRectangle*	in_pRect	�ϊ�������GglRectangle���
// * 3.const pngInfo*	in_pInfo	�摜�̍ő�̈�擾�p
//*/
//void GglRectangle_ExchangeIdentity(GglRectangle* out_pRect,
//								const GglRectangle* in_pRect,
//								const pngInfo* in_pInfo)
//{
//	// ��
//	if(in_pRect->t > 0.0f)
//		out_pRect->t = in_pRect->t / in_pInfo->Height;
//	else if(in_pRect->t > (int)in_pInfo->Height)
//		out_pRect->t = 1.0f;
//	else
//		out_pRect->t = 0.0f;
//
//	// ��
//	if(in_pRect->b > 0.0f)
//		out_pRect->b = in_pRect->b / in_pInfo->Height;
//	else if(in_pRect->b > (int)in_pInfo->Height)
//		out_pRect->b = 1.0f;
//	else
//		out_pRect->t = 0;
//
//	// ��
//	if(in_pRect->l > 0)
//		out_pRect->l = in_pRect->l / in_pInfo->Width;
//	else if(in_pRect->l > (int)in_pInfo->Width)
//		out_pRect->l = 1.0f;
//	else
//		out_pRect->l = 0;
//
//	// �E
//	if(in_pRect->r > 0)
//		out_pRect->r = in_pRect->r / in_pInfo->Width;
//	else if(in_pRect->r > (int)in_pInfo->Width)
//		out_pRect->r = 1.0f;
//	else
//		out_pRect->r = 0;
//
//	return ;
//}
