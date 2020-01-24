#pragma once

#include <QString>
#include <QList>
#include <QVector3D>
#include <QColor>
#include <QtCore>

class Util
{
public:
    static QByteArray str2ByteArray(const QString &str, int destSize);
	static QString curTimeStr();
	static QString tr(const char *str);

	static QString GBK2UTF8(const std::string &inStr);
	static QString UTF82GBK(const std::string &inStr);

	static QTime secToTime(int second);

	//************************************
	// Method:    fileSizeString
	// FullName:  Util::fileSizeString
	// Access:    public static 
	// Returns:   QString
	// Qualifier: ���ַ�����ʽ�����ļ���С
	// Parameter: quint64 sizeinbyte �ļ���С���ֽڣ�
	//************************************
	static QString fileSizeString(quint64 sizeinbyte);

    // �ֶ����Բ�ֵ(���ȣ�γ�ȣ��߶ȣ�
    // first: ��һ����
    // last: ���������һ����
    // count: �������ܵ��� count >= 2
    static QList<QVector3D> sectionLinearInterpolation(const QVector3D &first, const QVector3D &last, int count);

	//************************************
	// Method:    hz2Py
	// FullName:  Util::hz2Py
	// Access:    public static 
	// Returns:   QString
	// Qualifier: ����תƴ���������Ӣ�ģ���ֱ�ӷ��أ����ɻ����Ӣ��
	// Parameter: const QString & dest  ��ת���ַ�����֧��UTF-8 GBK��
	// Parameter: bool duoyin �Ƿ������ת��
	//************************************
	static QString hz2Py(const QString &dest, bool duoyin = false);

	static QColor color(int index);

    //************************************
    // Method:    LoLaDmsToDec
    // FullName:  Util::LoLaDmsToDec
    // Access:    public static 
    // Returns:   double 10���ƾ�γ����ֵ
    // Qualifier: ��γ�ȵĶȷ���ת��Ϊ10����
    // Parameter: int degree[in]  ��
    // Parameter: int minute[in]  ��
    // Parameter: int second[in]  ��
    //************************************
    static double LoLaDmsToDec(int degree, int minute, int second);

    //************************************
    // Method:    LoLaDmsToDec
    // FullName:  Util::LoLaDmsToDec
    // Access:    public static
    // Returns:   void
    // Qualifier: ��γ�ȵ�10����ת��Ϊ�ȷ���
    // Parameter: int& degree[out]  ��
    // Parameter: int& minute[out]  ��
    // Parameter: int& second[out]  ��
    // Parameter: int decimal[in]   10���ƾ�γ����ֵ
    //************************************
    static void LoLaDecToDms(int& degree, int& minute, int& second, double decimal);

    //************************************
    // Method:    LoDecToDmsText
    // FullName:  Util::LoLaDecToDmsText
    // Access:    public static
    // Returns:   QString ���ȵĶȷ����ַ���
    // Qualifier: ��γ�ȵ�10����ת��Ϊ�ȷ����ַ���
    // Parameter: int longitude[in]   10���ƾ�����ֵ
    //************************************
    static QString LoDecToDmsText(double longitude);

    //************************************
    // Method:    LaDecToDmsText
    // FullName:  Util::LoLaDecToDmsText
    // Access:    public static
    // Returns:   QString γ�ȵĶȷ����ַ���
    // Qualifier: ��γ�ȵ�10����ת��Ϊ�ȷ����ַ���
    // Parameter: int latitude[in]   10����γ����ֵ
    //************************************
    static QString LaDecToDmsText(double latitude);

    //************************************
    // Method:    LoLaDecToDmsDecText
    // FullName:  Util::LoLaDecToDmsDecText
    // Access:    public static
    // Returns:   QString ��γ�ȵĶȷ����ַ���
    // Qualifier: ��γ�ȵ�10����ת��Ϊ�ȷ����ַ���
    // Parameter: int longitude[in]   10���ƾ�����ֵ
    // Parameter: int latitude[in]    10����γ����ֵ
    //************************************
    static QString LoLaDecToDmsText(double longitude, double latitude);

