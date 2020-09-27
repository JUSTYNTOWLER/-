#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include "全局父类.h"


using namespace std;

class Calc_2:public Calc_G
{
public:
	Calc_2(string a);	// 判断大小，并将字符串转字符数组（在进行函数计算之前

	void checkstr0();	//检查是否有非法字符（在计算函数和转换进制之前





	void changenega();	//将所有的负数-a改为(0-a) (在计算函数和转换进制之后

	void checkstr(); // 检查是否有非法字符（在计算三角函数、幂函数、对数函数之后
					 //此处的非法字符指除四则运算、数字、括号以外的其他任何字符
					 //同时一并检查运算符号是否被适当地使用

	string getINPUT(); // 获得检查完毕无非法字符和运算的算式，允许进行四则运算

	~Calc_2();

private:

};


