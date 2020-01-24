/*!
* \文件 LineMapItem.h
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

class MAP_EXPORT LineMapItem : public MapItem
{
public:
	LineMapItem(MapLayer *mapLayer);
	LineMapItem(MapLayer *mapLayer, const QPointF &startPos, const QPointF& endPos);

	void setStartPos(const QPointF &startPos);
	const QPointF getStartPos() const;
	void setEndPos(const QPointF &endPos);
	const QPointF getEndPos() const;

protected:
	~LineMapItem();
};