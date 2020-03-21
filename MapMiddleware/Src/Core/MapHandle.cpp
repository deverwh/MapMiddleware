#include "MapHandle.h"
#include "IMapFactory.h"
#include "AbstractMapHandle.h"
#include "MapItem.h"
#include "MapFactoryLoader.h"
#include "MapLayer.h"
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QDateTime>

MapHandle::MapHandle(QWidget *parent /* = nullptr */)
: QWidget(parent)
{
	auto mapFactory = MapFactoryLoader::instance()->mapFactory();
	if (mapFactory)
	{
		d_ptr = mapFactory->createMapHandle();
		QHBoxLayout *layout = new QHBoxLayout(this);
		layout->setMargin(0);
		layout->addWidget(d_ptr);
		this->setLayout(layout);

		connect(d_ptr, &AbstractMapHandle::mousePressed, this, &MapHandle::mousePressed);
		connect(d_ptr, &AbstractMapHandle::mouseMoved, this, &MapHandle::mouseMoved);
		connect(d_ptr, &AbstractMapHandle::mouseReleased, this, &MapHandle::mouseReleased);
	}
}

MapHandle::~MapHandle()
{
	// ����ͼ��
	for (auto &mapLayer : m_mapLayers)
	{
		delete mapLayer;
	}
	m_mapLayers.clear();

	// ж�ص�ͼ���
	MapFactoryLoader::instance()->release();
}

void MapHandle::setState(MapHandleState::State state)
{
	d_ptr->setMapState(state);
}

void MapHandle::addMapLayer(MapLayer *mapLayer)
{
	// ���ͼ�㲻���ڣ�����ӵ�ͼ��
	if (m_mapLayers.find(mapLayer->getIndex()) == m_mapLayers.end())
	{
		m_mapLayers.insert(mapLayer->getIndex(), mapLayer);
	}
	d_ptr->addMapLayer(mapLayer->d_func());
}

MapLayer* MapHandle::getMapLayerByIndex(int mapLayerIndex)
{
	return m_mapLayers.value(mapLayerIndex);
}

void MapHandle::removeMapLayerByIndex(int mapLayerIndex)
{
	auto mapLayer = m_mapLayers.value(mapLayerIndex);
	if (mapLayer != nullptr)
	{
		d_ptr->removeMapLayerByIndex(mapLayerIndex);
		m_mapLayers.remove(mapLayerIndex);
		delete mapLayer;
	}
}

void MapHandle::removeMapLayer(MapLayer *mapLayer)
{
	if (mapLayer == nullptr) return;
	this->removeMapLayerByIndex(mapLayer->getIndex());
}