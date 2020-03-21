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
	// Qualifier: �Ƕ�ת����
	// Parameter: qreal degree
	//************************************
	static qreal degreeToRadians(qreal degree);

	//************************************
	// Method:    radiansToDegree
	// FullName:  Calculator::radiansToDegree
	// Access:    public static 
	// Returns:   qreal
	// Qualifier: ����ת�Ƕ�
	// Parameter: qreal radians
	//************************************
	static qreal radiansToDegree(qreal radians);

	//************************************
	// Method:    azimuth
	// FullName:  Calculator::azimuth
	// Access:    public static 
	// Returns:   qreal
	// Qualifier: ����������γ�ȵ���㺽��0-360�㣩
	// Parameter: QPointF firstPoint�� x Ϊ���ȣ� yΪγ��
	// Parameter: QPointF secondPoint��x Ϊ���ȣ� yΪγ��
	//************************************
	static qreal azimuth(const QPointF &firstPoint, const QPointF &secondPoint);

	//************************************
	// Method:    distance
	// FullName:  Calculator::distance
	// Access:    public static 
	// Returns:   qreal
	// Qualifier: ����������γ�ȵ��������֮��ľ��루��λ km)
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
	// Qualifier: ���ݸ�����㣬��㺽��Ŀ���������ľ��룬�������Բ����Ŀ���ľ�γ�ȣ����ȷ�Χ��-180�� - 180�㣩
	// Parameter: const QPointF & point�� ��㣬x Ϊ���ȣ�y Ϊγ��
	// Parameter: qreal azimuth�������Ŀ���ĺ���
	// Parameter: qreal distance����㵽Ŀ���ľ��루��λ km)
	//************************************
	static QPointF targetPoint(const QPointF &point, qreal azimuth, qreal distance);

	//************************************
	// Method:    �жϵ���Բ��λ�ù�ϵ
	// FullName:  Calculator::checkPointAndCycleRelation
	// Access:    public static 
	// Returns:   bool true ��Բ�� false ��Բ��
	// Qualifier:
	// Parameter: const QPointF & center	Բ��
	// Parameter: double fRadius			�뾶
	// Parameter: const QPointF & point		λ�õ�
	// DataTime:  2018-11-20 10:08:51
	//************************************
	static bool	checkPointAndCycleRelation(const QPointF& center, double fRadius, const QPointF& point);

	//************************************
	// Method:    �жϵ������εĹ�ϵ
	// FullName:  Calculator::checkPointAndSectorRelation
	// Access:    public static 
	// Returns:   bool  true �������� false ����������
	// Qualifier:
	// Parameter: const QPointF & center	Բ��
	// Parameter: double fRadius			�뾶		
	// Parameter: double startAngle			��ʼ��	
	// Parameter: double endAngle			������
	// Parameter: const QPointF & point		λ�õ�
	// DataTime:  2018-11-20 10:13:22
	//************************************
	static bool checkPointAndSectorRelation(const QPointF& center, double fRadius, double startAngle, double endAngle, const QPointF& point);

	//************************************
	// Method:    �жϵ������εĹ�ϵ
	// FullName:  Calculator::checkPointAndSectorRelation
	// Access:    public static 
	// Returns:   bool  true �������� false ����������
	// Qualifier:
	// Parameter: const QPointF & center		Բ��
	// Parameter: double fRadius				�뾶	
	// Parameter: double startAngle				��ʼ��
	// Parameter: double endAngle				������
	// Parameter: double planeAngle				�ɻ�����
	// Parameter: const QPointF & point			λ�õ�
	// DataTime:  2018-12-8 14:11:09
	//************************************
	static bool checkPointAndSectorRelation(const QPointF& center, double fRadius, double startAngle, double endAngle,double planeAngle, const QPointF& point);

    //************************************
    // Method:    ��תӢ��
    // FullName:  Calculator::meterToFoot
    // Access:    public static 
    // Returns:   double Ӣ��
    // Qualifier:
    // Parameter: double meter ��
    // DataTime:  2018-12-13 20:57:22
    //************************************
    static double meterToFoot(double meter);

    //************************************
    // Method:    Ӣ��ת��
    // FullName:  Calculator::meterToFoot
    // Access:    public static 
    // Returns:   double ��
    // Qualifier:
    // Parameter: double foot Ӣ��
    // DataTime:  2018-12-13 20:57:22
    //************************************
    static double footToMeter(double foot);

    //************************************
    // Method:    ǧ��ת����
    // FullName:  Calculator::kmToNMILE
    // Access:    public static 
    // Returns:   double ����
    // Qualifier:
    // Parameter: double km ǧ��
    // DataTime:  2018-12-14 10:00:14
    //************************************
    static double kmToNMILE(double km);

    //************************************
    // Method:    ����תǧ��
    // FullName:  Calculator::nmileToKM
    // Access:    public static 
    // Returns:   double ǧ��
    // Qualifier:
    // Parameter: double nmile ����
    // DataTime:  2018-12-14 10:00:14
    //************************************
    static double nmileToKM(double nmile);

	//************************************
	// Method:    speed
	// FullName:  Calculator::azimuth
	// Access:    public static 
	// Returns:   qreal
	// Qualifier: ����������γ�ȵ�����ٶȣ�km/h��
	// Parameter: QPointF firstPoint�� x Ϊ���ȣ� yΪγ��
	// Parameter: QPointF secondPoint��x Ϊ���ȣ� yΪγ��
	// Parameter: double time����������֮���ʱ�� h
	//************************************
	static double speed(const QPointF &firstPoint, const QPointF &secondPoint, double time);
};