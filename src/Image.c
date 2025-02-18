#include "Generic_GameLibrary.h"
#include "png.h"
#include <cv.h>
#include <highgui.h>
#pragma warning(disable:4996)
//
///***************************************************************************
// * GglImage_AssembleElements�֐�
// * uint�̉摜����pngInfo����GglImage�\���̂ɓ��ꂵ�ďo�͂��܂�
// * 
// * �߂�l�F�摜�C���[�W�o��
// * �����F
// * 1.const unsigned int*	in_image	//GglImage�^�ɓ˂����݂����C���[�W
// * 2.const pngInfo*			in_info		//GglImage�^�ɓ˂����݂����C���[�W���
// * 3.GglImage*					out_pImage	//�C���[�W�o��
//*/
//GglImage GglImage_AssembleElements(unsigned int* in_pImage,
//								pngRawInfo* in_pInfo,
//								GglImage* out_pImage)
//{
//	GglImage img;
//	img.image	= *in_pImage;
//	img.info	= *in_pInfo;
//
//	if(out_pImage != NULL)
//		*out_pImage = img;
//
//	return img;
//}
//
///************************************************************************************
// * GglImage_RegistImage�֐�
// * g_imageArray���I�z��ɃC���[�W����}������
// * ���邢�́AGglImage�^�ł���΂ǂ�Ȃ��̂ł��}�����邱�Ƃ��\�ł���
// * 
// * �߂�l�FGglBoolean(GglTrue = 1, GglFalse = 0�A���[�U�[�ݒ�)
// * �����F
// * 1.GglImage* out_pImage	�C���[�W�^�ւ̃|�C���^���w��A���ʂ�g_imageArray�z�������
// * 2.GglString in_string	�C���[�W�^�֑}���������t�@�C���̖��O�𑊑΃p�X�œ����
// * 
// ************************************************************************************
// * �o�[�W������� *******************************************************************
// * @Ver.1.0.0.ALPHA
// * �������� - GglString in_string
// *   �͑��΃p�X�̑Ώۃt�H���_�����������w�肷��K�v������
// *   �͊g���q�����������w�肷��K�v������(������̂�png�̂�)
// * ���P�\��͖��肾���݌v�Ƃ��Č������]�n����H
//*/
//GglBoolean GglImage_RegistImage(GglImage* out_pImage, GglString in_fileName)
//{
//	if(out_pImage == NULL)
//		return GglFalse;
//
//	//out_pImage->image = pngBind(in_fileName,
//	//							PNG_BUILDMIPMAP,
//	//							PNG_ALPHA,
//	//							&out_pImage->info,
//	//							GL_CLAMP,
//	//							GL_NEAREST,
//	//							GL_NEAREST);
//
//	return GglTrue;
//}

#ifndef PNG_STDIO_SUPPORTED

static void GglImage_PngReadData(png_structp png_ptr, png_bytep data, png_size_t length)
{
	png_size_t check;

	/* fread() returns 0 on error, so it is OK to store this in a png_size_t
	* instead of an int, which is what fread() actually returns.
	*/
	check = (png_size_t)fread(data, (png_size_t)1, length, (FILE *)png_ptr->io_ptr);

	if (check != length)
	{
		png_error(png_ptr, "Read Error");
	}

	return ;
}

static void GglImage_PngWriteData(png_structp png_ptr, png_bytep data, png_size_t length)
{
	png_uint_32 check;

	check = fwrite(data, 1, length, (FILE *)(png_ptr->io_ptr));
	if (check != length)
	{
		png_error(png_ptr, "Write Error");
	}

	return ;
}

static void GglImage_PngFlush(png_structp png_ptr)
{
	FILE *io_ptr;
	io_ptr = (FILE *)CVT_PTR((png_ptr->io_ptr));
	if (io_ptr != NULL)
	{
		fflush(io_ptr);
	}

	return ;
}

#endif

static void GglImage_LoadPngException(png_structp png_ptr, png_const_charp msg)
{
#ifdef PNG_CONSOLE_IO_SUPPORTED
	GglDebug_PrintExceptionLine();
#endif
}

