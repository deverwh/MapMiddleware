/*!
 * \�ļ� Define.h
 * \���� 2020/03/19 21:08
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� ��ͼȫ�ֶ���
 *
 *
 * \��¼ 2020/03/19 21:08 �½�
*/

#pragma once

namespace MapItemType
{
	enum Type
	{
		Unvalid,	// ��ЧͼԪ
		Point,		// ��ͼԪ
		Line,		// ��ͼԪ
	};
}

namespace MapHandleState
{
	enum State
	{
		Arrow,			// ��ͷģʽ
		Roaming,		// ����
		ZoomIn,			// ��С
		ZoonOut,		// �Ŵ�
	};
}