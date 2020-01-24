/*!
* \�ļ� LineMapItem.h
* \���� 2020/01/04 12:50
*
* \���� wanghao
* ��ϵ: wanghao@swiet.com
*
* \��� ��ͼԪ
*
*
* \���ļ�¼ 2020.1.4 �½�
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