#ifndef CDBTableNameDef_H
#define CDBTableNameDef_H

#include "DBDef.h"
#include <QString>

/*-----------------------------�زĿ����ݱ�ṹ-----------------------------*/

///////////////////////////////////�زĿ�-�ɼ����ݱ�Ŀ///////////////////////////////////////

//������ɼ����ݱ�Ŀ5.3.1.1.1
const QString TABLE_OF_COLLECTDATA = "SC_BM_GDCJ";
//������ɼ����ݱ�Ŀ��ṹ
const QString OFCollectData_CollectMode = "CJMS";		//�ɼ�ģʽ
const QString OFCollectData_ImageType = "TXLX";			//ͼ������


//�״��źŲɼ����ݱ�Ŀ5.3.1.1.3
const QString TABLE_RS_COLLECTDATA = "SC_BM_LDXHCJ";
//�״��źŲɼ����ݱ�Ŀ��ṹ
const QString RSCollectData_CollectMode = "CJMS";		//�ɼ�ģʽ
const QString RSCollectData_PdwNum = "SJGS";			//PDW���ݸ���
const QString RSCollectData_FileSize = "WJDX";			//�ļ���С

//IFF / TACAN�źŲɼ����ݱ�Ŀ5.3.1.1.5
const QString TABLE_ITR_COLLECTDATA = "SC_BM_DWTKXHCJ";
//IFF / TACAN�źŲɼ����ݱ�Ŀ��ṹ
const QString ITRCollectData_CollectMode = "CJMS";		//�ɼ�ģʽ
const QString ITRCollectData_PdwNum = "SJGS";			//PDW���ݸ���
const QString ITRCollectData_FileSize = "WJDX";			//�ļ���С

//Link16�źŲɼ����ݱ�Ŀ5.3.1.1.7
const QString TABLE_TLR_COLLECTDATA = "SC_BM_LINK16CJ";
//Link16�źŲɼ����ݱ�Ŀ��ṹ
const QString TLRCollectData_CollectMode = "CJMS";		//�ɼ�ģʽ
const QString TLRCollectData_CollectRate = "CYL";		//������
const QString TLRCollectData_FileSize = "WJDX";			//�ļ���С

//ͨ���źŲɼ����ݱ�Ŀ5.3.1.1.9
const QString TABLE_CSR_COLLECTDATA = "SC_BM_TXXHCJ";
const QString CSRCollectData_CollectMode = "CJMS";		//�ɼ�ģʽ
const QString CSRCollectData_CollectRate = "CYL";		//������
const QString CSRCollectData_FileSize = "WJDX";			//�ļ���С

//�����ɼ����ݱ�Ŀ5.3.1.1.11
const QString TABLE_VTR_COLLECTDATA = "SC_BM_HYXHCJ";
//�����ɼ����ݱ�Ŀ��ṹ
const QString VTRCollectData_CollectMode = "CJMS";		//�ɼ�ģʽ
const QString VTRCollectData_CollectRate = "CYL";		//������
const QString VTRCollectData_FileSize = "WJDX";			//�ļ���С

/*-----------------------------�زĿ����ݱ�ṹ����-----------------------------*/

/*-----------------------------�鱨�����ݱ�ṹ-----------------------------*/

///////////////////////////////////�鱨��-����/ͼ���ز��鱨///////////////////////////////////////

//����QB�زı���
const QString TABLE_TEXTMATERIAL = "QB_SC_WZ";
//����QB�زı�ṹ											  
const QString TextMaterial_ID = "ID";			//��ʶ
const QString TextMaterial_CompanyCode = "DWDM";		//��λ����
const QString TextMaterial_ReconDirection = "ZCFXMC";		//ZC��������
const QString TextMaterial_MobilePlatformCode = "JDPTBH";		//����ƽ̨����
const QString TextMaterial_TaskNo = "SSRWBH";		//����������
const QString TextMaterial_SensorCode = "CGQDH";		//����������
const QString TextMaterial_Route = "XL";			//��·
const QString TextMaterial_MessageFileType = "BZ";			//����
const QString TextMaterial_MessageLanguageTypeCode = "WZ";			//����
const QString TextMaterial_SendCompany = "FWDW";		//���ĵ�λ
const QString TextMaterial_MessageForm = "BWXS";		//������ʽ
const QString TextMaterial_SecretLevel = "MMDJ";		//���ܵȼ�
const QString TextMaterial_CopyTime = "CSSJ";		//����ʱ��
const QString TextMaterial_SendTime = "FWSJ";		//����ʱ��
const QString TextMaterial_SendNo = "FWBH";		//���ı��
const QString TextMaterial_SignatureName = "QF";			//ǩ��
const QString TextMaterial_Author = "BZ";			//����
const QString TextMaterial_Title = "BT";			//����
const QString TextMaterial_Topic = "ZTC";		//�����
const QString TextMaterial_RecvCompany = "SWDW";		//���ĵ�λ
const QString TextMaterial_TimeEffectLevel = "SXDJ";		//ʱЧ�ȼ�
const QString TextMaterial_ReportType = "BWLX";		//��������
const QString TextMaterial_Means = "SD";			//�ֶ�
const QString TextMaterial_AllergyFlag = "MGBBS";		//���б���ʶ
const QString TextMaterial_NationalRegion = "GJDQ";		//���ҵ���
const QString TextMaterial_ReportInfo = "BSXX";		//������Ϣ
const QString TextMaterial_Content = "ZW";			//����
const QString TextMaterial_SourceMaterial = "SCLY";		//�ز���Դ

///////////////////////////////////�鱨��-�ź����������鱨///////////////////////////////////////

//�״��ź���������5.3.3.2.1
const QString TABLE_RADAR_SIGCHARACTER = "QB_XHTZ_LD";
//�״��ź�����������ṹ
const QString RSSigChar_ID = "ID";						//��ʶ
const QString RSSigChar_LocateTime = "DWSJ";			//��λʱ��
const QString RSSigChar_LocateLongitude = "MBJD";		//��λ����
const QString RSSigChar_LocateLatitude = "MBWD";		//��λγ��
const QString RSSigChar_Freq = "SPBCZ";					//Ƶ��
const QString RSSigChar_PRI = "PRIBCZ";					//����
const QString RSSigChar_PluseWidth = "MKBCZ";			//����
const QString RSSigChar_Attribute = "MBMC";				//����(��)

//IFF�ź���������5.3.3.2.2
const QString TABLE_IFF_SIGCHARACTER = "QB_XHTZ_MZIFF";
//IFF�ź�����������ṹ
const QString IFFSigChar_ID = "ID";						//��ʶ
const QString IFFSigChar_LocateTime = "DWSJ";			//���ʱ��
const QString IFFSigChar_Freq = "SPPL";					//Ƶ��
const QString IFFSigChar_SignalType = "XHLX";			//�ź�����
const QString IFFSigChar_LocateLongitude = "MBJD";		//��λ����
const QString IFFSigChar_LocateLatitude = "MBWD";		//��λγ��
const QString IFFSigChar_Attribute = "MBMC";			//����(��)

