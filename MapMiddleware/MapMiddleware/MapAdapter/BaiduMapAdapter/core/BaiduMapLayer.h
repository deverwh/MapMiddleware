/*!
 * \文件 BaiduMapLayer.h
 * \日期 2020/01/23 21:16
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 百度地图图层
 *
 *
 * \记录 2020.01.23 新建
*/

#pragma once

#include "AbstractMapLayer.h"

class BaiduMapLayer : public AbstractMapLayer
{
public:
	BaiduMapLayer(AbstractMapHandle* mapHandle, const QString& name = QString());

protected:
	virtual void update() override;
};