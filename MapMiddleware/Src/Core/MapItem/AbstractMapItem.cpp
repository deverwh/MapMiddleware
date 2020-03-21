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

void AbstractMapItem::update(bool autoRedraw /*= true*/)
{
	onUpdate(autoRedraw);
}