//�����ź���������5.3.3.2.3
const QString TABLE_TACAN_SIGCHARACTER = "QB_XHTZ_TACAN";
//�����ź�����������ṹ
const QString TACANSigChar_ID = "ID";					//��ʶ
const QString TACANSigChar_LocateTime = "DWSJ";			//��λʱ��
const QString TACANSigChar_LocateLongitude = "MBJD";	//��λ����
const QString TACANSigChar_LocateLatitude = "MBWD";		//��λγ��
const QString TACANSigChar_Height = "PTGD";				//�߶�
const QString TACANSigChar_SignalType = "XHLX";			//�ź�����
//const QString TACANSigChar_LocateLatitude = "MBWD";		//ģʽ����
//const QString TACANSigChar_Height = "PTGD";				//����(��)
// const QString TACANSigChar_SignalType = "XHLX";			//ע���
//const QString TACANSigChar_Attribute = "MBMC";			//����(��)

//�̲�ͨ���ź���������5.3.3.2.4
const QString TABLE_SW_SIGCHARACTER = "QB_XH_DBTX";
//�̲�ͨ���ź�����������ṹ
const QString SWSigChar_ID = "ID";						//��ʶ
const QString SWSigChar_LocateTime = "DWSJ";			//���ʱ��
const QString SWSigChar_Freq = "SPPL";					//Ƶ��
const QString SWSigChar_SignalType = "XHLX";			//�ź�����
const QString SWSigChar_LocateLongitude = "MBJD";		//��λ����
const QString SWSigChar_LocateLatitude = "MBWD";		//��λγ��
const QString SWSigChar_Attribute = "MBMC";				//����(��)

//���̲�ͨ���ź���������5.3.3.2.5
const QString TABLE_SSW_SIGCHARACTER = "QB_XH_CDBSJL";

//΢��/����ͨ���ź���������5.3.3.2.6
const QString TABLE_MICROWAVE_SIGCHARACTER = "QB_XH_WBTX";

//���������ź���������5.3.3.2.7
const QString TABLE_SEASATELLITE_SIGCHARACTER = "QB_XH_HSWX";

//ҿ���ź���������5.3.3.2.8
const QString TABLE_MARITIMEIRIDIUM_SIGCHARACTER = "QB_XH_YXXH";

//��Ǳ�����ź���������5.3.3.2.9
const QString TABLE_SUBMARINEBUOY_SIGCHARACTER = "QB_XH_FQFB";


///////////////////////////////////�鱨��-�ۺ������鱨///////////////////////////////////////

//�ۺ������鱨����
const QString TABLE_COLLITEXT = "QB_WZ_JBBW";
//�ۺ������鱨��ṹ											  
const QString ColliText_ID = "ID";			//��ʶ
const QString ColliText_SendCompany = "FWDW";		//���ĵ�λ
const QString ColliText_MessageForm = "BWXS";		//������ʽ
const QString ColliText_SecretLevel = "MMDJ";		//���ܵȼ�
const QString ColliText_CopyTime = "SBSJ";		//����ʱ��
const QString ColliText_SendTime = "FWSJ";		//����ʱ��
const QString ColliText_SendNo = "FWBH";		//���ı��
const QString ColliText_SignatureName = "QFR";		//ǩ��
const QString ColliText_Author = "BZ";			//����
const QString ColliText_Title = "BT";			//����
const QString ColliText_Topic = "ZTC";		//�����
const QString ColliText_RecvCompany = "SWDW";		//���ĵ�λ
const QString ColliText_TimeEffectLevel = "SXDJ";		//ʱЧ�ȼ�
const QString ColliText_ReportType = "BWLX";		//��������
const QString ColliText_Means = "SD";			//�ֶ�
const QString ColliText_EbType = "EBFL";		//��������
const QString ColliText_SbType = "SBFL";		//�鱨������
const QString ColliText_AllergyFlag = "MGBBS";		//���б���ʶ
const QString ColliText_NationalRegion = "GJDQ";		//���ҵ���
const QString ColliText_ReconDirection = "ZCFXMC";		//ZC��������
const QString ColliText_SecretParse = "MMPY";		//���������鱨
const QString ColliText_SecretParseNo = "MMPYCGBH";	//��������ɹ����
const QString ColliText_SpNetReconNo = "MBBH";		//�����������Ŀ����
const QString ColliText_TaskName = "RWMC";		//��������
const QString ColliText_ShareRsName = "ZCZYMC";	//���������Դ����
const QString ColliText_ShareRsCompany = "ZCZYDW";		//���������Դ�ṩ��λ
const QString ColliText_SendMsg = "BSXX";		//������Ϣ
const QString ColliText_PositionPlatformNumber = "ZDPTDH";		//��أ�ƽ̨������
const QString ColliText_TaskID = "RWBH";		//������
const QString ColliText_ReconArea = "ZCQY";		//ZC����
const QString ColliText_ReportState = "SBZT";		//�ϱ�״̬
const QString ColliText_Content = "NR";			//��������
const QString ColliText_PositionPlatformLongitude = "ZDPTJD";		//���(ƽ̨)����
const QString ColliText_PositionPlatformLatitude = "ZDPTWD";		//���(ƽ̨)γ��
const QString ColliText_SaveTime = "RKSJ";		//���ʱ��


//�ۺ������鱨��������
const QString TABLE_COLLITEXTAPPENDIX = "QB_WZ_FJXX";
//�ۺ������鱨���������ݽṹ
const QString ColliTextAppendix_ID = "ID";			//��ʶ
const QString ColliTextAppendix_ConnectFlag = "GLID";		//�ۺ������鱨��ʶ
const QString ColliTextAppendix_FileType = "WJLX";		//�ļ�����
const QString ColliTextAppendix_FileName = "WJM";		//�ļ���
const QString ColliTextAppendix_FilePath = "WJLJ";		//�ļ�·��
const QString ColliTextAppendix_FileSize = "WJDX";		//�ļ���С
const QString ColliTextAppendix_FileTime = "WJSC";		//�ļ�ʱ��
const QString ColliTextAppendix_SaveTime = "RKSJ";		//���ʱ��


//�ۺ������鱨������ϵ����
const QString TABLE_COLLITEXTRELATION = "QB_WZ_GLGX";
//�ۺ������鱨������ϵ��ṹ											  
const QString ColliTextRelation_ID = "ID";			//��ʶ
const QString ColliTextRelation_ConnectFlag = "GLID";		//�ۺ������鱨��ʶ
const QString ColliTextRelation_PrimaryName = "YBWBM";		//ԭ���ı���
const QString ColliTextRelation_PrimaryFlag = "YBWBS";		//ԭ���ı�ʶ
const QString ColliTextRelation_SaveTime = "RKSJ";		//���ʱ��


