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
	for (auto &mapItem : m_mapItems)
	{
		delete mapItem;
	}
	m_mapItems.clear();

	delete d_ptr;
	d_ptr = nullptr;
}

void MapLayer::update()
{
	for (const auto &mapItem : m_mapItems)
	{
		mapItem->update(false);
	}
	d_ptr->update();
}

void MapLayer::addMapItem(MapItem *mapItem)
{
	if (mapItem == nullptr) return;

	auto mapLayer = mapItem->getMapLayer();
	if (mapLayer == nullptr)
	{
		mapItem->setMapLayer(this);
		m_mapItems.insert(mapItem->getId(), mapItem);
	}
	else
	{
		if (mapLayer != this)
		{
			// 先将图元从它所在的当前图层删除
			mapItem->getMapLayer()->m_mapItems.remove(mapItem->getId());
			m_mapItems.insert(mapItem->getId(), mapItem);
			mapItem->setMapLayer(this);
		}
	}
}

MapItem * MapLayer::getMapItemById(const QString &mapItemId) const
{
	return m_mapItems.value(mapItemId);
}

void MapLayer::removeMapItem(MapItem *mapItem)
{
	if (mapItem == nullptr) return;
	this->removeMapItemById(mapItem->getId());
}

void MapLayer::removeMapItemById(const QString& mapItemId)
{
	auto id = mapItemId;
	auto mapItem = m_mapItems.value(id);
	if (mapItem)
	{
		m_mapItems.remove(id);
		delete mapItem;
	}
}

int MapLayer::getIndex() const
{
	return d_ptr->getIndex();
}

const QString& MapLayer::getName() const
{
	return d_ptr->getName();
}

