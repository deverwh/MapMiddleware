#include "MapFactoryLoader.h"
#include "MapMiddlewareConfig.h"
#include "Interface_Global.h"
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

	// 读取配置，获取特定地图实例
	QString name = MapMiddlewareConfig::mapName();
	if (name.isEmpty()) return nullptr;

	// 通过Qt插件框架获取地图实例接口
	// 插件目录
	QDir mapPluginDir = QDir(qApp->applicationDirPath());
	if (mapPluginDir.cd(MapMiddlewareDir)) // 切换到特定地图插件目录
	{
		bool isLoaded = false;
		// 遍历插件目录获取特定地图工厂
		for (auto dir : mapPluginDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
		{
			mapPluginDir.cd(dir);
			auto pluginDir = mapPluginDir.absolutePath();

			// 新增PATH搜索路径
			QString pathEnv = qgetenv("PATH");
			if (!pathEnv.contains(pluginDir))
			{
				QByteArray newPath = pathEnv.append(QString(";%1;").arg(mapPluginDir.absolutePath())).toLocal8Bit();
				bool b = qputenv("PATH", newPath);
			}

			// 遍历文件
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
			// 已经加载
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
