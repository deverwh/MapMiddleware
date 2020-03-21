/*!
 * \�ļ� AbstractMapLayer.h
 * \���� 2020/01/09 9:45
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

#include "Interface_Global.h"
#include <QString>
#include <QMap>

class AbstractMapHandle;
class AbstractMapItem;

class INTERFACE_EXPORT AbstractMapLayer
{
public:
	AbstractMapLayer(AbstractMapHandle* mapHandle, const QString& name = QString());
	virtual ~AbstractMapLayer();

	virtual void update() = 0;

	// ��ȡͼ�����ڵĵ�ͼʵ��
	inline AbstractMapHandle* getMapHandle() const { return m_mapHandle; }

	// ��ȡͼ������
	inline int getIndex() const { return m_index; }

	// ��ȡͼ������
	//************************************
	inline const QString& getName() const { return m_name; }

protected:
	AbstractMapHandle*				m_mapHandle = nullptr;	// ��ͼʵ��
	int								m_index		= -1;		// ͼ������
	QString							m_name;					// ͼ������
};