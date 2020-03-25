/*!
 * \文件 BaiduMapHandle.h
 * \日期 2020/03/19 21:13
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 百度地图实例
 *
 *
 * \记录 2020/03/19 21:13 新建
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

	// 添加图层
	virtual void addMapLayer(AbstractMapLayer *mapLayer) override;

	// 删除图层，删除图层会连带删除图层上的所有图元
	virtual void removeMapLayerByIndex(int mapLayerIndex) override;

	// 设置经纬网格显隐, true，隐藏，false，显示
	virtual void setGridHidden(bool hidden) override;

	// 设置地图状态
	virtual void setMapState(MapHandleState::State state) override;
	virtual void zoomIn() override;
	virtual void zoomOut() override;

	BaiduMapView *baiduMap() const { return m_baiduMap; }

private:
	BaiduMapView *	m_baiduMap = nullptr;
};