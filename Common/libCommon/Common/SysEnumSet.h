#ifndef SYSENUMSET_H
#define SYSENUMSET_H

#include <QtCore>

//系统使用的枚举定义

namespace NS_SYS_Enum {
 
//分系统编号
class CSystemNum
{
public:
    /*
0=任务系统总体
1=雷达信号侦测分系统；
2=通信信号侦测分系统；
3= Link16信号侦测分系统；
4=IFF/TACAN信号侦测分系统；
5=光电侦察分系统；
6=指挥控制与情报处理分系统(指控子系统)；
7=指挥控制与情报处理分系统(情报处理子系统)；
8=任务通信分系统；
9=地面处理与应用系统

*/
    enum ESystemNum
    {
        TaskSys=0,  //任务系统总体
        RS,         //雷达信号侦测分系统
        CSR,        //通信信号侦测分系统
        TLR,        //Link16信号侦测分系统
        ITR,        //IFF/TACAN信号侦测分系统
        OF,         //光电侦察分系统
        CIS_ZK,     //指挥控制与情报处理分系统(指控子系统)
		CIS_QB,		//指挥控制与情报处理分系统(情报处理子系统)
        CS,			//任务通信分系统
        GAS,        //地面处理与应用系统
		Invalid = 255,	//无效值
    };

    static QMap<quint32,QString> &GetMap();
	static QString	EnumName();
};

//角色编号
class CRoleNum
{
public:
    enum ERoleNum
    {
        Invalid=0,				//无效角色
		RadarSigMaster = 1,		//雷达信号主控侦测角色
		RadarSigAssist = 2,		//雷达信号副控侦测角色	
		CommonSig = 3,			//通信信号侦测角色
		EspecialSig = 4,		//特殊信号侦测角色
		Link16 = 5,				//Link16信号侦测角色
        IFF_TACAN=6,			//IFF和TACAN信号侦测角色
		TOEC = 7,				//光电侦察角色
        TaskManage=8,			//任务管理角色
        QBProcess=9,			//情报处理角色
    };

    static QMap<quint32, QString> &GetMap();
	static QString	EnumName();
};

//显控台位编号
class CDisplayCtrlDeviceNum
{
public:
    enum EDisplayCtrlDeviceNum
    {
        Invalid=0,				//无效台位
		IFF_TACAN = 1,			//IFF和TACAN信号侦测台位
		Link16 = 2,				//Link16信号侦测台位
		Common1 = 3,			//通信信号侦测台位1
		Common2 = 4,			//通信信号侦测台位2
		EspecialSig = 5,		//特殊信号侦察台位
        RadarSignalAssist = 6,	//雷达信号侦测副控台位
		RadarSpy = 7,			//雷达信号侦测主控台位
		CommandSubSys = 8,		//指控子系统
        QBProcess = 9,			//情报处理台位
        TOECSpy=10,				//光电侦察台位
    };

