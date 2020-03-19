#include "MainWidget.h"
#include "MapHandle.h"
#include "MapLayer.h"
#include "PointMapItem.h"
//#include "LineMapItem.h"
#include <QGridLayout>
#include <QDebug>
#include <QTimer>
#include <qglobal.h>
#include <QDateTime>

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	auto mapHandle = new MapHandle(this);
	auto mapLayer = new MapLayer(mapHandle);
	mapHandle->addMapLayer(mapLayer);
	auto layerName = mapLayer->getName();
	int index = mapLayer->getIndex();

	QGridLayout *layout = new QGridLayout;
	layout->setMargin(0);
	layout->addWidget(mapHandle, 0, 0);

	this->setLayout(layout);

	qsrand(QDateTime::currentMSecsSinceEpoch());

	connect(mapHandle, &MapHandle::mousePressed, this, [&, mapLayer, mapHandle](qreal longitude, qreal latitude, Qt::MouseButton button)
	{
		/*static int size = 1;

		int r = qrand() % 255;
		int g = qrand() % 255;
		int b = qrand() % 255;

		auto point = new PointMapItem(mapLayer, QPointF(longitude, latitude), size++, QColor(r, g, b));
		mapLayer->addMapItem(point);

		auto line = new LineMapItem(mapLayer, QPointF(longitude, latitude), QPointF(longitude + 1, latitude + 1));
		line->draw();*/
	});
}