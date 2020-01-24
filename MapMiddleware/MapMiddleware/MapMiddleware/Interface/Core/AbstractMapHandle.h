/*!
 * \�ļ� AbstractMapHandle.h
 * \���� 2020/01/06 9:57
 *
 * \���� wanghao
 * ��ϵ: wanghao@swiet.com
 *
 * \��� ��ͼʵ���������ӿ�
 *
 *
 * \���ļ�¼ 2020.1.6 �½�
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

	// ���ͼ��
	virtual void addMapLayer(AbstractMapLayer *mapLayer) = 0;

	// ɾ��ͼ�㣬ɾ��ͼ�������ɾ��ͼ���ϵ�����ͼԪ
	virtual void removeMapLayer(int mapLayerIndex) = 0;

	// ���þ�γ��������, true�����أ�false����ʾ
	virtual void setGridHidden(bool hidden) = 0;

	// ���õ�ͼ״̬������ʵ����Ҫ�ȵ��ø��෽��
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
	LongLatLabel			*	m_longLatLabel	= nullptr;				// ��γ����ʾ��ǩ
	MapTool					*	m_mapTool		= nullptr;				// ��ͼ������
};