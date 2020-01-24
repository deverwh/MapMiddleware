#include "Calculator.h"
#include <qmath.h>

qreal Calculator::degreeToRadians(qreal degree)
{
	return degree / 180 * M_PI;
}

qreal Calculator::radiansToDegree(qreal radians)
{
	return 180 / M_PI * radians;
}

qreal Calculator::azimuth(const QPointF &firstPoint, const QPointF &secondPoint)
{
	qreal φ1		= degreeToRadians(firstPoint.y());
	qreal φ2		= degreeToRadians(secondPoint.y());
	qreal Δλ		= degreeToRadians(secondPoint.x() - firstPoint.x());
	qreal y			= qSin(Δλ) * qCos(φ2);
	qreal x			= qCos(φ1) * qSin(φ2) - qSin(φ1) * qCos(φ2) * qCos(Δλ);
	qreal degree	= radiansToDegree(qAtan2(y, x));
	return fmod(degree + 360, 360);
}

qreal Calculator::distance(const QPointF &firstPoint, const QPointF &secondPoint)
{
	qreal R			= 6371000;
	qreal φ1		= degreeToRadians(firstPoint.y());
	qreal φ2		= degreeToRadians(secondPoint.y());
	qreal Δφ = degreeToRadians(secondPoint.y() - firstPoint.y());
	qreal Δλ		= degreeToRadians(secondPoint.x() - firstPoint.x());
	qreal a			= qPow(qSin(Δφ / 2), 2) + qCos(φ1) * qCos(φ2) * qPow(qSin(Δλ / 2), 2);
	qreal c			= 2 * qAtan2(qSqrt(a), qSqrt(1 - a));
	qreal d			= R * c;
	return d / 1000;
}

qreal Calculator::distance( double firstlon,  double firstlat,  double secondlon,  double secondlat)
{
    QPointF firstpoint;
    QPointF secondpoint;
    firstpoint.setX(firstlon);
    firstpoint.setY(firstlat);

    secondpoint.setX(secondlon);
    secondpoint.setY(secondlat);

    return distance(firstpoint, secondpoint);
}

QPointF Calculator::targetPoint(const QPointF &point, qreal azimuth, qreal distance)
{
	qreal R			= 6371000;
	qreal υ			= distance * 1000 / R;
	qreal φ1		= degreeToRadians(point.y());
	qreal λ1		= degreeToRadians(point.x());
	qreal θ			= degreeToRadians(azimuth);
	qreal φ2		= qAsin(qSin(φ1) * qCos(υ) + qCos(φ1) * qSin(υ) * qCos(θ));
	qreal λ2		= λ1 + qAtan2(qSin(θ) * qSin(υ) * qCos(φ1), qCos(υ) - qSin(φ1)*qSin(φ2));
	λ2				= fmod((λ2 + 540), 360) - 180;  // 转换为-180 - 180
	QPointF ret;
	ret.setX(radiansToDegree(λ2));
	ret.setY(radiansToDegree(φ2));
	return ret;
}

bool Calculator::checkPointAndCycleRelation(const QPointF& center, double fRadius, const QPointF& point)
{
	bool flg = false;
	do 
	{
		double fDistance = distance(center, point);
		flg = fDistance <= fRadius;//两点之间的距离小于等于 半径 在圆内
	} while (false);
	return flg;
}

bool Calculator::checkPointAndSectorRelation(const QPointF& center, double fRadius, double startAngle, double endAngle, const QPointF& point)
{
	bool flg = false;
	do
	{
		startAngle = (startAngle > 360) ? startAngle - 360 : startAngle;
		endAngle = (endAngle > 360) ? endAngle - 360 : endAngle;

		double fDistance = distance(center, point);//两点间距离
		//距离大于半径 false
		if (fDistance > fRadius)
		{
			break;
		}

		double fAngle = azimuth(center, point);//两点之间夹角

		if (startAngle > endAngle )
		{
			if (fAngle > startAngle && fAngle <= 360)
			{
				flg = true;
				break;
			}
			if (fAngle < endAngle && fAngle >= 0)
			{
				flg = true;
				break;
			}
		}
		else
		{
			if (fAngle >= startAngle && fAngle <= endAngle)//连线于正北方向夹角，在扇形范围内
			{
				flg = true;
			}
		}
				
	} while (false);
	return flg;
}

bool Calculator::checkPointAndSectorRelation(const QPointF& center, double fRadius, double startAngle, double endAngle, double planeAngle, const QPointF& point)
{
	bool flg = false;
	do
	{
		double fDistance = distance(center, point);//两点间距离
		//距离大于半径 false
		if (fDistance > fRadius)
		{
			break;
		}

		double fAngle = azimuth(center, point);//两点之间夹角

		if (0 == startAngle && 360 == endAngle)
		{
			flg = true;
			break;
		}

		double tmpstart = startAngle + planeAngle;
		double tmpend = endAngle + planeAngle;

		if (tmpstart < 360 && tmpend >360)
		{
			if (fAngle >= tmpstart && fAngle <= tmpend)
			{
				flg = true;
				break;
			}
		}

		if (tmpstart > 360 && tmpend > 360)
		{
			tmpstart = (tmpstart > 360) ? tmpstart - 360 : tmpstart;
			tmpend = (tmpend > 360) ? tmpend - 360 : tmpend;

			if (fAngle >= tmpstart && fAngle <= tmpend)
			{
				flg = true;
				break;
			}
		}

		if (tmpstart < 360 && tmpend < 360)
		{
			if (fAngle >= tmpstart && fAngle <= tmpend)
			{
				flg = true;
				break;
			}
		}

	} while (false);
	return flg;
}

//1英尺 = 0.3048米
double Calculator::meterToFoot(double meter)
{
    return meter / 0.3048;
}

double Calculator::footToMeter(double foot)
{
    return foot * 0.3048;
}

//1海里 = 1.852千米
double Calculator::kmToNMILE(double km)
{
    return km / 1.852;
}

double Calculator::nmileToKM(double nmile)
{
    return nmile * 1.852;
}

double Calculator::speed(const QPointF &firstPoint, const QPointF &secondPoint, double time)
{
	auto distance = Calculator::distance(firstPoint, secondPoint);
	if (distance == 0)
	{
		return 0;
	}
	return distance / time;
}
