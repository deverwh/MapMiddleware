#include "CSoftWareIDManager.h"
#include "CXmlFileParse.h"
#include "InfoCode.h"

#include <QFile>

CSoftWareIDManager::CSoftWareIDManager(QObject *parent)
	: QObject(parent)
	, m_pXmlParse(NULL)
	, m_strConfigPath("")
{
	m_pXmlParse = new CXmlFileParse;
}

CSoftWareIDManager::~CSoftWareIDManager()
{
	if (m_pXmlParse)
	{
		delete m_pXmlParse;
		m_pXmlParse = NULL;
	}
}

//加载配置文件
bool CSoftWareIDManager::LoadConfig(const QString& strPath)
{
	if (strPath.isEmpty())
		return false;

	QFile file(strPath);
	if (!file.exists())
		return false;

	//不要重复加载
	if (!m_strConfigPath.compare(strPath))
		return true;

	m_strConfigPath = strPath;

	if (m_pXmlParse && m_pXmlParse->Load(strPath))
	{
		//将数据更改存储方式
		SaveInfoBySelf();

		return true;
	}

	return false;
}

//根据分系统名称，获取分系统编号
QString CSoftWareIDManager::GetSystemNum(const QString& strSysName)
{
	QString strRet;
	if (strSysName.isEmpty())
		return strRet;

	QMap<int, stSystemInfo>::const_iterator iter = m_mapSystem.begin();
	while (iter != m_mapSystem.end())
	{
		if (!iter->strName.compare(strSysName))
		{
			strRet = iter->strId;
			break;
		}
		
		++iter;
	}

	return strRet;
}

//根据软件名称，获取分系统编号
QString CSoftWareIDManager::GetSystemNumBySoft(const QString& strSoftWareName)
{
	QString strRet;
	if (strSoftWareName.isEmpty())
		return strRet;

	QMap<int, stSystemInfo>::const_iterator iter = m_mapSystem.begin();
	while (iter != m_mapSystem.end())
	{
		QMap<int, stSoftInfo>::const_iterator softIter = iter->softs.begin();
		while (softIter != iter->softs.end())
		{
			if (!softIter->strName.compare(strSoftWareName))
			{
				strRet = iter->strId;
				break;
			}

			++softIter;
		}

		++iter;
	}

	return strRet;
}

//根据软件名称，获取软件编号
QString CSoftWareIDManager::GetSoftWareNum(const QString& strSoftWareName)
{
	QString strRet;
	if (strSoftWareName.isEmpty())
		return strRet;

	QMap<int, stSystemInfo>::const_iterator iter = m_mapSystem.begin();
	while (iter != m_mapSystem.end())
	{
		QMap<int, stSoftInfo>::const_iterator softIter = iter->softs.begin();
		while (softIter != iter->softs.end())
		{
			if (!softIter->strName.compare(strSoftWareName))
			{
				strRet = softIter->strId;
				break;
			}

			++softIter;
		}

		++iter;
	}

	return strRet;
}

//根据软件名称、台位名称，获取台位编号、插件编号
QString CSoftWareIDManager::GetTableNum(const QString& strSoftWareName, const QString& strTableName, QString& strPluginId)
{
	QString strRet;
	if (strSoftWareName.isEmpty() || strTableName.isEmpty())
		return strRet;

	QMap<int, stSystemInfo>::const_iterator iter = m_mapSystem.begin();
	while (iter != m_mapSystem.end())
	{
		QMap<int, stSoftInfo>::const_iterator softIter = iter->softs.begin();
		while (softIter != iter->softs.end())
		{
			if (!softIter->strName.compare(strSoftWareName))
			{
				QMap<int, stTableInfo>::const_iterator tableIter = softIter->tables.begin();
				while (tableIter != softIter->tables.end())
				{
					if (!tableIter->strName.compare(strTableName))
					{
						strRet = tableIter->strId;
						strPluginId = tableIter->strPluginId;
						break;
					}

					++tableIter;
				}
			}

			++softIter;
		}

		++iter;
	}

	return strRet;
}

