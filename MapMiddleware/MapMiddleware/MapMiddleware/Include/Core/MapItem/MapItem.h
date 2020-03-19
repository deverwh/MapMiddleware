/*!
 * \�ļ� MapItem.h
 * \���� 2020/03/19 20:21
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� �����ͼͼԪ����
 *
 *
 * \��¼ 2020/03/19 20:21 �½�
*/

#pragma once

#include "Map_Global.h"
#include "Define.h"

class MapLayer;

class AbstractMapItem;
class MAP_EXPORT MapItem
{
	MAP_DECLARE_PRIVATE(MapItem)
	friend class MapLayer;
public:
	MapItem();
	MapItem(MapItemType::Type type);

	// ˢ��ͼԪ��ˢ�º��Ƿ��ػ棬Ĭ��Ϊtrue
	void update(bool autoRedraw = true);

	// ��ȡͼԪid��uuid
	const QString& getId() const;

	// ͼԪλ��
	void setPos(const QPointF &pos);
	const QPointF &getPos() const;

	// ͼԪ��ת
	void setRotate(qreal rotate);
	qreal getRotate() const;

	// ��ȡͼԪ����ͼ��
	inline MapLayer* getMapLayer() const { return m_mapLayer; }

protected:
	void setMapLayer(MapLayer *mapLayer);

protected:
	AbstractMapItem		*	d_ptr		= nullptr;
	MapLayer			*	m_mapLayer	= nullptr;	// ͼԪ���ڵ�ͼ��
	QList<MapItem*>			m_children;				// ����ͼԪ

protected:
	virtual ~MapItem() = 0;
};