#include "JSBrige.h"



QObject * JSBrige::instance()
{
	static JSBrige jsBrige;
	return &jsBrige;
}

JSBrige::JSBrige()
{
}

JSBrige::~JSBrige()
{
}


QString JSBrige::getUsers(int i)
{
	return QString("{"
		"	data: ["
		"		{code:'001', name:'234', price:'123.456'},"
		"		{code:'001', name:'adb', price:'123.456'},"
		"		{code:'001', name:'adb', price:'123.456'}"
		"   ]"
		"}"
	);
}
