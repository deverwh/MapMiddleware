#include "BaiduMapView.h"
#include "BaiduMapConfig.h"
#include <QtWebChannel>
#include <QtWebEngineWidgets>
#include <QWebEngineSettings>

BaiduMapView::BaiduMapView(QWidget *parent)
	: QWebEngineView(parent)
{
	QWebChannel *channel = new QWebChannel(this);
	channel->registerObject("bridge", this);
	this->page()->setWebChannel(channel);
	this->settings()->setDefaultTextEncoding("UTF-8");

	QString strMapPath = BaiduMapConfig::mapServer();
	QUrl url(strMapPath);
	this->page()->load(url);
	this->triggerPageAction(QWebEnginePage::Reload, true);

	this->setMouseTracking(true);
}

BaiduMapView::~BaiduMapView()
{
	this->page()->webChannel()->deregisterObject(this);
}

void BaiduMapView::addPoint(const QString &poingJson)
{
	emit sendAddPointMessage(poingJson);
}

void BaiduMapView::removeMapItem(const QString &id)
{
	emit removeOverlay(id);
}

void BaiduMapView::mouseMoved(qreal longitude, qreal latitude)
{
	emit signalMouseMoved(longitude, latitude);
}

