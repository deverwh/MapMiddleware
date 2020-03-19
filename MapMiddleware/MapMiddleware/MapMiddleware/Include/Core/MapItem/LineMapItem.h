/*!
 * \�ļ� LineMapItem.h
 * \���� 2020/03/19 21:09
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� ��ͼԪ
 *
 *
 * \��¼ 2020/03/19 21:09 �½�
*/

#pragma once

#include "MapItem.h"
#include <QColor>

class MAP_EXPORT LineMapItem : public MapItem
{
public:
	LineMapItem();
	LineMapItem(const QPointF &startPos, const QPointF& endPos);

	void setStartPos(const QPointF &startPos);
	const QPointF getStartPos() const;
	void setEndPos(const QPointF &endPos);
	const QPointF getEndPos() const;

protected:
	~LineMapItem();
};