/*!
 * \文件 Define.h
 * \日期 2020/01/10 15:57
 *
 * \作者 wanghao
 * 联系: wanghao@swiet.com
 *
 * \简介 地图全局定义
 *
 *
 * \更改记录 2020.1.10 新建
*/

#pragma once

namespace MapItemType
{
	enum Type
	{
		Unvalid,	// 无效图元
		Point,		// 点图元
		Line,		// 线图元
	};
}

namespace MapHandleState
{
	enum State
	{
		Arrow,			// 箭头模式
		Roaming,		// 漫游
		ZoomIn,			// 缩小
		ZoonOut,		// 放大
	};
}