    //************************************
    // Method:    LoLaDecFromDmsDecText
    // FullName:  Util::LoLaDecFromDmsText
    // Access:    public static
    // Returns:   bool ת���Ƿ�ɹ�
    // Qualifier: ��γ�ȵĶȷ����ַ�����Ϊ10������ֵ
    // Parameter: int decimal[out]                  10���ƾ�γ����ֵ
    // Parameter: const QString& dmsStr[out]     �ȷ����ַ���
    //************************************
    static bool LoLaDecFromDmsText(double& decimal, const QString& dmsStr);

    //************************************
    // Method:    LoLaDecFromDmsDecText
    // FullName:  Util::LoLaDecFromDmsText
    // Access:    public static
    // Returns:   bool ת���Ƿ�ɹ�
    // Qualifier: ��γ�ȵĶȷ����ַ�����Ϊ10������ֵ
    // Parameter: int longitude[out]                  10���ƾ�����ֵ
    // Parameter: int latitude[out]                  10����γ����ֵ
    // Parameter: const QString& dmsDecStr[out]     �ȷ����ַ���
    //************************************
    static bool LoLaDecFromDmsText(double& longitude, double& latitude, const QString& dmsStr);

    //************************************
    // Method:    timeToHhmmssStr
    // FullName:  Util::timeToHhmmssStr
    // Access:    public static
    // Returns:   QString ���ʱ���ʱ�����ַ���(hh:mm:ss)��Сʱ�ɳ���24Сʱ
    // Qualifier: ���ʱ�������תΪʱ�����ַ���
    // Parameter: int time[in]  ���ʱ�������
    //************************************
    static QString timeToHhmmssStr(quint64 time);

    //************************************
    // Method:    timeFromHhmmssStr
    // FullName:  Util::timeFromHhmmssStr
    // Access:    public static
    // Returns:   int ���ʱ�������
    // Qualifier: ���ʱ���ʱ�����ַ���תΪ����
    // Parameter: const QString& timeStr[in]  ���ʱ���ʱ�����ַ���
    //************************************
    static quint64 timeFromHhmmssStr(const QString& timeStr);

    //�ƶ����ڵ���Ļ���ұ�
    static void moveToDesktopRight(QWidget* widget);

    //��תΪ"��/Ӣ��"�ַ���
    static QString meterToMeterFootStr(double meter);

    //"��/Ӣ��"�ַ���תΪ�� 
    static bool meterFromMeterFootStr(double& meter, const QString& strMeterFoot);

	// ��������߼�ID��ȡ��ϵͳ���
	static int subSystemCodeFromLogicId(quint32 logicId);
	// ��������߼�ID��ȡ���ID
	static int softwareIdFromLogicId(quint32 logicId);

	static QString toHex(quint64 number);

	//************************************
	// Method:    timeToSecond
	// FullName:  Util::timeToSecond
	// Access:    public static 
	// Returns:   quint64
	// Qualifier: ����ָ������ʱ�����1970��1��1�� 0:0:0������
	// Parameter: const QDateTime & dateTime
	//************************************
	static quint64 dateTimeToSecond(const QDateTime &dateTime);

	//************************************
	// Method:    convertToDateTime
	// FullName:  Util::convertToDateTime
	// Access:    public static 
	// Returns:   QDateTime
	// Qualifier: ������1970��1��1�� 0:0:0������ת��ΪQDateTime
	// Parameter: quint64 second
	//************************************
	static QDateTime secondToDateTime(quint64 second);

	//************************************
	// ����: colorToARGB
	// ȫ��: Util::colorToARGB
	// �ÿ�: public static 
	// ����: int
	// ���: ��Colorת��ΪARGB
	// ����: const QColor & color
	//************************************
	static int colorToARGB(const QColor &color);
};

