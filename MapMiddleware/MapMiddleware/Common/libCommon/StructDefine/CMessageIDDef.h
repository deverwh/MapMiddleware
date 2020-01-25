#ifndef CMessageIDDef_h__
#define CMessageIDDef_h__

#include "EDataType.h"

/*
//指挥文电通知
const int NOTIFY_TELEGRAM					= EDT_USER_CUSTOM_FLAG + 1;
//指挥命令通知
const int NOTIFY_COMMANDORDER				= EDT_USER_CUSTOM_FLAG + 2;
//侦察计划通知
const int NOTIFY_RECONPLAN					= EDT_USER_CUSTOM_FLAG + 3;
//综合情报上报审核通知
const int NOTIFY_INFOREVIEW					= EDT_USER_CUSTOM_FLAG + 4;
//指挥命令反馈
const int NOTIFY_COMMANDORDER_FALLBACK		= EDT_USER_CUSTOM_FLAG + 5;
//侦察计划反馈
const int NOTIFY_RECONPLAN_FALLBACK			= EDT_USER_CUSTOM_FLAG + 6;
*/

//错误提示通知
const int NOTIFY_ERRORMESSAGE				= EDT_USER_CUSTOM_FLAG + 20;
//错误提示通知
const int NOTIFY_WARNMESSAGE				= EDT_USER_CUSTOM_FLAG + 21;

#endif // CMessageIDDef_h__
