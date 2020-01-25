#include "Util.h"
#include <QDateTime>
#include <QHostAddress>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QTextCodec>
#include <QApplication>
#include <QDesktopWidget>
#include "Han2Py.h"
#include "Calculator.h"
#include <Windows.h>

QByteArray Util::str2ByteArray(const QString &str, int destSize)
{
    QByteArray ret(destSize, '0');
    memcpy(ret.data(), str.toStdString().c_str(), str.size());
    return ret;
}

QString Util::curTimeStr()
{
	auto curTime = QTime::currentTime();
	return curTime.toString("hh:mm:ss ");
}

QString Util::tr(const char *str)
{
	auto codec = QTextCodec::codecForName("gb2312");
	if (codec != nullptr)
	{
		return codec->toUnicode(str);
	}
	else
	{
		return str;
	}
}

QString Util::GBK2UTF8(const std::string &inStr)
{
	int n = ::MultiByteToWideChar(CP_ACP, 0, inStr.c_str(), -1, nullptr, 0);
	WCHAR *str1 = new WCHAR[n];
	::MultiByteToWideChar(CP_ACP, 0, inStr.c_str(), -1, str1, n);
	n = ::WideCharToMultiByte(CP_UTF8, 0, str1, -1, nullptr, 0, nullptr, nullptr);
	char *str2 = new char[n];
	int nlen = ::WideCharToMultiByte(CP_UTF8, 0, str1, -1, str2, n, nullptr, nullptr);
	QString ret = str2;
	delete [] str1;
	str1 = nullptr;
	delete [] str2;
	str2 = nullptr;
	return ret;
}

QString Util::UTF82GBK(const std::string &inStr)
{
	int n = ::MultiByteToWideChar(CP_UTF8, 0, inStr.c_str(), -1, NULL, 0);
	WCHAR* wszANSI = new WCHAR[n];
	::MultiByteToWideChar(CP_UTF8, 0, inStr.c_str(), -1, wszANSI, n);
	n = ::WideCharToMultiByte(CP_ACP, 0, wszANSI, -1, NULL, 0, NULL, NULL);
	char* szANSI = new char[n];
	int nlen = ::WideCharToMultiByte(CP_ACP, 0, wszANSI, -1, szANSI, n, NULL, NULL);
	QString ret = szANSI;
	delete[] wszANSI;
	wszANSI = nullptr;
	delete[] szANSI;
	szANSI = nullptr;
	return ret;
}

QTime Util::secToTime(int second)
{
	QTime time(0, 0);
	return time.addSecs(second);
}

QString Util::fileSizeString(quint64 sizeinbyte)
{
	quint64 kb = (quint64)1024;
	quint64 mb = (quint64)1024 * 1024;
	quint64 gb = (quint64)1024 * 1024 * 1024;
	quint64 tb = (quint64)1024 * 1024 * 1024 * 1024;

	if (sizeinbyte > kb && sizeinbyte <= mb){
		return (QString("%1 KB").arg((double)sizeinbyte / 1024, 10, 'f', 2));
	} else if (sizeinbyte > mb && sizeinbyte <= gb){
		return (QString("%1 MB").arg((double)sizeinbyte / (1024 * 1024), 10, 'f', 2));
	} else if (sizeinbyte > gb && sizeinbyte <= tb){
		return (QString("%1 GB").arg((double)sizeinbyte / (1024 * 1024 * 1024), 10, 'f', 2));
	} else if (sizeinbyte > tb){
		return (QString("%1 TB").arg((double)sizeinbyte / tb, 10, 'f', 2));
	} else{
		return (QString("%1 Byte").arg((double)sizeinbyte, 10, 'f', 2));
	}
}

