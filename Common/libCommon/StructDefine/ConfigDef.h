#ifndef ConfigDef_h__
#define ConfigDef_h__

#include <QString>

//�������
extern QString IPluginName;
//�������·��
extern QString IAppPath;
//�������·��
#define IPluginPath						QStringLiteral("%1/Plugins/%2/").arg(IAppPath).arg(IPluginName)

//��������ļ�
#define CONFIG_TABLE_INFO_PATH			"Config/TableInfo.xml"
//����߼�ID�����ļ�
#define CONFIG_SOFTWARE_LOGICID_PATH	"Config/SoftWareID.xml"
//���̨λ��Ϣ�����ļ�
#define CONFIG_TABLE_PATH				"Config/PostConfig.xml"
//�����ܽ�ģ�������ļ�
#define CONFIG_EXPORT_TEMPLATE_PATH		"Config/TempLate.xml"
//�����ܽ�ģ���ļ�����
#define CONFIG_EXPORT_FILENAME			"Config/TaskTemplate.docx"


//���� 0~360
#define         REG_DEG_LONGITUDE                           "(([0-9])|([1-9][0-9])|([1-2][0-9]{2})|(3[0-5][0-9]))(\\.[0-9]{1,6})?"  //0~360

#define         REG_DEG_LONGITUDE_EX                        "((\\-)?(([0-9])|([1-9][0-9])|(1[0-7][0-9]))(\\.[0-9]{1,6})?)|(181)"  //-+180
//γ�� 0~180
#define         REG_DEG_LATITUDE                            "(([0-9])|([1-9][0-9])|(1[0-7][0-9]))(\\.[0-9]{1,6})?"  //0~180

#define         REG_DEG_LATITUDE_EX                         "((\\-)?(([0-9])|([1-8][0-9]))(\\.[0-9]{1,6})?)|(91)"  //-+90

#define         REG_DEG_MIN_SEC                             "[0-9]|([1-5][0-9])" //0~59

#define         REG_DEG_INTEGER                             "[1-9][0-9]{0,9}" //����

#define         REG_DEG_Decimal                             "[1-9][0-9]{1,5}(\\.[0-9]{1,4})?" //С��

#define         REG_DEG_TargetNum                           "[1-9][0-9]{0,9}" //Ŀ����

#define         REG_DEG_Angle360                            "(([1-9][0-9]{0,1})|([1-2][0-9][0-9])|(3[1-5][0-9])|(0))(\\.[0-9]{1,2})?" //0~359.99

#define         REG_DEG_DataCount                           "[1-9][0-9]{0,5}" //DataCount

#define         REG_DEG_uchar                               "([0-9])|([1-9][0-9])|(1[0-9]{2})|(2[0-4][0-9])|(25[0-5])" //0~255

#define         REG_DEG_Angle90                             "(([1-8][0-9])|([0-9]))(\\.[0-9]{1,2})?" //0~89.99

#define         REG_DEG_Radius                              "[1-9][0-9]{0,9}(\\.[0-9]{1,6})?" //�뾶

#endif // ConfigDef_h__
