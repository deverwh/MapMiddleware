/*!
 * \文件 AbstractMapItem.h
 * \日期 2020/01/04 11:41
 *
 * \作者 wanghao
 * 联系: wanghao@swiet.com
 *
 * \简介 图元实现基类
 *
 *
 * \更改记录 2020.1.4 新建
*/

#pragma once

#include "Interface_Global.h"
#include "Define.h"
#include <QString>
#include <QPoint>

class AbstractMapLayer;

class INTERFACE_EXPORT AbstractMapItem
{
	friend class AbstractMapLayer;
	friend class MapItem;
public:
	AbstractMapItem();
	virtual ~AbstractMapItem();

	//************************************
	// 方法: draw
	// 全名: AbstractMapItem::draw
	// 访控: virtual public 
	// 返回: void
	// 简介: 在图层上绘制图元
	//************************************
	void draw();

	//************************************
	// 方法: moveTo
	// 全名: AbstractMapItem::moveTo
	// 访控: virtual public 
	// 返回: void
	// 简介: 在图层上移动
	// 参数: const QPointF & newPos
	//************************************
	void moveTo(const QPointF &newPos);

	//************************************
	// 方法: remove
	// 全名: AbstractMapItem::remove
	// 访控: virtual public 
	// 返回: void
	// 简介: 从图层上删除图元
	//************************************
	void remove();

	//************************************
	// 方法: id
	// 全名: AbstractMapItem::id
	// 访控: virtual public 
	// 返回: const QString&
	// 简介: 获取图元id，uuid
	//************************************
	inline const QString& id() const { return m_id; }

	//************************************
	// 方法: setPos
	// 全名: AbstractMapItem::setPos
	// 访控: public 
	// 返回: void
	// 简介: 设置位置
	// 参数: const QPointF & pos
	//************************************
	inline void setPos(const QPointF &pos) { m_pos = pos; }

	//************************************
	// 方法: pos
	// 全名: AbstractMapItem::pos
	// 访控: public 
	// 返回: const QPointF &
	// 简介: 返回当前位置
	//************************************
	inline const QPointF &pos() const { return m_pos; }

protected:
	virtual void onDraw() = 0;
	virtual void onMoveTo(const QPointF &newPos) = 0;
	virtual void onRemove() = 0;

protected:
	//************************************
	// 方法: setMapLayer
	// 全名: AbstractMapItem::setMapLayer
	// 访控: protected 
	// 返回: void
	// 简介: 设置图元所在的图层
	// 参数: AbstractMapLayer * mapLayer
	//************************************
	inline void setMapLayer(AbstractMapLayer* mapLayer) { m_mapLayer = mapLayer; }

protected:
	QString				m_id;								// 图元Id
	MapItemType::Type	m_type		= MapItemType::Unvalid;	// 图元类型
	QPointF				m_pos		= QPointF(0, 0);		// 图元位置，x 经度，y 纬度，默认在(0,0)
	qreal				m_angle		= 0;					// 图元旋转角度，默认为正北，无旋转
	bool				m_isDraw	= false;				// 图元是否已绘制在图层上，如果已绘制，则默认行为应该是移动，子类需进行处理，remove行为需将此字段设置为false	
	AbstractMapLayer*	m_mapLayer	= nullptr;				// 图元所在的图层
};
