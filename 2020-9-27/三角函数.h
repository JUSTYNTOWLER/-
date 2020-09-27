#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include "全局父类.h"

using namespace std;

class Calc_SC :public Calc_G{

public:

	Calc_SC();
	void checkSC();//检查三角函数的合法性：其后必须有一个合法数
	void calcSC();//计算三角函数，用计算后的数替代原算式中的三角函数

};


