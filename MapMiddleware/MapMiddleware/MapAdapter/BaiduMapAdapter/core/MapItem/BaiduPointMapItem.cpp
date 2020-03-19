#include "BaiduPointMapItem.h"
#include "BaiduMapHandle.h"
#include "BaiduMapLayer.h"

BaiduPointMapItem::BaiduPointMapItem()
{
}

void BaiduPointMapItem::onUpdate(bool autoRedraw)
{
	// 绘制

	// 自动刷新
	if (autoRedraw)
	{
		this->m_mapLayer->update();
	}
}