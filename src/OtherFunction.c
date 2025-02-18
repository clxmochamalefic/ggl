#include "Generic_GameLibrary.h"

#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

#pragma warning(disable : 4996)

// ���ӁI
// ���̊֐��̖߂�l�͓��I�z��ł��I�I
// �K��Free���Ă�������
//
// GglString_ExtractErase�֐�
// �w�肵�������񂩂炢�����̔C�ӂ̕�����𔲂������������Ԃ��܂�
// �Ⴆ�΁A"sixaxis"�Ƃ����P�ꂩ��"si"��"x"�𔲂������Ƃ��́A
// GglString_ExtractErase(2, "sixaxis", "si", "x");
// �Ə����܂�
// �Ȃ��A���̏ꍇ�̖߂�l��"ais"�ł�
GglBoolean GglString_ExtractErase(const int ic_count, GglString o_str, const int tgtlen, const GglString ic_target, ...)
{
	GglString	in;		// ic_target�Ƃ�������킬���Ƃ��O�̕������u��
	GglString	out;	// �킬���Ƃ�����̕������u��
	GglString	str;
	int			i;
	va_list		list;
	char*		pos;
	char*		prev = NULL;
	int			count= 0;

	if(ic_target == NULL)
	{
		if(o_str != NULL)
		{
			*o_str = 0;
		}

		return GglFalse;
	}

	if(o_str == NULL)
	{
		return GglFalse;
	}
	
	va_start(list, ic_target);
	in = (GglString)GglMemory_New(sizeof(char)*tgtlen);
	memset(in, 0, tgtlen);
	strncpy(in, ic_target, tgtlen);


	while( count++ < ic_count)
	{
		str = va_arg(list, GglString);
		i = 0;
		out = (GglString)malloc(sizeof(char)*strlen(in)+1);
		memset(out, 0, strlen(in)+1);

		for( (prev == NULL) ? (pos = in) : (pos = prev); pos != NULL; pos = prev+strlen(str))
		{
			prev = strstr(pos, str);
			
			if(prev == NULL)
			{
				for(;pos != (in + strlen(in)); pos++, i++)
				{
					*(out+i) = *pos;
				}

				break;
			}

			for(;pos != prev; pos++, i++)
			{
				*(out + i) = *pos;
			}
		}

		free(in);
		in = (GglString)malloc(sizeof(char)*(strlen(out)+1));
		memset(in, 0, strlen(out)+1);
		strncpy(in, out, strlen(out)+1);
	}

	free(out);
	va_end(list);

	strncpy(o_str, in, strlen(in)+1);
	free(in);
	return GglTrue;
}

GglString GglString_EraseFirst(int _eraseLength, GglString _target)
{
	int targetLength = (int)strlen(_target);
	int i,j;

	if(targetLength - _eraseLength <= 0)
	{
		return "\0";
	}

	for(i=0, j=0; i<targetLength; i++)
	{
		if( i < _eraseLength )
		{
			continue;
		}

		(_target[j]) = (_target[i]);
		j++;
	}

	(_target[j]) = '\0';

	return _target;
}

/**
 * �����񐶐��֐�
 *
 * @param	������������
 * @param	�����񒷂�
 * @return	��������������
*/
GglString GglString_MakeString(GglString str, GglSize length)
{
	return ( strncpy( (char*)GglMemory_New(length), str, length) );
}