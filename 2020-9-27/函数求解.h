#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include "全局父类.h"

using namespace std;

class Calc_func:public Calc_G {

public:

	void Calcfun1();	//	一元一次函数

	void Calcfun2();	//	一元二次函数

	void Calcfun31();	//	指数函数a^x

	void Calcfun32();	//	指数函数x^a

	void Calcfun41();	//	对数函数log x(a)

	void Calcfun42();	//	对数函数log a(x)

	void Calcfun5();	//	反比例函数


};