//�ۺ������鱨�ϱ��������
const QString TABLE_COLLITEXTRESPONSE = "QB_WZ_SBQK";
//�ۺ������鱨�ϱ������ṹ											  
const QString ColliTextResponse_ID = "ID";			//��ʶ
const QString ColliTextResponse_ConnectFlag = "GLID";		//�ۺ������鱨��ʶ
const QString ColliTextResponse_ModifyFlag = "XGBWID";		//�ۺ������鱨�޸ı��ı�ʶ
const QString ColliTextResponse_ReportContent = "SBNR";		//�ϱ�����
const QString ColliTextResponse_ExamineAttitude = "SGYJ";		//������
const QString ColliTextResponse_ExamineState = "SPZT";		//����״̬
const QString ColliTextResponse_SaveTime = "RKSJ";		//���ʱ��


///////////////////////////////////�鱨��-�ۺ�̬���鱨///////////////////////////////////////

//�ۺ�̬�ƻ�����Ϣ5.3.3.4.1
const QString TABLE_COLLISITUATION = "QB_TS_JBXX";
const QString ColliSituation_ID = "BS";				//��ʶ
const QString ColliSituation_ReportState = "SBZT";	//�ϱ�״̬

/*-----------------------------�鱨�����ݱ�ṹ����-----------------------------*/

/*-----------------------------Ŀ���ź�֪ʶ�����ݱ�ṹ-----------------------------*/

///////////////////////////////////Ŀ���ź�֪ʶ��-ʵ��Ŀ��֪ʶ///////////////////////////////////////
//ʵ��Ŀ���������5.3.4.2.1

//½��ƽ̨Ŀ����������5.3.4.2.1.1
const QString TABLE_LANDPLATTARGETCHARACTER = "MB_GY_LJPTTZ";

//����ƽ̨Ŀ����������5.3.4.2.1.2
const QString TABLE_OCEANPLATTARGETCHARACTER = "MB_GY_HJPTTZ";

//�ջ�ƽ̨Ŀ����������5.3.4.2.1.3
const QString TABLE_AIRPLATTARGETCHARACTER = "MB_GY_KJPTTZ";

//����/�ڱ������������5.3.4.2.1.4
const QString TABLE_DDTARGETCHARACTER = "MB_GY_DDZDTZ";

//�״������������5.3.4.2.1.5
const QString TABLE_LDTARGETCHARACTER = "MB_GY_LDZDTZ";

//������������5.3.4.2.1.6
const QString TABLE_JCTARGETCHARACTER = "MB_GY_JCTZ";

//�ۿ���������5.3.4.2.1.7
const QString TABLE_GKTARGETCHARACTER = "MB_GY_GKTZ";

/*-----------------------------Ŀ���ź�֪ʶ�����ݱ�ṹ����-----------------------------*/

/*-----------------------------��������ݱ�ṹ-----------------------------*/

///////////////////////////////////�����-��Դ����///////////////////////////////////////
//
////װ�����
//const QString TABLE_EQUIPMENTSTATE = "GL_ZY_ZBSJ";
////װ����������ṹ
//const QString EquipmentState_ID = "ID";			//��ʶ
//const QString EquipmentState_EquipmentNumber = "ZBBH";		//װ�����
//const QString EquipmentState_ExtSystemNumber = "FXTBH";		//��ϵͳ���
//const QString EquipmentState_EquipmentTypeNumber = "ZBLXBH";		//װ�����ͱ��
//const QString EquipmentState_EquipmentName = "ZBMC";		//װ������
//const QString EquipmentState_EquipmentType = "ZBZL";		//װ������
//const QString EquipmentState_EquipmentWarehouse = "ZBSCCS";		//װ����������
//const QString EquipmentState_EquipmentCabinetNumber = "ZBSCJGBH";	//װ������������
//const QString EquipmentState_EquipmentCabinetName = "ZBSCJHMC";	//װ����������
//const QString EquipmentState_Number = "ZBSL";		//װ������
//const QString EquipmentState_CurrentState = "DQZT";		//��ǰ״̬
//
////�����������
//const QString TABLE_RECONABILITYDATA = "GL_ZY_ZCNLSJ";
////����������ݽṹ
//const QString ReconAbilityData_Number = "ZCTXBH";		//����������
//const QString ReconAbilityData_AerialType = "ZCTXLX";		//�����������
//const QString ReconAbilityData_InitialAzimuth = "QSFW";		//��ʼ��λ
//const QString ReconAbilityData_StopAzimuth = "JZFW";		//��ֹ��λ
//const QString ReconAbilityData_InitiaPitch = "QSFY";		//��ʼ����
//const QString ReconAbilityData_StopPitch = "JZFY";		//��ֹ����
//const QString ReconAbilityData_ToEarth = "DDZCJL";		//�Ե�
//const QString ReconAbilityData_ToAir = "DKZCJL";		//�Կ�
//const QString ReconAbilityData_ToSea = "DHZCJL";		//�Ժ�
//const QString ReconAbilityData_StartFreq = "QSPL";		//��ʼƵ��
//const QString ReconAbilityData_StopFreq = "JZPL";		//��ֹƵ��
//const QString ReconAbilityData_CheckFreqPrecision = "CPJD";		//��Ƶ����
//const QString ReconAbilityData_CheckDirectionPrecision = "DWJD";		//��λ����
//
////װ����������
//const QString TABLE_EQUIPMENTABILITY = "GL_ZY_ZBNLGL";
////װ�������������ݽṹ
//const QString EquipmentAbility_ID = "ID";			//��ʶ
//const QString EquipmentAbility_ReconAbilityNumber = "CGQDH";		//����������
//const QString EquipmentAbility_EquipmentNumber = "ZCTXBH";		//װ�����
//
////��������
//const QString TABLE_TRACKSDATA = "GL_ZY_HJSJ";
////��ƽ̨�������ݽṹ
//const QString TracksData_ID = "ID";			//��ʶ
//const QString TracksData_MobilePlatformNumber = "JDPTBH";		//����ƽ̨����
//const QString TracksData_PlatformState = "PTZT";		//ƽ̨״̬
//const QString TracksData_PlatformLongitude = "PTJD";		//ƽ̨����
//const QString TracksData_PlatformLatitude = "PTWD";		//ƽ̨γ��
//const QString TracksData_PlatformRolling = "PTHY";		//ƽ̨��ҡ
//const QString TracksData_PlatformPitch = "PTZY";		//ƽ̨��ҡ
//const QString TracksData_PlatformCourse = "PTHX";		//ƽ̨����
//const QString TracksData_PlatformSpeed = "PTHS";		//ƽ̨����
//const QString TracksData_WavehouseTime = "RKSJ";		//���ʱ��
//
////������־����
//const QString TABLE_METEOROLOGICALLOG = "GL_ZY_QXRZSJ";
////������־�������ݽṹ
//const QString MeteorologicalLog_ID = "ID";			//��ʶ
//const QString MeteorologicalLog_Time = "SJ";			//ʱ��
//const QString MeteorologicalLog_Temperature = "QW";			//����
//const QString MeteorologicalLog_RelativeHumidity = "XDSD";		//���ʪ��
//const QString MeteorologicalLog_Pressure = "QY";			//��ѹ
//const QString MeteorologicalLog_WindDirection = "FX";			//����
//const QString MeteorologicalLog_WindSpeed = "FS";			//����


