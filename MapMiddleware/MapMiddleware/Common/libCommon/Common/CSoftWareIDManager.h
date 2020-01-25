#ifndef CSOFTWAREIDMANAGER_H
#define CSOFTWAREIDMANAGER_H

#include <QObject>
#include <QMap>

//̨λ��Ϣ
typedef struct st_TableInfo_
{
	QString  strName;
	QString  strId;
	QString  strPluginId;
}stTableInfo;

//�����Ϣ
typedef struct st_SoftInfo_
{
	QString  strName;
	QString  strId;
	QMap<int, stTableInfo> tables;
}stSoftInfo;

//��ϵͳ��Ϣ
typedef struct st_SystemInfo_
{
	QString  strName;
	QString  strId;
	QMap<int, stSoftInfo> softs;
}stSystemInfo;

class CXmlFileParse;

//����߼�ID������
class CSoftWareIDManager : public QObject
{
	Q_OBJECT
public:
	CSoftWareIDManager(QObject *parent = 0);
	~CSoftWareIDManager();

public:
	//���������ļ�
	bool LoadConfig(const QString& strPath);

	//���ݷ�ϵͳ���ƣ���ȡ��ϵͳ���
	QString GetSystemNum(const QString& strSysName);

	//����������ƣ���ȡ��ϵͳ���
	QString GetSystemNumBySoft(const QString& strSoftWareName);

	//����������ƣ���ȡ������
	QString GetSoftWareNum(const QString& strSoftWareName);

	//����������ơ�̨λ���ƣ���ȡ̨λ��š�������
	QString GetTableNum(const QString& strSoftWareName, const QString& strTableName, QString& strPluginId);

	//��ȡ����߼�ID
	QString GetSoftWareLogicNum(const QString& strSoftWareName, const QString& strTableName);

	//���ݷ�ϵͳ��ţ���ȡ��ϵͳ�����������Ϣ��������ơ����������ţ�
	bool GetSoftInfoBySystemNum(const QString& strSysNum, QList<QPair<QString, QString>>& softInfos);

	//���������ţ���ȡ���������̨λ��Ϣ��̨λ���ơ�̨λ������ţ�
	bool GetTableInfoBySoftNum(const QString& strSoftNum, QList<stTableInfo>& tableInfos);

	//���ݷ�ϵͳ��ţ���ȡ��ϵͳ������̨λ��Ϣ��̨λ�������(����߼�Id)�������ţ����Id����
	bool GetPluginIdBySystemNum(const QString& strSysNum, QList<QPair<QString, QString>>& pluginids);
	bool GetPluginIdBySystemNum(const uint& iSysNum, QList<QPair<uint, uint>>& pluginids);

	//��ȡ���ID
	bool GetPluginNumBySoftNum(const QString& strSoftShortNum, QList<int>& pluginNums);
	int GetPluginNumBySoftNum(const QString& strSoftShortNum, const int& iTableNum);
	int GetPluginNumBySoftNum(const QString& strSoftFullNum);
	int GetPluginNumBySoftNum(int softFullNum);

private:
	//�����ݸ��Ĵ洢��ʽ
	void SaveInfoBySelf();


private:
	CXmlFileParse  *m_pXmlParse;

	QString  m_strConfigPath;		//xml�����ļ�·��

	QMap<int, stSystemInfo>	 m_mapSystem;	//��ϵͳmap
	QMap<QString, QString>   m_mapTablePlugin;	//̨λ���������ţ�������
};

#endif // CSOFTWAREIDMANAGER_H
