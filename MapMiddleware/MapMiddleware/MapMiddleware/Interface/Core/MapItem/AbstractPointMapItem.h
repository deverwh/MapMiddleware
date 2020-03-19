/*!
 * \�ļ� AbstractPointMapItem.h
 * \���� 2020/03/19 21:04
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� �����ͼԪ����
 *
 *
 * \��¼ 2020/03/19 21:04 �½�
*/

#pragma once

#include "Interface_Global.h"
#include "AbstractMapItem.h"
#include <QColor>

class INTERFACE_EXPORT AbstractPointMapItem : public AbstractMapItem
{
public:
	// ��С
	void setSize(int size);

	// ��ɫ
	void setColor(const QColor &color);

protected:
	int		m_size	= 1;				// ��Ĵ�С	
	QColor	m_color	= QColor(Qt::red);	// �����ɫ
};