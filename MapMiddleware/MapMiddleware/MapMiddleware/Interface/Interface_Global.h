/*!
 * \�ļ� Interface_Global.h
 * \���� 2020/03/19 21:06
 *
 * \���� deverwh
 * 	��ϵ deverwh@outlook.com
 *
 * \��� ͨ�ö���
 *
 *
 * \��¼ 2020/03/19 21:06 �½�
*/

#pragma once

#ifdef _BUILDING_INTERFACE
#define INTERFACE_EXPORT __declspec(dllexport)
#else // _BUILDING_INTERFACE
#define INTERFACE_EXPORT __declspec(dllimport)
#endif // _BUILDING_INTERFACE