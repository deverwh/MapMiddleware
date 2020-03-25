/*!
 * \�ļ� AbstractMapHandle.h
 * \���� 2020/03/19 21:07
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� ��ͼʵ���������ӿ�
 *
 *
 * \��¼ 2020/03/19 21:07 �½�
*/

#pragma once

#include "Interface_Global.h"
#include "Define.h"
#include <QWidget>
#include <QMap>

class QTimer;
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
	virtual void removeMapLayerByIndex(int mapLayerIndex) = 0;

	// ���þ�γ��������, true�����أ�false����ʾ
	virtual void setGridHidden(bool hidden) = 0;

	// ���õ�ͼ״̬������ʵ����Ҫ�ȵ��ø��෽��
	virtual void setMapState(MapHandleState::State state) = 0;

	virtual void zoomIn() = 0;
	virtual void zoomOut() = 0;

protected:
	MapHandleState::State		m_mapState = MapHandleState::Arrow;

signals:
	void mapStateChanged(MapHandleState::State state);
	void mousePressed(qreal longitude, qreal latitude, Qt::MouseButton button);
	void mouseMoved(qreal longitude, qreal latitude);
	void mouseReleased(qreal longitude, qreal latitude, Qt::MouseButton button);


protected:
	virtual void showEvent(QShowEvent *);
	virtual void hideEvent(QHideEvent *);

private:
	QTimer					*	m_freshTimer	= nullptr;				// ˢ�¶�ʱ������Ҫ���ڸ��¸���λ��
	LongLatLabel			*	m_longLatLabel	= nullptr;				// ��γ����ʾ��ǩ
	MapTool					*	m_mapTool		= nullptr;				// ��ͼ������

private slots:
	void onFreshTimerTimeOut();
};