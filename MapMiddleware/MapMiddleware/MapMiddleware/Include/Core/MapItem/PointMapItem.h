/*!
 * \�ļ� PointMapItem.h
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