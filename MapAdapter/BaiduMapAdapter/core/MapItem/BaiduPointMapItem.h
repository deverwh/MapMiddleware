/*!
 * \文件 BaiduPointMapItem.h
 * \日期 2020/03/19 21:12
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 百度地图点图元
 *
 *
 * \记录 2020/03/19 21:12 新建
*/

#pragma once

#include "BaiduMapItem.h"
#include "AbstractPointMapItem.h"

class BaiduPointMapItem : public BaiduMapItem, public AbstractPointMapItem
{
public:
	BaiduPointMapItem();
	~BaiduPointMapItem();

protected:
	virtual void onUpdate(bool autoRedraw) override;
};