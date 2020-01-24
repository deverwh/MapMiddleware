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
}

BaiduMapHandle::~BaiduMapHandle()
{

}

void BaiduMapHandle::addMapLayer(AbstractMapLayer *mapLayer)
{

}

void BaiduMapHandle::removeMapLayer(int mapLayerIndex)
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

void BaiduMapHandle::resizeEvent(QResizeEvent *event)
{
	AbstractMapHandle::resizeEvent(event);
}

void BaiduMapHandle::wheelEvent(QWheelEvent *event)
{
	AbstractMapHandle::wheelEvent(event);
}

void BaiduMapHandle::mousePressEvent(QMouseEvent *event)
{
	AbstractMapHandle::mousePressEvent(event);
}

void BaiduMapHandle::mouseMoveEvent(QMouseEvent *event)
{
	AbstractMapHandle::mouseMoveEvent(event);
}