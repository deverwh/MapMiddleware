/*!
 * \文件 Define.h
 * \日期 2020/03/19 21:08
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 地图全局定义
 *
 *
 * \记录 2020/03/19 21:08 新建
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