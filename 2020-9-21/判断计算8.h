#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include "全局父类.h"

using namespace std;

class Calc_OCT:public Calc_G {

public:
	Calc_OCT();

	void checkoct(); //判断是否有非法的进制运算

	void changeoct(); //将八进制数字符串转为十进制数字符串

};
