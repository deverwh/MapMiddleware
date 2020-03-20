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
	QString cmd = QString("addPoint(%1)")
		.arg(poingJson);
	//把要调用的JS命令当做QString传递给网页
	//对应baidumap.html 第77行
	//这就实现了QT通过C++调用JS函数，QT向网页传递数据
	this->page()->runJavaScript(cmd);
	//emit sendAddPointMessage(poingJson);
}

void BaiduMapView::removeMapItem(const QString &id)
{
	QString cmd = QString("removeOverlay(\"%1\")")
		.arg(id);
	this->page()->runJavaScript(cmd);
}

void BaiduMapView::mouseMoved(qreal longitude, qreal latitude)
{
	emit signalMouseMoved(longitude, latitude);
}

