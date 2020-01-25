/*!
 * \�ļ� MapHandle.h
 * \���� 2019/12/31 19:31
 *
 * \���� wanghao
 * ��ϵ: wanghao@swiet.com
 *
 * \��� ��ͼʵ����
 *
 *
 * \���ģ�2019.12.31 �½�
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
	MapLayer* mapLayer(int mapLayerIndex);

	// ɾ��ͼ�㣬ɾ��ͼ�������ɾ��ͼ���ϵ�����ͼԪ
	void removeMapLayer(int mapLayerIndex);

	// ��ͼʵ���Ƿ���Ч
	bool isValid() const;

signals:
	void mouseMoved(qreal longitude, qreal latitude);
	void mousePressed(qreal longitude, qreal latitude, Qt::MouseButton button);
	void mouseReleased(qreal longitude, qreal latitude, Qt::MouseButton button);

private:
	QMap<int, MapLayer *>		m_mapLayers;
	MapHandleState::State		m_state		= MapHandleState::Arrow; // ��ͼ״̬

protected:
	AbstractMapHandle	*d_ptr = nullptr;
};