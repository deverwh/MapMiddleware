#include "LineMapItem.h"
#include "MapHandle.h"
#include "AbstractLineMapItem.h"

LineMapItem::LineMapItem(MapLayer *mapLayer)
: MapItem(mapLayer, MapItemType::Line)
{

}

LineMapItem::LineMapItem(MapLayer *mapLayer, const QPointF &startPos, const QPointF& endPos)
: MapItem(mapLayer, MapItemType::Line)
{
	setStartPos(startPos);
	setEndPos(endPos);
}

LineMapItem::~LineMapItem()
{

}

void LineMapItem::setStartPos(const QPointF &startPos)
{
	dynamic_cast<AbstractLineMapItem*>(d_ptr)->setStartPos(startPos);
	setPos((getStartPos() + getEndPos()) / 2);
}

const QPointF LineMapItem::getStartPos() const
{
	return dynamic_cast<AbstractLineMapItem*>(d_ptr)->getStartPos();
}

void LineMapItem::setEndPos(const QPointF &endPos)
{
	dynamic_cast<AbstractLineMapItem*>(d_ptr)->setEndPos(endPos);
	setPos((getStartPos() + getEndPos()) / 2);
}

const QPointF LineMapItem::getEndPos() const
{
	return dynamic_cast<AbstractLineMapItem*>(d_ptr)->getEndPos();
}
