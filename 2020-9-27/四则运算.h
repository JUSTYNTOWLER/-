#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include "全局父类.h"

using namespace std;

class Calc_1
{
public:
	Calc_1(string a);

	void getSuffix();//获取后缀表达式
	float Calc_Suffix();//计算后缀表达式
	void m_init();//初始化
	~Calc_1();

private:
	char in[100];//输入的表达式
	stack<char> s1;//中缀表达式转换为后缀表达式时用到的栈
	vector<string> out;//后缀表达式
	stack<float> s2;//后缀表达式计算结果时用到的栈
	float result=0;//计算结果

};