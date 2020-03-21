#include "MainWidget.h"
#include <QtWidgets/QApplication>
#include <qtwebengineglobal.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtWebEngine::initialize();
	MainWidget w;
	w.show();
	return a.exec();
}
