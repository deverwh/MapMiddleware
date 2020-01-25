/*!
 * \�ļ� AbstractMapItem.h
 * \���� 2020/01/04 11:41
 *
 * \���� wanghao
 * ��ϵ: wanghao@swiet.com
 *
 * \��� ͼԪʵ�ֻ���
 *
 *
 * \���ļ�¼ 2020.1.4 �½�
*/

#pragma once

#include "Interface_Global.h"
#include "Define.h"
#include <QString>
#include <QPoint>

class AbstractMapLayer;

class INTERFACE_EXPORT AbstractMapItem
{
	friend class AbstractMapLayer;
	friend class MapItem;
public:
	AbstractMapItem();
	virtual ~AbstractMapItem();

	//************************************
	// ����: draw
	// ȫ��: AbstractMapItem::draw
	// �ÿ�: virtual public 
	// ����: void
	// ���: ��ͼ���ϻ���ͼԪ
	//************************************
	void draw();

	//************************************
	// ����: moveTo
	// ȫ��: AbstractMapItem::moveTo
	// �ÿ�: virtual public 
	// ����: void
	// ���: ��ͼ�����ƶ�
	// ����: const QPointF & newPos
	//************************************
	void moveTo(const QPointF &newPos);

	//************************************
	// ����: remove
	// ȫ��: AbstractMapItem::remove
	// �ÿ�: virtual public 
	// ����: void
	// ���: ��ͼ����ɾ��ͼԪ
	//************************************
	void remove();

	//************************************
	// ����: id
	// ȫ��: AbstractMapItem::id
	// �ÿ�: virtual public 
	// ����: const QString&
	// ���: ��ȡͼԪid��uuid
	//************************************
	inline const QString& id() const { return m_id; }

	//************************************
	// ����: setPos
	// ȫ��: AbstractMapItem::setPos
	// �ÿ�: public 
	// ����: void
	// ���: ����λ��
	// ����: const QPointF & pos
	//************************************
	inline void setPos(const QPointF &pos) { m_pos = pos; }

	//************************************
	// ����: pos
	// ȫ��: AbstractMapItem::pos
	// �ÿ�: public 
	// ����: const QPointF &
	// ���: ���ص�ǰλ��
	//************************************
	inline const QPointF &pos() const { return m_pos; }

protected:
	virtual void onDraw() = 0;
	virtual void onMoveTo(const QPointF &newPos) = 0;
	virtual void onRemove() = 0;

protected:
	//************************************
	// ����: setMapLayer
	// ȫ��: AbstractMapItem::setMapLayer
	// �ÿ�: protected 
	// ����: void
	// ���: ����ͼԪ���ڵ�ͼ��
	// ����: AbstractMapLayer * mapLayer
	//************************************
	inline void setMapLayer(AbstractMapLayer* mapLayer) { m_mapLayer = mapLayer; }

protected:
	QString				m_id;								// ͼԪId
	MapItemType::Type	m_type		= MapItemType::Unvalid;	// ͼԪ����
	QPointF				m_pos		= QPointF(0, 0);		// ͼԪλ�ã�x ���ȣ�y γ�ȣ�Ĭ����(0,0)
	qreal				m_angle		= 0;					// ͼԪ��ת�Ƕȣ�Ĭ��Ϊ����������ת
	bool				m_isDraw	= false;				// ͼԪ�Ƿ��ѻ�����ͼ���ϣ�����ѻ��ƣ���Ĭ����ΪӦ�����ƶ�����������д���remove��Ϊ�轫���ֶ�����Ϊfalse	
	AbstractMapLayer*	m_mapLayer	= nullptr;				// ͼԪ���ڵ�ͼ��
};