////////////////////////////////�����-ָ������//////////////////////////////////////////

//ָ���ĵ����
const QString TABLE_TELEGRAM = "GL_ZK_ZHWD";
//ָ���ĵ�����ݽṹ										   
const QString Telegram_ID = "ZHWDID";		//��ʶ
const QString Telegram_TaskCode = "RWDH";		//�������
const QString Telegram_ParentTaskCode = "FRWDH";		//���������
const QString Telegram_TaskLevel = "RWDJ";		//����ȼ�
const QString Telegram_TaskType = "RWLX";		//��������
const QString Telegram_TaskStartTime = "RWKSSJ";		//����ƻ���ʼʱ��
const QString Telegram_TaskEndTime = "RWJSSJ";		//����ƻ�����ʱ��
const QString Telegram_SendNo = "FWBH";		//���ı��
const QString Telegram_CreateTime = "CWSJ";		//����ʱ��
const QString Telegram_SendTime = "BGSJ";		//����ʱ��
const QString Telegram_Sender = "FWDW";		//���ĵ�λ
const QString Telegram_Receiver = "SWDW";		//���ĵ�λ
const QString Telegram_TimeEffectLevel = "SXDJ";		//ʱЧ�ȼ�
const QString Telegram_SecretLevel = "MMDJ";		//���ܵȼ�		
const QString Telegram_Author = "BZ";			//����
const QString Telegram_ReportType = "BWLX";		//��������
const QString Telegram_Title = "BT";			//����
const QString Telegram_Content = "ZW";			//����
const QString Telegram_RespondInfo = "HFXX";		//�ظ���Ϣ
const QString Telegram_BCheck = "SFCK";		//�Ƿ�鿴
const QString Telegram_TaskSource = "RWLY";		//������Դ
const QString Telegram_Recorder = "LRY";		//¼��Ա
const QString Telegram_RecordTime = "LRSJ";		//¼��ʱ��
const QString Telegram_SendState = "FSZT";		//����״̬
const QString Telegram_SaveTime = "RKSJ";		//���ʱ��

//����ƻ�����											   
const QString TABLE_TASKPLAN = "GL_ZK_JCRWJH";
//����ƻ������ݽṹ										    
const QString TaskPlan_ID = "RWJHID";		//��ʶ
const QString TaskPlan_TelegramFlag = "ZHWDID";		//ZH�ĵ��ʶ
const QString TaskPlan_Title = "RWJHBT";		//����ƻ�����
const QString TaskPlan_Summarize = "RWJHGS";		//�ƻ�����
const QString TaskPlan_Emphasis = "RWJHZD";		//�����ص�
const QString TaskPlan_Request = "RWJHYQ";		//��ɼ�Ҫ��
const QString TaskPlan_StartTime = "JHKSSJ";		//�ƻ���ʼʱ��
const QString TaskPlan_EndTime = "JHJSSJ";		//�ƻ�����ʱ��
const QString TaskPlan_MobilePlatformCode = "JDPTDH";		//����ƽ̨����
const QString TaskPlan_EquipComRequest = "PTBZXQ";		//װ����ͨ�ű��ϼ�����
const QString TaskPlan_AdvancePlan = "TQCZYA";		//���鴦��Ԥ��
const QString TaskPlan_ActualizeRequest = "SSYQ";		//ʵʩҪ��
const QString TaskPlan_OpinionAdvice = "YJJY";		//�������
const QString TaskPlan_NextWork = "XYBGZ";		//��һ������
const QString TaskPlan_RecordTime = "LRSJ";		//¼��ʱ��
const QString TaskPlan_ConfigMgr = "PZGL";		//���ù���
const QString TaskPlan_RecordCompany = "LRDW";		//¼�뵥λ
const QString TaskPlan_TaskType = "RWLB";		//�������
const QString TaskPlan_TaskNo = "RWBH";		//������
const QString TaskPlan_BRead = "SFCK";		//�Ƿ�鿴
const QString TaskPlan_ActiveArea = "HDQY";		//�����
const QString TaskPlan_PlanLine = "JHHX";		//�ƻ�����
const QString TaskPlan_PlanState = "JHZT";		//�ƻ�״̬
const QString TaskPlan_SaveTime = "RKSJ";		//���ʱ��


//����ƻ������ϵ����
const QString TABLE_PLANAREARELATION = "GL_ZK_JHQYGX";
//����ƻ������ϵ��ṹ
const QString PlanAreaRelation_ID = "ID";			//��ʶ
const QString PlanAreaRelation_TackPlanID = "RWJHID";		//����ƻ�ID
const QString PlanAreaRelation_ReconDirectionName = "ZCFXMC";		//��췽������
const QString PlanAreaRelation_ReconArea = "ZCQY";		//�������
const QString PlanAreaRelation_SaveTime = "RKSJ";		//���ʱ��

//����ƻ�Ŀ���ϵ����
const QString TABLE_TASKPLANTARGETRELATION = "GL_ZK_JHMBGX";
//����ƻ�Ŀ���ϵ��ṹ
const QString TaskPlanTargetRelation_ID = "ID";			//��ʶ
const QString TaskPlanTargetRelation_PlanID = "RWJHID";		//����ƻ�ID
const QString TaskPlanTargetRelation_ReconTargetName = "ZCMBMC";		//���Ŀ������
const QString TaskPlanTargetRelation_reconTargetcode = "ZCMBNM";		//���Ŀ������
const QString TaskPlanTargetRelation_SaveTime = "RKSJ";		//���ʱ��

