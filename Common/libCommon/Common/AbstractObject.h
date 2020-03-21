#pragma once

#include <QObject>

class AbstractObject : public QObject
{
public:
	AbstractObject(QObject *parent = nullptr) : QObject(parent) {}
	virtual ~AbstractObject() {}

	//************************************
	// Method:    lastErrorMessage
	// FullName:  AbstractObject::lastErrorMessage
	// Access:    public 
	// Returns:   const QString & 最后一次错误信息
	// Qualifier: 获取最后一次错误信息，注直接调用此方法，返回的信息是无效的
	//************************************
	const QString &lastErrorMessage() const { return m_lastErrorMessage; }

protected:
	QString		m_lastErrorMessage;
};