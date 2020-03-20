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
	if (mapPluginDir.cd(MapMiddlewareDir)) // �л����ض���ͼ���Ŀ¼
	{
		// �л�����ͼ���Ŀ¼
		if (mapPluginDir.cd(MAP_NAME))
		{
			auto configPath = mapPluginDir.absoluteFilePath("config.ini");
			QSettings settings(configPath, QSettings::IniFormat);
			mapServer = settings.value("MapServer", mapServer).toString();
		}
	}
	return mapServer;
}
