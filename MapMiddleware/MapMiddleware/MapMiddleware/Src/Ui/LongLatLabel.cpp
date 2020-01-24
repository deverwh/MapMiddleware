#include "LongLatLabel.h"
#include "ui_LongLatLabel.h"
#include "Util.h"

LongLatLabel::LongLatLabel(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::LongLatLabel();
	ui->setupUi(this);

	this->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
}

LongLatLabel::~LongLatLabel()
{
	delete ui;
}

void LongLatLabel::set(qreal longitude, qreal latitude)
{
	ui->longlatLabel->setText(Util::LoLaDecToDmsText(longitude, latitude));
}
