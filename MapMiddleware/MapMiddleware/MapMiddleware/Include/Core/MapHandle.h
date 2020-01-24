/*!
 * \文件 MapHandle.h
 * \日期 2019/12/31 19:31
 *
 * \作者 wanghao
 * 联系: wanghao@swiet.com
 *
 * \简介 地图实例类
 *
 *
 * \更改：2019.12.31 新建
*/

#pragma once

#include "Map_Global.h"
#include "Define.h"
#include <QWidget>
#include <QMap>

class MapLayer;
class MapItem;

class AbstractMapHandle;
class MAP_EXPORT MapHandle : public QWidget
{
	Q_OBJECT
	MAP_DECLARE_PRIVATE(MapHandle)
public:
	MapHandle(QWidget *parent = nullptr);
	~MapHandle();

	//************************************
	// 方法: setState
	// 全名: MapHandle::setState
	// 访控: public 
	// 返回: void
	// 简介: 设置地图状态
	// 参数: MapHandleState::State state
	//************************************
	void setState(MapHandleState::State state);

	//************************************
	// 方法: addMapLayer
	// 全名: MapHandle::addMapLayer
	// 访控: public 
	// 返回: void
	// 简介: 添加图层
	// 参数: MapLayer * mapLayer
	//************************************
	void addMapLayer(MapLayer *mapLayer);

	//************************************
	// 方法: mapLayer
	// 全名: MapHandle::mapLayer
	// 访控: public 
	// 返回: MapLayer*
	// 简介: 根据图层索引获取图层
	// 参数: int mapLayerIndex
	//************************************
	MapLayer* mapLayer(int mapLayerIndex);

	//************************************
	// 方法: removeMapLayer
	// 全名: MapHandle::removeMapLayer
	// 访控: public 
	// 返回: void
	// 简介: 删除图层，删除图层会连带删除图层上的所有图元
	// 参数: int mapLayerIndex
	//************************************
	void removeMapLayer(int mapLayerIndex);

	//************************************
	// Method:    isValid
	// FullName:  MapHandle::isValid
	// Access:    public 
	// Returns:   bool
	// Qualifier: 地图实例是否有效
	//************************************
	bool isValid() const;

signals:
	void mouseMoved(qreal longitude, qreal latitude);
	void mousePressed(qreal longitude, qreal latitude, Qt::MouseButton button);
	void mouseReleased(qreal longitude, qreal latitude, Qt::MouseButton button);

private:
	QMap<int, MapLayer *>		m_mapLayers;
	MapHandleState::State		m_state		= MapHandleState::Arrow; // 地图状态

protected:
	AbstractMapHandle	*d_ptr = nullptr;
};