//ָ�����ݸ�������
const QString TABLE_APPENDIX = "GL_ZK_FJ";
//ָ�����ݸ��������ݽṹ
const QString Appendix_ID = "FJID";		//����ID
const QString Appendix_ConnectFlag = "GLWJ";		//�����ļ�¼��ʶ
const QString Appendix_AppendixModule = "SSMK";		//����ģ��
const QString Appendix_FileType = "WJLX";		//�ļ�����
const QString Appendix_FileName = "WJM";		//�ļ���
const QString Appendix_FileSize = "WJDX";		//�ļ���С
const QString Appendix_FileTime = "WJSC";		//�ļ�ʱ��
const QString Appendix_FilePath = "WJLJ";		//�ļ�·��
const QString Appendix_UploadTime = "SCSJ";		//�ϴ�ʱ��
const QString Appendix_FTPFrontDecorate = "FTP";		//FTPǰ׺


//����ִ�б���
const QString TABLE_TASKEXEC = "GL_ZK_RWZX";
//����ִ�б����ݽṹ
const QString TaskExec_ID = "ID";			//��ʶ
const QString TaskExec_ReconDirectionName = "ZCFXMC";		//ZC��������
const QString TaskExec_ReconArea = "ZCQY";		//ZC����
const QString TaskExec_PositionPlatformNumber = "ZDPTDH";		//��أ�ƽ̨������
const QString TaskExec_TaskName = "RWMC";		//��������
const QString TaskExec_TaskNo = "RWBH";		//������
const QString TaskExec_DataUpdateTime = "RKSJ";		//���ݸ���ʱ��

//ָ���������											   
const QString TABLE_COMMANDORDER = "GL_ZK_ZHML";
//ָ����������ݽṹ										    
const QString CommandOrder_ID = "ID";			//��ʶ
const QString CommandOrder_ConnectTelegramFlag = "ZHWDBS";		//����ZH�ĵ��ʶ
const QString CommandOrder_CreateTime = "CWSJ";		//����ʱ��
const QString CommandOrder_SendTime = "XDSJ";		//�´�ʱ��
const QString CommandOrder_ReceivingSubSystem = "JSFXT";		//���շ�ϵͳ
const QString CommandOrder_TimeEffectLevel = "SXDJ";		//ʱЧ�ȼ�
const QString CommandOrder_Author = "BZ";			//����
const QString CommandOrder_Title = "BT";			//����
const QString CommandOrder_Content = "ZW";			//����
const QString CommandOrder_SaveTime = "RKSJ";		//���ʱ��

//���ƻ�����											   
const QString TABLE_RECONPLAN = "GL_ZK_ZCJH";
//���ƻ������ݽṹ										    
const QString ReconPlan_ID = "ID";		//ZC�ƻ���ʶ				
const QString ReconPlan_ConnectTelegramFlag = "ZHWDBS";	//����ZH�ĵ��ʶ
const QString ReconPlan_TaskPlanFlag = "RWJHBS";	//����ƻ���ʶ
const QString ReconPlan_StartTime = "KSSJ";		//��ʼʱ��
const QString ReconPlan_EndTime = "JSSJ";		//����ʱ��
const QString ReconPlan_Area = "ZCQY";		//ZC����
const QString ReconPlan_ObjectLongitude = "ZCDXJD";	//ZC���󾭶�
const QString ReconPlan_ObjectLatitude = "ZCDXWD";	//ZC����γ��
const QString ReconPlan_ReceivingSubSystem = "JSFXT";		//���շ�ϵͳ
const QString ReconPlan_ReceivingStation = "JSTW";		//����̨λ
const QString ReconPlan_DeliveryTime = "XDSJ";		//�´�ʱ��
const QString ReconPlan_TimeEffectLevel = "SXDJ";		//ʱЧ�ȼ�
const QString ReconPlan_Author = "BZ";		//����
const QString ReconPlan_Title = "BT";		//����
const QString ReconPlan_Type = "JHRWLX";	//ZC�ƻ�����
const QString ReconPlan_Content = "ZW";		//����

//���ƻ�������ϵ����
const QString TABLE_RECONPLANPARMETER = "GL_ZK_ZCJHCSGX";
//���ƻ�������ϵ��ṹ
const QString ReconPlanParmeter_ID = "ID";			//��ʶ
const QString ReconPlanParmeter_RconPlanID = "RWJHID";		//���ƻ�ID
const QString ReconPlanParmeter_ReconPlanParmeterName = "JHCSMC";		//���ƻ���������
const QString ReconPlanParmeter_ParmeterFlag = "JHCSBZ";		//���ƻ�������ʶ

//�״�������
const QString TABLE_RADARRECON = "GL_ZK_LDZCJH";
//�״����ƻ����������ݽṹ                     
const QString RadarReconPlanParam_ID = "ID";		//��ʶ
const QString RadarReconPlanParam_ReconTargetcode = "ZCMBNM";	//ZCĿ������
const QString RadarReconPlanParam_ReconObject = "ZCDX";		//ZC����
const QString RadarReconPlanParam_ReconAntType = "ZCTX";		//ZC��������
const QString RadarReconPlanParam_StartFrequency = "QSPL";		//��ʼƵ��
const QString RadarReconPlanParam_EndFrequency = "ZZPL";		//��ֹƵ��

//ͨ���ղ����
const QString TABLE_COMMSURVEY = "GL_ZK_TXPCJH";
//ͨ���ղ�ƻ����������ݽṹ
const QString CommSurveyPlanParam_ID = "ID";			//��ʶ
const QString CommSurveyPlanParam_ReconTargetcode = "ZCMBNM";		//ZCĿ������
const QString CommSurveyPlanParam_ReconObject = "ZCDX";		//ZC����
const QString CommSurveyPlanParam_ReconAntType = "ZCTX";		//ZC��������
const QString CommSurveyPlanParam_StartFrequency = "QSPL";		//��ʼƵ��
const QString CommSurveyPlanParam_EndFrequency = "ZZPL";		//��ֹƵ��
const QString CommSurveyPlanParam_PlanParamSource = "JHCSLY";		//�ƻ�������Դ

//ͨ��������
const QString TABLE_COMMUNICATESIFT = "GL_ZK_TXXCJH";
//ͨ�����ƻ����������ݽṹ
const QString CommunicateSiftPlanParam_ID = "ID";			//��ʶ
const QString CommunicateSiftPlanParam_ReconTargetcode = "ZCMBNM";		//ZCĿ������
const QString CommunicateSiftPlanParam_ReconObject = "ZCDX";		//ZC����
const QString CommunicateSiftPlanParam_ReconAntType = "ZCTX";		//ZC��������
const QString CommunicateSiftPlanParam_CenterFrequency = "ZXPL";		//����Ƶ��
const QString CommunicateSiftPlanParam_BandWidth = "DK";			//����
const QString CommunicateSiftPlanParam_ModulationMode = "TZFS";		//���Ʒ�ʽ
const QString CommunicateSiftPlanParam_SymbolRate = "FHSL";		//��������
const QString CommunicateSiftPlanParam_PlanParamSource = "JHCSLY";		//�ƻ�������Դ

