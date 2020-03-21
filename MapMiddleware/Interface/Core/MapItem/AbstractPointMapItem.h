/*!
 * \文件 AbstractPointMapItem.h
 * \日期 2020/03/19 21:04
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 抽象点图元基类
 *
 *
 * \记录 2020/03/19 21:04 新建
*/

#pragma once

#include "Interface_Global.h"
#include "AbstractMapItem.h"
#include <QColor>

class INTERFACE_EXPORT AbstractPointMapItem : public AbstractMapItem
{
public:
	// 大小
	void setSize(int size);

	// 颜色
	void setColor(const QColor &color);

protected:
	int		m_size	= 1;				// 点的大小	
	QColor	m_color	= QColor(Qt::red);	// 点的颜色
};