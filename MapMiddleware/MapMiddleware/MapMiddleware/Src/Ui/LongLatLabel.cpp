#include "LongLatLabel.h"
#include "ui_LongLatLabel.h"
#include "AbstractMapHandle.h"
#include "Util.h"

LongLatLabel::LongLatLabel(AbstractMapHandle *mapHandle)
	: QWidget(nullptr)
	, m_mapHandle(mapHandle)
{
	ui = new Ui::LongLatLabel();
	ui->setupUi(this);

	this->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
}

LongLatLabel::~LongLatLabel()
{
	delete ui;
}

void LongLatLabel::set(qreal longitude, qreal latitude)
{
	ui->longlatLabel->setText(Util::LoLaDecToDmsText(longitude, latitude));
}
