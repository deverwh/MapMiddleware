/*!
 * \�ļ� BaiduMapFactory.h
 * \���� 2020/03/19 21:14
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� �ٶȵ�ͼ����
 *
 *
 * \��¼ 2020/03/19 21:14 �½�
*/

#pragma once

#include "IMapFactory.h"

class BaiduMapFactory : public QObject, public IMapFactory
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "interface.MapFactory")
	Q_INTERFACES(IMapFactory)

public:
	// ��ȡ��ͼ����
	virtual QString mapName() override;

	// ������ͼʵ��
	virtual AbstractMapHandle* createMapHandle() override;

	// ������ͼͼ��ʵ���������δָ�����ƣ���Ĭ������ΪMapLayer[index]��ͼ�������Զ�����
	virtual AbstractMapLayer* createMapLayer(AbstractMapHandle* mapHandle, const QString& name = QString()) override;

	// ����ָ����ͼԪ���ͣ������ض���ͼͼԪ����
	virtual AbstractMapItem* createMapItem(MapItemType::Type itemType) override;
};