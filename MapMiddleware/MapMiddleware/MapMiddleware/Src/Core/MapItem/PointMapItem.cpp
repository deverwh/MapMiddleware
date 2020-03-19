#include "PointMapItem.h"
#include "MapHandle.h"
#include "AbstractPointMapItem.h"

PointMapItem::PointMapItem()
: MapItem(MapItemType::Point)
{

}

PointMapItem::PointMapItem(const QPointF &pos, int size /* = 1 */, const QColor &color /* = QColor(Qt::red) */)
: MapItem(MapItemType::Point)
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