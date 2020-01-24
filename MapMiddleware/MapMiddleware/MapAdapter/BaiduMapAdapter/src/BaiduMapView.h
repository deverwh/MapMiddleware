#pragma once

#include <QWebEngineView>

class BaiduMapView : public QWebEngineView
{
	Q_OBJECT

public:
	BaiduMapView(QWidget *parent = Q_NULLPTR);
	~BaiduMapView();
};
