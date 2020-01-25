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

	// 设置地图状态
	void setState(MapHandleState::State state);

	// 添加图层
	void addMapLayer(MapLayer *mapLayer);

	// 根据图层索引获取图层
	MapLayer* mapLayer(int mapLayerIndex);

	// 删除图层，删除图层会连带删除图层上的所有图元
	void removeMapLayer(int mapLayerIndex);

	// 地图实例是否有效
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