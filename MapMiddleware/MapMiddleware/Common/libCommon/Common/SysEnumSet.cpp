#include "SysEnumSet.h"

using namespace NS_SYS_Enum;

QMap<quint32, QString> &CSystemNum::GetMap()
{
    static QMap<quint32,QString> map;
	map.insert(TaskSys, QStringLiteral("任务系统总体"));
	map.insert(RS, QStringLiteral("雷达信号侦测分系统"));
	map.insert(CSR, QStringLiteral("通信信号侦测分系统"));
	map.insert(TLR, QStringLiteral("Link16信号侦测分系统"));
	map.insert(ITR, QStringLiteral("IFF/TACAN信号侦测分系统"));
    map.insert(OF,QStringLiteral("光电侦察分系统"));
	map.insert(CIS_ZK, QStringLiteral("指挥控制与情报处理分系统(指控子系统)"));
	map.insert(CIS_QB, QStringLiteral("指挥控制与情报处理分系统(情报处理子系统)"));
    map.insert(CS,QStringLiteral("任务通信分系统"));
    map.insert(GAS,QStringLiteral("地面处理与应用系统"));
	map.insert(Invalid, QStringLiteral("无效值"));

    return map;
}

QString CSystemNum::EnumName()
{
	return QStringLiteral("分系统编号");
}

QMap<quint32, QString> &CRoleNum::GetMap()
{
    static QMap<quint32,QString> map;
    map.insert(Invalid,QStringLiteral("无效角色"));
	map.insert(RadarSigMaster, QStringLiteral("雷达信号主控侦测角色"));
	map.insert(RadarSigAssist, QStringLiteral("雷达信号副控侦测角色"));
	map.insert(CommonSig, QStringLiteral("通信信号侦测角色"));
	map.insert(EspecialSig, QStringLiteral("特殊信号侦测角色2"));
	map.insert(Link16, QStringLiteral("Link16信号侦测角色"));
    map.insert(IFF_TACAN,QStringLiteral("IFF和TACAN信号侦测角色"));
	map.insert(TOEC, QStringLiteral("光电侦察角色"));
    map.insert(TaskManage,QStringLiteral("任务管理角色"));
    map.insert(QBProcess,QStringLiteral("情报处理角色"));

    return map;
}

QString CRoleNum::EnumName()
{
	return QStringLiteral("角色编号");
}

QMap<quint32, QString> &CDisplayCtrlDeviceNum::GetMap()
{
    static QMap<quint32,QString> map;
    map.insert(Invalid,QStringLiteral("无效"));
	map.insert(IFF_TACAN, QStringLiteral("IFF/TACAN侦测"));
	map.insert(Link16, QStringLiteral("LINK16侦测"));
	map.insert(Common1, QStringLiteral("通侦1"));
	map.insert(Common2, QStringLiteral("通侦2"));
	map.insert(EspecialSig, QStringLiteral("特殊"));
	map.insert(RadarSignalAssist, QStringLiteral("雷侦副控"));
    map.insert(RadarSpy, QStringLiteral("雷侦主控"));
	map.insert(CommandSubSys, QStringLiteral("指控"));
    map.insert(QBProcess,QStringLiteral("情报处理"));
    map.insert(TOECSpy,QStringLiteral("光侦"));

    return map;
}

QString CDisplayCtrlDeviceNum::EnumName()
{
	return QStringLiteral("显控台位代号");
}

QMap<quint32, QString> & NS_SYS_Enum::CAgingLevel::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(TopPremium, QStringLiteral("特急"));
	map.insert(Premium, QStringLiteral("加急"));
	map.insert(Urgent, QStringLiteral("急"));
	map.insert(Normal, QStringLiteral("平"));
	return map;
}

QString NS_SYS_Enum::CAgingLevel::EnumName()
{
	return QStringLiteral("时效等级");
}

QMap<quint32, QString> & NS_SYS_Enum::CClassiFied::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(TopSecret, QStringLiteral("绝密"));
	map.insert(Confidential, QStringLiteral("机密"));
	map.insert(Secret, QStringLiteral("秘密"));
	map.insert(Interioral, QStringLiteral("内部"));
	map.insert(Publicity, QStringLiteral("公开"));

	return map;
}

QString NS_SYS_Enum::CClassiFied::EnumName()
{
	return QStringLiteral("秘密等级");
}

