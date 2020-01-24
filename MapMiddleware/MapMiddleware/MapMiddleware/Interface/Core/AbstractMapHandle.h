/*!
 * \文件 AbstractMapHandle.h
 * \日期 2020/01/06 9:57
 *
 * \作者 wanghao
 * 联系: wanghao@swiet.com
 *
 * \简介 地图实例适配器接口
 *
 *
 * \更改记录 2020.1.6 新建
*/

#pragma once

#include "Interface_Global.h"
#include "Define.h"
#include <QWidget>
#include <QMap>

class LongLatLabel;
class MapTool;
class AbstractMapLayer;

class INTERFACE_EXPORT AbstractMapHandle : public QWidget
{
	Q_OBJECT
public:
	AbstractMapHandle(QWidget *parent = nullptr);
	virtual ~AbstractMapHandle();

	// 添加图层
	virtual void addMapLayer(AbstractMapLayer *mapLayer) = 0;

	// 删除图层，删除图层会连带删除图层上的所有图元
	virtual void removeMapLayer(int mapLayerIndex) = 0;

	// 设置经纬网格显隐, true，隐藏，false，显示
	virtual void setGridHidden(bool hidden) = 0;

	// 设置地图状态，子类实现需要先调用父类方法
	virtual void setMapState(MapHandleState::State state) = 0;

protected:
	MapHandleState::State		m_mapState = MapHandleState::Arrow;

signals:
	void mapStateChanged(MapHandleState::State state);
	void mousePressed(qreal longitude, qreal latitude, Qt::MouseButton button);
	void mouseMoved(qreal longitude, qreal latitude);
	void mouseReleased(qreal longitude, qreal latitude, Qt::MouseButton button);

protected:
	virtual void paintEvent(QPaintEvent *) override;
	virtual void mousePressEvent(QMouseEvent *) override;
	virtual void mouseMoveEvent(QMouseEvent *) override;
	virtual void mouseReleaseEvent(QMouseEvent *) override;
	virtual void showEvent(QShowEvent *) override;
	virtual void hideEvent(QHideEvent *) override;
private:
	LongLatLabel			*	m_longLatLabel	= nullptr;				// 经纬度显示标签
	MapTool					*	m_mapTool		= nullptr;				// 地图工具栏
};