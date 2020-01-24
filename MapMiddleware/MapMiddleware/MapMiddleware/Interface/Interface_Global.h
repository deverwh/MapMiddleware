/*!
* \文件 Interface_Global.h
* \日期 2020/01/07 17:48
*
* \作者 wanghao
* 联系: wanghao@swiet.com
*
* \简介 通用定义
*
*
* \更改记录 2020.1.7 新建
*/

#pragma once

#ifdef _BUILDING_INTERFACE
#define INTERFACE_EXPORT __declspec(dllexport)
#else // _BUILDING_INTERFACE
#define INTERFACE_EXPORT __declspec(dllimport)
#endif // _BUILDING_INTERFACE