QMap<quint32, QString> & NS_SYS_Enum::CCountryRegionCode::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(Unknown, QStringLiteral("不明"));
	map.insert(AND, QStringLiteral("安道尔"));
	map.insert(ARE, QStringLiteral("阿联酋"));
	map.insert(AFG, QStringLiteral("阿富汗"));
	map.insert(ATG, QStringLiteral("安提瓜和巴布达"));
	map.insert(AIA, QStringLiteral("安圭拉"));
	map.insert(ALB, QStringLiteral("阿尔巴尼亚"));
	map.insert(ARM, QStringLiteral("亚美尼亚"));
	map.insert(ANT, QStringLiteral("荷属安的列斯"));
	map.insert(AGO, QStringLiteral("安哥拉"));
	map.insert(ATA, QStringLiteral("南极洲"));
	map.insert(ARG, QStringLiteral("阿根廷"));
	map.insert(ASM, QStringLiteral("美属萨摩亚"));
	map.insert(AUT, QStringLiteral("奥地利"));
	map.insert(AUS, QStringLiteral("澳大利亚"));
	map.insert(ABW, QStringLiteral("阿鲁巴"));
	map.insert(AZE, QStringLiteral("阿塞拜疆"));
	map.insert(BIH, QStringLiteral("波斯尼亚和黑塞哥维那"));
	map.insert(BRB, QStringLiteral("巴巴多斯"));
	map.insert(BGD, QStringLiteral("孟加拉国"));
	map.insert(BEL, QStringLiteral("比利时"));
	map.insert(BFA, QStringLiteral("布基纳法索"));
	map.insert(BGR, QStringLiteral("保加利亚"));
	map.insert(BHR, QStringLiteral("巴林"));
	map.insert(BDI, QStringLiteral("布隆迪"));
	map.insert(BEN, QStringLiteral("贝宁"));
	map.insert(BMU, QStringLiteral("百慕大"));
	map.insert(BRN, QStringLiteral("文莱"));
	map.insert(BOL, QStringLiteral("玻利维亚"));
	map.insert(BRA, QStringLiteral("巴西"));
	map.insert(BHS, QStringLiteral("巴哈马"));
	map.insert(BTN, QStringLiteral("不丹"));
	map.insert(BVT, QStringLiteral("布维岛"));
	map.insert(BWA, QStringLiteral("博茨瓦纳"));
	map.insert(BLR, QStringLiteral("白俄罗斯"));
	map.insert(BLZ, QStringLiteral("伯利兹"));
	map.insert(CAN, QStringLiteral("加拿大"));
	map.insert(CCK, QStringLiteral("科科斯(基林)群岛"));
	map.insert(CAF, QStringLiteral("中非"));
	map.insert(COG, QStringLiteral("刚果"));
	map.insert(CHE, QStringLiteral("瑞士"));
	map.insert(CIV, QStringLiteral("科特迪瓦"));
	map.insert(COK, QStringLiteral("库克群岛"));
	map.insert(CHL, QStringLiteral("智利"));
	map.insert(CMR, QStringLiteral("喀麦隆"));
	map.insert(CHN, QStringLiteral("中国"));
	map.insert(COL, QStringLiteral("哥伦比亚"));
	map.insert(CRI, QStringLiteral("哥斯达黎加"));
	map.insert(CTN, QStringLiteral("台湾"));
	map.insert(CUB, QStringLiteral("古巴"));
	map.insert(CPV, QStringLiteral("佛得角"));
	map.insert(CYP, QStringLiteral("塞浦路斯"));
	map.insert(CZE, QStringLiteral("捷克"));
	map.insert(DEU, QStringLiteral("德国"));
	map.insert(DJI, QStringLiteral("吉布提"));
	map.insert(DNK, QStringLiteral("丹麦"));
	map.insert(DMA, QStringLiteral("多米尼克"));
	map.insert(DOM, QStringLiteral("多米尼加共和国"));
	map.insert(DZA, QStringLiteral("阿尔及利亚"));
	map.insert(ECU, QStringLiteral("厄瓜多尔"));
	map.insert(EST, QStringLiteral("爱沙尼亚"));
	map.insert(EGY, QStringLiteral("埃及"));
	map.insert(ESH, QStringLiteral("西撒哈拉"));
	map.insert(ERI, QStringLiteral("厄立特里亚"));
	map.insert(ESP, QStringLiteral("西班牙"));
	map.insert(ETH, QStringLiteral("埃塞俄比亚"));
	map.insert(FIN, QStringLiteral("芬兰"));
	map.insert(FJI, QStringLiteral("斐济"));
	map.insert(FLK, QStringLiteral("马尔维纳斯群岛(福克兰群岛)"));
	map.insert(FSM, QStringLiteral("密克罗尼西亚"));
	map.insert(FRO, QStringLiteral("法罗群岛"));
	map.insert(FRA, QStringLiteral("法国"));
	map.insert(GAB, QStringLiteral("加蓬"));
	map.insert(GBR, QStringLiteral("英国"));
	map.insert(GRD, QStringLiteral("格林纳达"));
	map.insert(GEO, QStringLiteral("格鲁吉亚"));
	map.insert(GUF, QStringLiteral("法属圭亚那"));
	map.insert(GHA, QStringLiteral("加纳"));
	map.insert(GIB, QStringLiteral("直布罗陀"));
	map.insert(GRL, QStringLiteral("格陵兰"));
	map.insert(GMB, QStringLiteral("冈比亚"));
	map.insert(GIN, QStringLiteral("几内亚"));
	map.insert(GLP, QStringLiteral("瓜德罗普"));
	map.insert(GNQ, QStringLiteral("赤道几内亚"));
	map.insert(GRC, QStringLiteral("希腊"));
	map.insert(SGS, QStringLiteral("南乔治亚岛和南桑德韦奇岛"));
	map.insert(GTM, QStringLiteral("危地马拉"));
	map.insert(GUM, QStringLiteral("关岛"));
	map.insert(GNB, QStringLiteral("几内亚比绍"));
	map.insert(GUY, QStringLiteral("圭亚那"));
	map.insert(HKG, QStringLiteral("香港"));
	map.insert(HMD, QStringLiteral("赫德岛和麦克唐纳岛"));
	map.insert(HND, QStringLiteral("洪都拉斯"));
	map.insert(HRV, QStringLiteral("克罗地亚"));
	map.insert(HTI, QStringLiteral("海地"));
	map.insert(HUN, QStringLiteral("匈牙利"));
	map.insert(IDN, QStringLiteral("印度尼西亚"));
	map.insert(IRL, QStringLiteral("爱尔兰"));
	map.insert(ISR, QStringLiteral("以色列"));
	map.insert(IND, QStringLiteral("印度"));
	map.insert(IOT, QStringLiteral("英属印度洋领土"));
	map.insert(IRQ, QStringLiteral("伊拉克"));
	map.insert(IRN, QStringLiteral("伊朗"));
	map.insert(ISL, QStringLiteral("冰岛"));
	map.insert(ITA, QStringLiteral("意大利"));
	map.insert(JAM, QStringLiteral("牙买加"));
	map.insert(JOR, QStringLiteral("约旦"));
	map.insert(JPN, QStringLiteral("日本"));
	map.insert(KEN, QStringLiteral("肯尼亚"));
	map.insert(KGZ, QStringLiteral("吉尔吉斯斯坦"));
	map.insert(KHM, QStringLiteral("柬埔寨"));
	map.insert(KIR, QStringLiteral("基里巴斯"));
	map.insert(COM, QStringLiteral("科摩罗"));
	map.insert(KNA, QStringLiteral("圣基茨和尼维斯"));
	map.insert(PRK, QStringLiteral("朝鲜"));
	map.insert(KOR, QStringLiteral("韩国"));
	map.insert(KWT, QStringLiteral("科威特"));
	map.insert(CYM, QStringLiteral("开曼群岛"));
	map.insert(KAZ, QStringLiteral("哈萨克斯坦"));
	map.insert(LAO, QStringLiteral("老挝"));
	map.insert(LBN, QStringLiteral("黎巴嫩"));
	map.insert(LCA, QStringLiteral("圣卢西亚"));
	map.insert(LIE, QStringLiteral("列支敦士登"));
	map.insert(LKA, QStringLiteral("斯里兰卡"));
	map.insert(LBR, QStringLiteral("利比里亚"));
	map.insert(LSO, QStringLiteral("莱索托"));
	map.insert(LTU, QStringLiteral("立陶宛"));
	map.insert(LUX, QStringLiteral("卢森堡"));
	map.insert(LVA, QStringLiteral("拉脱维亚"));
	map.insert(LBY, QStringLiteral("利比亚"));
	map.insert(MAR, QStringLiteral("摩洛哥"));
	map.insert(MCO, QStringLiteral("摩纳哥"));
	map.insert(MDA, QStringLiteral("摩尔多瓦"));
	map.insert(MDG, QStringLiteral("马达加斯加"));
	map.insert(MHL, QStringLiteral("马绍尔群岛"));
	map.insert(MKD, QStringLiteral("马斯顿"));
	map.insert(MLI, QStringLiteral("马里"));
	map.insert(MMR, QStringLiteral("缅甸"));
	map.insert(MNG, QStringLiteral("蒙古"));
	map.insert(MAC, QStringLiteral("澳门"));
	map.insert(MNP, QStringLiteral("北马里亚纳"));
	map.insert(MTQ, QStringLiteral("马提尼克"));
	map.insert(MRT, QStringLiteral("毛里塔尼亚"));
	map.insert(MSR, QStringLiteral("蒙特塞拉特"));
	map.insert(MLT, QStringLiteral("马耳他"));
	map.insert(MUS, QStringLiteral("毛里求斯"));
	map.insert(MDV, QStringLiteral("马尔代夫"));
	map.insert(MWI, QStringLiteral("马拉维"));
	map.insert(MEX, QStringLiteral("墨西哥"));
	map.insert(MYS, QStringLiteral("马来西亚"));
	map.insert(MOZ, QStringLiteral("莫桑比克"));
	map.insert(NAM, QStringLiteral("纳米比亚"));
	map.insert(NCL, QStringLiteral("新喀里多尼亚"));
	map.insert(NER, QStringLiteral("尼日尔"));
	map.insert(NFK, QStringLiteral("诺福克岛"));
	map.insert(NGA, QStringLiteral("尼日利亚"));
	map.insert(NIC, QStringLiteral("尼加拉瓜"));
	map.insert(NLD, QStringLiteral("荷兰"));
	map.insert(NOR, QStringLiteral("挪威"));
	map.insert(NPL, QStringLiteral("尼泊尔"));
	map.insert(NRU, QStringLiteral("瑙鲁"));
	map.insert(NIU, QStringLiteral("纽埃"));
	map.insert(NZL, QStringLiteral("新西兰"));
	map.insert(OMN, QStringLiteral("阿曼"));
	map.insert(PAN, QStringLiteral("巴拿马"));
	map.insert(PER, QStringLiteral("秘鲁"));
	map.insert(PYF, QStringLiteral("法属波利尼西亚"));
	map.insert(PNG, QStringLiteral("巴布亚新几内亚"));
	map.insert(PHL, QStringLiteral("菲律宾"));
	map.insert(PAK, QStringLiteral("巴基斯坦"));
	map.insert(POL, QStringLiteral("波兰"));
	map.insert(SPM, QStringLiteral("圣皮埃尔和密克隆"));
	map.insert(PCN, QStringLiteral("皮特凯恩群岛"));
	map.insert(PRI, QStringLiteral("波多黎各"));
	map.insert(PST, QStringLiteral("巴勒斯坦"));
	map.insert(PRT, QStringLiteral("葡萄牙"));
	map.insert(PLW, QStringLiteral("贝劳"));
	map.insert(PRY, QStringLiteral("巴拉圭"));
	map.insert(QAT, QStringLiteral("卡塔尔"));
	map.insert(REU, QStringLiteral("留尼汪"));
	map.insert(ROM, QStringLiteral("罗马尼亚"));
	map.insert(RUS, QStringLiteral("俄罗斯"));
	map.insert(RWA, QStringLiteral("卢旺达"));
	map.insert(SAU, QStringLiteral("沙特阿拉伯"));
	map.insert(SLB, QStringLiteral("所罗门群岛"));
	map.insert(SYC, QStringLiteral("塞舌尔"));
	map.insert(SDN, QStringLiteral("苏丹"));
	map.insert(SWE, QStringLiteral("瑞典"));
	map.insert(SGP, QStringLiteral("新加坡"));
	map.insert(SHN, QStringLiteral("圣赫勒拿"));
	map.insert(SVN, QStringLiteral("斯洛文尼亚"));
	map.insert(SJM, QStringLiteral("斯瓦尔巴群岛"));
	map.insert(SVK, QStringLiteral("斯洛伐克"));
	map.insert(SLE, QStringLiteral("塞拉利昂"));
	map.insert(SMR, QStringLiteral("圣马力诺"));
	map.insert(SEN, QStringLiteral("塞内加尔"));
	map.insert(SOM, QStringLiteral("索马里"));
	map.insert(SUR, QStringLiteral("苏里南"));
	map.insert(STP, QStringLiteral("圣多美和普林西比"));
	map.insert(SLV, QStringLiteral("萨尔瓦多"));
	map.insert(SYR, QStringLiteral("叙利亚"));
	map.insert(SWZ, QStringLiteral("斯威士兰"));
	map.insert(TCA, QStringLiteral("特克斯科斯群岛"));
	map.insert(TCD, QStringLiteral("乍得"));
	map.insert(ATF, QStringLiteral("法属南部领土"));
	map.insert(TGO, QStringLiteral("多哥"));
	map.insert(THA, QStringLiteral("泰国"));
	map.insert(TJK, QStringLiteral("塔吉克斯坦"));
	map.insert(TKL, QStringLiteral("托克劳"));
	map.insert(TKM, QStringLiteral("土库曼斯坦"));
	map.insert(TUN, QStringLiteral("突尼斯"));
	map.insert(TON, QStringLiteral("汤加"));
	map.insert(TMP, QStringLiteral("东帝汶"));
	map.insert(TUR, QStringLiteral("土耳其"));
	map.insert(TTO, QStringLiteral("特立尼达和多巴哥"));
	map.insert(TUV, QStringLiteral("图瓦卢"));
	map.insert(TZA, QStringLiteral("坦桑尼亚"));
	map.insert(UKR, QStringLiteral("乌克兰"));
	map.insert(UGA, QStringLiteral("乌干达"));
	map.insert(UMI, QStringLiteral("美属太平洋各群岛"));
	map.insert(USA, QStringLiteral("美国"));
	map.insert(URY, QStringLiteral("乌拉圭"));
	map.insert(UZB, QStringLiteral("乌兹别克斯坦"));
	map.insert(VAT, QStringLiteral("梵蒂冈"));
	map.insert(VCT, QStringLiteral("圣文森特和格林纳丁斯"));
	map.insert(VEN, QStringLiteral("委内瑞拉"));
	map.insert(VGB, QStringLiteral("英属维尔京群岛"));
	map.insert(VIR, QStringLiteral("美属维尔京群岛"));
	map.insert(VNM, QStringLiteral("越南"));
	map.insert(VUT, QStringLiteral("瓦努阿图"));
	map.insert(WLF, QStringLiteral("瓦利斯和富图纳群岛"));
	map.insert(WSM, QStringLiteral("西萨摩亚"));
	map.insert(YEM, QStringLiteral("也门"));
	map.insert(MYT, QStringLiteral("马约特"));
	map.insert(YUG, QStringLiteral("南斯拉夫"));
	map.insert(ZAF, QStringLiteral("南非"));
	map.insert(ZMB, QStringLiteral("赞比亚"));
	map.insert(ZAR, QStringLiteral("扎伊尔"));
	map.insert(ZWE, QStringLiteral("津巴布韦"));

	return map;
}

