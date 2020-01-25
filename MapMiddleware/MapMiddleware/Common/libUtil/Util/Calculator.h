#pragma once

#include <QPointF>

class Calculator
{
public:
	//************************************
	// Method:    degreeToRadians
	// FullName:  Calculator::degreeToRadians
	// Access:    public static 
	// Returns:   qreal
	// Qualifier: 角度转弧度
	// Parameter: qreal degree
	//************************************
	static qreal degreeToRadians(qreal degree);

	//************************************
	// Method:    radiansToDegree
	// FullName:  Calculator::radiansToDegree
	// Access:    public static 
	// Returns:   qreal
	// Qualifier: 弧度转角度
	// Parameter: qreal radians
	//************************************
	static qreal radiansToDegree(qreal radians);

	//************************************
	// Method:    azimuth
	// FullName:  Calculator::azimuth
	// Access:    public static 
	// Returns:   qreal
	// Qualifier: 根据两个经纬度点计算航向（0-360°）
	// Parameter: QPointF firstPoint， x 为经度， y为纬度
	// Parameter: QPointF secondPoint，x 为经度， y为纬度
	//************************************
	static qreal azimuth(const QPointF &firstPoint, const QPointF &secondPoint);

	//************************************
	// Method:    distance
	// FullName:  Calculator::distance
	// Access:    public static 
	// Returns:   qreal
	// Qualifier: 根据两个经纬度点计算两点之间的距离（单位 km)
	// Parameter: const QPointF & firstPoint
	// Parameter: const QPointF & secondPoint
	//************************************
	static qreal distance(const QPointF &firstPoint, const QPointF &secondPoint);

    static qreal distance( double firstlon,  double firstlat,  double secondlon, double secondlat );

	//************************************
	// Method:    targetPoint
	// FullName:  Calculator::targetPoint
	// Access:    public static 
	// Returns:   QT_NAMESPACE::QPointF
	// Qualifier: 根据给定起点，起点航向，目标点距离起点的距离，计算出大圆周上目标点的经纬度（经度范围：-180° - 180°）
	// Parameter: const QPointF & point， 起点，x 为经度，y 为纬度
	// Parameter: qreal azimuth，起点与目标点的航向
	// Parameter: qreal distance，起点到目标点的距离（单位 km)
	//************************************
	static QPointF targetPoint(const QPointF &point, qreal azimuth, qreal distance);

	//************************************
	// Method:    判断点与圆的位置关系
	// FullName:  Calculator::checkPointAndCycleRelation
	// Access:    public static 
	// Returns:   bool true 在圆内 false 在圆外
	// Qualifier:
	// Parameter: const QPointF & center	圆心
	// Parameter: double fRadius			半径
	// Parameter: const QPointF & point		位置点
	// DataTime:  2018-11-20 10:08:51
	//************************************
	static bool	checkPointAndCycleRelation(const QPointF& center, double fRadius, const QPointF& point);

	//************************************
	// Method:    判断点于扇形的关系
	// FullName:  Calculator::checkPointAndSectorRelation
	// Access:    public static 
	// Returns:   bool  true 在扇形内 false 在在扇形外
	// Qualifier:
	// Parameter: const QPointF & center	圆心
	// Parameter: double fRadius			半径		
	// Parameter: double startAngle			起始角	
	// Parameter: double endAngle			结束角
	// Parameter: const QPointF & point		位置点
	// DataTime:  2018-11-20 10:13:22
	//************************************
	static bool checkPointAndSectorRelation(const QPointF& center, double fRadius, double startAngle, double endAngle, const QPointF& point);

	//************************************
	// Method:    判断点于扇形的关系
	// FullName:  Calculator::checkPointAndSectorRelation
	// Access:    public static 
	// Returns:   bool  true 在扇形内 false 在在扇形外
	// Qualifier:
	// Parameter: const QPointF & center		圆心
	// Parameter: double fRadius				半径	
	// Parameter: double startAngle				起始角
	// Parameter: double endAngle				结束角
	// Parameter: double planeAngle				飞机航向
	// Parameter: const QPointF & point			位置点
	// DataTime:  2018-12-8 14:11:09
	//************************************
	static bool checkPointAndSectorRelation(const QPointF& center, double fRadius, double startAngle, double endAngle,double planeAngle, const QPointF& point);

    //************************************
    // Method:    米转英尺
    // FullName:  Calculator::meterToFoot
    // Access:    public static 
    // Returns:   double 英尺
    // Qualifier:
    // Parameter: double meter 米
    // DataTime:  2018-12-13 20:57:22
    //************************************
    static double meterToFoot(double meter);

    //************************************
    // Method:    英尺转米
    // FullName:  Calculator::meterToFoot
    // Access:    public static 
    // Returns:   double 米
    // Qualifier:
    // Parameter: double foot 英尺
    // DataTime:  2018-12-13 20:57:22
    //************************************
    static double footToMeter(double foot);

    //************************************
    // Method:    千米转海里
    // FullName:  Calculator::kmToNMILE
    // Access:    public static 
    // Returns:   double 海里
    // Qualifier:
    // Parameter: double km 千米
    // DataTime:  2018-12-14 10:00:14
    //************************************
    static double kmToNMILE(double km);

    //************************************
    // Method:    海里转千米
    // FullName:  Calculator::nmileToKM
    // Access:    public static 
    // Returns:   double 千米
    // Qualifier:
    // Parameter: double nmile 海里
    // DataTime:  2018-12-14 10:00:14
    //************************************
    static double nmileToKM(double nmile);

	//************************************
	// Method:    speed
	// FullName:  Calculator::azimuth
	// Access:    public static 
	// Returns:   qreal
	// Qualifier: 根据两个经纬度点计算速度（km/h）
	// Parameter: QPointF firstPoint， x 为经度， y为纬度
	// Parameter: QPointF secondPoint，x 为经度， y为纬度
	// Parameter: double time，两个航点之间的时间 h
	//************************************
	static double speed(const QPointF &firstPoint, const QPointF &secondPoint, double time);
};