/*!
 * \�ļ� EmptyMapItem.h
 * \���� 2020/03/19 20:38
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� ��ͼԪ�������κ�����
 *
 *
 * \��¼ 2020/03/19 20:38 �½�
*/

#pragma once

#include "AbstractMapItem.h"

class EmptyMapItem : public AbstractMapItem
{
public:

protected:
	virtual void onUpdate(bool autoRedraw) override {}
};