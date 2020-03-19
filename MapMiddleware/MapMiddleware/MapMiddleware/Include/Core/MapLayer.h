/*!
 * \文件 MapLayer.h
 * \日期 2020/03/19 20:24
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 地图图层
 *
 *
 * \记录 2020/03/19 20:24 新建
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

	// 刷新图层
	void update();

	// 图层上添加图元
	void addMapItem(MapItem *mapItem);

	// 获取指定Id的图元
	MapItem *getMapItemById(const QString &mapItemId) const;

	// 删除图元
	void removeMapItem(MapItem *mapItem);
	void removeMapItemById(const QString& mapItemId);

	// 获取图层索引
	int getIndex() const;

	// 获取图层名称
	const QString& getName() const;

private:
	QMap<QString, MapItem *> m_mapItems;

protected:
	~MapLayer();
	AbstractMapLayer *d_ptr = nullptr;
};