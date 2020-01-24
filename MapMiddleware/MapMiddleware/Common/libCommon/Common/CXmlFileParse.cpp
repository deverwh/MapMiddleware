#include "CXmlFileParse.h"
#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <QDir>

#include <QDebug>

static int count = 0;

CXmlFileParse::CXmlFileParse()
{

}

CXmlFileParse::~CXmlFileParse()
{

}

bool CXmlFileParse::Load(const QString& strPath)
{
	if (strPath.isEmpty())
    {
        return false;
    }

    QDomDocument objDocument;
	QString strError;
    //打开文件
	QFile objFile(strPath);

    if (objFile.open(QIODevice::ReadOnly))
    {
		objDocument.setContent(&objFile, &strError);
        objFile.close();			
    }

	m_mapNodeItems.clear();

	qDebug() << count << "start parse xml nodes";

    //循环递归读取节点
	QDomNodeList objList = objDocument.childNodes();
	for (int i = 0; i < objList.size(); ++i)
	{
		QDomElement item = objList.item(i).toElement();
		if (item.isNull())
		{
			continue;
		}

		QString strTag = QString("./") + item.tagName();

		LoadDomElement(strTag, item);
	}

	qDebug() << count << "end parse xml nodes";

    return true;
}

void CXmlFileParse::LoadDomElement(const QString& strParentNode, const QDomElement& element)
{
	QDomNode node;

	if (element.hasChildNodes())
	{
		//有子节点
		QDomNodeList lst = element.childNodes();

		//若子节点中有节点名字相同，则需要单独添加自定义id，以区别
		QSet<int> indexSet;
		bool bAddIndex = GetAddIndex(lst, indexSet);
		int addIndex = 0;

		for (int i = 0; i < lst.count(); ++i)
		{
			node = lst.item(i);

			switch (node.nodeType())
			{
			case QDomNode::TextNode:
			{
				m_mapNodeItems[strParentNode] = node.nodeValue();

				qDebug() << ++count << "___" << strParentNode << " : " << node.nodeValue();
			}
				break;
			case QDomNode::ElementNode:
			{
				QString tag = strParentNode + "/" + node.nodeName();
				if (bAddIndex && indexSet.contains(i))
				{
					tag.append(QString("(%1)").arg(++addIndex));
				}

				LoadDomElement(tag, node.toElement());
			}
				break;
			default:
				break;
			}
		}
	}

	//节点属性
	{
		QDomNamedNodeMap nnmap = element.attributes();
		for (int i = 0; i != nnmap.count(); ++i)
		{
			node = nnmap.item(i);
			if (QDomNode::AttributeNode != node.nodeType())
			{
				continue;
			}

			QString strKey = strParentNode + "#" + node.nodeName();

			m_mapNodeItems[strKey] = node.nodeValue();
		}
	}

	//空节点
	if (element.text().isEmpty())
	{
		m_mapNodeItems[strParentNode] = QString();
		qDebug() << ++count << "___" << strParentNode << " : empty";
	}
}

bool CXmlFileParse::Save(const QString& strPath)
{
	Q_UNUSED(strPath)

    return true;
}

int CXmlFileParse::GetOneNodeChildCount(const QString& strParentNode)
{
	int iCount = 0;
	if (strParentNode.isEmpty() || m_mapNodeItems.isEmpty())
		return iCount;

	int nodeLevel = strParentNode.count("/");

	QMap<QString, QString>::iterator itr = m_mapNodeItems.begin();
	while (itr != m_mapNodeItems.end())
	{
		QString strKey = itr.key();
		int keyLevel = strKey.count("/");
		if (strKey.contains(strParentNode) && keyLevel == nodeLevel + 1)
		{
			//多个节点时，判断是否为本节点
			if (strKey.contains("("))
			{
				QString strNum = strKey.section("(", 1, 1).section(")", 0, 0);
				if (!strNum.isEmpty())
				{
					if (iCount < strNum.toInt())
						iCount = strNum.toInt();
				}
			}
		}

		++itr;
	}

	return iCount;
}

