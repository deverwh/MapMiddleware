#include "AbstractPointMapItem.h"

void AbstractPointMapItem::setSize(int size)
{
	if (size <= 10 && size > 0)
	{
		m_size = size;
	}
}

void AbstractPointMapItem::setColor(const QColor &color)
{
	m_color = color;
}