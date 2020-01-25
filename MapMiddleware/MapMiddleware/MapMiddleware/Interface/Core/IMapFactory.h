/*!
 * \�ļ� IMapFactory.h
 * \���� 2020/01/06 15:52
 *
 * \���� wanghao
 * ��ϵ: wanghao@swiet.com
 *
 * \��� �����ͼ����
 *
 *
 * \���ļ�¼ 2020.1.6 �½�
*/

#pragma once

#include "Define.h"
#include <QObject>

class AbstractMapHandle;
class AbstractMapLayer;
class AbstractMapItem;

class IMapFactory
{
public:
	//************************************
	// ����: mapName
	// ȫ��: IMapFactory::mapName
	// �ÿ�: virtual public 
	// ����: QString
	// ���: ��ȡ��ͼ����
	//************************************
	virtual QString mapName() = 0;

	//************************************
	// ����: getMapHandle
	// ȫ��: IMapFactory::createMapHandle
	// �ÿ�: virtual public 
	// ����: AbstractMapHandle*
	// ���: ������ͼʵ��
	//************************************
	virtual AbstractMapHandle* createMapHandle() = 0;

	//************************************
	// ����: createMapLayer
	// ȫ��: IMapFactory::createMapLayer
	// �ÿ�: virtual public 
	// ����: AbstractMapLayer*
	// ���: ������ͼͼ��ʵ������
	// ����: AbstractMapHandle * mapHandle
	// ����: const QString & name
	//************************************
	virtual AbstractMapLayer* createMapLayer(AbstractMapHandle* mapHandle, const QString& name = QString()) = 0;

	//************************************
	// ����: createMapItem
	// ȫ��: IMapFactory::createMapItem
	// �ÿ�: virtual public 
	// ����: IMapItem*
	// ���: ����ָ����ͼԪ���ͣ������ض���ͼͼԪ����
	// ����: MapItemType::Type itemType
	//************************************
	virtual AbstractMapItem* createMapItem(MapItemType::Type itemType) = 0;
};

// �����ӿ�
#define MapFactory_iid "interface.MapFactory"
Q_DECLARE_INTERFACE(IMapFactory, MapFactory_iid)