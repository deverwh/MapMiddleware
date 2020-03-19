/*!
 * \�ļ� BaiduMapHandle.h
 * \���� 2020/03/19 21:13
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� �ٶȵ�ͼʵ��
 *
 *
 * \��¼ 2020/03/19 21:13 �½�
*/

#pragma once

#include "AbstractMapHandle.h"

class BaiduMapView;

class BaiduMapHandle : public AbstractMapHandle
{
	Q_OBJECT

public:
	BaiduMapHandle(QWidget *parent = nullptr);
	~BaiduMapHandle();

	// ���ͼ��
	virtual void addMapLayer(AbstractMapLayer *mapLayer) override;

	// ɾ��ͼ�㣬ɾ��ͼ�������ɾ��ͼ���ϵ�����ͼԪ
	virtual void removeMapLayerByIndex(int mapLayerIndex) override;

	// ���þ�γ��������, true�����أ�false����ʾ
	virtual void setGridHidden(bool hidden) override;

	// ���õ�ͼ״̬
	virtual void setMapState(MapHandleState::State state) override;

	BaiduMapView *baiduMap() const { return m_baiduMap; }

private:
	BaiduMapView *	m_baiduMap = nullptr;
};