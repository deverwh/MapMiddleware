/*!
 * \文件 IMapFactory.h
 * \日期 2020/03/19 21:06
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 抽象地图工厂
 *
 *
 * \记录 2020/03/19 21:06 新建
*/

#pragma once

#include "Define.h"
#include <QObject>

class AbstractMapHandle;
class AbstractMapLayer;
class AbstractMapItem;

class IMapFactory
{
public:
	//************************************
	// 方法: mapName
	// 全名: IMapFactory::mapName
	// 访控: virtual public 
	// 返回: QString
	// 简介: 获取地图名称
	//************************************
	virtual QString mapName() = 0;

	//************************************
	// 方法: getMapHandle
	// 全名: IMapFactory::createMapHandle
	// 访控: virtual public 
	// 返回: AbstractMapHandle*
	// 简介: 创建地图实例
	//************************************
	virtual AbstractMapHandle* createMapHandle() = 0;

	//************************************
	// 方法: createMapLayer
	// 全名: IMapFactory::createMapLayer
	// 访控: virtual public 
	// 返回: AbstractMapLayer*
	// 简介: 创建地图图层实例对象
	// 参数: AbstractMapHandle * mapHandle
	// 参数: const QString & name
	//************************************
	virtual AbstractMapLayer* createMapLayer(AbstractMapHandle* mapHandle, const QString& name = QString()) = 0;

	//************************************
	// 方法: createMapItem
	// 全名: IMapFactory::createMapItem
	// 访控: virtual public 
	// 返回: IMapItem*
	// 简介: 根据指定的图元类型，创建特定地图图元对象
	// 参数: MapItemType::Type itemType
	//************************************
	virtual AbstractMapItem* createMapItem(MapItemType::Type itemType) = 0;
};

// 声明接口
#define MapFactory_iid "interface.MapFactory"
Q_DECLARE_INTERFACE(IMapFactory, MapFactory_iid)