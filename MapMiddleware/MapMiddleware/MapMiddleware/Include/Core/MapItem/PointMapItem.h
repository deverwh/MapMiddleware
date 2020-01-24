/*!
 * \文件 PointMapItem.h
 * \日期 2020/01/04 12:50
 *
 * \作者 wanghao
 * 联系: wanghao@swiet.com
 *
 * \简介 点图元
 *
 *
 * \更改记录 2020.1.4 新建
*/

#pragma once

#include "MapItem.h"
#include <QColor>

class MAP_EXPORT PointMapItem : public MapItem
{
public:
	PointMapItem(MapLayer *mapLayer);
	PointMapItem(MapLayer *mapLayer, const QPointF &pos, int size = 1, const QColor &color = QColor(Qt::red));

	void setPos(const QPointF &pos);
	void setSize(int size);
	void setColor(const QColor &color);

protected:
	~PointMapItem();
};