QString NS_SYS_Enum::CCountryRegionCode::EnumName()
{
	return QStringLiteral("国家地区");
}

QMap<quint32, QString> & CSignalType::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(Unknown, QStringLiteral("未知"));
	map.insert(RadarSig, QStringLiteral("雷达信号"));
	map.insert(SW, QStringLiteral("短波"));
	map.insert(SSW, QStringLiteral("超短波"));
	map.insert(Report, QStringLiteral("话报"));
	map.insert(MissileRemote, QStringLiteral("导弹遥测"));
	map.insert(HopFreq, QStringLiteral("跳频"));
	map.insert(SpreadFreq, QStringLiteral("扩频"));
	map.insert(Link16, QStringLiteral("Link16"));
	map.insert(TACAN, QStringLiteral("塔康信号"));
	map.insert(AIS, QStringLiteral("AIS信号"));
	map.insert(ACARS, QStringLiteral("ACARS信号"));
	map.insert(ADS_B, QStringLiteral("ADS_B信号"));
	map.insert(IFF, QStringLiteral("IFF信号"));
	map.insert(IFF_US, QStringLiteral("美制IFF"));
	map.insert(IFF_RUS, QStringLiteral("俄制IFF"));
	map.insert(IFFQue_US, QStringLiteral("美制IFF询问"));
	map.insert(IFFRes_US, QStringLiteral("美制IFF应答"));
	map.insert(Gen_DataLink, QStringLiteral("常规数据链信号"));
	map.insert(Link11, QStringLiteral("Link11信号"));
	map.insert(Link4A, QStringLiteral("Link4A信号"));
	map.insert(link14, QStringLiteral("link14信号"));
	map.insert(Universal_Satellite, QStringLiteral("卫星信号"));
	map.insert(Sea_Third_Satellite, QStringLiteral("海事三代卫星信号"));
	map.insert(Sea_Forth_Satellite, QStringLiteral("海事四代卫星信号"));
	map.insert(MaritimeIridium, QStringLiteral("铱星卫星信号"));
	map.insert(NStar, QStringLiteral("NStar信号"));
	map.insert(MSS, QStringLiteral("MSS信号"));
	map.insert(Tactics_Star, QStringLiteral("战术星信号"));
	map.insert(Orbcomm, QStringLiteral("Orbcomm信号"));
	map.insert(SubmarineBuoy, QStringLiteral("反潜浮标信号"));

	return map;
}

