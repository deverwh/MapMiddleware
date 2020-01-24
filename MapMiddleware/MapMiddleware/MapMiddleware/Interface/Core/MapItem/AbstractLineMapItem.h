/*!
* \�ļ� AbstractPointMapItem.h
* \���� 2020/01/08 17:33
*
* \���� wanghao
* ��ϵ: wanghao@swiet.com
*
* \��� �����ͼԪ����
*
*
* \���ļ�¼ 2020.1.8 �½�
*/

#pragma once

#include "Interface_Global.h"
#include "AbstractMapItem.h"
#include <QColor>

class INTERFACE_EXPORT AbstractLineMapItem : public AbstractMapItem
{
public:
	inline void setStartPos(const QPointF &startPos) { m_startPos = startPos; }
	const QPointF getStartPos() const { return m_startPos; }
	inline void setEndPos(const QPointF &endPos) { m_endPos = endPos; }
	const QPointF getEndPos()  const { return m_endPos; }

protected:
	QPointF m_startPos	= QPointF(0, 0);	// ���	
	QPointF	m_endPos	= QPointF(0, 0);	// �յ�
};