    static QMap<quint32, QString> &GetMap();
	static QString	EnumName();
};


//时效等级
class CAgingLevel
{
public:
	enum EAgingLevelType
	{
		TopPremium = 1,			//特急
		Premium = 2,			//加急
		Urgent = 3,				//急
		Normal = 4,				//平
	};
	static QMap<quint32, QString> &GetMap();
	static QString EnumName();
};

//秘密等级
class CClassiFied
{
public:
	enum EClassiFiedType
	{
		TopSecret = 1,			//绝密
		Confidential = 2,		//机密
		Secret = 3,				//秘密
		Interioral = 4,			//内部
		Publicity = 5,			//公开
	};
	static QMap<quint32, QString> &GetMap();
	static QString EnumName();
};

//国家地区
class CCountryRegionCode
{
public:
	enum ECountryRegion
	{
		Unknown = 000,//	不明
		AND,//	安道尔
		ARE,//	阿联酋
		AFG,//	阿富汗
		ATG,//	安提瓜和巴布达
		AIA,//	安圭拉
		ALB,//	阿尔巴尼亚
		ARM,//	亚美尼亚
		ANT,//	荷属安的列斯
		AGO,//	安哥拉
		ATA,//	南极洲
		ARG,//	阿根廷
		ASM,//	美属萨摩亚
		AUT,//	奥地利
		AUS,//	澳大利亚
		ABW,//	阿鲁巴
		AZE,//	阿塞拜疆
		BIH,//	波斯尼亚和黑塞哥维那
		BRB,//	巴巴多斯
		BGD,//	孟加拉国
		BEL,//	比利时
		BFA,//	布基纳法索
		BGR,//	保加利亚
		BHR,//	巴林
		BDI,//	布隆迪
		BEN,//	贝宁
		BMU,//	百慕大
		BRN,//	文莱
		BOL,//	玻利维亚
		BRA,//	巴西
		BHS,//	巴哈马
		BTN,//	不丹
		BVT,//	布维岛
		BWA,//	博茨瓦纳
		BLR,//	白俄罗斯
		BLZ,//	伯利兹
		CAN,//	加拿大
		CCK,//	科科斯(基林)群岛
		CAF,//	中非
		COG,//	刚果
		CHE,//	瑞士
		CIV,//	科特迪瓦
		COK,//	库克群岛
		CHL,//	智利
		CMR,//	喀麦隆
		CHN,//	中国
		COL,//	哥伦比亚
		CRI,//	哥斯达黎加
		CTN,//	台湾
		CUB,//	古巴
		CPV,//	佛得角
		CYP,//	塞浦路斯
		CZE,//	捷克
		DEU,//	德国
		DJI,//	吉布提
		DNK,//	丹麦
		DMA,//	多米尼克
		DOM,//	多米尼加共和国
		DZA,//	阿尔及利亚
		ECU,//	厄瓜多尔
		EST,//	爱沙尼亚
		EGY,//	埃及
		ESH,//	西撒哈拉
		ERI,//	厄立特里亚
		ESP,//	西班牙
		ETH,//	埃塞俄比亚
		FIN,//	芬兰
		FJI,//	斐济
		FLK,//	马尔维纳斯群岛(福克兰群岛)
		FSM,//	密克罗尼西亚
		FRO,//	法罗群岛
		FRA,//	法国
		GAB,//	加蓬
		GBR,//	英国
		GRD,//	格林纳达
		GEO,//	格鲁吉亚
		GUF,//	法属圭亚那
		GHA,//	加纳
		GIB,//	直布罗陀
		GRL,//	格陵兰
		GMB,//	冈比亚
		GIN,//	几内亚
		GLP,//	瓜德罗普
		GNQ,//	赤道几内亚
		GRC,//	希腊
		SGS,//	南乔治亚岛和南桑德韦奇岛
		GTM,//	危地马拉
		GUM,//	关岛
		GNB,//	几内亚比绍
		GUY,//	圭亚那
		HKG,//	香港
		HMD,//	赫德岛和麦克唐纳岛
		HND,//	洪都拉斯
		HRV,//	克罗地亚
		HTI,//	海地
		HUN,//	匈牙利
		IDN,//	印度尼西亚
		IRL,//	爱尔兰
		ISR,//	以色列
		IND,//	印度
		IOT,//	英属印度洋领土
		IRQ,//	伊拉克
		IRN,//	伊朗
		ISL,//	冰岛
		ITA,//	意大利
		JAM,//	牙买加
		JOR,//	约旦
		JPN,//	日本
		KEN,//	肯尼亚
		KGZ,//	吉尔吉斯斯坦
		KHM,//	柬埔寨
		KIR,//	基里巴斯
		COM,//	科摩罗
		KNA,//	圣基茨和尼维斯
		PRK,//	朝鲜
		KOR,//	韩国
		KWT,//	科威特
		CYM,//	开曼群岛
		KAZ,//	哈萨克斯坦
		LAO,//	老挝
		LBN,//	黎巴嫩
		LCA,//	圣卢西亚
		LIE,//	列支敦士登
		LKA,//	斯里兰卡
		LBR,//	利比里亚
		LSO,//	莱索托
		LTU,//	立陶宛
		LUX,//	卢森堡
		LVA,//	拉脱维亚
		LBY,//	利比亚
		MAR,//	摩洛哥
		MCO,//	摩纳哥
		MDA,//	摩尔多瓦
		MDG,//	马达加斯加
		MHL,//	马绍尔群岛
		MKD,//	马斯顿
		MLI,//	马里
		MMR,//	缅甸
		MNG,//	蒙古
		MAC,//	澳门
		MNP,//	北马里亚纳
		MTQ,//	马提尼克
		MRT,//	毛里塔尼亚
		MSR,//	蒙特塞拉特
		MLT,//	马耳他
		MUS,//	毛里求斯
		MDV,//	马尔代夫
		MWI,//	马拉维
		MEX,//	墨西哥
		MYS,//	马来西亚
		MOZ,//	莫桑比克
		NAM,//	纳米比亚
		NCL,//	新喀里多尼亚
		NER,//	尼日尔
		NFK,//	诺福克岛
		NGA,//	尼日利亚
		NIC,//	尼加拉瓜
		NLD,//	荷兰
		NOR,//	挪威
		NPL,//	尼泊尔
		NRU,//	瑙鲁
		NIU,//	纽埃
		NZL,//	新西兰
		OMN,//	阿曼
		PAN,//	巴拿马
		PER,//	秘鲁
		PYF,//	法属波利尼西亚
		PNG,//	巴布亚新几内亚
		PHL,//	菲律宾
		PAK,//	巴基斯坦
		POL,//	波兰
		SPM,//	圣皮埃尔和密克隆
		PCN,//	皮特凯恩群岛
		PRI,//	波多黎各
		PST,//	巴勒斯坦
		PRT,//	葡萄牙
		PLW,//	贝劳
		PRY,//	巴拉圭
		QAT,//	卡塔尔
		REU,//	留尼汪
		ROM,//	罗马尼亚
		RUS,//	俄罗斯
		RWA,//	卢旺达
		SAU,//	沙特阿拉伯
		SLB,//	所罗门群岛
		SYC,//	塞舌尔
		SDN,//	苏丹
		SWE,//	瑞典
		SGP,//	新加坡
		SHN,//	圣赫勒拿
		SVN,//	斯洛文尼亚
		SJM,//	斯瓦尔巴群岛
		SVK,//	斯洛伐克
		SLE,//	塞拉利昂
		SMR,//	圣马力诺
		SEN,//	塞内加尔
		SOM,//	索马里
		SUR,//	苏里南
		STP,//	圣多美和普林西比
		SLV,//	萨尔瓦多
		SYR,//	叙利亚
		SWZ,//	斯威士兰
		TCA,//	特克斯科斯群岛
		TCD,//	乍得
		ATF,//	法属南部领土
		TGO,//	多哥
		THA,//	泰国
		TJK,//	塔吉克斯坦
		TKL,//	托克劳
		TKM,//	土库曼斯坦
		TUN,//	突尼斯
		TON,//	汤加
		TMP,//	东帝汶
		TUR,//	土耳其
		TTO,//	特立尼达和多巴哥
		TUV,//	图瓦卢
		TZA,//	坦桑尼亚
		UKR,//	乌克兰
		UGA,//	乌干达
		UMI,//	美属太平洋各群岛
		USA,//	美国
		URY,//	乌拉圭
		UZB,//	乌兹别克斯坦
		VAT,//	梵蒂冈
		VCT,//	圣文森特和格林纳丁斯
		VEN,//	委内瑞拉
		VGB,//	英属维尔京群岛
		VIR,//	美属维尔京群岛
		VNM,//	越南
		VUT,//	瓦努阿图
		WLF,//	瓦利斯和富图纳群岛
		WSM,//	西萨摩亚
		YEM,//	也门
		MYT,//	马约特
		YUG,//	南斯拉夫
		ZAF,//	南非
		ZMB,//	赞比亚
		ZAR,//	扎伊尔
		ZWE,//	津巴布韦

	};

