
#ifndef _CXMLFILEPARSE_H_
#define _CXMLFILEPARSE_H_

#include <QString>
#include <QMap>
#include <QSet>

class QDomElement;
class QDomNodeList;

//xml文件解析类

class CXmlFileParse
{

public:
    CXmlFileParse();
    virtual ~CXmlFileParse();

public:
	/**
	* @brief:  加载文件
	* @param:  strPath:文件路径
	* @return: 结果，true：成功，false：失败
	*/
	bool Load(const QString& strPath);

	/**
	* @brief:  保存文件
	* @param:  strPath:文件路径
	* @return: 结果，true：成功，false：失败
	*/
	bool Save(const QString& strPath);

	/**
	* @brief:  获取节点的子节点个数
	* @param:  strParentNode:父节点路径
	* @return: 结果，子节点个数
	*/
	int GetOneNodeChildCount(const QString& strParentNode);

	/**
	* @brief:  获取节点信息
	* @param:  strNode:节点路径
	* @param:  index:节点序号，若有多个同名节点，需要先GetOneNodeChildCount获取子节点个数，再循环获取每个子节点数据
	* @param:  record:节点信息
	* @return: 无
	*/
	void GetOneNodeInfo(const QString& strNode, const int& index = 0, QMap<QString, QString>& record = QMap<QString, QString>());


	int GetNodeSubChildCount(const QString& strParentNode);
	//获取给定节点本层信息（属性、文本）
	void GetNodeLevelInfo(const QString& strNode, const int& index = 0, QMap<QString, QString>& record = QMap<QString, QString>());

	/**
	* @brief:  获取所有节点信息
	* @param:  无
	* @return: 所有节点信息
	*/
	QMap<QString, QString>& GetAllNodeInfo();
private:
	/**
	* @brief:  加载指定节点下面的Xml元素
	* @param:  strParentNode:父节点路径
	* @param:  element:Xml节点元素
	* @return: 无
	*/
	void LoadDomElement(const QString& strParentNode, const QDomElement& element);


	/*   bool TryPeekValue(const QString& strPath, QString& strValue);
	   bool TryPeekAttribute(const QString& strPath, const QString& strName, QString& strValue);
	   bool AddValue(const QString& strPath, QString& strValue);
	   bool AddAttribute(const QString& strPath, const QString& strName, QString& strValue);
	   bool RemoveValue(const QString& strPath);
	   bool RemoveAttribute(const QString& strPath, const QString& strName);
	   bool ModifyValue(const QString& strPath, QString& strValue);
	   bool ModifyAttribute(const QString& strPath, const QString& strName, QString& strValue);*/

	/**
	* @brief:  获取需要添加的自定义序号
	* @param:  nodeList:节点列表
	* @param:  indexSet:需要添加自定义序号的节点编号
	* @return: 结果，true：成功，false：失败
	*/
	bool GetAddIndex(const QDomNodeList& nodeList, QSet<int>& indexSet);

protected:
	QMap<QString, QString>      m_mapNodeItems;			//节点数据列表
};

#endif //_CXMLFILEPARSE_H_