//IFF/TACAN���ӱ���
const QString TABLE_IFFTACANMONITOR = "GL_ZK_IFFTACAN";
//IFF/TACAN���Ӽƻ����������ݽṹ
const QString IffTacanMonitorPlanParam_ID = "ID";			//��ʶ
const QString IffTacanMonitorPlanParam_Targetcode = "ZCMBNM";		//���Ŀ������
const QString IffTacanMonitorPlanParam_TechnicalSystem = "JSTZ";		//��������
const QString IffTacanMonitorPlanParam_RadioFreqArray = "SPPL";		//��ƵƵ�ʼ�
const QString IffTacanMonitorPlanParam_StorageTime = "RKSJ";		//���ʱ��
const QString IffTacanMonitorPlanParam_RadiationSourceName = "FSYMC";		//����Դ����

//���������
const QString TABLE_PHOTOELECTRICRECON = "GL_ZK_GDTXZC";
//���ͼ��ƻ����������ݽṹ  
const QString PhotoelectricImagePlanParam_ID = "ID";			//��ʶ
const QString PhotoelectricImagePlanParam_ReconTargetcode = "ZCMBNM";		//ZCĿ������
const QString PhotoelectricImagePlanParam_ReconObject = "ZCDX";		//ZC����
const QString PhotoelectricImagePlanParam_ReconAzimuth = "RWFW";		//��췽λ
const QString PhotoelectricImagePlanParam_PlanArea = "RWQY";		//��������
const QString PhotoelectricImagePlanParam_DetectionMode = "ZZMS";		//����ģʽ
const QString PhotoelectricImagePlanParam_PlanParamSource = "JHCSLY";		//�ƻ�������Դ

//��Ƶ�ź�������
const QString TABLE_FREQHOPPING = "GL_ZK_TPXHZC";
//��Ƶ�źżƻ����������ݽṹ
const QString FrequencyHoppingPlanParam_ID = "ID";			//��ʶ
const QString FrequencyHoppingPlanParam_Targetcode = "ZCMBNM";		//���Ŀ������
const QString FrequencyHoppingPlanParam_ReconObject = "ZCDX";		//������
const QString FrequencyHoppingPlanParam_StartFrequency = "QSPL";		//��ʼƵ��
const QString FrequencyHoppingPlanParam_EndFrequency = "ZZPL";		//��ֹƵ��
const QString FrequencyHoppingPlanParam_HopSpeed = "TS";			//����
const QString FrequencyHoppingPlanParam_HopFrequencyPeriod = "TPZQ";		//��Ƶ����
const QString FrequencyHoppingPlanParam_PlanParamSource = "JHCSLY";		//�ƻ�������Դ

//��Ƶ�ź����
const QString TABLE_SPREADSPECTRUM = "GL_ZK_KPXHZ";
//��Ƶ�źżƻ����������ݽṹ
const QString SpreadSpectrumPlanParam_ID = "ID";			//��ʶ
const QString SpreadSpectrumPlanParam_Targetcode = "ZCMBNM";		//���Ŀ������
const QString SpreadSpectrumPlanParam_ReconObject = "ZCDX";		//������
const QString SpreadSpectrumPlanParam_CenterFrequency = "ZXPL";		//����Ƶ��
const QString SpreadSpectrumPlanParam_BandWidth = "DK";			//����
const QString SpreadSpectrumPlanParam_ModulationMode = "TZFS";		//���Ʒ�ʽ
const QString SpreadSpectrumPlanParam_SymbolRate = "FHSL";		//��������
const QString SpreadSpectrumPlanParam_SpreadingCodeLength = "KPMC";		//��Ƶ�볤
const QString SpreadSpectrumPlanParam_SpreadingCodeSequence = "KPMSL";		//��Ƶ������
const QString SpreadSpectrumPlanParam_PlanParamSource = "JHCSLY";		//�ƻ�������Դ

//�������־
const QString TABLE_COMMANDRESPOND = "GL_ZK_MLFKRZ";
//�������־�����ݽṹ									  
const QString CommandRespondLog_ID = "ID";			//��ʶ
const QString CommandRespondLog_ConnectCommandOrderID = "GLMLBS";		//���������ʶ
const QString CommandRespondLog_ConnectCommandOrderType = "GLMLLX";		//������������
const QString CommandRespondLog_ExecState = "ZXZT";		//ִ��״̬
const QString CommandRespondLog_FeedbackTime = "FKSJ";		//����ʱ��
const QString CommandRespondLog_ReceivingSubSystem = "JSFXT";		//���շ�ϵͳ
const QString CommandRespondLog_ReceivingStation = "JSTW";	// ����̨λ
const QString CommandRespondLog_FeedbackContent = "FKZW";		//��������
const QString CommandRespondLog_Remark = "BZ";			//��ע

//ֵ����־
const QString TABLE_ORDERLYLOG = "GL_ZK_ZBRZ";
//ֵ����־�����ݽṹ
const QString Orderlylog_ID = "ID";			//ֵ����־ID
const QString Orderlylog_PositionPlatformNumber = "ZDPTDH";		//��أ�ƽ̨������
const QString Orderlylog_TaskName = "RWMC";		//��������
const QString Orderlylog_TaskNo = "RWBH";		//������
const QString Orderlylog_SubSystemNo = "FXTBH";		//��ϵͳ���
const QString Orderlylog_StationNo = "FXTTWBH";	//̨λ���
const QString Orderlylog_Author = "ZXR";		//׫д��
const QString Orderlylog_CreateTime = "ZXSJ";		//׫дʱ��
const QString Orderlylog_Title = "RZBT";		//��־����
const QString Orderlylog_FinishedWork = "YWCGZ";		//����ɹ���
const QString Orderlylog_UndoWork = "DWCGZ";		//����ɹ���
const QString Orderlylog_Remark = "BZ";			//��ע
const QString Orderlylog_SaveTime = "RKSJ";		//���ʱ��

