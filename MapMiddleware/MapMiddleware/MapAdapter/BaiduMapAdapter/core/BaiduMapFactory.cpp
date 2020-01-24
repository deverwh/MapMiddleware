#include "BaiduMapFactory.h"
#include "BaiduMap_Gloable.h"
#include "BaiduMapHandle.h"
#include "BaiduMapLayer.h"
#include "BaiduPointMapItem.h"

QString BaiduMapFactory::mapName()
{
	return BAIDUMAP_NAME;
}

AbstractMapHandle * BaiduMapFactory::createMapHandle()
{
	return new BaiduMapHandle;
}

AbstractMapLayer* BaiduMapFactory::createMapLayer(AbstractMapHandle* mapHandle, const QString& name /* = QString() */)
{
	return new BaiduMapLayer(mapHandle, name);
}

AbstractMapItem * BaiduMapFactory::createMapItem(MapItemType::Type itemType)
{
	switch (itemType)
	{
	case MapItemType::Point:		return new BaiduPointMapItem;	break;
	default:	break;
	}
	return nullptr;
}