	static QMap<quint32, QString> &GetMap();
	static QString	EnumName();
};

//信号类型
class CSignalType
{
public:
	enum ESignalType
	{
		Unknown = 0,//未知
		RadarSig = 1,//雷达信号
		SW = 2,//短波
		SSW = 3,//超短波
		MicroWave = 4,//微波
		Report = 5,   //话报
		MissileRemote = 6, //导弹遥测
		HopFreq = 7,//跳频
		SpreadFreq = 8,     //扩频
		Link16 = 9,//Link16
		TACAN = 10,//塔康
		AIS = 11,//AIS
		ACARS = 12,//ACARS
		ADS_B = 13,//ADS-B
		IFF = 14,//IFF 
		IFF_US = 141,//美制IFF 
		IFF_RUS = 142,//俄制IFF
		IFFQue_US = 143,//美制IFF询问
		IFFRes_US = 144,//美制IFF应答 
		Gen_DataLink = 15,//常规数据链信号
		Link11 = 151,//Link11数据链信号
		Link4A = 152,//Link4A数据链信号
		link14 = 153,//Link14数据链信号
		Universal_Satellite = 16,//卫星信号		
		Sea_Third_Satellite = 161,//海事三代卫星信号		
		Sea_Forth_Satellite = 162,//海事四代卫星信号		
		MaritimeIridium = 163,//铱星卫星信号		
		NStar = 164,//NStar		
		MSS = 165,//MSS		
		Tactics_Star = 166,//战术星		
		Orbcomm = 167,//Orbcomm
		SubmarineBuoy = 17,//反潜浮标信号
	};

