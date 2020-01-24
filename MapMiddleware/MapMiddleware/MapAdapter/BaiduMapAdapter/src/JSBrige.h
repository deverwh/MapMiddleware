#pragma once

#include <QObject>

class JSBrige : public QObject
{
	Q_OBJECT

public:

	static QObject *instance();

	JSBrige();
	~JSBrige();

public slots:
	QString getUsers(int);
};
