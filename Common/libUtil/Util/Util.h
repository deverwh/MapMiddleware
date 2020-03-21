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
	// Qualifier: 以字符串形式返回文件大小
	// Parameter: quint64 sizeinbyte 文件大小（字节）
	//************************************
	static QString fileSizeString(quint64 sizeinbyte);

    // 分段线性插值(经度，纬度，高度）
    // first: 第一个点
    // last: 插入后的最后一个点
    // count: 插入后的总点数 count >= 2
    static QList<QVector3D> sectionLinearInterpolation(const QVector3D &first, const QVector3D &last, int count);

	//************************************
	// Method:    hz2Py
	// FullName:  Util::hz2Py
	// Access:    public static 
	// Returns:   QString
	// Qualifier: 汉字转拼音（如果是英文，则直接返回），可混合中英文
	// Parameter: const QString & dest  待转的字符串（支持UTF-8 GBK）
	// Parameter: bool duoyin 是否多音字转换
	//************************************
	static QString hz2Py(const QString &dest, bool duoyin = false);

	static QColor color(int index);

    //************************************
    // Method:    LoLaDmsToDec
    // FullName:  Util::LoLaDmsToDec
    // Access:    public static 
    // Returns:   double 10进制经纬度数值
    // Qualifier: 经纬度的度分秒转换为10进制
    // Parameter: int degree[in]  度
    // Parameter: int minute[in]  分
    // Parameter: int second[in]  秒
    //************************************
    static double LoLaDmsToDec(int degree, int minute, int second);

    //************************************
    // Method:    LoLaDmsToDec
    // FullName:  Util::LoLaDmsToDec
    // Access:    public static
    // Returns:   void
    // Qualifier: 经纬度的10进制转换为度分秒
    // Parameter: int& degree[out]  度
    // Parameter: int& minute[out]  分
    // Parameter: int& second[out]  秒
    // Parameter: int decimal[in]   10进制经纬度数值
    //************************************
    static void LoLaDecToDms(int& degree, int& minute, int& second, double decimal);

    //************************************
    // Method:    LoDecToDmsText
    // FullName:  Util::LoLaDecToDmsText
    // Access:    public static
    // Returns:   QString 经度的度分秒字符串
    // Qualifier: 经纬度的10进制转换为度分秒字符串
    // Parameter: int longitude[in]   10进制经度数值
    //************************************
    static QString LoDecToDmsText(double longitude);

    //************************************
    // Method:    LaDecToDmsText
    // FullName:  Util::LoLaDecToDmsText
    // Access:    public static
    // Returns:   QString 纬度的度分秒字符串
    // Qualifier: 经纬度的10进制转换为度分秒字符串
    // Parameter: int latitude[in]   10进制纬度数值
    //************************************
    static QString LaDecToDmsText(double latitude);

    //************************************
    // Method:    LoLaDecToDmsDecText
    // FullName:  Util::LoLaDecToDmsDecText
    // Access:    public static
    // Returns:   QString 经纬度的度分秒字符串
    // Qualifier: 经纬度的10进制转换为度分秒字符串
    // Parameter: int longitude[in]   10进制经度数值
    // Parameter: int latitude[in]    10进制纬度数值
    //************************************
    static QString LoLaDecToDmsText(double longitude, double latitude);

    //************************************
    // Method:    LoLaDecFromDmsDecText
    // FullName:  Util::LoLaDecFromDmsText
    // Access:    public static
    // Returns:   bool 转换是否成功
    // Qualifier: 经纬度的度分秒字符串换为10进制数值
    // Parameter: int decimal[out]                  10进制经纬度数值
    // Parameter: const QString& dmsStr[out]     度分秒字符串
    //************************************
    static bool LoLaDecFromDmsText(double& decimal, const QString& dmsStr);

    //************************************
    // Method:    LoLaDecFromDmsDecText
    // FullName:  Util::LoLaDecFromDmsText
    // Access:    public static
    // Returns:   bool 转换是否成功
    // Qualifier: 经纬度的度分秒字符串换为10进制数值
    // Parameter: int longitude[out]                  10进制经度数值
    // Parameter: int latitude[out]                  10进制纬度数值
    // Parameter: const QString& dmsDecStr[out]     度分秒字符串
    //************************************
    static bool LoLaDecFromDmsText(double& longitude, double& latitude, const QString& dmsStr);

    //************************************
    // Method:    timeToHhmmssStr
    // FullName:  Util::timeToHhmmssStr
    // Access:    public static
    // Returns:   QString 相对时间的时分秒字符串(hh:mm:ss)，小时可超过24小时
    // Qualifier: 相对时间的秒数转为时分秒字符串
    // Parameter: int time[in]  相对时间的秒数
    //************************************
    static QString timeToHhmmssStr(quint64 time);

    //************************************
    // Method:    timeFromHhmmssStr
    // FullName:  Util::timeFromHhmmssStr
    // Access:    public static
    // Returns:   int 相对时间的秒数
    // Qualifier: 相对时间的时分秒字符串转为秒数
    // Parameter: const QString& timeStr[in]  相对时间的时分秒字符串
    //************************************
    static quint64 timeFromHhmmssStr(const QString& timeStr);

    //移动窗口到屏幕的右边
    static void moveToDesktopRight(QWidget* widget);

    //米转为"米/英尺"字符串
    static QString meterToMeterFootStr(double meter);

    //"米/英尺"字符串转为米 
    static bool meterFromMeterFootStr(double& meter, const QString& strMeterFoot);

	// 根据软件逻辑ID获取分系统编号
	static int subSystemCodeFromLogicId(quint32 logicId);
	// 根据软件逻辑ID获取软件ID
	static int softwareIdFromLogicId(quint32 logicId);

	static QString toHex(quint64 number);

	//************************************
	// Method:    timeToSecond
	// FullName:  Util::timeToSecond
	// Access:    public static 
	// Returns:   quint64
	// Qualifier: 返回指定日期时间距离1970年1月1日 0:0:0的秒数
	// Parameter: const QDateTime & dateTime
	//************************************
	static quint64 dateTimeToSecond(const QDateTime &dateTime);

	//************************************
	// Method:    convertToDateTime
	// FullName:  Util::convertToDateTime
	// Access:    public static 
	// Returns:   QDateTime
	// Qualifier: 将距离1970年1月1日 0:0:0的秒数转换为QDateTime
	// Parameter: quint64 second
	//************************************
	static QDateTime secondToDateTime(quint64 second);

	//************************************
	// 方法: colorToARGB
	// 全名: Util::colorToARGB
	// 访控: public static 
	// 返回: int
	// 简介: 将Color转换为ARGB
	// 参数: const QColor & color
	//************************************
	static int colorToARGB(const QColor &color);
};