	static QMap<quint32, QString> &GetMap();
	static QString	EnumName();

};

//定位方式
class COrientType
{
public:
	enum EOrientType
	{
		Unknown = 0,			//未知(缺省无效值)
		SinglePlane = 1,		//单机交会定位
		SinglePlaneFast = 2,	//单机快速定位
		DoublePlane = 3,		//双机交会定位
		SkyFloorCoop = 4,		//空地协同定位
		Manpower = 5,			//人工定位
		SingleStation = 6,		//单站定位
	};

	static QMap<quint32, QString> &GetMap();
	static QString	EnumName();
};

//射频类型
class CRFType
{
public:
	enum ERFType
	{
		Unknown = 0,			//未知
		Fixed = 1,				//固定射频
		Opt = 2,				//射频可选择
		AssAgg = 3,				//射频分集
		ShotChange = 4,			//频率捷变
		PulseMidSC = 5,			//射频脉间捷变
		PulseArrSC = 6,			//射频脉组捷变
		ConWave    = 7,			//连续波
		Noise	   = 8,			//噪声
		Uneven	   = 9,			//参差
		Coding     = 10,		//编码
		ModulateFreq = 11,		//调频
		Complex    = 12,		//复合
		Other		= 254,		//其它
		Invalid     = 255,		//无效
	};

	static QMap<quint32, QString> &GetMap();
	static QString	EnumName();
};

//重复间隔类型
class CPRIType
{
public:
	enum EPRIType
	{
		Unknown = 0,			//未知
		Fixed = 1,				//固定
		Uneven = 2,				//参差
		JumpChange = 3,			//跳变
		Wobble	= 4,			//抖动
		Coding = 5,				//编码
		GlideChange = 6,		//滑变
		ArrayChange = 7,		//组变
		FrameConver	= 9,		//帧间转换
		Opt = 10,				//可选择
		Other = 254,			//其它
		Invalid = 255,			//无效
	};

	static QMap<quint32, QString> &GetMap();
	static QString	EnumName();
};

//脉宽类型
class CPWType
{
public:
	enum EPWType
	{
		Unknown = 0,			//未知
		Fixed = 1,				//固定
		Coding = 2,				//编码
		ShotChange = 3,			//捷变
		Opt = 4,				//可选择
		Complex = 5,			//复合
		DoublePulse = 6,		//双脉冲
		MultiPulse = 7,			//多脉冲
		Other = 254,			//其它
		Invalid = 255,			//无效
	};

