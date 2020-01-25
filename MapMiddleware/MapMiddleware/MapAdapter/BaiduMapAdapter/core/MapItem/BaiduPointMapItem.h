/*!
 * \文件 BaiduPointMapItem.h
 * \日期 2020/01/23 21:11
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 百度地图点图元
 *
 *
 * \记录 2020.01.23 新建
*/

#pragma once

#include "BaiduMapItem.h"
#include "AbstractPointMapItem.h"

class BaiduPointMapItem : public BaiduMapItem, public AbstractPointMapItem
{
public:
	BaiduPointMapItem();
	~BaiduPointMapItem();

	virtual void onDraw() override;
	virtual void onMoveTo(const QPointF &newPos) override;
	virtual void onRemove() override;
};