void CXmlFileParse::GetOneNodeInfo(const QString& strNode, const int& index /*= 0*/, QMap<QString, QString>& record /*= QMap<QString, QString>()*/)
{
	if (strNode.isEmpty() || index < 0 || m_mapNodeItems.isEmpty())
		return;

	int nodeLevel = strNode.count("/");

	//获取本层节点的内容
	QMap<QString, QString>::iterator itr = m_mapNodeItems.begin();
	while (itr != m_mapNodeItems.end())
	{
		QString strKey = itr.key();
		int keyLevel = strKey.count("/");
		if (strKey.contains(strNode) && keyLevel == nodeLevel + 1)
		{
			//多个节点时，判断是否为本节点
			if (strKey.contains("("))
			{
				QString strIndex = QString("(%1)").arg(index + 1);
				int appendIndex = strKey.indexOf(strIndex);
				if (appendIndex > 0)
				{
					strKey = strKey.remove(appendIndex, 3);

					QString strRecordKey = strKey.right(strKey.length() - strNode.length() - 1);

					record.insert(strRecordKey, itr.value());
				}
			}
			else
			{
				QString strRecordKey = strKey.right(strKey.length() - strNode.length() - 1);

				record.insert(strRecordKey, itr.value());
			}
		}

		++itr;
	}
}

int CXmlFileParse::GetNodeSubChildCount(const QString& strParentNode)
{
	int iCount = 0;
	if (strParentNode.isEmpty() || m_mapNodeItems.isEmpty())
		return iCount;

	QMap<QString, QString>::iterator itr = m_mapNodeItems.begin();
	while (itr != m_mapNodeItems.end())
	{
		QString strKey = itr.key();
		if (strKey.contains(strParentNode))
		{
			//多个节点时，判断是否为本节点
			QString strTemp = strKey.right(strKey.length() - strParentNode.length());
			if (strTemp.contains("(") && strTemp.indexOf("(") == 0)
			{
				QString strTmp = strTemp.section("(", 1, 1);
				QString strNum = strTmp.section(")", 0, 0);
				if (!strNum.isEmpty())
				{
					if (iCount < strNum.toInt())
						iCount = strNum.toInt();
				}
			}
			else
				iCount = 1;
		}

		++itr;
	}

	return iCount;
}

void CXmlFileParse::GetNodeLevelInfo(const QString& strNode, const int& index /*= 0*/, QMap<QString, QString>& record /*= QMap<QString, QString>()*/)
{
	if (strNode.isEmpty() || index < 0 || m_mapNodeItems.isEmpty())
		return;

	int nodeLevel = strNode.count("/");
	int iCount = GetNodeSubChildCount(strNode);
	QString strCurNode;
	if (iCount == 1)
		strCurNode = strNode;
	else
		strCurNode = QString("%1(%2)").arg(strNode).arg(index + 1);

	//获取本层节点的内容
	QMap<QString, QString>::iterator itr = m_mapNodeItems.begin();
	while (itr != m_mapNodeItems.end())
	{
		QString strKey = itr.key();
		int keyLevel = strKey.count("/");
		if (strKey.contains(strCurNode))
		{
			QString strTemp = strKey.right(strKey.length() - strCurNode.length());
			if (strTemp.indexOf("#") == 0)
			{
				//属性
				QString strRecordKey = strTemp.remove(0, 1);

				record.insert(strRecordKey, itr.value());
			}
			else
			{
				/*if (keyLevel != nodeLevel + 1 || strTemp.contains("#"))
				{
				++itr;
				continue;
				}
				*/
				if (strTemp.isEmpty())
				{
					QString strRecordKey = "value";

					record.insert(strRecordKey, itr.value());
				}
			}
		}

		++itr;
	}
}

QMap<QString, QString>& CXmlFileParse::GetAllNodeInfo()
{
	return m_mapNodeItems;
}

