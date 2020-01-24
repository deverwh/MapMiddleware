/*!
 * \文件 AbstractPointMapItem.h
 * \日期 2020/01/08 17:33
 *
 * \作者 wanghao
 * 联系: wanghao@swiet.com
 *
 * \简介 抽象点图元基类
 *
 *
 * \更改记录 2020.1.8 新建
*/

#pragma once

#include "Interface_Global.h"
#include "AbstractMapItem.h"
#include <QColor>

class INTERFACE_EXPORT AbstractPointMapItem : public AbstractMapItem
{
public:
	//************************************
	// 方法: setSize
	// 全名: AbstractPointMapItem::setSize
	// 访控: virtual public 
	// 返回: void
	// 简介: 设置大小
	// 参数: int size
	//************************************
	void setSize(int size);

	//************************************
	// 方法: setColor
	// 全名: AbstractPointMapItem::setColor
	// 访控: virtual public 
	// 返回: void
	// 简介: 设置颜色
	// 参数: const QColor & color
	//************************************
	void setColor(const QColor &color);

	//************************************
	// 方法: size
	// 全名: AbstractPointMapItem::size
	// 访控: public 
	// 返回: int
	// 简介: 获取大小
	//************************************
	int size() const;

	//************************************
	// 方法: color
	// 全名: AbstractPointMapItem::color
	// 访控: public 
	// 返回: const QT_NAMESPACE::QColor &
	// 简介: 获取颜色
	//************************************
	const QColor &color() const;

protected:
	int		m_size	= 1;				// 点的大小	
	QColor	m_color	= QColor(Qt::red);	// 点的颜色
};