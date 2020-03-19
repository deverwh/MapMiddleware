/*!
 * \文件 MapItem.h
 * \日期 2020/03/19 20:21
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 抽象地图图元基类
 *
 *
 * \记录 2020/03/19 20:21 新建
*/

#pragma once

#include "Map_Global.h"
#include "Define.h"

class MapLayer;

class AbstractMapItem;
class MAP_EXPORT MapItem
{
	MAP_DECLARE_PRIVATE(MapItem)
	friend class MapLayer;
public:
	MapItem();
	MapItem(MapItemType::Type type);

	// 刷新图元，刷新后是否重绘，默认为true
	void update(bool autoRedraw = true);

	// 获取图元id，uuid
	const QString& getId() const;

	// 图元位置
	void setPos(const QPointF &pos);
	const QPointF &getPos() const;

	// 图元旋转
	void setRotate(qreal rotate);
	qreal getRotate() const;

	// 获取图元所在图层
	inline MapLayer* getMapLayer() const { return m_mapLayer; }

protected:
	void setMapLayer(MapLayer *mapLayer);

protected:
	AbstractMapItem		*	d_ptr		= nullptr;
	MapLayer			*	m_mapLayer	= nullptr;	// 图元所在的图层
	QList<MapItem*>			m_children;				// 孩子图元

protected:
	virtual ~MapItem() = 0;
};