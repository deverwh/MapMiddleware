/*!
 * \文件 BaiduMapView.h
 * \日期 2020/03/19 21:14
 *
 * \作者 deverwh
 * 	联系 deverwh@outlook.com
 *
 * \简介 百度地图窗口
 *
 *
 * \记录 2020/03/19 21:14 新建
*/

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