	static QMap<quint32, QString> &GetMap();
	static QString	EnumName();
};

// 模式号代号
class CIFFModeNo
{
public:
	enum EIFFModeType
	{
		Unknown = 0,    // 未知
		M1Question = 1,    // M-1询问
		M2Question = 2,    // M-2询问
		M3AQuestion = 3,    // M-3/A询问
		MBQuestion = 4,    // M-B询问
		MCQuestion = 5,    // M-C询问
		MDQuestion = 6,    // M-D询问
		M4_2USQuestion = 7,    // M-4询问2微妙
		M4_1USQuestion = 8,    // M-4询问1微妙
		S_MODEQuestion16Dot25 = 9,    // S-MODE询问16.25
		S_MODEQuestion32Dot25 = 10,   // S-MODE询问30.25
		MarkAnswer = 11,   // Mark系列应答
		M4Answer = 12,   // M-4应答
		S_MODEAnswer56bit = 13,   // S模式56bit应答
		S_MODEAnswer112bit = 14,   // S模式112bit应答
		M_S_ASCall = 15,   // M_S_A/S全呼叫
		M_S_CSCall = 16,   // M_S_C/S全呼叫
		M_S_ACall = 17,   // M_S_A仅A全呼叫
		M_S_CCall = 18,   // M_S_C仅C全呼叫
		M_1_Answer = 19,   // M_1应答
		M_2_Answer = 20,   // M_2应答
		M_3A_Answer = 21,   // M_3/A应答
		M_C_Answer = 22,   // M_C应答
		LEV1 = 23,   // 预留2
		LEV2 = 24,   // 预留3
		M5SK = 25,   // M5询问
		M5L1 = 26,   // M5应答Level1
		M5L2 = 27,   // M5应答Level2
		AA = 51,   // A511-A询问
		AB = 52,   // A511-B询问
		AAAS = 53,   // A511-A应答
		ABAS = 54,   // A511-B应答
		R1A = 55,   // R-1A询问
		R1B = 56,   // R-1B询问
		R2A = 57,   // R-2A询问
		R2B = 58,   // R-2B询问
		R346 = 59,   // R-3,4,6询问
		R1AS = 60,   // R-1应答
		R2AS = 61,   // R-2应答
		R3AS = 62,   // R-3应答
		R4AS = 63,   // R-4应答
		R6AS = 64,   // R-6应答
		RB = 65,   // R-Beacon
		RLev1 = 66,   // R-预留1
		RLev2 = 67,   // R-预留2
		AttRad_HighLevOri = 68,   // 调度雷达询问高度剩油
		AttRad_PlaneID = 69,   // 调度雷达询问机号
		AttRad_Answer = 70,   // 调度雷达询问应答信号(不加信息)
		AttRad_Speed = 71,   // 调度雷达询问速度
		A5xxLR_ASHelp = 72,   // A - 5xx着陆雷达应答(呼救)
		A5xxDR_Answer = 73,   // A - 5xx探测雷达应答
		A5xxLR_ASUnderca = 74,   // A - 5xx着陆雷达应答(放起落架)
		A5xxLR_Answer = 75,   // A - 5xx着陆雷达应答
		A5xxAD_ASHelp = 76,   // A - 5xx调度雷达不含信息应答(呼救)
		A5xxAD_Answer = 77,   // A - 5xx调度雷达不含信息应答
		A5xxAD_ASPlaneIDHelp = 78,   // A - 5xx调度雷达机号应答(呼救)
		A5xxAD_ASPlaneID = 79,   // A - 5xx调度雷达机号应答
		A5xxAD_ASSpeedHelp = 80,   // A - 5xx调度雷达速度应答(呼救)
		A5xxAD_ASSpeed = 81,   // A - 5xx调度雷达速度应答
		A5xxAD_ASHighLevOriHelp = 82,   // A - 5xx调度雷达高度剩油应答(呼救)
		A5xxAD_ASHighLevOri = 83,   // A - 5xx调度雷达高度剩油应答
		OtherFreq = 84,   // 其他频率模式
		Other = 254,  // 其他
		Invalid = 255,  //无效
	};
	static QMap<quint32, QString> &GetMap();
	static QString EnumName();
	static QList<int> NormalModeNoList();
	static QList<int> Mode4ModeNoList();
	static QList<int> ModeSModeNoList();

	static QList<int> NormalMode1NoList();
	static QList<int> NormalMode2NoList();
	static QList<int> NormalMode3ANoList();
	static QList<int> NormalModeCNoList();
};

//空速代码
class CAirSpeedCode
{
public:
	enum EAirSpeedType
	{
		UnWork = 0,			//ACAS不工作
		S140KMH = 1,		//140公里/小时(75英尺)
		S140To280KMH = 2,	//≥140公里/小时≤280公里/小时(75和150英尺)
		S280To560KMH = 3,	//＞280公里/小时≤560公里/小时(150和300英尺)
		S560To1110KMH = 4,	//＞560公里/小时≤1110公里/小时(300和600英尺)
		S1110To2220KMH = 5,	//＞1110公里/小时≤2220公里/小时(600和1200英尺)
		S2220KMH = 6,		//＞2220公里/小时(1200英尺)
	};

