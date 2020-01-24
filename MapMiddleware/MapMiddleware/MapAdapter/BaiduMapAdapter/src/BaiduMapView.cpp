#include "BaiduMapView.h"
#include "JSBrige.h"
#include <QtWebChannel>
#include <QtWebEngineWidgets>

BaiduMapView::BaiduMapView(QWidget *parent)
	: QWebEngineView(parent)
{
	QWebChannel *channel = new QWebChannel(this);
	channel->registerObject("bridge", JSBrige::instance());
	this->page()->setWebChannel(channel);

	this->settings()->setDefaultTextEncoding("UTF-8");

	QString strMapPath = "http://127.0.0.1/";
	strMapPath += "baidumap/main.html";
	QUrl url(strMapPath);
	this->page()->load(url);
}

BaiduMapView::~BaiduMapView()
{

}

