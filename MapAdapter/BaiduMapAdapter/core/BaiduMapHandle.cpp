#include "BaiduMapHandle.h"
#include "BaiduMapView.h"
#include <QtWidgets>
#include <QtCore>

BaiduMapHandle::BaiduMapHandle(QWidget *parent)
	: AbstractMapHandle(parent)
{
	m_baiduMap = new BaiduMapView(this);
	QHBoxLayout *layout = new QHBoxLayout(this);
	layout->setMargin(0);
	layout->addWidget(m_baiduMap);
	this->setLayout(layout);
	this->setMouseTracking(true);

	connect(m_baiduMap, &BaiduMapView::signalMouseMoved, this, &AbstractMapHandle::mouseMoved);
}

BaiduMapHandle::~BaiduMapHandle()
{

}

void BaiduMapHandle::addMapLayer(AbstractMapLayer *mapLayer)
{

}

void BaiduMapHandle::removeMapLayerByIndex(int mapLayerIndex)
{

}

void BaiduMapHandle::setGridHidden(bool hidden)
{

}

void BaiduMapHandle::setMapState(MapHandleState::State state)
{
	AbstractMapHandle::setMapState(state);
	// TODO
}