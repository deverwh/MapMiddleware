/*!
 * \�ļ� AbstractMapItem.h
 * \���� 2020/01/04 11:35
 *
 * \���� wanghao
 * ��ϵ: wanghao@swiet.com
 *
 * \��� �����ͼͼԪ����
 *
 *
 * \���ļ�¼ 2020.1.4 �½�
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
	MapItem(MapLayer *mapLayer, MapItemType::Type type);

	//************************************
	// ����: draw
	// ȫ��: MapItem::draw
	// �ÿ�: virtual public 
	// ����: void
	// ���: ����ͼԪ
	//************************************
	void draw();

	//************************************
	// ����: moveTo
	// ȫ��: MapItem::moveTo
	// �ÿ�: public 
	// ����: void
	// ���: ��ͼ�����ƶ�
	// ����: const QPointF & newPos
	//************************************
	void moveTo(const QPointF &newPos);

	//************************************
	// ����: remove
	// ȫ��: MapItem::remove
	// �ÿ�: virtual public 
	// ����: void
	// ���: ��ͼ����ɾ��ͼԪ
	// ����: AbstractMapLayer * mapLayer
	//************************************
	virtual void remove();

	//************************************
	// ����: id
	// ȫ��: MapItem::id
	// �ÿ�: virtual public 
	// ����: const QString&
	// ���: ��ȡͼԪid��uuid
	//************************************
	const QString& id() const;

	//************************************
	// ����: setPos
	// ȫ��: MapItem::setPos
	// �ÿ�: public 
	// ����: void
	// ���: ����λ��
	// ����: const QPointF & pos
	//************************************
	void setPos(const QPointF &pos);

	//************************************
	// ����: pos
	// ȫ��: MapItem::pos
	// �ÿ�: public 
	// ����: const QPointF &
	// ���: ���ص�ǰλ��
	//************************************
	const QPointF &pos() const;

	inline MapLayer* mapLayer() const { return m_mapLayer; }

protected:
	void setMapLayer(MapLayer *mapLayer);

protected:
	AbstractMapItem		*	d_ptr		= nullptr;
	MapLayer			*	m_mapLayer	= nullptr;				// ͼԪ���ڵ�ͼ��
	MapItemType::Type		m_type		= MapItemType::Unvalid;	// ͼԪ���ͣ�Ĭ��Ϊ��ЧͼԪ

protected:
	virtual ~MapItem() = 0;
};