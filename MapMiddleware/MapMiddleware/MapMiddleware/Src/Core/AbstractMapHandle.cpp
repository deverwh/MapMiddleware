#include "AbstractMapHandle.h"
#include "LongLatLabel.h"
#include "MapTool.h"
#include <QMouseEvent>
#include <QDateTime>

AbstractMapHandle::AbstractMapHandle(QWidget *parent /*= nullptr*/)
:QWidget(parent)
{
	this->setMouseTracking(true);

	m_longLatLabel = new LongLatLabel(this);
	m_mapTool = new MapTool(this);

	this->installEventFilter(m_longLatLabel);
	
	// Ĭ��������״̬
	this->setMapState(MapHandleState::Roaming);

	connect(this, &AbstractMapHandle::mouseMoved, this, [&](qreal longitude, qreal latitude)
	{
		m_longLatLabel->set(longitude, latitude);
	});
}

AbstractMapHandle::~AbstractMapHandle()
{

}

void AbstractMapHandle::setMapState(MapHandleState::State state)
{
	if (m_mapState != state)
	{
		m_mapState = state;
		switch (m_mapState)
		{
		case MapHandleState::Arrow:
			this->setCursor(Qt::ArrowCursor);
			break;
		case MapHandleState::Roaming:
			this->setCursor(Qt::OpenHandCursor);
			break;
		case MapHandleState::ZoomIn:
			this->setCursor(QCursor(QPixmap(":/images/Map_Zoomin.png")));
			break;
		case MapHandleState::ZoonOut:
			this->setCursor(QCursor(QPixmap(":/images/Map_Zoomout.png")));
			break;
		default:
			break;
		}
		emit mapStateChanged(m_mapState);
	}
}

void AbstractMapHandle::paintEvent(QPaintEvent *event)
{
	static QDateTime preDateTime = QDateTime::currentDateTime();
	QDateTime curDateTime = QDateTime::currentDateTime();
	if (preDateTime.msecsTo(curDateTime) > 40)
	{
		// ��������ת��Ϊ��Ļ����
		auto pos = mapToGlobal(this->pos());

		m_mapTool->move(pos.x() + 8, pos.y() + 8);
	}

	QWidget::paintEvent(event);
}

void AbstractMapHandle::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::RightButton)
	{
		if (m_mapState == MapHandleState::Roaming)		// ���������ר�⣬�Ҽ����л�Ϊ��ͷ״̬
		{
			this->setMapState(MapHandleState::Arrow);
		}
	}
	else if (event->button() == Qt::LeftButton)
	{
		if (m_mapState == MapHandleState::Roaming)
		{
			this->setCursor(Qt::ClosedHandCursor); // ����Ϊץ��ͼ���
		}
	}

	// ���þ�γ������
	//m_longLatLabel->set(mapPos.x(), mapPos.y());

	//emit mousePressed(mapPos.x(), mapPos.y(), event->button());
	QWidget::mousePressEvent(event);
}

void AbstractMapHandle::mouseMoveEvent(QMouseEvent *event)
{
	static QDateTime preDateTime = QDateTime::currentDateTime();
	QDateTime curDateTime = QDateTime::currentDateTime();
// 	if (preDateTime.msecsTo(curDateTime) > 40)
// 	{
// 		// ��Ļ����ת��Ϊ��ͼ����
// 		auto mapPos = screenPosToMapPos(event->pos());
// 		// ���þ�γ������
// 		m_longLatLabel->set(mapPos.x(), mapPos.y());
// 
// 		emit mouseMoved(mapPos.x(), mapPos.y());
// 	}
	QWidget::mouseMoveEvent(event);
}

void AbstractMapHandle::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		if (m_mapState == MapHandleState::Roaming)
		{
			this->setCursor(Qt::OpenHandCursor);
		}
	}

// 	��Ļ����ת��Ϊ��ͼ����
// 		auto mapPos = screenPosToMapPos(event->pos());
// 		// ���þ�γ������
// 		m_longLatLabel->set(mapPos.x(), mapPos.y());
// 	
// 		emit mouseReleased(mapPos.x(), mapPos.y(), event->button());

	QWidget::mouseReleaseEvent(event);
}

void AbstractMapHandle::showEvent(QShowEvent *event)
{
	m_mapTool->show();
	QWidget::showEvent(event);
}

void AbstractMapHandle::hideEvent(QHideEvent *event)
{
	m_mapTool->hide();
	QWidget::hideEvent(event);
}