QList<QVector3D> Util::sectionLinearInterpolation(const QVector3D &first, const QVector3D &last, int count)
{
    QList<QVector3D> ret;

	if (abs(first.x() - last.x()) < 0.0000001) // 经度相同
	{
		double Δy = (last.y() - first.y()) / count;
		double Δz = (last.z() - first.z()) / count;
		for (int i = 0; i < count; ++i)
		{
			ret.push_back(QVector3D(first.x(), first.y() + i * Δy, first.z() + i * Δz));
		}
	}
	else
	{
		for (int k = 0; k < count; ++k)
		{
			double x1 = first.x();
			double x2 = last.x();
			double y1 = first.y();
			double y2 = last.y();
			double z1 = first.z();
			double z2 = last.z();

			double xk = x1 + (x2 - x1) * k / count;
			double yk = (xk - x2) / (x1 - x2) * y1 + (xk - x1) / (x2 - x1) * y2;
			double zk = (xk - x2) / (x1 - x2) * z1 + (xk - x1) / (x2 - x1) * z2;

			ret.push_back(QVector3D(xk, yk, zk));
		}
	}
	return ret;
}

QString Util::hz2Py(const QString &dest, bool duoyin)
{
	auto destStr = dest.toStdString();
	const char *inbuf = destStr.c_str();
	char * outbuf = new char[HZ2PY_OUTPUT_BUF_ARRAY_SIZE];
	memset(outbuf, '\0', sizeof(char)* HZ2PY_OUTPUT_BUF_ARRAY_SIZE);
	if (is_utf8_string(inbuf)) {
		pinyin_utf8(inbuf, outbuf, true, duoyin, false, false, false, false, true);
	}
	else {
		pinyin_gb2312(inbuf, outbuf, true, duoyin, false, false, false, false, true);
	}
	QString ret(outbuf);
	delete[] outbuf;
	return ret;
}

QColor Util::color(int index)
{
	static QList<QColor> colorList;
	if (colorList.isEmpty())
	{
		colorList
			<< QColor(85, 170, 127)
			<< QColor(255, 170, 127)
			<< QColor(170, 170, 127)
			<< QColor(155, 155, 231)
			<< QColor(170, 255, 255)
			<< QColor(160, 160, 160)
			<< QColor(85, 255, 255)
			<< QColor(255, 255, 127)
			<< QColor(170, 255, 127)
			<< QColor(170, 85, 0)
			<< QColor(255, 85, 0)
			;
	}
	return colorList.value(index, colorList.at(0));
}

double Util::LoLaDmsToDec(int degree, int minute, int second)
{
    return degree + (minute + second / 60.0) / 60.0;
}

void Util::LoLaDecToDms(int& degree, int& minute, int& second, double decimal)
{
    degree = (int)decimal;
    double tmpMinute = (decimal - degree) * 60;
    minute = (int)tmpMinute;
    second = (tmpMinute - minute) * 60;
}

QString Util::LoDecToDmsText(double longitude)
{
    char ewChar = (longitude >= 0) ? 'E' : 'W';

    longitude = abs(longitude);

    int degree = 0;
    int minute = 0;
    int second = 0;

    LoLaDecToDms(degree, minute, second, longitude);


    return QString("%1%2%3").arg(degree, 3, 10, QChar('0'))
        .arg(minute, 2, 10, QChar('0'))
        .arg(second, 2, 10, QChar('0'))
        + ewChar;
}

QString Util::LaDecToDmsText(double latitude)
{
    char nsChar = (latitude >= 0) ? 'N' : 'S';

    latitude = abs(latitude);

    int degree = 0;
    int minute = 0;
    int second = 0;

    LoLaDecToDms(degree, minute, second, latitude);


    return QString("%1%2%3").arg(degree, 2, 10, QChar('0'))
        .arg(minute, 2, 10, QChar('0'))
        .arg(second, 2, 10, QChar('0'))
        + nsChar;
}

QString Util::LoLaDecToDmsText(double longitude, double latitude)
{
    return LaDecToDmsText(latitude) + LoDecToDmsText(longitude);
}

