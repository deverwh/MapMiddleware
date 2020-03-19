/*!
 * \文件 LineMapItem.h
 * \日期 2020/03/19 21:09
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 线图元
 *
 *
 * \记录 2020/03/19 21:09 新建
*/

#pragma once

#include "MapItem.h"
#include <QColor>

class MAP_EXPORT LineMapItem : public MapItem
{
public:
	LineMapItem();
	LineMapItem(const QPointF &startPos, const QPointF& endPos);

	void setStartPos(const QPointF &startPos);
	const QPointF getStartPos() const;
	void setEndPos(const QPointF &endPos);
	const QPointF getEndPos() const;

protected:
	~LineMapItem();
};