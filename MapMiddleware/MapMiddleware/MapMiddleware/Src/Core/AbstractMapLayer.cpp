#include "AbstractMapLayer.h"
#include "AbstractMapItem.h"

AbstractMapLayer::AbstractMapLayer(AbstractMapHandle* mapHandle, const QString& name /* = QString() */)
: m_mapHandle(mapHandle)
{
	static int index = 0;

	m_index = index++;
	if (name.isEmpty())
	{
		m_name = QString("MapLayer%1").arg(index, 3, 10, QChar('0'));
	}
	else
	{
		m_name = name;
	}
}

AbstractMapLayer::~AbstractMapLayer()
{

}
