#ifndef CMenuDef_h__
#define CMenuDef_h__

//菜单项枚举值//对应XML中菜单ID
enum emMenuItem
{
	emMenu_CommandManage			= 1,	//指挥文电管理
	emMenu_TaskPlanManage			= 2,	//任务计划管理
	emMenu_DataInputDispatch		= 3,	//数据接入分发
	emMenu_InnerCooperate			= 4,	//内部协同侦察管理
	emMenu_IntelligenceManage		= 5,	//情报审批管理
	emMenu_ResourceManager			= 6,	//共用资源使用仲裁管理
	emMenu_FileTranslate			= 7,	//文件传输审批
	emMenu_ExternCooperate			= 8,	//外部协同侦察管理
	emMenu_SimulateTrain			= 9,	//模拟训练管理
	emMenu_TaskSummarize			= 10,	//侦察任务总结
	emMenu_LogManage				= 11,	//日志记录管理
	emMenu_RoleManage				= 12,	//软件角色管理
};


#endif // CMenuDef_h__
