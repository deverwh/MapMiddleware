/*!
 * \�ļ� MapLayer.h
 * \���� 2020/03/19 20:24
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� ��ͼͼ��
 *
 *
 * \��¼ 2020/03/19 20:24 �½�
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

	// ˢ��ͼ��
	void update();

	// ͼ�������ͼԪ
	void addMapItem(MapItem *mapItem);

	// ��ȡָ��Id��ͼԪ
	MapItem *getMapItemById(const QString &mapItemId) const;

	// ɾ��ͼԪ
	void removeMapItem(MapItem *mapItem);
	void removeMapItemById(const QString& mapItemId);

	// ��ȡͼ������
	int getIndex() const;

	// ��ȡͼ������
	const QString& getName() const;

private:
	QMap<QString, MapItem *> m_mapItems;

protected:
	~MapLayer();
	AbstractMapLayer *d_ptr = nullptr;
};