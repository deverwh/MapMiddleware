/*!
 * \文件 BaiduMapFactory.h
 * \日期 2020/01/23 21:03
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 百度地图工厂
 *
 *
 * \记录 2020.01.23 新建
*/

#pragma once

#include "IMapFactory.h"

class BaiduMapFactory : public QObject, public IMapFactory
{
	Q_OBJECT
		Q_PLUGIN_METADATA(IID "interface.MapFactory")
		Q_INTERFACES(IMapFactory)

public:
	// 获取地图名称
	virtual QString mapName() override;

	// 创建地图实例
	virtual AbstractMapHandle* createMapHandle() override;

	// 创建地图图层实例对象，如果未指定名称，则默认名称为MapLayer[index]，图层索引自动增长
	virtual AbstractMapLayer* createMapLayer(AbstractMapHandle* mapHandle, const QString& name = QString()) override;

	// 根据指定的图元类型，创建特定地图图元对象
	virtual AbstractMapItem* createMapItem(MapItemType::Type itemType) override;
};