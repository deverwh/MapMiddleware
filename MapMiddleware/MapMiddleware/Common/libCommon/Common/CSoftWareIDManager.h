#ifndef CSOFTWAREIDMANAGER_H
#define CSOFTWAREIDMANAGER_H

#include <QObject>
#include <QMap>

//台位信息
typedef struct st_TableInfo_
{
	QString  strName;
	QString  strId;
	QString  strPluginId;
}stTableInfo;

//软件信息
typedef struct st_SoftInfo_
{
	QString  strName;
	QString  strId;
	QMap<int, stTableInfo> tables;
}stSoftInfo;

//分系统信息
typedef struct st_SystemInfo_
{
	QString  strName;
	QString  strId;
	QMap<int, stSoftInfo> softs;
}stSystemInfo;

class CXmlFileParse;

//软件逻辑ID管理器
class CSoftWareIDManager : public QObject
{
	Q_OBJECT
public:
	CSoftWareIDManager(QObject *parent = 0);
	~CSoftWareIDManager();

public:
	//加载配置文件
	bool LoadConfig(const QString& strPath);

	//根据分系统名称，获取分系统编号
	QString GetSystemNum(const QString& strSysName);

	//根据软件名称，获取分系统编号
	QString GetSystemNumBySoft(const QString& strSoftWareName);

	//根据软件名称，获取软件编号
	QString GetSoftWareNum(const QString& strSoftWareName);

	//根据软件名称、台位名称，获取台位编号、插件编号
	QString GetTableNum(const QString& strSoftWareName, const QString& strTableName, QString& strPluginId);

	//获取软件逻辑ID
	QString GetSoftWareLogicNum(const QString& strSoftWareName, const QString& strTableName);

	//根据分系统编号，获取分系统下所有软件信息（软件名称、软件完整编号）
	bool GetSoftInfoBySystemNum(const QString& strSysNum, QList<QPair<QString, QString>>& softInfos);

	//根据软件编号，获取软件下所有台位信息（台位名称、台位完整编号）
	bool GetTableInfoBySoftNum(const QString& strSoftNum, QList<stTableInfo>& tableInfos);

	//根据分系统编号，获取分系统下所有台位信息（台位完整编号(软件逻辑Id)、插件编号（插件Id））
	bool GetPluginIdBySystemNum(const QString& strSysNum, QList<QPair<QString, QString>>& pluginids);
	bool GetPluginIdBySystemNum(const uint& iSysNum, QList<QPair<uint, uint>>& pluginids);

	//获取插件ID
	bool GetPluginNumBySoftNum(const QString& strSoftShortNum, QList<int>& pluginNums);
	int GetPluginNumBySoftNum(const QString& strSoftShortNum, const int& iTableNum);
	int GetPluginNumBySoftNum(const QString& strSoftFullNum);
	int GetPluginNumBySoftNum(int softFullNum);

private:
	//将数据更改存储方式
	void SaveInfoBySelf();


private:
	CXmlFileParse  *m_pXmlParse;

	QString  m_strConfigPath;		//xml配置文件路径

	QMap<int, stSystemInfo>	 m_mapSystem;	//分系统map
	QMap<QString, QString>   m_mapTablePlugin;	//台位软件完整编号，插件编号
};

#endif // CSOFTWAREIDMANAGER_H
