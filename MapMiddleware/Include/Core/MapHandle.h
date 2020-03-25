/*!
 * \�ļ� MapHandle.h
 * \���� 2020/03/19 20:16
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� ��ͼʵ����
 *
 *
 * \��¼ 2020/03/19 20:16 �½�
*/

#pragma once

#include "Map_Global.h"
#include "Define.h"
#include <QWidget>
#include <QMap>

class MapLayer;
class MapItem;

class AbstractMapHandle;
class MAP_EXPORT MapHandle : public QWidget
{
	Q_OBJECT
	MAP_DECLARE_PRIVATE(MapHandle)
public:
	MapHandle(QWidget *parent = nullptr);
	~MapHandle();

	// ���õ�ͼ״̬
	void setState(MapHandleState::State state);

	// ���ͼ��
	void addMapLayer(MapLayer *mapLayer);

	// ����ͼ��������ȡͼ��
	MapLayer* getMapLayerByIndex(int mapLayerIndex);

	// ɾ��ͼ�㣬ɾ��ͼ�������ɾ��ͼ���ϵ�����ͼԪ
	void removeMapLayer(MapLayer *mapLayer);
	void removeMapLayerByIndex(int mapLayerIndex);

	// �Ŵ�
	void zoomIn();

	// ��С
	void zoomOut();

signals:
	void mouseMoved(qreal longitude, qreal latitude);
	void mousePressed(qreal longitude, qreal latitude, Qt::MouseButton button);
	void mouseReleased(qreal longitude, qreal latitude, Qt::MouseButton button);

private:
	AbstractMapHandle		*	d_ptr			= nullptr;
	QMap<int, MapLayer *>		m_mapLayers;
	MapHandleState::State		m_state			= MapHandleState::Arrow; // ��ͼ״̬
};