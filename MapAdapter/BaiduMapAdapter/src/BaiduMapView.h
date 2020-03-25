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

	void zoomIn();
	void zoomOut();

	void addPoint(const QString &poingJson);

	void removeMapItem(const QString &id);

signals:
	// JS发送到Qt
	void signalMouseMoved(qreal longitude, qreal latitude);

	// Qt发送到JS
	void sendAddPointMessage(const QString &poingJson);
	void removeOverlay(const QString &id);

public slots:
	void mouseMoved(qreal, qreal);
};
