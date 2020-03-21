/*!
 * \�ļ� PointMapItem.h
 * \���� 2020/03/19 21:08
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� ��ͼԪ
 *
 *
 * \��¼ 2020/03/19 21:08 �½�
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
	// ��С1-10����λkm
	void setSize(int size);
	void setColor(const QColor &color);

protected:
	~PointMapItem();
};