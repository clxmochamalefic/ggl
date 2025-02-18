#include "Generic_GameLibrary.h"

/**********************************************************
 * FpsInitialize�֐�
 * FPS�v���V�X�e�������������܂�
 *
 * �߂�l�F�Ȃ�
 * �����F
 * 1.const FpsCountMode in_countMode	Fps�v�����[�h�̐ݒ�
*/
void GglFps_Initialize(const GglClock in_countMode)
{
	g_fps.countMode		= in_countMode;	//�����œn���ꂽFPS�l�ɂď�����
	g_fps.leaveTime		= clock();		//���ݎ����ɂď�����
	g_fps.secondTime	= clock();		//���ݎ����ɂď�����
	g_fps.nowCount		= 0;			//�[��������
	g_fps.secondCount	= 0;			//�[��������

	return ;
}

/**********************************************************
 * FpsUpdate�֐�
 * FPS�̌v�����X�V���܂�
 * �X�V�ł���ꍇ�̓^�X�N�̎��s���s����悤�AGglTrue��Ԃ��܂�
 *
 * �߂�l�FGglBoolean�^�AGglTrue��GglFalse��Ԃ�
 * �����F�Ȃ�
*/
GglBoolean GglFps_Update(void)
{
	GglClock t = clock();

	// ���s�ł��邩�ǂ������r����B�s�̏ꍇreturn GglFalse;
	if( clock() - g_fps.leaveTime > g_fps.countMode)
	{
		g_fps.leaveTime = clock();						//���ݎ��Ԃ�O�񎞊ԂƂ��ĕۑ�
		g_fps.nowCount++;								//FPS���J�E���g

		if(g_fps.leaveTime >= g_fps.secondTime + 1000)	//���1�b���o���Ă����ꍇ
			GglFps_OneSecond();								//1�b�o�����Ƃ��̏����ֈړ�

		return GglTrue;
	}
	
	return GglFalse;
}

/************************************************************
 * FpsOneSecond�֐�
 * FPS��1�b�ԃJ�E���g���X�V���܂�
 *
 * �߂�l�A�����F�Ȃ�
*/
void GglFps_OneSecond(void)
{
	g_fps.secondTime	= g_fps.leaveTime;
	g_fps.secondCount	= g_fps.nowCount;
	g_fps.nowCount		= 0;

//	GglFps_ConsoleDraw();
	return ;
}

/************************************************************
 * FpsDraw�֐�
 * ���݂�FPS�J�E���g���R���\�[���ɕ\�����܂�
 * 
 * �߂�l�A�����F�Ȃ�
*/
void GglFps_ConsoleDraw(void)
{
	printf("FPS = %d\n", g_fps.secondCount);
	printf("NowRegistTask = %d\n", g_linkList.count);
	return;
}