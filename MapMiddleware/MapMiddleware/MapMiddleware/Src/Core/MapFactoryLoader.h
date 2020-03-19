/*!
 * \�ļ� MapFactoryLoader.h
 * \���� 2020/03/19 21:08
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� ��ͼ�������������
 *		����
 *
 * \��¼ 2020/03/19 21:08 �½�
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