/*!
 * \�ļ� BaiduPointMapItem.h
 * \���� 2020/03/19 21:12
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� �ٶȵ�ͼ��ͼԪ
 *
 *
 * \��¼ 2020/03/19 21:12 �½�
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