//bool CXmlFileParse::TryPeekValue(const QString& strPath, QString& strValue)
//{
//    strValue.clear();
//
//    QString strKey = QString("./") + strPath;
//
//    if (m_mapNodeItems.find(strKey) != m_mapNodeItems.end())
//    {
//        strValue = m_mapNodeItems[strKey];        
//    }
//
//    return !strValue.isEmpty();
//}
//
//bool CXmlFileParse::TryPeekAttribute(const QString& strPath, const QString& strName, QString& strValue)
//{
//	strValue.clear();
//
//	QString strKey = QString("./") + strPath + QString("#") + strName;
//
//	if (m_mapNodeItems.find(strKey) != m_mapNodeItems.end())
//	{
//		strValue = m_mapNodeItems[strKey];		
//	}
//
//    return !strValue.isEmpty();
//}
//
//bool CXmlFileParse::AddValue(const QString& strPath, QString& strValue)
//{
//	bool bRet = false;
//
//	QString strKey = QString("./") + strPath;
//
//	if (m_mapNodeItems.find(strKey) == m_mapNodeItems.end())
//	{
//		m_mapNodeItems[strKey] = strValue;
//
//		bRet = true;
//	}
//
//	return bRet;
//}
//
//bool CXmlFileParse::AddAttribute(const QString& strPath, const QString& strName, QString& strValue)
//{
//	bool bRet = false;
//
//	QString strKey = QString("./") + strPath + QString("#") + strName;
//
//	if (m_mapNodeItems.find(strKey) == m_mapNodeItems.end())
//	{
//		m_mapNodeItems[strKey] = strValue;
//
//		bRet = true;
//	}
//
//	return bRet;
//}
//
//bool CXmlFileParse::RemoveValue(const QString& strPath)
//{
//	bool bRet = false;
//
//	QString strKey = QString("./") + strPath;
//
//	if (m_mapNodeItems.find(strKey) != m_mapNodeItems.end())
//	{
//		m_mapNodeItems.remove(strKey);
//
//		bRet = true;
//	}
//
//	//移除与该节点相关的所有节点
//	QMap<QString, QString> mapTemp(m_mapNodeItems);
//
//	for (QMap<QString, QString>::iterator iter = mapTemp.begin(); iter != mapTemp.end(); ++iter)
//	{
//		if (iter.key().contains(strKey, Qt::CaseInsensitive))
//		{
//			m_mapNodeItems.remove(iter.key());
//		}
//	}
//
//
//	return bRet;
//}
//
//bool CXmlFileParse::RemoveAttribute(const QString& strPath, const QString& strName)
//{
//	bool bRet = false;
//
//	QString strKey = QString("./") + strPath + QString("#") + strName;
//
//	if (m_mapNodeItems.find(strKey) != m_mapNodeItems.end())
//	{
//		m_mapNodeItems.remove(strKey);
//
//		bRet = true;
//	}
//
//	return bRet;
//}
//
//bool CXmlFileParse::ModifyValue(const QString& strPath, QString& strValue)
//{
//	bool bRet = false;
//
//	QString strKey = QString("./") + strPath;
//
//	if (m_mapNodeItems.find(strKey) != m_mapNodeItems.end())
//	{
//		m_mapNodeItems[strKey] = strValue;
//
//		bRet = true;
//	}
//
//	return bRet;
//}
//
//bool CXmlFileParse::ModifyAttribute(const QString& strPath, const QString& strName, QString& strValue)
//{
//	bool bRet = false;
//
//	QString strKey = QString("./") + strPath + QString("#") + strName;
//
//	if (m_mapNodeItems.find(strKey) != m_mapNodeItems.end())
//	{
//		m_mapNodeItems[strKey] = strValue;
//
//		bRet = true;
//	}
//
//	return bRet;
//}

bool CXmlFileParse::GetAddIndex(const QDomNodeList& nodeList, QSet<int>& indexSet)
{
	bool bRet = false;
	indexSet.clear();

	int iNodeCount = nodeList.size();
	for (int i = 0; i < iNodeCount; ++i)
	{
		QDomNode iNode = nodeList.item(i);
		for (int j = i + 1; j < iNodeCount; ++j)
		{
			QDomNode jNode = nodeList.item(j);
			if (iNode.nodeName() == jNode.nodeName())
			{
				bRet = true;
				indexSet.insert(i);
				indexSet.insert(j);
			}
		}
	}

	return bRet;
}
