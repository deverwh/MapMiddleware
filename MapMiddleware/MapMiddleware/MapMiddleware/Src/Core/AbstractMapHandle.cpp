#include "AbstractMapHandle.h"
#include "LongLatLabel.h"
#include "MapTool.h"
#include <QTimer>
#include <QMouseEvent>
#include <QDateTime>

AbstractMapHandle::AbstractMapHandle(QWidget *parent /*= nullptr*/)
:QWidget(parent)
{
	m_freshTimer = new QTimer(this);
	connect(m_freshTimer, &QTimer::timeout, this, &AbstractMapHandle::onFreshTimerTimeOut);
		
	m_longLatLabel = new LongLatLabel(this);
	m_mapTool = new MapTool(this);

	// 默认是漫游状态
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

void AbstractMapHandle::onFreshTimerTimeOut()
{
	static QDateTime preDateTime = QDateTime::currentDateTime();
	QDateTime curDateTime = QDateTime::currentDateTime();
	if (preDateTime.msecsTo(curDateTime) > 40)
	{
		// 窗口坐标转换为屏幕坐标
		auto pos = mapToGlobal(this->pos());

		m_longLatLabel->move(pos.x() + this->width() - m_longLatLabel->width(), pos.y() + 2);  // 经纬度显示标签位置
		m_mapTool->move(pos.x() + 8, pos.y() + 8);
	}
}

void AbstractMapHandle::showEvent(QShowEvent *event)
{
	m_freshTimer->start(10);
	m_longLatLabel->show();
	m_mapTool->show();
	QWidget::showEvent(event);
}

void AbstractMapHandle::hideEvent(QHideEvent *event)
{
	m_freshTimer->stop();
	m_longLatLabel->hide();
	m_mapTool->hide();
	QWidget::hideEvent(event);
}