QString CSignalType::EnumName()
{
	return QStringLiteral("信号类型");
}

QMap<quint32, QString> & COrientType::GetMap()
{
	static QMap<quint32,QString> map;
	map.insert(Unknown, QStringLiteral("未知"));
	map.insert(SinglePlane, QStringLiteral("单机交会定位"));
	map.insert(SinglePlaneFast, QStringLiteral("单机快速定位"));
	map.insert(DoublePlane, QStringLiteral("双机交会定位"));
	map.insert(SkyFloorCoop, QStringLiteral("空地协同定位"));
	map.insert(Manpower, QStringLiteral("人工定位"));
	map.insert(SingleStation, QStringLiteral("单站定位"));

	return map;
}

QString COrientType::EnumName()
{
	return QStringLiteral("定位方式");
}


//雷达射频类型
QMap<quint32, QString> & CRFType::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(Unknown, QStringLiteral("未知"));
	map.insert(Fixed, QStringLiteral("固定射频"));
	map.insert(Opt, QStringLiteral("射频可选择"));
	map.insert(AssAgg, QStringLiteral("射频分集"));
	map.insert(ShotChange, QStringLiteral("频率捷变"));
	map.insert(PulseMidSC, QStringLiteral("射频脉间捷变"));
	map.insert(PulseArrSC, QStringLiteral("射频脉组捷变"));
	map.insert(ConWave, QStringLiteral("连续波"));
	map.insert(Noise, QStringLiteral("噪声"));
	map.insert(Uneven, QStringLiteral("参差"));
	map.insert(Coding, QStringLiteral("编码"));
	map.insert(ModulateFreq, QStringLiteral("调频"));
	map.insert(Complex, QStringLiteral("复合"));
	map.insert(Other, QStringLiteral("其它"));
	map.insert(Invalid, QStringLiteral("无效"));

	return map;
}

