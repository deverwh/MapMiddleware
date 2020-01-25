#include "MapLayer.h"
#include "MapFactoryLoader.h"
#include "MapHandle.h"
#include "MapItem.h"
#include "AbstractMapLayer.h"
#include "AbstractMapItem.h"

MapLayer::MapLayer(MapHandle* mapHandle, const QString &name /* = QString() */)
{
	auto factory = MapFactoryLoader::instance()->mapFactory();
	if (factory)
	{
		d_ptr = factory->createMapLayer(mapHandle->d_func(), name);
	}
}

MapLayer::~MapLayer()
{
	// 清除图层上的所有图元
	for (auto mapItem : m_mapItems)
	{
		delete mapItem;
	}
	m_mapItems.clear();

	delete d_ptr;
	d_ptr = nullptr;
}

void MapLayer::addMapItem(MapItem *mapItem)
{
	// 如果图元的当前图层不是本图层
	if (mapItem->m_mapLayer != this)
	{
		// 先将图元从它所在的当前图层删除
		mapItem->remove(); // 清除地图显示
		mapItem->m_mapLayer->m_mapItems.remove(mapItem->id());
		mapItem->setMapLayer(this);
	}

	auto item = m_mapItems.find(mapItem->id());
	// 图层上不存在此图元
	if (item == m_mapItems.end())
	{
		m_mapItems.insert(mapItem->id(), mapItem);
		mapItem->d_func()->draw();
	}
	else
	{
		item.value()->d_func()->moveTo(mapItem->pos());
	}
}

MapItem * MapLayer::mapItem(const QString &mapItemId) const
{
	return m_mapItems.value(mapItemId);
}

void MapLayer::removeMapItem(const QString& mapItemId)
{
	auto id = mapItemId;
	auto mapItem = m_mapItems.value(id);
	if (mapItem)
	{
		m_mapItems.remove(id);
		delete mapItem;
	}
}

int MapLayer::index() const
{
	return d_ptr->index();
}

const QString& MapLayer::name() const
{
	return d_ptr->name();
}

