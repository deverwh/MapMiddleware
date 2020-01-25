/*!
 * \�ļ� AbstractPointMapItem.h
 * \���� 2020/01/08 17:33
 *
 * \���� wanghao
 * ��ϵ: wanghao@swiet.com
 *
 * \��� �����ͼԪ����
 *
 *
 * \���ļ�¼ 2020.1.8 �½�
*/

#pragma once

#include "Interface_Global.h"
#include "AbstractMapItem.h"
#include <QColor>

class INTERFACE_EXPORT AbstractPointMapItem : public AbstractMapItem
{
public:
	//************************************
	// ����: setSize
	// ȫ��: AbstractPointMapItem::setSize
	// �ÿ�: virtual public 
	// ����: void
	// ���: ���ô�С
	// ����: int size
	//************************************
	void setSize(int size);

	//************************************
	// ����: setColor
	// ȫ��: AbstractPointMapItem::setColor
	// �ÿ�: virtual public 
	// ����: void
	// ���: ������ɫ
	// ����: const QColor & color
	//************************************
	void setColor(const QColor &color);

	//************************************
	// ����: size
	// ȫ��: AbstractPointMapItem::size
	// �ÿ�: public 
	// ����: int
	// ���: ��ȡ��С
	//************************************
	int size() const;

	//************************************
	// ����: color
	// ȫ��: AbstractPointMapItem::color
	// �ÿ�: public 
	// ����: const QT_NAMESPACE::QColor &
	// ���: ��ȡ��ɫ
	//************************************
	const QColor &color() const;

protected:
	int		m_size	= 1;				// ��Ĵ�С	
	QColor	m_color	= QColor(Qt::red);	// �����ɫ
};