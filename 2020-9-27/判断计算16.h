#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include "全局父类.h"

using namespace std;

class Calc_HEX:public Calc_G {

public:

	Calc_HEX();

	void checkhex(); //判断是否有非法的进制运算

	void calchex(); //将十六进制数字符串转为十进制数字符串
};