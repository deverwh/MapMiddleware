/*!
 * \�ļ� Map_Global.h
 * \���� 2020/01/03 17:48
 *
 * \���� wanghao
 * ��ϵ: wanghao@swiet.com
 *
 * \��� ͨ�ö���
 *
 *
 * \���ļ�¼ 2020.1.3 �½�
*/

#pragma once

#include <QObject>

#ifdef _BUILDING_MAP
#define MAP_EXPORT __declspec(dllexport)
#else // _BUILDING_MAP
#define MAP_EXPORT __declspec(dllimport)
#endif // _BUILDING_MAP

#define MAP_DECLARE_PRIVATE(Class) \
	public:\
	inline Abstract##Class* d_func() { return reinterpret_cast<Abstract##Class *>(qGetPtrHelper(d_ptr)); } \
	inline const Abstract##Class* d_func() const { return reinterpret_cast<const Abstract##Class *>(qGetPtrHelper(d_ptr)); } \
	friend class Abstract##Class;