//获取软件逻辑ID
QString CSoftWareIDManager::GetSoftWareLogicNum(const QString& strSoftWareName, const QString& strTableName)
{
	QString strRet;

	QString strSysNum = GetSystemNumBySoft(strSoftWareName);
	QString strSoftNum = GetSoftWareNum(strSoftWareName);
	QString strPluginId;
	QString strTableNum = GetTableNum(strSoftWareName, strTableName, strPluginId);

	if (strSysNum.isEmpty() || strSoftNum.isEmpty() || strTableNum.isEmpty())
		return strRet;

	strRet = QString("%1%2%3").arg(strSysNum).arg(strSoftNum.mid(2)).arg(strTableNum.mid(2));

	return strRet;
}

bool CSoftWareIDManager::GetSoftInfoBySystemNum(const QString& strSysNum, QList<QPair<QString, QString>>& softInfos)
{
	if (strSysNum.isEmpty())
		return false;

	QMap<int, stSystemInfo>::const_iterator iter = m_mapSystem.begin();
	while (iter != m_mapSystem.end())
	{
		if (!iter->strId.compare(strSysNum))
		{
			QMap<int, stSoftInfo>::const_iterator softIter = iter->softs.begin();
			while (softIter != iter->softs.end())
			{
				QString strFullNum = QString("%1%2").arg(strSysNum).arg(softIter->strId.mid(2));
				QPair<QString, QString> softInfo(softIter->strName, strFullNum);

				softInfos.push_back(softInfo);

				++softIter;
			}
		}

		++iter;
	}

	return true;
}

bool CSoftWareIDManager::GetTableInfoBySoftNum(const QString& strSoftNum, QList<stTableInfo>& tableInfos)
{
	if (strSoftNum.isEmpty())
		return false;

	QMap<int, stSystemInfo>::const_iterator iter = m_mapSystem.begin();
	while (iter != m_mapSystem.end())
	{
		//确认当前软件属于本分系统
		if (strSoftNum.contains(iter->strId) && strSoftNum.indexOf(iter->strId) == 0)
		{
			QString strSoftShortNum = QString("0x%1").arg(strSoftNum.mid(iter->strId.length()));
			QMap<int, stSoftInfo>::const_iterator softIter = iter->softs.begin();
			while (softIter != iter->softs.end())
			{
				if (!softIter->strId.compare(strSoftShortNum))
				{
					QMap<int, stTableInfo>::const_iterator tableIter = softIter->tables.begin();
					while (tableIter != softIter->tables.end())
					{
						QString strFullNum = QString("%1%2%3")
							.arg(iter->strId)
							.arg(softIter->strId.mid(2))
							.arg(tableIter->strId.mid(2));
						QPair<QString, QString> softInfo(softIter->strName, strFullNum);

						stTableInfo tableInfo;
						tableInfo.strName = tableIter->strName;
						tableInfo.strId = strFullNum;
						tableInfo.strPluginId = tableIter->strPluginId;

						tableInfos.push_back(tableInfo);

						++tableIter;
					}
				}

				++softIter;
			}
		}

		++iter;
	}

	return true;
}

bool CSoftWareIDManager::GetPluginIdBySystemNum(const QString& strSysNum, QList<QPair<QString, QString>>& pluginids)
{
	QList<QPair<QString, QString>> softInfos;
	if (!GetSoftInfoBySystemNum(strSysNum, softInfos))
		return false;

	for (int i = 0; i < softInfos.size(); ++i)
	{
		QString strSoftNum = softInfos.at(i).second;
		QList<stTableInfo> tables;
		GetTableInfoBySoftNum(strSoftNum, tables);
		
		foreach(stTableInfo tableInfo, tables)
		{
			pluginids.push_back(QPair<QString, QString>(tableInfo.strId, tableInfo.strPluginId));
		}
	}

	return true;
}

bool CSoftWareIDManager::GetPluginIdBySystemNum(const uint& iSysNum, QList<QPair<uint, uint>>& pluginids)
{
	if (iSysNum < 1 || iSysNum > 7)
		return false;

	QString strSysNum = QString("0x%1").arg(iSysNum, 4, HEXADECIMAL, QChar('0'));

	QList<QPair<QString, QString>> tableInfos;
	GetPluginIdBySystemNum(strSysNum, tableInfos);

	for (int i = 0; i < tableInfos.size(); ++i)
	{
		bool bOk = false;
		uint tableId = tableInfos.at(i).first.mid(2).toInt(&bOk, HEXADECIMAL);
		uint pluginId = tableInfos.at(i).second.mid(2).toInt(&bOk, HEXADECIMAL);

		pluginids.push_back(QPair<uint, uint>(tableId, pluginId));
	}

	return true;
}

