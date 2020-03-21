/*!
 * \�ļ� BaiduMapLayer.h
 * \���� 2020/01/23 21:16
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� �ٶȵ�ͼͼ��
 *
 *
 * \��¼ 2020.01.23 �½�
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