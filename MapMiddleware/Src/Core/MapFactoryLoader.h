/*!
 * \文件 MapFactoryLoader.h
 * \日期 2020/03/19 21:08
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 地图工厂插件加载器
 *		单例
 *
 * \记录 2020/03/19 21:08 新建
*/

#pragma once

#include "Singleton.h"
#include "IMapFactory.h"
#include <QMap>

class QPluginLoader;

class MapFactoryLoader
{
	DEC_SINGLETON(MapFactoryLoader)
public:
	~MapFactoryLoader();

	//************************************
	// 方法: mapFactory
	// 全名: MapFactoryLoader::mapFactory
	// 访控: public 
	// 返回: IMapFactory *
	// 简介: 返回加载的地图工厂接口
	//************************************
	IMapFactory *mapFactory();

private:
	QPluginLoader *m_pluginLoader = nullptr;
	void unloadPlugin();
};