/*!
 * \文件 EmptyMapItem.h
 * \日期 2020/03/19 20:38
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 空图元，不做任何事情
 *
 *
 * \记录 2020/03/19 20:38 新建
*/

#pragma once

#include "AbstractMapItem.h"

class EmptyMapItem : public AbstractMapItem
{
public:

protected:
	virtual void onUpdate(bool autoRedraw) override {}
};