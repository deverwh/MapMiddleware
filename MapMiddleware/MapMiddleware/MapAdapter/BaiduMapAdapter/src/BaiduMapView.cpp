#include "BaiduMapView.h"
#include <QtWebChannel>
#include <QtWebEngineWidgets>

BaiduMapView::BaiduMapView(QWidget *parent)
	: QWebEngineView(parent)
{
	QWebChannel *channel = new QWebChannel(this);
	channel->registerObject("bridge", this);
	this->page()->setWebChannel(channel);
	this->settings()->setDefaultTextEncoding("UTF-8");

	QString strMapPath = "http://www.deverat.com/"; // 此地址是我的云服务器，托管了百度的离线地图，可以通过http://www.deverat.com/baidumap访问FTP内容，应该可以下载，注tiles文件很多
	strMapPath += "baidumap/main.html";
	QUrl url(strMapPath);
	this->page()->load(url);
	this->triggerPageAction(QWebEnginePage::Reload, true);

	this->setMouseTracking(true);
}

BaiduMapView::~BaiduMapView()
{
	this->page()->webChannel()->deregisterObject(this);

}

void BaiduMapView::mouseMoved(qreal longitude, qreal latitude)
{
	emit signalMouseMoved(longitude, latitude);
}

