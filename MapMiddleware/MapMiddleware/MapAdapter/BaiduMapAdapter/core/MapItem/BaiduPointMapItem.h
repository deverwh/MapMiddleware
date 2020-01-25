/*!
 * \�ļ� BaiduPointMapItem.h
 * \���� 2020/01/23 21:11
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� �ٶȵ�ͼ��ͼԪ
 *
 *
 * \��¼ 2020.01.23 �½�
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