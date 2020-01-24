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
	// Returns:   const QString & ���һ�δ�����Ϣ
	// Qualifier: ��ȡ���һ�δ�����Ϣ��עֱ�ӵ��ô˷��������ص���Ϣ����Ч��
	//************************************
	const QString &lastErrorMessage() const { return m_lastErrorMessage; }

protected:
	QString		m_lastErrorMessage;
};