bool Util::LoLaDecFromDmsText(double& decimal, const QString& dmsStr)
{
    if (dmsStr.isEmpty())
    {
        decimal = 0;
        return true;
    }

    int numSigned = 0;
    QChar lastChar = dmsStr.at(dmsStr.length() - 1);
    if ('N' == lastChar || 'E' == lastChar)
    {
        numSigned = 1;
    }
    else if ('S' == lastChar || 'W' == lastChar)
    {
        numSigned = -1;
    }
    else
    {
        return false;
    }

    int degree = dmsStr.mid(0, dmsStr.size() - 5).toInt();
    int minute = dmsStr.mid(dmsStr.size() - 5, 2).toInt();
    int second = dmsStr.mid(dmsStr.size() - 3, 2).toInt();

    decimal = LoLaDmsToDec(degree, minute, second) * numSigned;
    return true;
}

bool Util::LoLaDecFromDmsText(double& longitude, double& latitude, const QString& dmsStr)
{
    int indexN = dmsStr.indexOf('N');
    int indexS = dmsStr.indexOf('S');
    if (-1 == indexN && -1 == indexS)
    {
        return false;
    }

    int indexLoLast = (-1 != indexN) ? indexN : indexS;

    if (!LoLaDecFromDmsText(latitude, dmsStr.mid(0, indexLoLast + 1)))
    {
        return false;
    }

    if (!LoLaDecFromDmsText(longitude, dmsStr.mid(indexLoLast + 1)))
    {
        return false;
    }

    return true;
}

QString Util::timeToHhmmssStr(quint64 time)
{
    return QString("%1:%2:%3").arg(time / 3600, 2, 10, QChar('0'))
        .arg(time / 60 % 60, 2, 10, QChar('0')).arg(time % 60, 2, 10, QChar('0'));
}

quint64 Util::timeFromHhmmssStr(const QString& timeStr)
{
    QStringList hhMmSsStrList = timeStr.split(":");
    if (3 != hhMmSsStrList.size())
    {
        return 0;
    }

    return hhMmSsStrList.at(0).toULong() * 3600 + hhMmSsStrList.at(1).toULong() * 60 + hhMmSsStrList.at(2).toULong();
}

void Util::moveToDesktopRight(QWidget* widget)
{
    auto desktopWidget = QApplication::desktop();
    auto rectDesktop = desktopWidget->screenGeometry();

    QPoint pos;
    pos.setX(rectDesktop.width() - widget->width() - 15);
    pos.setY(25);

    widget->move(pos);
}

QString Util::meterToMeterFootStr(double meter)
{
    return QString::number(meter, 'f', 2) + QStringLiteral("/")
        + QString::number(Calculator::meterToFoot(meter), 'f', 2);
}

bool Util::meterFromMeterFootStr(double& meter, const QString& strMeterFoot)
{
    int indexMeter = strMeterFoot.indexOf(QStringLiteral("/"));

    if (indexMeter < 0)
    {
        meter = 0;
        return false;
    }

    meter = strMeterFoot.mid(0, indexMeter).toDouble();

    return true;
}

int Util::subSystemCodeFromLogicId(quint32 logicId)
{
	int ret = (logicId & 0xFFFF0000) >> 16;
	return ret;
}

int Util::softwareIdFromLogicId(quint32 logicId)
{
	int ret = (logicId & 0x0000FF00) >> 8;
	return ret;
}

QString Util::toHex(quint64 number)
{
	return QString("0x%1").arg(QString::number(number, 16).toUpper());
}

QDateTime Util::secondToDateTime(quint64 second)
{
	return QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0)).addSecs(second);
}

int Util::colorToARGB(const QColor &color)
{
	int ret = 0;
	auto c = color.toRgb();
	ret = ret | color.alpha();
	ret = (ret << 8) | color.red();
	ret = (ret << 8) | color.green();
	ret = (ret << 8) | color.blue();
	return ret;
}

quint64 Util::dateTimeToSecond(const QDateTime &dateTime)
{
	return QDateTime(QDate(1970, 1, 1), QTime(0, 0, 0)).secsTo(dateTime);
}