	static QMap<quint32, QString> &GetMap();
	static QString EnumName();
};

//状态代码
class CStateCode
{
public:
	enum EStateCode
	{
		NoInfo = 0,		//无信息
		Sky = 1,		//空中
		Land = 2,		//地面
		Unknown = 3,	//不明
		Exigence = 4,	//紧急
		WirelessInvalid = 5,	//无线电失效
		Hijack = 6,		//劫持
		Invalid = 255,	//无效
	};

	static QMap<quint32, QString> &GetMap();
	static QString EnumName();
};

//敌我属性
class CFriendOrFoe
{
public:
	enum EFriendOrFoeType
	{
		Unknown = 0,    //不明
		Foe,            //敌方
		Own,            //我方
		Friend,         //友方
		Neutrality,     //中立
		PotentialFoe,   //潜在敌方
		Unidentified,   //未鉴别
		Undefinition,   //未定义
		Invalid = 255   //无效值
	};
	static QMap<quint32, QString> &GetMap();
	static QString EnumName();
};

//调制方式
class CModulateType
{
public:
	enum EModulateType
	{
		Unknown = 0,			//不明
		AM = 1,					//AM
		FM = 2,					//FM
		CW = 3,					//CW
		FSK2 = 4,				//2FSK
		ASK2 = 5,				//2ASK
		FSK4 = 6,				//4FSK
		BPSK = 7,				//BPSK
		QPSK = 8,				//QPSK
		PSK8 = 9,				//8PSK
		QAM16 = 10,				//16QAM
		MSK = 11,				//MSK
		OQPSK = 12,				//OQPSK
		Pi4DQPSK = 13,			//Pi4DQPSK
		QAM8 = 14,				//8QAM
		APSK16 = 15,			//16APSK
		APSK32 = 16,			//32APSK
		GMSK = 17,				//GMSK
		FM_2FSK = 18,			//FM - 2FSK
		FSK3 = 19,				//3FSK
		UQPSK = 35,				//UQPSK
		PCM_PSK = 36,			//PCM / PSK
		PCM_FM = 37,			//PCM / FM
		PCM_BPSKPM = 38,		//PCM / BPSK / PM
		Link11 = 101,			//Link11
		Link4A = 102,			//Link4A
		Link14 = 103,			//Link14
		Tetra = 104,			//Tetra 信号
		USB = 105,				//USB
		LSB = 106,				//LSB
		ISB = 107,				//ISB
		SAM = 108,				//SAM
		FAX = 109,				//FAX
		FSK = 110,				//FSK
		AFSK = 111,				//AFSK
		DCW = 112,				//DCW
		WFM = 113,				//WFM
		SSB = 115,				//SSB
		FSK8 = 115,				//8FSK
		QAM32 = 116,			//QAM32
		QAM64 = 117,			//QAM64
		QAM128 = 118,			//QAM128
		QAM256 = 119,			//QAM256
		Link16_slew = 123,		//Link16_slew
		ALE2G = 124,			//2G_ALE
		ALE3G = 125,			//3G_ALE
		Other = 999,			//其它

	};

	static QMap<quint32, QString> &GetMap();
	static QString	EnumName();
};

//目标性质
class CTargetCharacter
{
public:
	enum ETargetCharacterType
	{
		Unknown = 0,			// 不明
		Military = 1,			// 军用目标
		Civilian = 2,			// 民用目标
		Paramilitary = 3,		// 准军事目标
		Simulate = 4,			// 模拟目标
		Decoy = 5,				// 假目标
		MC = 6,					// 军民两用目标
		Invalid = 255			// 其他目标
	};

