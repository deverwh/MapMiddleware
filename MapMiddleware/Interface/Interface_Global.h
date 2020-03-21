/*!
 * \文件 Interface_Global.h
 * \日期 2020/03/19 21:06
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 通用定义
 *
 *
 * \记录 2020/03/19 21:06 新建
*/

#pragma once

#ifdef _BUILDING_INTERFACE
#define INTERFACE_EXPORT __declspec(dllexport)
#else // _BUILDING_INTERFACE
#define INTERFACE_EXPORT __declspec(dllimport)
#endif // _BUILDING_INTERFACE

// 地图中间件目录
#define MapMiddlewareDir "./MapMiddleware"