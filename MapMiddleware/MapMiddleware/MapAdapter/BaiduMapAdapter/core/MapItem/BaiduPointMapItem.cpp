#include "BaiduPointMapItem.h"
#include "BaiduMapHandle.h"
#include "BaiduMapLayer.h"

BaiduPointMapItem::BaiduPointMapItem()
{
}

void BaiduPointMapItem::onUpdate(bool autoRedraw)
{
	// ����

	// �Զ�ˢ��
	if (autoRedraw)
	{
		this->m_mapLayer->update();
	}
}