//ƽ̨�����
const QString TABLE_TASKBRIEF = "GL_ZK_RWJB";
//ƽ̨����򱨱����ݽṹ
const QString TaskBrief_ID = "ID";			//�����ID
const QString TaskBrief_PositionPlatformNumber = "ZDPTDH";		//��أ�ƽ̨������
const QString TaskBrief_TaskName = "RWMC";		//��������
const QString TaskBrief_TaskNo = "RWBH";		//������
const QString TaskBrief_TaskStartTime = "KSSJ";		//����ʼʱ��
const QString TaskBrief_TaskEndTime = "JSSJ";		//�������ʱ��
const QString TaskBrief_TelegramFlag = "RWDH";		//����ָ���ĵ��ʶ
const QString TaskBrief_TaskPlanFlag = "RWJHNM";		//��������ƻ���ʶ
const QString TaskBrief_FlexiblePlatformCode = "JDPTBH";		//����ƽ̨����
const QString TaskBrief_ReportMadeCompany = "BGZZDW";		//����������λ
const QString TaskBrief_ReportMaker = "BGZZR";		//����������
const QString TaskBrief_ReportMadeTime = "BGZZSJ";		//��������ʱ��
const QString TaskBrief_ReportContent = "BGNR";		//��������
const QString TaskBrief_ReconDirection = "ZCFX";		//��췽��
const QString TaskBrief_ReconObject = "ZCDX";		//������
const QString TaskBrief_StartPlace = "CFD";		//������
const QString TaskBrief_BackPlace = "FHD";		//���ص�
const QString TaskBrief_TotalRoute = "ZHC";		//�ܺ���
const QString TaskBrief_SaveTime = "RKSJ";		//���ʱ��

//�ڲ�Эͬ
const QString TABLE_INNERCOOPERATE = "GL_ZK_NBXT";
//�ڲ�Эͬ���������ݽṹ
const QString InnerCooperateParam_ID = "ID";			//��ʶ
const QString InnerCooperateParam_ConnectReconPlanFlag = "GLZCJHBS";	//����ZC�ƻ���ʶ
const QString InnerCooperateParam_CreateTime = "CWSJ";		//����ʱ��
const QString InnerCooperateParam_SendTime = "XDSJ";		//�´�ʱ��
const QString InnerCooperateParam_ReceivingSubSystem = "JSFXT";		//���շ�ϵͳ
const QString InnerCooperateParam_ReceivingStation = "JSTW";		//����̨λ
const QString InnerCooperateParam_TimeEffectLevel = "SXDJ";		//ʱЧ�ȼ�
const QString InnerCooperateParam_Author = "BZ";			//����
const QString InnerCooperateParam_Title = "BT";			//����
const QString InnerCooperateParam_Content = "ZW";			//����


//////////////////////////////////�����-�������////////////////////////////////////////

//�ļ���������
const QString TABLE_TRANSFERTASK = "GL_JCSJ_CSRW";
//�ļ�������������ݽṹ
const QString TransferTask_ID = "BS";			//��ʶ
const QString TransferTask_TaskType = "RWLX";		//������������
const QString TransferTask_DataSource = "SJLY";		//�ļ���Դ
const QString TransferTask_FileType = "WJLX";		//�ļ�����
const QString TransferTask_FileSize = "WJJDX";		//�ļ���С
const QString TransferTask_FileName = "WJMC";		//�ļ�����
const QString TransferTask_ReceiveCompany = "JSDW";		//���յ�λ
const QString TransferTask_TimeEffectLevel = "SXDJ";		//ʱЧ�ȼ�
const QString TransferTask_TransmintState = "RWZT";		//����״̬
const QString TransferTask_TransmintProccess = "RWJD";		//�������
const QString TransferTask_KALink = "KALL";		//������õ���·
const QString TransferTask_Remark = "BZ";			//��ע
const QString TransferTask_SaveTime = "RKSJ";		//���ʱ��


//��ж�����ݼ�¼
const QString TABLE_LOADUNLOADDATARECORD = "GL_JCSJ_XZSJJL";
//��ж�����ݼ�¼�����ݽṹ
const QString LoadUnloadDataRecord_ID = "ID";			//��ʶ
const QString LoadUnloadDataRecord_PositionPlatformNumber = "ZDPTDH";		//��أ�ƽ̨������
const QString LoadUnloadDataRecord_Operator = "CZY";		//����Ա
const QString LoadUnloadDataRecord_Type = "JXZLX";		//��ж������
const QString LoadUnloadDataRecord_Content = "JXZLN";		//��ж������
const QString LoadUnloadDataRecord_Time = "CZSJ";		//��ж��ʱ��
const QString LoadUnloadDataRecord_DataDestination = "SJQX";		//������Դ/ȥ��
const QString LoadUnloadDataRecord_Remark = "BZ";			//��ע



//////////////////////////////////�����-������־����////////////////////////////////////////

//�״��ź���������־5.3.5.4.2
const QString TABLE_RS_OPERATELOG = "GL_RZ_LDXHZCCZ";
//�״��ź���������־�����ݽṹ
const QString RSOperateLog_PlatNo = "ZDPTDH";				//��أ�ƽ̨������
const QString RSOperateLog_TaskID = "RWBH";					//���������/ѵ�������ʶ
const QString RSOperateLog_EventID = "SJID";				//�������¼�ID
const QString RSOperateLog_ScoutStationNo = "ZHYLJS";		//����λID
const QString RSOperateLog_EventContent = "SJMS";			//�������¼�����
	
//�����������־5.3.5.4.3
const QString TABLE_OF_OPERATELOG = "GL_RZ_GDZCCZ";
//�����������־�����ݽṹ
const QString OFOperateLog_PlatNo = "ZDPTDH";				//��أ�ƽ̨������
const QString OFOperateLog_TaskID = "RWBH";					//���������/ѵ�������ʶ
const QString OFOperateLog_EventID = "SJID";				//�������¼�ID
const QString OFOperateLog_ScoutStationNo = "ZHYLJS";		//����λID
const QString OFOperateLog_EventContent = "SJMS";			//�������¼�����

//ͨ���ź���������־5.3.5.4.4
const QString TABLE_CSR_OPERATELOG = "GL_RZ_TXXHZCCZ";
//ͨ���ź���������־�����ݽṹ
const QString CSROperateLog_PlatNo = "ZDPTDH";				//��أ�ƽ̨������
const QString CSROperateLog_TaskID = "RWBH";				//���������/ѵ�������ʶ
const QString CSROperateLog_EventID = "SJID";				//�������¼�ID
const QString CSROperateLog_ScoutStationNo = "ZHYLJS";		//����λID
const QString CSROperateLog_EventContent = "SJMS";			//�������¼�����

//Link16�ź���������־5.3.5.4.5
const QString TABLE_TLR_OPERATELOG = "GL_RZ_LINK16XHZCCZ";
//Link16�ź���������־�����ݽṹ
const QString TLROperateLog_PlatNo = "ZDPTDH";				 //��أ�ƽ̨������
const QString TLROperateLog_TaskID = "RWBH";				 //���������/ѵ�������ʶ
const QString TLROperateLog_EventID = "SJID";				 //�������¼�ID
const QString TLROperateLog_ScoutStationNo = "ZHYLJS";		 //����λID
const QString TLROperateLog_EventContent = "SJMS";			 //�������¼�����

