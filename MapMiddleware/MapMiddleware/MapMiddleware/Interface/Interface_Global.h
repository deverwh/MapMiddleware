/*!
* \�ļ� Interface_Global.h
* \���� 2020/01/07 17:48
*
* \���� wanghao
* ��ϵ: wanghao@swiet.com
*
* \��� ͨ�ö���
*
*
* \���ļ�¼ 2020.1.7 �½�
*/

#pragma once

#ifdef _BUILDING_INTERFACE
#define INTERFACE_EXPORT __declspec(dllexport)
#else // _BUILDING_INTERFACE
#define INTERFACE_EXPORT __declspec(dllimport)
#endif // _BUILDING_INTERFACE