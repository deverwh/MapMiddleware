/*!
 * \�ļ� MapFactoryLoader.h
 * \���� 2020/01/07 8:39
 *
 * \���� wanghao
 * ��ϵ: wanghao@swiet.com
 *
 * \��� ��ͼ�������������
 *		����
 *
 *
 * \���ļ�¼
*/

#pragma once

#include "Singleton.h"
#include "IMapFactory.h"
#include <QMap>

class QPluginLoader;

class MapFactoryLoader
{
	DEC_SINGLETON(MapFactoryLoader)
public:
	~MapFactoryLoader();

	//************************************
	// ����: mapFactory
	// ȫ��: MapFactoryLoader::mapFactory
	// �ÿ�: public 
	// ����: IMapFactory *
	// ���: ���ؼ��صĵ�ͼ�����ӿ�
	//************************************
	IMapFactory *mapFactory();

private:
	QPluginLoader *m_pluginLoader = nullptr;
	void unloadPlugin();
};