//IFF/TACAN�ź���������־5.3.5.4.6
const QString TABLE_ITR_OPERATELOG = "GL_RZ_DWTKXHZCCZ";
//IFF/TACAN�ź���������־�����ݽṹ
const QString ITROperateLog_PlatNo = "ZDPTDH";				  //��أ�ƽ̨������
const QString ITROperateLog_TaskID = "RWBH";				  //���������/ѵ�������ʶ
const QString ITROperateLog_EventID = "SJID";				  //�������¼�ID
const QString ITROperateLog_ScoutStationNo = "ZHYLJS";		  //����λID
const QString ITROperateLog_EventContent = "SJMS";			  //�������¼�����

//������������־5.3.5.4.7
const QString TABLE_TM_OPERATELOG = "GL_RZ_RWGLCZ";
//������������־�����ݽṹ
const QString TMOperateLog_PlatNo = "ZDPTDH";					//��أ�ƽ̨������
const QString TMOperateLog_TaskID = "RWBH";						//���������/ѵ�������ʶ
const QString TMOperateLog_EventID = "SJID";					//�������¼�ID
const QString TMOperateLog_ScoutStationNo = "ZHYLJS";			//����λID
const QString TMOperateLog_EventContent = "SJMS";				//�������¼�����

//�鱨���������־5.3.5.4.8
const QString TABLE_QB_OPERATELOG = "GL_RZ_QBCLCZ";
//�鱨���������־�����ݽṹ
const QString QBOperateLog_PlatNo = "ZDPTDH";					//��أ�ƽ̨������
const QString QBOperateLog_TaskID = "RWBH";						//���������/ѵ�������ʶ
const QString QBOperateLog_EventID = "SJID";					//�������¼�ID
const QString QBOperateLog_ScoutStationNo = "ZHYLJS";			//����λID
const QString QBOperateLog_EventContent = "SJMS";				//�������¼�����

//����ͨ�Ų�����־5.3.5.4.9
const QString TABLE_CS_OPERATELOG = "GL_RZ_RWCLCZ";
//����ͨ�Ų�����־�����ݽṹ
const QString CSOperateLog_PlatNo = "ZDPTDH";					//��أ�ƽ̨������
const QString CSOperateLog_TaskID = "RWBH";						//���������/ѵ�������ʶ
const QString CSOperateLog_EventID = "SJID";					//�������¼�ID
const QString CSOperateLog_ScoutStationNo = "ZHYLJS";			//����λID
const QString CSOperateLog_EventContent = "SJMS";				//�������¼�����

///////////////////////////////////�����-��ά����///////////////////////////////////////

//����ϵͳ������־5.3.5.8.1
const QString TABLE_TASKSYSTEM_HEALTHLOG = "GL_YW_RWXTJK";
//����ϵͳ������־��ṹ
const QString TaskSystemHealthLog_RSState = "LDSYS";	//�״��ź�����ϵͳ״̬
const QString TaskSystemHealthLog_CSRState = "TXSYS";	//ͨ���ź�����ϵͳ״̬
const QString TaskSystemHealthLog_TLRState = "LINK16SYS";	//Link16�ź�����ϵͳ״̬
const QString TaskSystemHealthLog_ITRState = "DWTKSYS";	//IFF/TACAN�ź�����ϵͳ״̬
const QString TaskSystemHealthLog_OFState = "GDSYS";	//�������ϵͳ״̬
const QString TaskSystemHealthLog_CISState = "ZKQBSYS";	//ָ�ӿ������鱨�����ϵͳ״̬
const QString TaskSystemHealthLog_CSState = "RWTXSYS";	//����ͨ�ŷ�ϵͳ״̬

//�����ϵͳ������־5.3.5.8.2
const QString TABLE_RS_HEALTHLOG = "GL_YW_LZJK";
//�����ϵͳ������־��ṹ
const QString RSHealthLog_SaveTime = "RKSJ";		//���ʱ��

//ͨ���ϵͳ������־5.3.5.8.3
const QString TABLE_CSR_HEALTHLOG = "GL_YW_TZJK";
//ͨ���ϵͳ������־��ṹ
const QString CSRHealthLog_SaveTime = "RKSJ";		//���ʱ��

//Link16��ϵͳ������־5.3.5.8.4
const QString TABLE_TLR_HEALTHLOG = "GL_YW_LINK16JK";
//Link16��ϵͳ������־��ṹ
const QString TLRHealthLog_SaveTime = "RKSJ";		//���ʱ��

//IFF/TACAN��ϵͳ������־5.3.5.8.5
const QString TABLE_ITR_HEALTHLOG = "GL_YW_DWTKJK";
//IFF/TACAN��ϵͳ������־��ṹ
const QString ITRHealthLog_SaveTime = "RKSJ";		//���ʱ��

//�����ϵͳ������־5.3.5.8.6
const QString TABLE_OF_HEALTHLOG = "GL_YW_GZJK";
//�����ϵͳ������־��ṹ
const QString OFHealthLog_SaveTime = "RKSJ";		//���ʱ��

//ָ�ӿ������鱨�����ϵͳ������־5.3.5.8.7
const QString TABLE_CIS_HEALTHLOG = "GL_YW_ZKQBJK";
//ָ�ӿ������鱨�����ϵͳ������־��ṹ
const QString CISHealthLog_SaveTime = "RKSJ";		//���ʱ��

//����ͨ�ŷ�ϵͳ������־5.3.5.8.8
const QString TABLE_CS_HEALTHLOG = "GL_YW_RWTXJK";
//����ͨ�ŷ�ϵͳ������־��ṹ
const QString CSHealthLog_SaveTime = "RKSJ";		//���ʱ��

///////////////////////////////////�����-������///////////////////////////////////////

//�ֵ�����
const QString TABLE_DICTIONARYNAME = "ZD_ZDMC";
//�ֵ����Ʊ����ݽṹ
const QString DictionaryName_ID = "ZDID";		//�ֵ�ID
const QString DictionaryName_Name = "ZDMC";		//�ֵ�����
const QString DictionaryName_Discription = "ZDSM";		//�ֵ�˵��
const QString DictionaryName_ParentID = "FZDID";		//���ֵ�ID
const QString DictionaryName_BUsed = "SFQY";		//�Ƿ�����
const QString DictionaryName_RefferenceStandard = "CKBZ";		//�ο���׼


//�ֵ�ֵ
const QString TABLE_DICTIONARYVALUE = "ZD_ZDZ";
//�ֵ�ֵ�����ݽṹ
const QString DictionaryValue_ValueID = "ZDZID";		//�ֵ�ֵID
const QString DictionaryValue_DictionaryID = "ZDID";		//�ֵ�ID
const QString DictionaryValue_ShortCut = "QZ";		//ȡֵ
const QString DictionaryValue_CodeValue = "BMZ";		//����ֵ
const QString DictionaryValue_Sequence = "XH";		//���

/*-----------------------------��������ݱ�ṹ�������-----------------------------*/

#endif // CDBTableNameDef_H