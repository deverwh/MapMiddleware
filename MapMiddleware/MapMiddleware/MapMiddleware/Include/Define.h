/*!
 * \�ļ� Define.h
 * \���� 2020/01/10 15:57
 *
 * \���� wanghao
 * ��ϵ: wanghao@swiet.com
 *
 * \��� ��ͼȫ�ֶ���
 *
 *
 * \���ļ�¼ 2020.1.10 �½�
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