	static QMap<quint32, QString> &GetMap();
	static QString	EnumName();
};

//目标任务
class CTargetTask
{
public:
	enum ETargetTaskType
	{
		Unknown = 0,						//不明	公共
		Duty_B = 1001,						//值勤	舰船
		Train_B = 1002,						//训练	舰船
		Manoeuvre_B = 1003,					//演习	舰船
		Spy_B = 1004,						//侦察	舰船
		Battle_B = 1005,					//作战	舰船
		Stakeout_B = 1006,					//监视	舰船
		ProtectHalieutics_B = 1007,			//护渔	舰船
		SearchHelp_B = 1008,				//搜救	舰船
		Comm3Area_B = 1009,					//两岸三通	舰船
		ProtectTrader_B = 1010,				//商船护航	舰船
		Shakedown_B = 1011,					//试航	舰船
		Boat_B = 1012,						//航渡	舰船
		Work_B = 1013,						//作业	舰船
		Guard_B = 1014,						//警戒	舰船
		Logistics_B = 1015,					//后勤	舰船
		Transport_B = 1016,					//舰船运输	舰船
		Inbreak_B = 1017,					//舰船入侵	舰船
		Patrol_P = 2001,					//巡逻	飞机
		Train_P = 2002,						//训练	飞机
		SwitchField_P = 2003,				//转场	飞机
		ProtectFly_P = 2004,				//护航	飞机
		Spy_P = 2005,						//侦察	飞机
		Airdrop_P = 2006,					//空投	飞机
		Battle_P = 2007,					//作战	飞机
		Manoeuvre_P = 2008,					//演习	飞机
		Duty_P = 2009,						//勤务	飞机
		Comm3Area_P = 2010,					//两岸三通	飞机
		SpecialTransport_P = 2011,			//要员专送	飞机
		Transport_P = 2012,					//飞机运输	飞机
		Inbreak_P = 2013,					//飞机入侵	飞机
		Train_M = 4001,						//演训	导弹
		Attack_M = 4002,					//攻击	导弹
		Other = 99999,						//其它	公共

	};

	static QMap<quint32, QString> &GetMap();
	static QString	EnumName();
};

//目标分类
class CTargetType
{
public:
	enum ETargetType
	{
		Unknown = 0,		// 不明
		Land = 1,			// 陆地目标
		Sea = 2,			// 海洋目标
		Sky = 3,			// 空中目标
		Plane = 301,		// 飞机
		Equip = 4,			// 装备
		Weapon = 5,			// 武器
		Space = 6,			// 空间
		Army = 8,			// 部队
		Other = 99			// 其他
	};

	static QMap<quint32, QString> &GetMap();
	static QString	EnumName();
};

//响应故障码
class CResponseFaultCode
{
public:
	enum ERespFaultType
	{
		Normal				= 0,	//正常
		FrameStructError	= 1,	//帧结构错误
		FrameLenError		= 2,	//帧长错误
		SourceLogicIdError	= 3,	//源逻辑ID错误
		DestLogicIdError	= 4,	//目的逻辑ID错误
		InfoTypeError		= 5,	//信息类别错误
		InfoSubTypeError	= 6,	//信息子类错误
		DataParamError		= 7		//数据区参数错误
	};

	static QMap<quint32, QString> &GetMap();
	static QString	EnumName();
};

//职称类型
class CProfessionalTitleTypes
{
public:
    enum EProfessionalTitleType
    {
        AssistantEngineer=1,//助理工程师
        Engineer=2,//工程师
        SeniorEngineer=3,//高级工程师
        AssistantTranslator=4,//助理翻译
        Translator=5,//翻译
        AssociateSeniorTranslator=6,//副译审
        SeniorTranslator=7,//译审
        ResearchIntern=8,//实习研究员
        AssociateResearchFellow=9,//副研究员
        ResearchFellow=10,//研究员
        Technician=11   //技师
    };
    static QMap<quint32, QString> &GetMap();
    static QString EnumName();
};

//专业类型
class CMajorTypes
{
public:
    enum EMajorType
    {
       CommandControlCommunication=1,//指控通信专业
       RadarSignal=2,//雷达信号专业
       CommunicationSignal=3,//通信信号专业
       TOEC=4,//光电专业
       Link16Signal=5,//Link16信号专业
       IFF_TACANSignal=6,//IFF和TACAN信号专业
       MessageProcess=7,//情报处理专业
       Language=8,//语言专业
    };
    static QMap<quint32, QString> &GetMap();
    static QString EnumName();
};

}

#endif // SYSENUMSET_H