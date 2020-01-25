#include "AbstractPointMapItem.h"

void AbstractPointMapItem::setSize(int size)
{
	m_size = size;
}

void AbstractPointMapItem::setColor(const QColor &color)
{
	m_color = color;
}

int AbstractPointMapItem::size() const
{
	return m_size;
}

const QColor & AbstractPointMapItem::color() const
{
	return m_color;
}
