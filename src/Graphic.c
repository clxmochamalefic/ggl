#include "Generic_GameLibrary.h"

/******************************************************
 * GglPerspective�֐�
 * �`�惂�[�h�𓧎����e�ɐ؂�ւ��܂�
 * 
 * �߂�l�A�����F�Ȃ�
*/
void GglGraphic_Perspective(void)
{
	glMatrixMode(GL_PROJECTION);						//�s�񃂁[�h�ؑ�
	glLoadIdentity();									//�s�񏉊���

	gluPerspective( GglGraphic_PERS_FOVY,
					(double)GglGraphic_PERS_WIDTH / GglGraphic_PERS_HEIGHT, 
					GglGraphic_PERS_ZNEAR,
					GglGraphic_PERS_ZFAR);

	return ;
}

/******************************************************
 * GglOrtho2d�֐�
 * �`�惂�[�h�𕽍s���e�ɐ؂�ւ��܂�
 *
 * �߂�l�A�����F�Ȃ�
*/
void GglGraphic_Ortho2d(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(GglGraphic_ORTHO_LEFT, GglGraphic_ORTHO_RIGHT, GglGraphic_ORTHO_BOTTOM, GglGraphic_ORTHO_TOP);

	return ;
}

/****************************************************************
 * GglGraphic_DrawSpriteBegin�֐�
 * 2D�X�v���C�g�̕`��̊J�n�������s���܂�
 * ���ۂɂ́A2D��`�悷��ׂ�3D�`��w�������̊K�w�ɍ~��Ă��܂�
 *
 * �߂�l�F�Ȃ�
 * �����@�F�Ȃ�
*/
void GglGraphic_DrawSpriteBegin(void)
{
	glMatrixMode(GL_PROJECTION);			// �ˉe�ϊ��s��ݒ�
	glPushMatrix();							// ���݂̎ˉe�ϊ��s���ۑ�
	gluLookAt(0, 0, -1, 0, 0, 0, 0, 1, 0);
	glLoadIdentity();
	glOrtho(0, GglGraphic_ORTHO_RIGHT, GglGraphic_ORTHO_BOTTOM, 0, -1, 1);	// ���ˉe�ϊ��ݒ�
	
	glMatrixMode(GL_MODELVIEW);				// ���f���r���[�ϊ��s��ݒ�
	glPushMatrix();							// ���݂̃��f���r���[�s���ۑ�
	glLoadIdentity();						// �P�ʍs���ݒ�
}

/****************************************************************
 * GglGraphic_DrawSpriteEnd�֐�
 * 2D�X�v���C�g�̕`��̏I���������s���܂�
 * ���ۂɂ́A2D��`����I�����邽�߁A3D�`��w�֖߂��Ă��܂�
 *
 * �߂�l�F�Ȃ�
 * �����@�F�Ȃ�
*/
void GglGraphic_DrawSpriteEnd(void)
{
	glMatrixMode(GL_PROJECTION);	// �ˉe�ϊ��s��ݒ�
	glPopMatrix();					// �ˉe�ϊ��s��𕜌�
	glMatrixMode(GL_MODELVIEW);		// ���f���r���[�ϊ��s��ݒ�
	glPopMatrix();					// ���f���r���[�s��𕜌�
	glLoadIdentity();				// �P�ʍs���ݒ�
}