QString CRFType::EnumName()
{
	return QStringLiteral("射频类型");
}


//雷达重复间隔类型
QMap<quint32, QString> & CPRIType::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(Unknown, QStringLiteral("未知"));
	map.insert(Fixed, QStringLiteral("固定"));
	map.insert(Uneven, QStringLiteral("参差"));
	map.insert(JumpChange, QStringLiteral("跳变"));
	map.insert(Wobble, QStringLiteral("抖动"));
	map.insert(Coding, QStringLiteral("编码"));
	map.insert(GlideChange, QStringLiteral("滑变"));
	map.insert(ArrayChange, QStringLiteral("组变"));
	map.insert(8, QStringLiteral("多普勒"));
	map.insert(FrameConver, QStringLiteral("帧间转换"));
	map.insert(Opt, QStringLiteral("可选择"));
	map.insert(Other, QStringLiteral("其它"));
	map.insert(Invalid, QStringLiteral("无效"));

	return map;
}

QString CPRIType::EnumName()
{
	return QStringLiteral("重复间隔类型");
}

//雷达脉宽类型
QMap<quint32, QString> & CPWType::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(Unknown, QStringLiteral("未知"));
	map.insert(Fixed, QStringLiteral("固定"));
	map.insert(Coding, QStringLiteral("编码"));
	map.insert(ShotChange, QStringLiteral("捷变"));
	map.insert(Opt, QStringLiteral("可选择"));
	map.insert(Complex, QStringLiteral("复合"));
	map.insert(DoublePulse, QStringLiteral("双脉冲"));
	map.insert(MultiPulse, QStringLiteral("多脉冲"));
	map.insert(Other, QStringLiteral("其它"));
	map.insert(Invalid, QStringLiteral("无效"));

	return map;
}

QString CPWType::EnumName()
{
	return QStringLiteral("脉宽类型");
}


