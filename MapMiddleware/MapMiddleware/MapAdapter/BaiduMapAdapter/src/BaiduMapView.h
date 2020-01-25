#pragma once

#include <QWebEngineView>

class BaiduMapView : public QWebEngineView
{
	Q_OBJECT

public:
	BaiduMapView(QWidget *parent = Q_NULLPTR);
	~BaiduMapView();

signals:
	void signalMouseMoved(qreal longitude, qreal latitude);

public slots:
	void mouseMoved(qreal, qreal);
};
