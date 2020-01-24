/*!
* \文件 AbstractPointMapItem.h
* \日期 2020/01/08 17:33
*
* \作者 wanghao
* 联系: wanghao@swiet.com
*
* \简介 抽象点图元基类
*
*
* \更改记录 2020.1.8 新建
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