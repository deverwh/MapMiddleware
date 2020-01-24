#ifndef _MSG_STRING_H_
#define _MSG_STRING_H_


namespace MsgString
{
    const QString INFO = QStringLiteral("提示");
    const QString WARN = QStringLiteral("警告");
    const QString ERR = QStringLiteral("错误"); //不能写为ERROR，ERROR是个已定义的宏

    const QString OK = QStringLiteral(" 确定 ");
    const QString CANCEL = QStringLiteral(" 取消 ");
    const QString CLOSE = QStringLiteral(" 关闭 ");
    const QString SAVE = QStringLiteral(" 保存 ");
};


#endif //_MSG_STRING_H_