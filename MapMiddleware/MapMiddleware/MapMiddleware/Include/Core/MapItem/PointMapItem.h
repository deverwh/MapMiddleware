/*!
 * \文件 PointMapItem.h
 * \日期 2020/03/19 21:08
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 点图元
 *
 *
 * \记录 2020/03/19 21:08 新建
*/

#pragma once

#include "MapItem.h"
#include <QColor>

class MAP_EXPORT PointMapItem : public MapItem
{
public:
	PointMapItem();
	PointMapItem(const QPointF &pos, int size = 1, const QColor &color = QColor(Qt::red));

	void setPos(const QPointF &pos);
	// 大小1-10，单位km
	void setSize(int size);
	void setColor(const QColor &color);

protected:
	~PointMapItem();
};