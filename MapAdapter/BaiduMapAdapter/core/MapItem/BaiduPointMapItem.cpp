#include "BaiduPointMapItem.h"
#include "BaiduMapHandle.h"
#include "BaiduMapLayer.h"
#include "BaiduMapView.h"
#include <QVariant>

BaiduPointMapItem::BaiduPointMapItem()
{
}

BaiduPointMapItem::~BaiduPointMapItem()
{
	auto baiduMapHandle = dynamic_cast<BaiduMapHandle*>(m_mapLayer->getMapHandle());
	baiduMapHandle->baiduMap()->removeMapItem(m_id);
}

void BaiduPointMapItem::onUpdate(bool autoRedraw)
{
	// 绘制
	QString poingJson = QString(
		"{"
		"\"id\": \"%1\","
		"\"longitude\": %2,"
		"\"latitude\": %3,"
		"\"size\": %4,"
		"\"color\": %5"
		"}")
		.arg(m_id)
		.arg(m_pos.rx())
		.arg(m_pos.ry())
		.arg(m_size)
		.arg(m_color.value());
	
	auto baiduMapHandle = dynamic_cast<BaiduMapHandle*>(m_mapLayer->getMapHandle());
	if (m_isDraw)
	{
		baiduMapHandle->baiduMap()->removeMapItem(m_id);
	}
		
	baiduMapHandle->baiduMap()->addPoint(poingJson);
	m_isDraw = true;

	// 自动刷新
	if (autoRedraw)
	{
		this->m_mapLayer->update();
	}
}