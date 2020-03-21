#include "MapItem.h"
#include "MapLayer.h"
#include "AbstractMapItem.h"
#include "MapFactoryLoader.h"
#include "EmptyMapItem.h"

MapItem::MapItem()
{
	d_ptr = new EmptyMapItem();
}

MapItem::MapItem(MapItemType::Type type)
{
	auto factory = MapFactoryLoader::instance()->mapFactory();
	if (factory)
	{
		d_ptr = factory->createMapItem(type);
	}
	else
	{
		d_ptr = new EmptyMapItem();
	}
}

MapItem::~MapItem()
{
	for (auto &child : m_children)
	{
		delete child;
	}
	m_children.clear();

	delete d_ptr;
	d_ptr = nullptr;
}

void MapItem::update(bool autoRedraw /*= true*/)
{
	d_ptr->update(autoRedraw);
	for (const auto &child : m_children)
	{
		child->update(autoRedraw);
	}
}

const QString& MapItem::getId() const
{
	return d_ptr->getId();
}

void MapItem::setMapLayer(MapLayer *mapLayer)
{
	m_mapLayer = mapLayer;
	d_ptr->setMapLayer(m_mapLayer->d_func());
	for (const auto &child : m_children)
	{
		child->setMapLayer(m_mapLayer);
	}
}

void MapItem::setPos(const QPointF &pos)
{
	auto offset = d_ptr->getPos() - pos;
	d_ptr->setPos(pos);
	// ���ú���ͼԪλ��
	for (auto &child : m_children)
	{
		child->setPos(child->getPos() - pos);
	}
}

const QPointF & MapItem::getPos() const
{
	return d_ptr->getPos();
}

void MapItem::setRotate(qreal rotate)
{
	d_ptr->setRotate(rotate);
	// ��Ҫ���㺢��ͼԪ����ת��λ�ã��ݲ�֪��ô��������֪���ɸ�֪��лл
}

qreal MapItem::getRotate() const
{
	return d_ptr->getRotate();
}