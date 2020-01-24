#include "AbstractMapItem.h"
#include "MapFactoryLoader.h"
#include <QUuid>

AbstractMapItem::AbstractMapItem()
{
	auto uuid = QUuid::createUuid().toString();
	uuid.remove("{").remove("}");
	m_id = uuid;
}

AbstractMapItem::~AbstractMapItem()
{

}

void AbstractMapItem::draw()
{
	if (m_isDraw)
	{
		onMoveTo(m_pos);
	}
	else
	{
		onDraw();
		m_isDraw = true;
	}
}

void AbstractMapItem::moveTo(const QPointF &newPos)
{
	onMoveTo(newPos);
}

void AbstractMapItem::remove()
{
	onRemove();
	m_isDraw = false;
}
