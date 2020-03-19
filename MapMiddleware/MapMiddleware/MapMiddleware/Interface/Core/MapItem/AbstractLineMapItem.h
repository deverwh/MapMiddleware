/*!
 * \文件 AbstractLineMapItem.h
 * \日期 2020/03/19 21:05
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 抽象线图元基类
 *
 *
 * \记录 2020/03/19 21:05 新建
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
	QPointF m_startPos	= QPointF(0, 0);	// 起点	
	QPointF	m_endPos	= QPointF(0, 0);	// 终点
};