QMap<quint32, QString> & NS_SYS_Enum::CIFFModeNo::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(Unknown, QStringLiteral("未知"));
	map.insert(M1Question, QStringLiteral("M-1询问"));
	map.insert(M2Question, QStringLiteral("M-2询问"));
	map.insert(M3AQuestion, QStringLiteral("M-3/A询问"));
	map.insert(MBQuestion, QStringLiteral("M-B询问"));
	map.insert(MCQuestion, QStringLiteral("M-C询问"));
	map.insert(MDQuestion, QStringLiteral("M-D询问"));
	map.insert(M4_2USQuestion, QStringLiteral("M-4询问2微妙"));
	map.insert(M4_1USQuestion, QStringLiteral("M-4询问1微妙"));
	map.insert(S_MODEQuestion16Dot25, QStringLiteral("S-MODE询问16.2"));
	map.insert(S_MODEQuestion32Dot25, QStringLiteral("S-MODE询问30.2"));
	map.insert(MarkAnswer, QStringLiteral("Mark系列应答"));
	map.insert(M4Answer, QStringLiteral("M-4应答"));
	map.insert(S_MODEAnswer56bit, QStringLiteral("S模式56bit应答"));
	map.insert(S_MODEAnswer112bit, QStringLiteral("S模式112bit应答"));
	map.insert(M_S_ASCall, QStringLiteral("M_S_A/S全呼叫"));
	map.insert(M_S_CSCall, QStringLiteral("M_S_C/S全呼叫"));
	map.insert(M_S_ACall, QStringLiteral("M_S_A仅A全呼叫"));
	map.insert(M_S_CCall, QStringLiteral("M_S_C仅C全呼叫"));
	map.insert(M_1_Answer, QStringLiteral("M-1应答"));
	map.insert(M_2_Answer, QStringLiteral("M-2应答"));
	map.insert(M_3A_Answer, QStringLiteral("M-3/A应答"));
	map.insert(M_C_Answer, QStringLiteral("M-C应答"));
	map.insert(LEV1, QStringLiteral("预留2"));
	map.insert(LEV2, QStringLiteral("预留3"));
	map.insert(M5SK, QStringLiteral("M5询问"));
	map.insert(M5L1, QStringLiteral("M5应答Level1"));
	map.insert(M5L2, QStringLiteral("M5应答Level2"));
	map.insert(AA, QStringLiteral("A511-A询问"));
	map.insert(AB, QStringLiteral("A511-B询问"));
	map.insert(AAAS, QStringLiteral("A511-A应答"));
	map.insert(ABAS, QStringLiteral("A511-B应答"));
	map.insert(R1A, QStringLiteral("R-1A询问"));
	map.insert(R1B, QStringLiteral("R-1B询问"));
	map.insert(R2A, QStringLiteral("R-2A询问"));
	map.insert(R2B, QStringLiteral("R-2B询问"));
	map.insert(R346, QStringLiteral("R-3,4,6询问"));
	map.insert(R1AS, QStringLiteral("R-1应答"));
	map.insert(R2AS, QStringLiteral("R-2应答"));
	map.insert(R3AS, QStringLiteral("R-3应答"));
	map.insert(R4AS, QStringLiteral("R-4应答"));
	map.insert(R6AS, QStringLiteral("R-6应答"));
	map.insert(RB, QStringLiteral("R-Beacon"));
	map.insert(RLev1, QStringLiteral("R-预留1"));
	map.insert(RLev2, QStringLiteral("R-预留2"));
	map.insert(AttRad_HighLevOri, QStringLiteral("调度雷达询问高度剩油"));
	map.insert(AttRad_PlaneID, QStringLiteral("调度雷达询问机号"));
	map.insert(AttRad_Answer, QStringLiteral("调度雷达询问应答信号(不加信息)"));
	map.insert(AttRad_Speed, QStringLiteral("调度雷达询问速度"));
	map.insert(A5xxLR_ASHelp, QStringLiteral("A - 5xx着陆雷达应答(呼救)"));
	map.insert(A5xxDR_Answer, QStringLiteral("A - 5xx探测雷达应答"));
	map.insert(A5xxLR_ASUnderca, QStringLiteral("A - 5xx着陆雷达应答(放起落架)"));
	map.insert(A5xxLR_Answer, QStringLiteral("A - 5xx着陆雷达应答"));
	map.insert(A5xxAD_ASHelp, QStringLiteral("A - 5xx调度雷达不含信息应答(呼救)"));
	map.insert(A5xxAD_Answer, QStringLiteral("A - 5xx调度雷达不含信息应答"));
	map.insert(A5xxAD_ASPlaneIDHelp, QStringLiteral("A - 5xx调度雷达机号应答(呼救)"));
	map.insert(A5xxAD_ASPlaneID, QStringLiteral("A - 5xx调度雷达机号应答"));
	map.insert(A5xxAD_ASSpeedHelp, QStringLiteral("A - 5xx调度雷达速度应答(呼救)"));
	map.insert(A5xxAD_ASSpeed, QStringLiteral("A - 5xx调度雷达速度应答"));
	map.insert(A5xxAD_ASHighLevOriHelp, QStringLiteral("A - 5xx调度雷达高度剩油应答(呼救)"));
	map.insert(A5xxAD_ASHighLevOri, QStringLiteral("A - 5xx调度雷达高度剩油应答"));
	map.insert(OtherFreq, QStringLiteral("其他频率模式"));
	map.insert(Other, QStringLiteral("其他"));
	map.insert(Invalid, QStringLiteral("无效"));

	return map;
}

QString NS_SYS_Enum::CIFFModeNo::EnumName()
{
	return QStringLiteral("模式号代码");
}

QList<int> NS_SYS_Enum::CIFFModeNo::NormalModeNoList()
{
	return QList<int>() << M1Question << M2Question << M3AQuestion << MCQuestion << M_3A_Answer << M_1_Answer << M_2_Answer << M_C_Answer;
}

QList<int> NS_SYS_Enum::CIFFModeNo::Mode4ModeNoList()
{
	return QList<int>() << M4_2USQuestion << M4_1USQuestion << M4Answer;
}

QList<int> NS_SYS_Enum::CIFFModeNo::ModeSModeNoList()
{
	return QList<int>() << S_MODEQuestion16Dot25 << S_MODEQuestion32Dot25 << S_MODEAnswer56bit << S_MODEAnswer112bit;
}

QList<int> NS_SYS_Enum::CIFFModeNo::NormalMode1NoList()
{
	return QList<int>() << M1Question << M_1_Answer;
}

QList<int> NS_SYS_Enum::CIFFModeNo::NormalMode2NoList()
{
	return QList<int>() << M_2_Answer << M2Question;
}

QList<int> NS_SYS_Enum::CIFFModeNo::NormalMode3ANoList()
{
	return QList<int>() << M3AQuestion << M_3A_Answer;
}

QList<int> NS_SYS_Enum::CIFFModeNo::NormalModeCNoList()
{
	return QList<int>() << MCQuestion << M_C_Answer;
}


QMap<quint32, QString> & NS_SYS_Enum::CAirSpeedCode::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(UnWork, QStringLiteral("ACAS不工作"));
	map.insert(S140KMH, QStringLiteral("140公里/小时(75英尺)"));
	map.insert(S140To280KMH, QStringLiteral("≥140公里/小时≤280公里/小时(75和150英尺)"));
	map.insert(S280To560KMH, QStringLiteral("＞280公里/小时≤560公里/小时(150和300英尺)"));
	map.insert(S560To1110KMH, QStringLiteral("＞560公里/小时≤1110公里/小时(300和600英尺)"));
	map.insert(S1110To2220KMH, QStringLiteral("＞1110公里/小时≤2220公里/小时(600和1200英尺)"));
	map.insert(S2220KMH, QStringLiteral("＞2220公里/小时(1200英尺)"));

	return map;
}

QString NS_SYS_Enum::CAirSpeedCode::EnumName()
{
	return QStringLiteral("空速代码");
}

