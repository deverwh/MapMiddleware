#include "LineMapItem.h"
#include "MapHandle.h"
#include "AbstractLineMapItem.h"

LineMapItem::LineMapItem()
: MapItem(MapItemType::Line)
{

}

LineMapItem::LineMapItem(const QPointF &startPos, const QPointF& endPos)
: MapItem(MapItemType::Line)
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
