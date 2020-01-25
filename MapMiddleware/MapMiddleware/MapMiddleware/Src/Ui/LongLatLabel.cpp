#include "LongLatLabel.h"
#include "ui_LongLatLabel.h"
#include "AbstractMapHandle.h"
#include "Util.h"

LongLatLabel::LongLatLabel(AbstractMapHandle *mapHandle, QWidget *parent /* = nullptr */)
	: QWidget(parent)
	, m_mapHandle(mapHandle)
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

bool LongLatLabel::eventFilter(QObject *object, QEvent *event)
{
	if (object != this) return false;

	switch (event->type())
	{
	case QEvent::Show:
		this->show();
		break;
	case QEvent::Hide:
		this->hide();
		break;
	case QEvent::Paint:
	{
		static QDateTime preDateTime = QDateTime::currentDateTime();
		QDateTime curDateTime = QDateTime::currentDateTime();
		if (preDateTime.msecsTo(curDateTime) > 40)
		{
			// ��������ת��Ϊ��Ļ����
			auto pos = m_mapHandle->mapToGlobal(m_mapHandle->pos());
			this->move(pos.x() + this->width() - this->width(), pos.y() + 2);  // ��γ����ʾ��ǩλ��
		}
	}
		break;
	default:
		break;
	}
	return false;
}