QMap<quint32, QString> & NS_SYS_Enum::CStateCode::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(NoInfo, QStringLiteral("无信息"));
	map.insert(Sky, QStringLiteral("空中"));
	map.insert(Land, QStringLiteral("地面"));
	map.insert(Unknown, QStringLiteral("不明"));
	map.insert(Exigence, QStringLiteral("紧急"));
	map.insert(WirelessInvalid, QStringLiteral("无线电失效"));
	map.insert(Hijack, QStringLiteral("劫持"));
	map.insert(Invalid, QStringLiteral("无效"));

	return map;
}

QString NS_SYS_Enum::CStateCode::EnumName()
{
	return QStringLiteral("状态代码");
}

QMap<quint32, QString> & NS_SYS_Enum::CFriendOrFoe::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(Unknown, QStringLiteral("不明"));
	map.insert(Foe, QStringLiteral("敌方"));
	map.insert(Own, QStringLiteral("我方"));
	map.insert(Friend, QStringLiteral("友方"));
	map.insert(Neutrality, QStringLiteral("中立"));
	map.insert(PotentialFoe, QStringLiteral("潜在敌方"));
	map.insert(Unidentified, QStringLiteral("未鉴别"));
	map.insert(Undefinition, QStringLiteral("未定义"));
	map.insert(Invalid, QStringLiteral("无效值"));

	return map;
}

QString NS_SYS_Enum::CFriendOrFoe::EnumName()
{
	return QStringLiteral("敌我属性");
}

QMap<quint32, QString> & NS_SYS_Enum::CModulateType::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(Unknown, QStringLiteral("不明"));
	map.insert(AM, QStringLiteral("AM"));
	map.insert(FM, QStringLiteral("FM"));
	map.insert(CW, QStringLiteral("CW"));
	map.insert(FSK2, QStringLiteral("2FSK"));
	map.insert(ASK2, QStringLiteral("2ASK"));
	map.insert(FSK4, QStringLiteral("4FSK"));
	map.insert(BPSK, QStringLiteral("BPSK"));
	map.insert(QPSK, QStringLiteral("QPSK"));
	map.insert(PSK8, QStringLiteral("8PSK"));
	map.insert(QAM16, QStringLiteral("16QAM"));
	map.insert(MSK, QStringLiteral("MSK"));
	map.insert(OQPSK, QStringLiteral("OQPSK"));
	map.insert(Pi4DQPSK, QStringLiteral("Pi4DQPSK"));
	map.insert(QAM8, QStringLiteral("8QAM"));
	map.insert(APSK16, QStringLiteral("16APSK"));
	map.insert(APSK32, QStringLiteral("32APSK"));
	map.insert(GMSK, QStringLiteral("GMSK"));
	map.insert(FM_2FSK, QStringLiteral("FM_2FSK"));
	map.insert(FSK3, QStringLiteral("3FSK"));
	map.insert(UQPSK, QStringLiteral("UQPSK"));
	map.insert(PCM_PSK, QStringLiteral("PCM_PSK"));
	map.insert(PCM_FM, QStringLiteral("PCM_FM"));
	map.insert(PCM_BPSKPM, QStringLiteral("PCM_BPSKPM"));
	map.insert(Link11, QStringLiteral("Link11"));
	map.insert(Link4A, QStringLiteral("Link4A"));
	map.insert(Link14, QStringLiteral("Link14"));
	map.insert(Tetra, QStringLiteral("Tetra信号"));
	map.insert(USB, QStringLiteral("USB"));
	map.insert(LSB, QStringLiteral("LSB"));
	map.insert(ISB, QStringLiteral("ISB"));
	map.insert(SAM, QStringLiteral("SAM"));
	map.insert(FAX, QStringLiteral("FAX"));
	map.insert(FSK, QStringLiteral("FSK"));
	map.insert(AFSK, QStringLiteral("AFSK"));
	map.insert(DCW, QStringLiteral("DCW"));
	map.insert(WFM, QStringLiteral("WFM"));
	map.insert(SSB, QStringLiteral("SSB"));
	map.insert(FSK8, QStringLiteral("8FSK"));
	map.insert(QAM32, QStringLiteral("QAM32"));
	map.insert(QAM64, QStringLiteral("QAM64"));
	map.insert(QAM128, QStringLiteral("QAM128"));
	map.insert(QAM256, QStringLiteral("QAM256"));
	map.insert(Link16_slew, QStringLiteral("Link16_slew"));
	map.insert(ALE2G, QStringLiteral("2G_ALE"));
	map.insert(ALE3G, QStringLiteral("3G_ALE"));
	map.insert(Other, QStringLiteral("其他"));

	return map;
}

QString NS_SYS_Enum::CModulateType::EnumName()
{
	return QStringLiteral("调制方式");
}


QMap<quint32, QString> & NS_SYS_Enum::CTargetCharacter::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(Unknown, QStringLiteral("不明"));
	map.insert(Military, QStringLiteral("军用目标"));
	map.insert(Civilian, QStringLiteral("民用目标"));
	map.insert(Paramilitary, QStringLiteral("准军事目标"));
	map.insert(Simulate, QStringLiteral("模拟目标"));
	map.insert(Decoy, QStringLiteral("假目标"));
	map.insert(MC, QStringLiteral("军民两用目标"));
	map.insert(Invalid, QStringLiteral("其他目标"));

	return map;
}

QString NS_SYS_Enum::CTargetCharacter::EnumName()
{
	return QStringLiteral("目标性质");
}

