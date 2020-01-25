#include "MapItem.h"
#include "MapLayer.h"
#include "AbstractMapItem.h"
#include "MapFactoryLoader.h"

MapItem::MapItem(MapLayer *mapLayer, MapItemType::Type type)
: m_type(type)
, m_mapLayer(mapLayer)
{
	auto factory = MapFactoryLoader::instance()->mapFactory();
	if (factory)
	{
		d_ptr = factory->createMapItem(m_type);
		d_ptr->setMapLayer(m_mapLayer->d_func());
	}
}

void MapItem::setMapLayer(MapLayer *mapLayer)
{
	m_mapLayer = mapLayer;
	d_ptr->setMapLayer(m_mapLayer->d_func());
}

MapItem::~MapItem()
{
	if (d_ptr != nullptr)
	{
		d_ptr->remove();
		delete d_ptr;
		d_ptr = nullptr;
	}
}

void MapItem::draw()
{
	if (d_ptr != nullptr)
	{
		d_ptr->draw();
	}
}

void MapItem::moveTo(const QPointF &newPos)
{
	if (d_ptr != nullptr)
	{
		d_ptr->setPos(newPos);
		d_ptr->moveTo(newPos);
	}
}

void MapItem::remove()
{
	if (d_ptr != nullptr)
	{
		d_ptr->remove();
	}
}

void MapItem::setPos(const QPointF &pos)
{
	if (d_ptr != nullptr)
	{
		d_ptr->setPos(pos);
	}
}

const QPointF & MapItem::pos() const
{
	if (d_ptr != nullptr)
	{
		return d_ptr->pos();
	}
	static QPointF p;
	return p;
}

const QString& MapItem::id() const
{
	if (d_ptr != nullptr)
	{
		return d_ptr->id();
	}
	static QString s;
	return s;
}