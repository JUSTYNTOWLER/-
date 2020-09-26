#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "四则运算.h"

using namespace std;





Calc_1::Calc_1(string a)
{
	strcpy(in, a.c_str());
}
Calc_1::~Calc_1()
{
}
void Calc_1::getSuffix()	//获取后缀表达式
{
	for (int i = 0; in[i] != '\0'; i++)
	{
		if ((in[i] >= '0' && in[i] <= '9') || in[i] == '.')//1,数字直接输出
		{
			string str;
			for (; (in[i] >= '0' && in[i] <= '9') || in[i] == '.'; i++)
			{
				//将一个数字存储到字符串中
				char s = in[i];
				str.push_back(s);
			}
			//将字符串输出
			out.push_back(str);
			i--;
		}
		else if (s1.empty())//2,遇见非数字时, 如果堆栈为空，则直接把该字符放入堆栈
		{
			s1.push(in[i]);
		}
		else if (in[i] == '+' || in[i] == '-')
			//2.1,如果是+或- 那么遍历堆栈栈顶元素 一直输出优先级>=加减的 即输出栈顶的+-*/,
			//当遇到其他字符时（如左括号）或堆栈空时break
		{
			while (!s1.empty()) {
				if (s1.top() == '+' || s1.top() == '-' || s1.top() == '*' || s1.top() == '/') {
					//把字符转换为字符串输出
					char x;
					x = s1.top();
					s1.pop();
					string str;
					str.push_back(x);
					out.push_back(str);
				}
				else break;
			}
			s1.push(in[i]);
		}
		else if (in[i] == '*' || in[i] == '/')
			//2.2,如果是*或/ 那么遍历堆栈栈顶元素 一直输出优先级>=乘除的 即输出栈顶的*/,
			//当遇到其他字符时（如左括号，减号，除号）或堆栈空时break
		{
			while (!s1.empty()) {
				if (s1.top() == '*' || s1.top() == '/') {
					//把字符转换为字符串输出
					char x;
					x = s1.top();
					s1.pop();
					string str;
					str.push_back(x);
					out.push_back(str);
				}
				else break;
			}
			s1.push(in[i]);
		}
		else if (in[i] == ')')
			//2.3,如果该字符是右括号时，一直输出栈顶元素，直到遇见左括号为止break:
		{
			while (!s1.empty()) {
				if (s1.top() == '(') {
					s1.pop();
					break;
				}
				//把字符转换为字符串输出
				char x;
				x = s1.top();
				s1.pop();
				string str;
				str.push_back(x);
				out.push_back(str);
			}
		}
		else if (in[i] == '(')
			//2.4,如果该字符是左括号时，直接放入堆栈
		{
			s1.push(in[i]);
		}
	}
	//字符串循环结束后 再输出堆栈中剩余的数据
	while (!s1.empty()) {
		//把字符转换为字符串输出
		char x;
		x = s1.top();
		s1.pop();
		string str;
		str.push_back(x);
		out.push_back(str);
	}
	//输出后缀表达式
	// for(int r=0;r<out.size();r++)
	// {
	//	  cout<<out.at(r)<<endl;
	// }
}

float Calc_1::Calc_Suffix()
{
	getSuffix();
	for (int i = 0; i < out.size(); i++)
	{
		stringstream s(out[i]);
		float t;
		if (s >> t)//如果是数字，直接入栈
		{
			s2.push(t);
		}
		else if (out[i] == "+" || out[i] == "-" || out[i] == "*" || out[i] == "/")//如果是运算符，弹栈两次，并进行运算，运算后，结果入栈
		{
			float x = s2.top();
			s2.pop();
			float y = s2.top();
			s2.pop();
			if (out[i] == "+")
			{
				s2.push(y + x);
			}
			else if (out[i] == "-") {
				s2.push(y - x);
			}
			else if (out[i] == "*") {
				s2.push(y * x);
			}
			else if (out[i] == "/") {
				s2.push(y / x);
			}
		}
	}
	float z = s2.top();
	s2.pop();
	result = z;
	return result;
}

void Calc_1::m_init()
{
	memset(in, '/0', sizeof(in));
	out.clear();
}



int main()
{
	string aaa = "333";
	cout << aaa.size();






}

