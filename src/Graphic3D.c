#include "Generic_GameLibrary.h"

/**
 * GglGraphic3d_Render�֐�
 * �w�肳�ꂽGglModel�\���̂�3D���f����`�悵�܂�
 * ���ꂼ�ꌴ�_����ړ����������Ȃ��A��]���������Ȃ��A�g�k���������Ȃ��ꍇ��NULL�����܂�
 *
 * @param �`�悵�������f��
 * @param �`��ʒu
 * @param ���f����]�p
 * @param ���f���g�k
*/
void GglGraphic3d_Render(const GglModel* in_pModel, const GglVector3d* in_pTranslate, const GglVector3d* in_pRotate, const GglVector3d* in_pScale)
{
	GglMatrix4x4 mat;
	int i;

	if(!in_pModel)
	{
		return ;
	}


	// ���f���s�񏉊���
	GglMatrix4x4_SetIdentity(&mat);

	// ���f���̃X�P�[���s���ǉ�
	if(in_pScale)
	{
		GglMatrix4x4 buf = GglMatrix4x4_GetScale(in_pScale);
		GglMatrix4x4_Mul(&mat, &mat, &buf);
	}

	// ���f���̉�]�s�����Z
	if(in_pRotate)
	{
		GglMatrix4x4 buf;

		buf = GglMatrix4x4_GetRotateYaw(in_pRotate->z);
		GglMatrix4x4_Mul(&mat, &mat, &buf);
		buf = GglMatrix4x4_GetRotatePitch(in_pRotate->y);
		GglMatrix4x4_Mul(&mat, &mat, &buf);
		buf = GglMatrix4x4_GetRotateRoll(in_pRotate->x);
		GglMatrix4x4_Mul(&mat, &mat, &buf);
	}

	// ���f���̈ʒu�s�����Z
	if(in_pTranslate)
	{
		GglMatrix4x4 buf = GglMatrix4x4_GetTranslation(in_pTranslate);
		GglMatrix4x4_Mul(&mat, &mat, &buf);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadMatrixd(mat.array[0]);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	for(i=0; i<(int)in_pModel->face.max; i++)
	{
		if(in_pModel->face.index[i].useFourPolygon)
		{
			glBegin(GL_QUADS);

				// �F��񃍁[�h
				glColor4fv(in_pModel->material.index[in_pModel->face.index[i].materialIndex].colorType.array);
			
				// �}�e���A����񃍁[�h
				glMaterialfv(GL_FRONT, GL_DIFFUSE, in_pModel->material.index[in_pModel->face.index[i].materialIndex].colorType.array);
				glMaterialfv(GL_FRONT, GL_SPECULAR, in_pModel->material.index[in_pModel->face.index[i].materialIndex].specularColor.array);
				glMaterialfv(GL_FRONT, GL_EMISSION, in_pModel->material.index[in_pModel->face.index[i].materialIndex].emissionColor.array);
				glMateriali(GL_FRONT, GL_SHININESS, in_pModel->material.index[in_pModel->face.index[i].materialIndex].lightPower);

				// �@����񃍁[�h
				glNormal3dv(in_pModel->face.normals[in_pModel->face.index[i].index[0]].array);
				glNormal3dv(in_pModel->face.normals[in_pModel->face.index[i].index[1]].array);
				glNormal3dv(in_pModel->face.normals[in_pModel->face.index[i].index[2]].array);
				glNormal3dv(in_pModel->face.normals[in_pModel->face.index[i].index[3]].array);

				// �o�[�e�N�X��񃍁[�h
				glVertex3dv(in_pModel->vertex.index[in_pModel->face.index[i].index[0]].array);
				glVertex3dv(in_pModel->vertex.index[in_pModel->face.index[i].index[1]].array);
				glVertex3dv(in_pModel->vertex.index[in_pModel->face.index[i].index[2]].array);
				glVertex3dv(in_pModel->vertex.index[in_pModel->face.index[i].index[3]].array);

				//// �e�N�X�`�����
				//if(in_pModel->face.index[i].useTexture)
				//{
				//	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
				//	glEnable(GL_TEXTURE_2D);
				//	
				//		glBindTexture(GL_TEXTURE_2D, in_pModel->face.index[i].uv);

				//	glDisable(GL_TEXTURE_2D);
				//}
				
			glEnd();
		}
		else
		{
			glBegin(GL_TRIANGLES);

				// �F��񃍁[�h
				glColor4fv(in_pModel->material.index[in_pModel->face.index[i].materialIndex].colorType.array);

				// �}�e���A����񃍁[�h
				glMaterialfv(GL_FRONT, GL_DIFFUSE, in_pModel->material.index[in_pModel->face.index[i].materialIndex].colorType.array);
				glMaterialfv(GL_FRONT, GL_SPECULAR, in_pModel->material.index[in_pModel->face.index[i].materialIndex].specularColor.array);
				glMaterialfv(GL_FRONT, GL_EMISSION, in_pModel->material.index[in_pModel->face.index[i].materialIndex].emissionColor.array);
				glMateriali(GL_FRONT, GL_SHININESS, in_pModel->material.index[in_pModel->face.index[i].materialIndex].lightPower);

				// �@����񃍁[�h
				glNormal3dv(in_pModel->face.normals[in_pModel->face.index[i].index[0]].array);
				glNormal3dv(in_pModel->face.normals[in_pModel->face.index[i].index[1]].array);
				glNormal3dv(in_pModel->face.normals[in_pModel->face.index[i].index[2]].array);

				// �o�[�e�N�X��񃍁[�h
				glVertex3dv(in_pModel->vertex.index[in_pModel->face.index[i].index[0]].array);
				glVertex3dv(in_pModel->vertex.index[in_pModel->face.index[i].index[1]].array);
				glVertex3dv(in_pModel->vertex.index[in_pModel->face.index[i].index[2]].array);

				//// �e�N�X�`�����
				//if(in_pModel->face.index[i].useTexture)
				//{
				//	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
				//	glEnable(GL_TEXTURE_2D);
				//	
				//		glBindTexture(GL_TEXTURE_2D, in_pModel->face.index[i].uv);

				//	glDisable(GL_TEXTURE_2D);
				//}

			glEnd();
		}
	}

	glPopMatrix();
	glDisable(GL_CULL_FACE);
	glLoadIdentity();

	return ;
}