QMap<quint32, QString> & NS_SYS_Enum::CTargetTask::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(Unknown, QStringLiteral("不明"));
	map.insert(Duty_B, QStringLiteral("值勤"));
	map.insert(Train_B, QStringLiteral("训练"));
	map.insert(Manoeuvre_B, QStringLiteral("演习"));
	map.insert(Spy_B, QStringLiteral("侦察"));
	map.insert(Battle_B, QStringLiteral("作战"));
	map.insert(Stakeout_B, QStringLiteral("监视"));
	map.insert(ProtectHalieutics_B, QStringLiteral("护渔"));
	map.insert(SearchHelp_B, QStringLiteral("搜救"));
	map.insert(Comm3Area_B, QStringLiteral("两岸三通"));
	map.insert(ProtectTrader_B, QStringLiteral("商船护航"));
	map.insert(Shakedown_B, QStringLiteral("试航"));
	map.insert(Boat_B, QStringLiteral("航渡"));
	map.insert(Work_B, QStringLiteral("作业"));
	map.insert(Guard_B, QStringLiteral("警戒"));
	map.insert(Logistics_B, QStringLiteral("后勤"));
	map.insert(Transport_B, QStringLiteral("舰船运输"));
	map.insert(Inbreak_B, QStringLiteral("舰船入侵"));
	map.insert(Patrol_P, QStringLiteral("巡逻"));
	map.insert(Train_P, QStringLiteral("训练"));
	map.insert(SwitchField_P, QStringLiteral("转场"));
	map.insert(ProtectFly_P, QStringLiteral("护航"));
	map.insert(Spy_P, QStringLiteral("侦察"));
	map.insert(Airdrop_P, QStringLiteral("空投"));
	map.insert(Battle_P, QStringLiteral("作战"));
	map.insert(Manoeuvre_P, QStringLiteral("演习"));
	map.insert(Duty_P, QStringLiteral("勤务"));
	map.insert(Comm3Area_P, QStringLiteral("两岸三通"));
	map.insert(SpecialTransport_P, QStringLiteral("要员专送"));
	map.insert(Transport_P, QStringLiteral("飞机运输"));
	map.insert(Inbreak_P, QStringLiteral("飞机入侵"));
	map.insert(Train_M, QStringLiteral("演训"));
	map.insert(Attack_M, QStringLiteral("攻击"));
	map.insert(Other, QStringLiteral("其它"));

	return map;
}

QString NS_SYS_Enum::CTargetTask::EnumName()
{
	return QStringLiteral("目标任务");
}

QMap<quint32, QString> & NS_SYS_Enum::CTargetType::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(Unknown, QStringLiteral("未知"));
	map.insert(Land, QStringLiteral("陆地目标"));
	map.insert(Sea, QStringLiteral("海洋目标"));
	map.insert(Sky, QStringLiteral("空中目标"));
	map.insert(Plane, QStringLiteral("飞机"));
	map.insert(Equip, QStringLiteral("装备"));
	map.insert(Weapon, QStringLiteral("武器"));
	map.insert(Space, QStringLiteral("空间"));
	map.insert(Army, QStringLiteral("部队"));
	map.insert(Other, QStringLiteral("其他"));

	return map;
}

QString NS_SYS_Enum::CTargetType::EnumName()
{
	return QStringLiteral("目标分类");
}

QMap<quint32, QString> & NS_SYS_Enum::CResponseFaultCode::GetMap()
{
	static QMap<quint32, QString> map;
	map.insert(Normal, QStringLiteral("正常"));
	map.insert(FrameStructError, QStringLiteral("帧结构错误"));
	map.insert(FrameLenError, QStringLiteral("帧长错误"));
	map.insert(SourceLogicIdError, QStringLiteral("源逻辑ID错误"));
	map.insert(DestLogicIdError, QStringLiteral("目的逻辑ID错误"));
	map.insert(InfoTypeError, QStringLiteral("信息类别错误"));
	map.insert(InfoSubTypeError, QStringLiteral("信息子类错误"));
	map.insert(DataParamError, QStringLiteral("数据区参数错误"));
	return map;
}

QString NS_SYS_Enum::CResponseFaultCode::EnumName()
{
	return QStringLiteral("响应故障码");
}



QMap<quint32, QString> & NS_SYS_Enum::CProfessionalTitleTypes::GetMap()
{
    static QMap<quint32, QString> map;
    map.insert(AssistantEngineer, QStringLiteral("助理工程师"));
    map.insert(Engineer, QStringLiteral("工程师"));
    map.insert(SeniorEngineer, QStringLiteral("高级工程师"));
    map.insert(AssistantTranslator, QStringLiteral("助理翻译"));
    map.insert(Translator, QStringLiteral("翻译"));
    map.insert(AssociateSeniorTranslator, QStringLiteral("副译审"));
    map.insert(ResearchIntern, QStringLiteral("实习研究员"));
    map.insert(AssociateResearchFellow, QStringLiteral("副研究员"));
    map.insert(ResearchFellow, QStringLiteral("研究员"));
    map.insert(Technician, QStringLiteral("技师"));
    return map;
}

QString NS_SYS_Enum::CProfessionalTitleTypes::EnumName()
{
    return QStringLiteral("职称");
}

QMap<quint32, QString> & NS_SYS_Enum::CMajorTypes::GetMap()
{
    static QMap<quint32, QString> map;
    map.insert(CommandControlCommunication, QStringLiteral("指控通信专业"));
    map.insert(RadarSignal, QStringLiteral("雷达信号专业"));
    map.insert(CommunicationSignal, QStringLiteral("通信信号专业"));
    map.insert(TOEC, QStringLiteral("光电专业"));
    map.insert(Link16Signal, QStringLiteral("Link16专业"));
    map.insert(IFF_TACANSignal, QStringLiteral("IFF和TACAN信号专业"));
    map.insert(MessageProcess, QStringLiteral("情报处理专业"));
    map.insert(Language, QStringLiteral("语言专业"));
    return map;
}

QString NS_SYS_Enum::CMajorTypes::EnumName()
{
    return QStringLiteral("专业");
}