/**
 * GglImage_LoadPng�֐�
 * PNG�C���[�W��ǂݍ���
 *
 * @param	�ǂݍ��񂾉摜 ��������Γ��I������������B���s�̂Ƃ���NULL
 * @param	�ǂݍ��񂾃t�@�C���|�C���^
 *
 * @return	�֐��̐������s
*/
GglImage* GglImage_LoadPng(GglImage* out_pImage, GglString in_fileName)
{
	FILE*			fp;
	png_structp		pPng;
	png_infop		pInfo;
	png_byte		pbSig[8];
	GglImage*		pImage;
	double			gamma;
	unsigned int	i=0, j=0;
	int				rb;
	GglUByte**		rows;
	int				imgid;
	png_bytep		test;
	png_color_16p	w;
	png_colorp		plte;
	int				pltemax;
	int				bgplte;

	// �����`�F�b�N
	if(!in_fileName)
	{
		return NULL;
	}

	// 1. �V�O�l�`���ǂݍ���
	fp = fopen(in_fileName, GGL_FILE_READ_BINALY);
	
	if(fp == NULL)
	{
		return NULL;
	}

	fread(pbSig, 1, 8, fp);

	if(png_sig_cmp(pbSig, 0, 8))
	{
		out_pImage = NULL;
		return NULL;
	}

	// png�\���̍쐬
	pPng = png_create_read_struct(	PNG_LIBPNG_VER_STRING,
									NULL,
									(png_error_ptr)GglImage_LoadPngException,
									(png_error_ptr)NULL);
	if(!pPng)
	{
		out_pImage = NULL;
		return NULL;
	}

	// info�\���̍쐬
	pInfo = png_create_info_struct(pPng);
	if(!pInfo)
	{
		png_destroy_read_struct(&pPng, NULL, NULL);
		out_pImage = NULL;
		return NULL;
	}

	pImage = (GglImage*)GglMemory_New(sizeof(GglImage));
	pImage->id = 0;

	// 3. �t�@�C���|�C���^�̃Z�b�g	
	png_init_io(pPng, fp);

	png_set_sig_bytes(pPng, 8);

	// 5. �f�[�^�ǂݍ���
	// PNG�C���[�W����info�f�[�^�ǂݍ���
	png_read_info(pPng, pInfo);

	// �摜���畝�ƍ��������擾
	png_get_IHDR(pPng, pInfo, &pImage->size.x, &pImage->size.y, &pImage->depth, &pImage->colorType, NULL, NULL, NULL);

	if(pImage->depth < 8)
	{
		png_set_expand(pPng);
	}

	if(pImage->depth == 16)
	{
		png_set_strip_16(pPng);
	}
	
	// �J���[�^�C�v
	switch(pImage->colorType)
	{
		case PNG_COLOR_TYPE_GRAY:
			png_set_gray_to_rgb(pPng);
			break;

		case PNG_COLOR_TYPE_GRAY_ALPHA:
			png_set_gray_to_rgb(pPng);
			png_set_tRNS_to_alpha(pPng);
			break;

		case PNG_COLOR_TYPE_RGB_ALPHA:
			if(png_get_valid(pPng, pInfo, PNG_INFO_tRNS))
			{
				png_get_tRNS(pPng, pInfo, &test, &i, &w);
			}
			else if(png_get_valid(pPng, pInfo, PNG_INFO_bKGD))
			{
				png_get_bKGD(pPng, pInfo, &w);
			}
			break;

		case PNG_COLOR_TYPE_PALETTE:
			
			if(png_get_valid(pPng, pInfo, PNG_INFO_tRNS))
			{
				png_get_tRNS(pPng, pInfo, &test, &bgplte, &w);
				png_get_PLTE(pPng, pInfo, &plte, &pltemax);
				png_set_palette_to_rgb(pPng);
				png_set_add_alpha(pPng, 0xff, PNG_FILLER_AFTER);
			}
			else if(png_get_valid(pPng, pInfo, PNG_INFO_bKGD))
			{
				png_get_bKGD(pPng, pInfo, &w);
				png_set_palette_to_rgb(pPng);
				png_set_add_alpha(pPng, 0xff, PNG_FILLER_AFTER);
			}
			break;

		default:
			break;
	}

	if(png_get_gAMA(pPng, pInfo, &gamma))
	{
		png_set_gamma(pPng, (double)2.2, gamma);
	}

	png_read_update_info(pPng, pInfo);

	pImage->channles		= png_get_channels(pPng, pInfo);

	// �摜���ƍ�����2�����z����쐬
	rb		= png_get_rowbytes(pPng, pInfo);
	pImage->rows	= (GglUByte*)GglMemory_New(sizeof(GglUByte*) * pImage->size.y * rb);
	
	for(i=0; i<pImage->size.y; i++)
	{
		png_read_row(pPng, pImage->rows + i*rb, NULL);
	}

	for(i=0; i<pImage->size.y; i++)
	{
		printf("\n");
		for(j=0; j<rb; j++)
		{
			printf("%x",pImage->rows[i*rb+j]);
			printf(j%4 == 3 ? "; " : ", ");
		}
	}

	if(pImage->colorType == PNG_COLOR_TYPE_PALETTE)
	{
		for(i=0; i<pImage->size.x * pImage->size.y; i++)
		{
			if(	pImage->rows[i*4]	== w->red &&
				pImage->rows[i*4+1] == w->green &&
				pImage->rows[i*4+2] == w->blue)
			{
				pImage->rows[i*4+3] = 0x00;
			}
			else
			{
				pImage->rows[i*4+3] = 0xff;
			}
		}
	}

	if(out_pImage)
	{
		out_pImage = pImage;
	}

	png_destroy_read_struct(&pPng, &pInfo, NULL);
	fclose(fp);

	// �e�N�X�`���ւ̓o�^
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &imgid);
	glBindTexture(GL_TEXTURE_2D, imgid);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, pImage->size.x, pImage->size.y, GL_RGBA, GL_UNSIGNED_BYTE, pImage->rows);
	glDisable(GL_TEXTURE_2D);

	pImage->id = imgid++;

	return pImage;
}

//GglImage* GglImage_LoadPng(GglImage* out_pImage, GglString in_fileName)
//{
//	IplImage* cvimg = cvLoadImage(in_fileName, CV_LOAD_IMAGE_ANYCOLOR);
//
//	if(cvimg == NULL)
//	{
//		out_pImage = NULL;
//		return NULL;
//	}
//
//	img = GglMemory_New(sizeof(GglImage));
//
//	cvimg->
//
////	/* �E�C���h�E���������ĉ摜��\������ */
////    cvNamedWindow("Image", CV_WINDOW_AUTOSIZE);
////    cvShowImage("Image",img);
//
// //   /* �L�[���͂�����܂ő҂� */
// //   cvWaitKey(0); /* ���ꂪ�Ȃ��ƁA1�u�����\������ďI��� */
//	//cvReleaseImage(&img);
//
//	img->
//
//	return NULL;
//}