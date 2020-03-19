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

	QString strMapPath = "http://www.deverat.com/"; // �˵�ַ���ҵ��Ʒ��������й��˰ٶȵ����ߵ�ͼ������ͨ��http://www.deverat.com/baidumap����FTP���ݣ�Ӧ�ÿ������أ�עtiles�ļ��ܶ�
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

void BaiduMapView::addPoint(const QString &poingJson)
{
	QString code = QString("var point = JSON.parse(\"%1\");alert(point);").arg(poingJson);
	this->page()->runJavaScript(code);

	emit sendAddPointMessage(poingJson);
}

void BaiduMapView::mouseMoved(qreal longitude, qreal latitude)
{
	emit signalMouseMoved(longitude, latitude);
}

