/*!
 * \�ļ� BaiduMapView.h
 * \���� 2020/03/19 21:14
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� �ٶȵ�ͼ����
 *
 *
 * \��¼ 2020/03/19 21:14 �½�
*/

#pragma once

#include <QWebEngineView>

class BaiduMapView : public QWebEngineView
{
	Q_OBJECT

public:
	BaiduMapView(QWidget *parent = Q_NULLPTR);
	~BaiduMapView();

	void addPoint(const QString &poingJson);

signals:
	// JS���͵�Qt
	void signalMouseMoved(qreal longitude, qreal latitude);

	// Qt���͵�JS
	void sendAddPointMessage(const QString &poingJson);

public slots:
	void mouseMoved(qreal, qreal);
};
