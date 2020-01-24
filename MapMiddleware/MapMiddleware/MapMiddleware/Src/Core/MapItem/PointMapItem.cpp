#include "PointMapItem.h"
#include "MapHandle.h"
#include "AbstractPointMapItem.h"

PointMapItem::PointMapItem(MapLayer *mapLayer)
: MapItem(mapLayer, MapItemType::Point)
{

}

PointMapItem::PointMapItem(MapLayer *mapLayer, const QPointF &pos, int size /* = 1 */, const QColor &color /* = QColor(Qt::red) */)
: MapItem(mapLayer, MapItemType::Point)
{
	setPos(pos);
	setSize(size);
	setColor(color);
}

PointMapItem::~PointMapItem()
{

}

void PointMapItem::setPos(const QPointF &pos)
{
	d_ptr->setPos(pos);
}

void PointMapItem::setSize(int size)
{
	dynamic_cast<AbstractPointMapItem*>(d_ptr)->setSize(size);
}

void PointMapItem::setColor(const QColor &color)
{
	dynamic_cast<AbstractPointMapItem*>(d_ptr)->setColor(color);
}