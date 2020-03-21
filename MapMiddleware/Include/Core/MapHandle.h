/*!
 * \文件 MapHandle.h
 * \日期 2020/03/19 20:16
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 地图实例类
 *
 *
 * \记录 2020/03/19 20:16 新建
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

	// 设置地图状态
	void setState(MapHandleState::State state);

	// 添加图层
	void addMapLayer(MapLayer *mapLayer);

	// 根据图层索引获取图层
	MapLayer* getMapLayerByIndex(int mapLayerIndex);

	// 删除图层，删除图层会连带删除图层上的所有图元
	void removeMapLayer(MapLayer *mapLayer);
	void removeMapLayerByIndex(int mapLayerIndex);

signals:
	void mouseMoved(qreal longitude, qreal latitude);
	void mousePressed(qreal longitude, qreal latitude, Qt::MouseButton button);
	void mouseReleased(qreal longitude, qreal latitude, Qt::MouseButton button);

private:
	AbstractMapHandle		*	d_ptr			= nullptr;
	QMap<int, MapLayer *>		m_mapLayers;
	MapHandleState::State		m_state			= MapHandleState::Arrow; // 地图状态
};