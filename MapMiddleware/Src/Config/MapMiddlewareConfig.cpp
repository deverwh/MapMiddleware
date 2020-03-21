#include "MapMiddlewareConfig.h"
#include "Interface_Global.h"
#include <QDir>
#include <QCoreApplication>
#include <QSettings>

QString MapMiddlewareConfig::mapName()
{
	QString ret = "baidu";

	// ²å¼þÄ¿Â¼
	QDir mapPluginDir = QDir(qApp->applicationDirPath());
	if (mapPluginDir.cd(MapMiddlewareDir))
	{
		QSettings settings(mapPluginDir.absoluteFilePath("config.ini"), QSettings::IniFormat);
		ret = settings.value("MapName").toString().trimmed();
	}
	return ret;
}

