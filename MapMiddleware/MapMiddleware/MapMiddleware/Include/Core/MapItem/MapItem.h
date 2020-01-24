/*!
 * \文件 AbstractMapItem.h
 * \日期 2020/01/04 11:35
 *
 * \作者 wanghao
 * 联系: wanghao@swiet.com
 *
 * \简介 抽象地图图元基类
 *
 *
 * \更改记录 2020.1.4 新建
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
	MapItem(MapLayer *mapLayer, MapItemType::Type type);

	//************************************
	// 方法: draw
	// 全名: MapItem::draw
	// 访控: virtual public 
	// 返回: void
	// 简介: 绘制图元
	//************************************
	void draw();

	//************************************
	// 方法: moveTo
	// 全名: MapItem::moveTo
	// 访控: public 
	// 返回: void
	// 简介: 在图层上移动
	// 参数: const QPointF & newPos
	//************************************
	void moveTo(const QPointF &newPos);

	//************************************
	// 方法: remove
	// 全名: MapItem::remove
	// 访控: virtual public 
	// 返回: void
	// 简介: 从图层上删除图元
	// 参数: AbstractMapLayer * mapLayer
	//************************************
	virtual void remove();

	//************************************
	// 方法: id
	// 全名: MapItem::id
	// 访控: virtual public 
	// 返回: const QString&
	// 简介: 获取图元id，uuid
	//************************************
	const QString& id() const;

	//************************************
	// 方法: setPos
	// 全名: MapItem::setPos
	// 访控: public 
	// 返回: void
	// 简介: 设置位置
	// 参数: const QPointF & pos
	//************************************
	void setPos(const QPointF &pos);

	//************************************
	// 方法: pos
	// 全名: MapItem::pos
	// 访控: public 
	// 返回: const QPointF &
	// 简介: 返回当前位置
	//************************************
	const QPointF &pos() const;

	inline MapLayer* mapLayer() const { return m_mapLayer; }

protected:
	void setMapLayer(MapLayer *mapLayer);

protected:
	AbstractMapItem		*	d_ptr		= nullptr;
	MapLayer			*	m_mapLayer	= nullptr;				// 图元所在的图层
	MapItemType::Type		m_type		= MapItemType::Unvalid;	// 图元类型，默认为无效图元

protected:
	virtual ~MapItem() = 0;
};