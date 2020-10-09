#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Calc
{
public:
	
	void setA();
	void CIN();//输入

	void checkroom();// 判断大小，并将字符串转字符数组（在进行函数计算之前
	void checkstr0();	//检查是否有非法字符（在计算函数和转换进制之前

	void checkhex(); //判断是否有非法的进制运算
	void calchex(); //将十六进制数字符串转为十进制数字符串

	void checkoct(); //判断是否有非法的进制运算
	void calcoct(); //将八进制数字符串转为十进制数字符串

	void checkbit(); //判断是否有非法的进制运算
	void calcbit(); //将二进制数字符串转为十进制数字符串

	void checkSC();//检查三角函数的合法性：其后必须有一个合法数
	void calcSC();//计算三角函数，用计算后的数替代原算式中的三角函数

	void calclog();//对数函数

	void calcpow();//幂函数

	void changenega();	//将所有的负数-a改为(0-a) (在计算函数和转换进制之后

	void COUT();

	void checkstr(); // 检查是否有非法字符（在计算三角函数、幂函数、对数函数之后
					 //此处的非法字符指除四则运算、数字、括号以外的其他任何字符
					 //同时一并检查运算符号是否被适当地使用

	string getINPUT(); // 获得检查完毕无非法字符和运算的算式，允许进行四则运算

	void m_init();//初始化
	void setIN(string a);
	void getSuffix();//获取后缀表达式
	double Calc_Suffix();//计算后缀表达式

	void RADIX(double a);


	void Calcfun1();	//	一元一次函数

	void Calcfun2();	//	一元二次函数

	void Calcfun31();	//	指数函数a^x

	void Calcfun32();	//	指数函数x^a

	void Calcfun41();	//	对数函数log x(a)

	void Calcfun42();	//	对数函数log a(x)

	void Calcfun5();	//	反比例函数

	int checkS();

	int R = 0;//判断输出的进制

	

private:

	char in[300];//输入的字符串（char数组类型
	vector<char> in_2;//输入的字符串（vector数组类型
	string INPUT;//输入的字符串
	bool s = 0;	//字符串是否合法的判断依据
	double a=0, b=0, c=0;//函数参数
	

	template <class T>
	void convertFromString(T& value, const string& s) {
		stringstream ss(s);
		ss >> value;
	}


	char IN[100];//输入的表达式
	stack<char> s1;//中缀表达式转换为后缀表达式时用到的栈
	vector<string> out;//后缀表达式
	stack<float> s2;//后缀表达式计算结果时用到的栈
	double result = 0;//计算结果

};
