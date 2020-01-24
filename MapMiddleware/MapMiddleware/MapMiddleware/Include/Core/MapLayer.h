/*!
 * \文件 MapLayer.h
 * \日期 2020/01/09 9:48
 *
 * \作者 wanghao
 * 联系: wanghao@swiet.com
 *
 * \简介 地图图层
 *
 *
 * \更改记录 2020.1.9 新建
*/

#pragma once

#include "Map_Global.h"
#include <QMap>

class MapHandle;
class MapItem;

class AbstractMapLayer;
class MAP_EXPORT MapLayer
{
	MAP_DECLARE_PRIVATE(MapLayer)
	friend class MapHandle;
public:
	MapLayer(MapHandle* mapHandle, const QString &name = QString());  // 如果未指定名称，则默认名称为MapLayer[index]，图层索引自动增长

	//************************************
	// 方法: addMapItem
	// 全名: MapLayer::addMapItem
	// 访控: public 
	// 返回: QString
	// 简介: 在图层上添加图元
	// 参数: MapItem * mapItem
	//************************************
	void addMapItem(MapItem *mapItem);

	//************************************
	// 方法: mapItem
	// 全名: MapLayer::mapItem
	// 访控: public 
	// 返回: MapItem *
	// 简介: 获取指定Id的图元
	// 参数: const QString & mapItemId
	//************************************
	MapItem *mapItem(const QString &mapItemId) const;

	//************************************
	// 方法: removeMapItem
	// 全名: MapLayer::removeMapItem
	// 访控: public 
	// 返回: void
	// 简介: 根据图元Id删除图元
	// 参数: QString mapItemId
	//************************************
	void removeMapItem(const QString& mapItemId);

	//************************************
	// 方法: index
	// 全名: MapLayer::index
	// 访控: public 
	// 返回: int
	// 简介: 获取图层索引
	//************************************
	int index() const;

	//************************************
	// 方法: name
	// 全名: MapLayer::name
	// 访控: public 
	// 返回: const QString&
	// 简介: 获取图层名称
	//************************************
	const QString& name() const;

private:
	QMap<QString, MapItem *> m_mapItems;

protected:
	~MapLayer();
	AbstractMapLayer *d_ptr = nullptr;
};