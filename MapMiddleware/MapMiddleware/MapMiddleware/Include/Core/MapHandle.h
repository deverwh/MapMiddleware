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

	//************************************
	// ����: setState
	// ȫ��: MapHandle::setState
	// �ÿ�: public 
	// ����: void
	// ���: ���õ�ͼ״̬
	// ����: MapHandleState::State state
	//************************************
	void setState(MapHandleState::State state);

	//************************************
	// ����: addMapLayer
	// ȫ��: MapHandle::addMapLayer
	// �ÿ�: public 
	// ����: void
	// ���: ���ͼ��
	// ����: MapLayer * mapLayer
	//************************************
	void addMapLayer(MapLayer *mapLayer);

	//************************************
	// ����: mapLayer
	// ȫ��: MapHandle::mapLayer
	// �ÿ�: public 
	// ����: MapLayer*
	// ���: ����ͼ��������ȡͼ��
	// ����: int mapLayerIndex
	//************************************
	MapLayer* mapLayer(int mapLayerIndex);

	//************************************
	// ����: removeMapLayer
	// ȫ��: MapHandle::removeMapLayer
	// �ÿ�: public 
	// ����: void
	// ���: ɾ��ͼ�㣬ɾ��ͼ�������ɾ��ͼ���ϵ�����ͼԪ
	// ����: int mapLayerIndex
	//************************************
	void removeMapLayer(int mapLayerIndex);

	//************************************
	// Method:    isValid
	// FullName:  MapHandle::isValid
	// Access:    public 
	// Returns:   bool
	// Qualifier: ��ͼʵ���Ƿ���Ч
	//************************************
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