/*!
 * \�ļ� MapLayer.h
 * \���� 2020/01/09 9:48
 *
 * \���� wanghao
 * ��ϵ: wanghao@swiet.com
 *
 * \��� ��ͼͼ��
 *
 *
 * \���ļ�¼ 2020.1.9 �½�
*/

#pragma once

#include "Map_Global.h"
#include <QMap>

class MapHandle;
class MapItem;

class AbstractMapLayer;
class MAP_EXPORT MapLayer
{
	MAP_DECLARE_PRIVATE(MapLayer)
	friend class MapHandle;
public:
	MapLayer(MapHandle* mapHandle, const QString &name = QString());  // ���δָ�����ƣ���Ĭ������ΪMapLayer[index]��ͼ�������Զ�����

	//************************************
	// ����: addMapItem
	// ȫ��: MapLayer::addMapItem
	// �ÿ�: public 
	// ����: QString
	// ���: ��ͼ�������ͼԪ
	// ����: MapItem * mapItem
	//************************************
	void addMapItem(MapItem *mapItem);

	//************************************
	// ����: mapItem
	// ȫ��: MapLayer::mapItem
	// �ÿ�: public 
	// ����: MapItem *
	// ���: ��ȡָ��Id��ͼԪ
	// ����: const QString & mapItemId
	//************************************
	MapItem *mapItem(const QString &mapItemId) const;

	//************************************
	// ����: removeMapItem
	// ȫ��: MapLayer::removeMapItem
	// �ÿ�: public 
	// ����: void
	// ���: ����ͼԪIdɾ��ͼԪ
	// ����: QString mapItemId
	//************************************
	void removeMapItem(const QString& mapItemId);

	//************************************
	// ����: index
	// ȫ��: MapLayer::index
	// �ÿ�: public 
	// ����: int
	// ���: ��ȡͼ������
	//************************************
	int index() const;

	//************************************
	// ����: name
	// ȫ��: MapLayer::name
	// �ÿ�: public 
	// ����: const QString&
	// ���: ��ȡͼ������
	//************************************
	const QString& name() const;

private:
	QMap<QString, MapItem *> m_mapItems;

protected:
	~MapLayer();
	AbstractMapLayer *d_ptr = nullptr;
};