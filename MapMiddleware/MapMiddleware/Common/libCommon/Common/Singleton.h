/*!
 * \文件 CSingleton.h
 * \日期 2019/12/31 19:42
 *
 * \作者 wanghao
 * Contact: wanghao@swiet.com
 *
 * \简介 单例类实现，线程安全
 *
 *
 * \更改：2019.12.31 新建
*/

#pragma once

#include <QReadWriteLock>

// 声明一个单例类，单例类必须有一个无参构造函数，在头文件类声明中添加此宏
#define DEC_SINGLETON(class_name) \
    public: static class_name* instance(); \
    public: static void release(); \
    private: static class_name *m_instance;

// 实现一个单例类，在cpp文件函数定义外部添加此宏
#define IMP_SINGLETON(class_name) \
    static QReadWriteLock class_name##_lock; \
	class_name* class_name::m_instance = nullptr; \
	class_name* class_name::instance() \
    { \
		if (class_name::m_instance == NULL) \
        { \
            class_name##_lock.lockForWrite(); \
			if (class_name::m_instance == NULL) \
            { \
				class_name::m_instance = new class_name(); \
            } \
            class_name##_lock.unlock(); \
        } \
		return m_instance; \
    } \
	void class_name::release() \
    { \
		class_name##_lock.lockForWrite(); \
		if (m_instance != NULL) {\
			delete m_instance; \
			m_instance = nullptr; \
        } \
		class_name##_lock.unlock(); \
    }