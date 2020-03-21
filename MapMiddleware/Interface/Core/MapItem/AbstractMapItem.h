/*!
 * \�ļ� AbstractMapItem.h
 * \���� 2020/03/19 21:05
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� ͼԪʵ�ֻ���
 *
 *
 * \��¼ 2020/03/19 21:05 �½�
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

	// ˢ��ͼԪ��ˢ�º��Ƿ��ػ棬Ĭ��Ϊtrue
	void update(bool autoRedraw = true);

	// ��ȡͼԪid��uuid
	inline const QString& getId() const { return m_id; }

	// ͼԪλ��
	inline void setPos(const QPointF &pos) { m_pos = pos; }
	inline const QPointF &getPos() const { return m_pos; }

	// ͼԪ��ת
	inline void setRotate(qreal rotate) { m_rotate = rotate; }
	inline qreal getRotate() const { return m_rotate; }

protected:
	virtual void onUpdate(bool autoRedraw) = 0;

protected:
	// ����ͼԪ���ڵ�ͼ��
	inline void setMapLayer(AbstractMapLayer* mapLayer) { m_mapLayer = mapLayer; }

protected:
	QString				m_id;								// ͼԪId
	MapItemType::Type	m_type		= MapItemType::Unvalid;	// ͼԪ����
	QPointF				m_pos		= QPointF(0, 0);		// ͼԪλ�ã�x ���ȣ�y γ�ȣ�Ĭ����(0,0)
	qreal				m_rotate	= 0;					// ͼԪ��ת�Ƕȣ�������ʱ�� ��Ĭ������ת
	AbstractMapLayer*	m_mapLayer	= nullptr;				// ͼԪ���ڵ�ͼ��
};
