#include "BaiduMapConfig.h"
#include "BaiduMap_Gloable.h"
#include "Interface_Global.h"
#include <QSettings>
#include <QDir>
#include <QCoreApplication>

QString BaiduMapConfig::mapServer()
{
	QString mapServer = "127.0.0.1";
	QDir mapPluginDir = QDir(qApp->applicationDirPath());
	if (mapPluginDir.cd(MapMiddlewareDir)) // 切换到特定地图插件目录
	{
		// 切换到地图插件目录
		if (mapPluginDir.cd(MAP_NAME))
		{
			auto configPath = mapPluginDir.absoluteFilePath("config.ini");
			QSettings settings(configPath, QSettings::IniFormat);
			mapServer = settings.value("MapServer", mapServer).toString();
		}
	}
	return mapServer;
}
