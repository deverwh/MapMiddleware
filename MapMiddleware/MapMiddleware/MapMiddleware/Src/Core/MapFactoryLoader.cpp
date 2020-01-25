#include "MapFactoryLoader.h"
#include "MapMiddlewareConfig.h"
#include <QDir>
#include <QCoreApplication>
#include <QPluginLoader>

IMP_SINGLETON(MapFactoryLoader)

MapFactoryLoader::~MapFactoryLoader()
{
	unloadPlugin();
}

IMapFactory * MapFactoryLoader::mapFactory()
{
	static IMapFactory *factory = nullptr;

	if (factory != nullptr) return factory;

	// ��ȡ���ã���ȡ�ض���ͼʵ��
	QString name = MapMiddlewareConfig::mapName();
	if (name.isEmpty()) return nullptr;

	// ͨ��Qt�����ܻ�ȡ��ͼʵ���ӿ�
	// ���Ŀ¼
	QDir mapPluginDir = QDir(qApp->applicationDirPath());
	if (mapPluginDir.cd("MapMiddleware")) // �л����ض���ͼ���Ŀ¼
	{
		bool isLoaded = false;
		// �������Ŀ¼��ȡ�ض���ͼ����
		for (auto dir : mapPluginDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
		{
			mapPluginDir.cd(dir);
			auto pluginDir = mapPluginDir.absolutePath();

			// ����PATH����·��
			QString pathEnv = qgetenv("PATH");
			if (!pathEnv.contains(pluginDir))
			{
				QByteArray newPath = pathEnv.append(QString(";%1;").arg(mapPluginDir.absolutePath())).toLocal8Bit();
				bool b = qputenv("PATH", newPath);
			}

			// �����ļ�
			for (auto fileName : mapPluginDir.entryList(QDir::Files))
			{
				m_pluginLoader = new QPluginLoader(mapPluginDir.absoluteFilePath(fileName));
				bool b = m_pluginLoader->load();
				auto err = m_pluginLoader->errorString();
				QObject *plugin = m_pluginLoader->instance();
				if (plugin)
				{
					factory = qobject_cast<IMapFactory *>(plugin);
					if (0 == factory->mapName().compare(name, Qt::CaseInsensitive))
					{
						isLoaded = true;
						break;
					}
					else
					{
						m_pluginLoader->unload();
						unloadPlugin();
						factory = nullptr;
					}
				}
				else
				{
					m_pluginLoader->unload();
					unloadPlugin();
				}
			}
			// �Ѿ�����
			if (isLoaded)
			{
				break;
			}
			mapPluginDir.cd("..");
		}
	}
	return factory;
}

void MapFactoryLoader::unloadPlugin()
{
	if (m_pluginLoader)
	{
		delete m_pluginLoader;
		m_pluginLoader = nullptr;
	}
}
