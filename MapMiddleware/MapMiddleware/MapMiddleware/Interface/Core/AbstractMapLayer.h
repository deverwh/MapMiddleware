/*!
 * \文件 AbstractMapLayer.h
 * \日期 2020/01/09 9:45
 *
 * \作者 wanghao
 * 联系: wanghao@swiet.com
 *
 * \简介 地图图层
 *
 *
 * \更改记录 2020.1.9 新建
*/

#pragma once

#include "Interface_Global.h"
#include <QString>
#include <QMap>

class AbstractMapHandle;
class AbstractMapItem;

class INTERFACE_EXPORT AbstractMapLayer
{
public:
	AbstractMapLayer(AbstractMapHandle* mapHandle, const QString& name = QString());
	virtual ~AbstractMapLayer();

	//************************************
	// 方法: mapHandle
	// 全名: AbstractMapLayer::mapHandle
	// 访控: public 
	// 返回: AbstractMapHandle*
	// 简介: 获取图层所在的地图实例
	//************************************
	inline AbstractMapHandle* mapHandle() const { return m_mapHandle; }

	//************************************
	// 方法: index
	// 全名: AbstractMapLayer::index
	// 访控: public 
	// 返回: int
	// 简介: 获取图层索引
	//************************************
	inline int index() const { return m_index; }

	//************************************
	// 方法: name
	// 全名: AbstractMapLayer::name
	// 访控: public 
	// 返回: const QString&
	// 简介: 获取图层名称
	//************************************
	inline const QString& name() const { return m_name; }

protected:
	AbstractMapHandle*				m_mapHandle = nullptr;	// 地图实例
	int								m_index		= -1;		// 图层索引
	QString							m_name;					// 图层名称
};