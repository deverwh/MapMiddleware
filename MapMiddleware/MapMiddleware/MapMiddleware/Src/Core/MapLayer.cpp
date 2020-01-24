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
	// ���ͼ���ϵ�����ͼԪ
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
	// ���ͼԪ�ĵ�ǰͼ�㲻�Ǳ�ͼ��
	if (mapItem->m_mapLayer != this)
	{
		// �Ƚ�ͼԪ�������ڵĵ�ǰͼ��ɾ��
		mapItem->remove(); // �����ͼ��ʾ
		mapItem->m_mapLayer->m_mapItems.remove(mapItem->id());
		mapItem->setMapLayer(this);
	}

	auto item = m_mapItems.find(mapItem->id());
	// ͼ���ϲ����ڴ�ͼԪ
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

