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

	//************************************
	// ����: mapHandle
	// ȫ��: AbstractMapLayer::mapHandle
	// �ÿ�: public 
	// ����: AbstractMapHandle*
	// ���: ��ȡͼ�����ڵĵ�ͼʵ��
	//************************************
	inline AbstractMapHandle* mapHandle() const { return m_mapHandle; }

	//************************************
	// ����: index
	// ȫ��: AbstractMapLayer::index
	// �ÿ�: public 
	// ����: int
	// ���: ��ȡͼ������
	//************************************
	inline int index() const { return m_index; }

	//************************************
	// ����: name
	// ȫ��: AbstractMapLayer::name
	// �ÿ�: public 
	// ����: const QString&
	// ���: ��ȡͼ������
	//************************************
	inline const QString& name() const { return m_name; }

protected:
	AbstractMapHandle*				m_mapHandle = nullptr;	// ��ͼʵ��
	int								m_index		= -1;		// ͼ������
	QString							m_name;					// ͼ������
};