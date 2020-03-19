/*!
 * \文件 MapMiddlewareConfig.h
 * \日期 2020/03/19 21:09
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 地图平台配置
 *
 *
 * \记录 2020/03/19 21:09 新建
*/

#pragma once

#include <QString>

class MapMiddlewareConfig
{
public:

	//************************************
	// 函数名称:  mapName
	// 函数全名:  MapMiddlewareConfig::mapName
	// 访问控制:  public static 
	// 返回值  :  QString
	// 函数简介:	 读取配置文件，获取需要加载的底层地图名称，即地图插件名，目前支持：GuoYao CETC（默认为CETC）
	//************************************
	static QString mapName();
};