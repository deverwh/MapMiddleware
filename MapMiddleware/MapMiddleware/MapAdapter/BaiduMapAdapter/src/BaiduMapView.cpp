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

	QString strMapPath = QString("file:///%1").arg(BaiduMapConfig::mapServer());
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
	//��Ҫ���õ�JS�����QString���ݸ���ҳ
	//��Ӧbaidumap.html ��77��
	//���ʵ����QTͨ��C++����JS������QT����ҳ��������
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

