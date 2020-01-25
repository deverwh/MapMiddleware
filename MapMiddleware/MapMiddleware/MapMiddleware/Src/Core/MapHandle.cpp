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
		d_ptr->setParent(this);
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
	// 清理图层
	for (auto mapLayer : m_mapLayers)
	{
		delete mapLayer;
	}
	m_mapLayers.clear();

	// 卸载地图插件
	MapFactoryLoader::instance()->release();
}

void MapHandle::setState(MapHandleState::State state)
{
	d_ptr->setMapState(state);
}

void MapHandle::addMapLayer(MapLayer *mapLayer)
{
	// 如果图层不存在，则添加到图层
	if (m_mapLayers.find(mapLayer->index()) == m_mapLayers.end())
	{
		m_mapLayers.insert(mapLayer->index(), mapLayer);
	}
	d_ptr->addMapLayer(mapLayer->d_func());
}

MapLayer* MapHandle::mapLayer(int mapLayerIndex)
{
	return m_mapLayers.value(mapLayerIndex);
}

void MapHandle::removeMapLayer(int mapLayerIndex)
{
	auto mapLayer = m_mapLayers.value(mapLayerIndex);
	if (mapLayer != nullptr)
	{
		d_ptr->removeMapLayer(mapLayerIndex);
		m_mapLayers.remove(mapLayerIndex);
		delete mapLayer;
	}
}

bool MapHandle::isValid() const
{
	return d_ptr != nullptr;
}

void MapHandle::paintEvent(QPaintEvent *event)
{
	QWidget::paintEvent(event);
}