bool CSoftWareIDManager::GetPluginNumBySoftNum(const QString& strSoftShortNum, QList<int>& pluginNums)
{
	if (strSoftShortNum.isEmpty())
		return false;

	QMap<QString, QString>::const_iterator iter = m_mapTablePlugin.begin();
	while (iter != m_mapTablePlugin.end())
	{
		if (iter.key().contains(strSoftShortNum) && iter.key().indexOf(strSoftShortNum) == 0)
		{
			QString strRet = iter.value();
			bool bOk;
			int iPluinNum = strRet.mid(2).toInt(&bOk, HEXADECIMAL);
			pluginNums.push_back(iPluinNum);
		}

		++iter;
	}

	return true;
}

int CSoftWareIDManager::GetPluginNumBySoftNum(const QString& strSoftShortNum, const int& iTableNum)
{
	if (strSoftShortNum.isEmpty() || iTableNum > 10)
		return 0;

	QString strFullNum = QString("%1%2").arg(strSoftShortNum).arg(iTableNum, INFOCODELEN, HEXADECIMAL, QChar('0'));
	
	return GetPluginNumBySoftNum(strFullNum);
}

int CSoftWareIDManager::GetPluginNumBySoftNum(const QString& strSoftFullNum)
{
	int iPluinNum = 0;
	if (strSoftFullNum.isEmpty())
		return iPluinNum;

	QMap<QString, QString>::const_iterator iter = m_mapTablePlugin.find(strSoftFullNum);
	if (iter != m_mapTablePlugin.end())
	{
		QString strRet = iter.value();
		QString strTemp = strRet.mid(2);
		bool bOk;
		iPluinNum = strTemp.toInt(&bOk, HEXADECIMAL);
	}

	return iPluinNum;
}


int CSoftWareIDManager::GetPluginNumBySoftNum(int softFullNum)
{
	QString strSoftFullNum = QString("0x%1").arg(softFullNum, 8, 16, QChar('0'));
	return GetPluginNumBySoftNum(strSoftFullNum);
}

void CSoftWareIDManager::SaveInfoBySelf()
{
	if (m_strConfigPath.isEmpty())
		return;

	if (!m_pXmlParse)
		return;
	
	//分系统
	QString strSys = "./root/system";
	int sysCount = m_pXmlParse->GetNodeSubChildCount(strSys);
	for (int i = 0; i < sysCount; ++i)
	{
		QMap<QString, QString> sysContent;
		m_pXmlParse->GetNodeLevelInfo(strSys, i, sysContent);

		stSystemInfo sysInfo;
		sysInfo.strName = sysContent["name"];
		sysInfo.strId = sysContent["id"];

		//软件
		QString strSoft;
		if (sysCount == 1)
			strSoft = QString("%1/software").arg(strSys);
		else
			strSoft = QString("%1(%2)/software").arg(strSys).arg(i + 1);

		int softCount = m_pXmlParse->GetNodeSubChildCount(strSoft);
		for (int j = 0; j < softCount; ++j)
		{
			QMap<QString, QString> softContent;
			m_pXmlParse->GetNodeLevelInfo(strSoft, j, softContent);

			stSoftInfo softInfo;
			softInfo.strName = softContent["name"];
			softInfo.strId = softContent["id"];

			//台位
			QString strTable;
			if (softCount == 1)
				strTable = QString("%1/table").arg(strSoft);
			else
				strTable = QString("%1(%2)/table").arg(strSoft).arg(j + 1);

			int tableCount = m_pXmlParse->GetNodeSubChildCount(strTable);
			for (int k = 0; k < tableCount; ++k)
			{
				QMap<QString, QString> tableContent;
				m_pXmlParse->GetNodeLevelInfo(strTable, k, tableContent);

				stTableInfo oneTable;
				oneTable.strName = tableContent["name"];
				oneTable.strId = tableContent["id"];
				oneTable.strPluginId = tableContent["value"];

				softInfo.tables.insert(k, oneTable);

				//完整台位编号
				QString strTableFullNum = QString("%1%2%3")
					.arg(sysContent["id"])
					.arg(softContent["id"].mid(2))
					.arg(tableContent["id"].mid(2));

				m_mapTablePlugin.insert(strTableFullNum, tableContent["value"]);
			}

			sysInfo.softs.insert(j, softInfo);
		}

		m_mapSystem.insert(i, sysInfo);
	}
}
