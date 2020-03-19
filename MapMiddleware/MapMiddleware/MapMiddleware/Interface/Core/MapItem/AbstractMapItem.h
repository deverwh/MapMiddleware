/*!
 * \文件 AbstractMapItem.h
 * \日期 2020/03/19 21:05
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 图元实现基类
 *
 *
 * \记录 2020/03/19 21:05 新建
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

	// 刷新图元，刷新后是否重绘，默认为true
	void update(bool autoRedraw = true);

	// 获取图元id，uuid
	inline const QString& getId() const { return m_id; }

	// 图元位置
	inline void setPos(const QPointF &pos) { m_pos = pos; }
	inline const QPointF &getPos() const { return m_pos; }

	// 图元旋转
	inline void setRotate(qreal rotate) { m_rotate = rotate; }
	inline qreal getRotate() const { return m_rotate; }

protected:
	virtual void onUpdate(bool autoRedraw) = 0;

protected:
	// 设置图元所在的图层
	inline void setMapLayer(AbstractMapLayer* mapLayer) { m_mapLayer = mapLayer; }

protected:
	QString				m_id;								// 图元Id
	MapItemType::Type	m_type		= MapItemType::Unvalid;	// 图元类型
	QPointF				m_pos		= QPointF(0, 0);		// 图元位置，x 经度，y 纬度，默认在(0,0)
	qreal				m_rotate	= 0;					// 图元旋转角度，正北逆时针 ，默认无旋转
	AbstractMapLayer*	m_mapLayer	= nullptr;				// 图元所在的图层
};
