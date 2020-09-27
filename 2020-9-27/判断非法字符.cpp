#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "判断非法字符.h"
#include "全局父类.h"

using namespace std;


Calc_2::Calc_2(string a) {

	in[0] = '\0';
	in_2[0] = '\0';

	if (a.size() > 99) {
		cout << "算式过长！" << endl;
		s = 0;
	}
	else if (a.size() < 1) {
		cout << "算式过短！" << endl;
		s = 0;
	}
	else {
		INPUT = a;
		strcpy(in, INPUT.c_str());
		s = 1;
	}

}




void Calc_2::checkstr0() {

	if (s) 
	{

		for (int i = 0; i < INPUT.size(); i++)
		{
			if ((int)in[i] <= 57 && (int)in[i] >= 48) //数字1～9
			{
				continue;
			}
			else if (in[i] == '+')
			{
				continue;
			}
			else if (in[i] == '-')
			{
				continue;
			}
			else if (in[i] == '*')
			{
				continue;
			}
			else if (in[i] == '/')
			{
				continue;
			}
			else if (in[i] == '(')
			{
				continue;
			}
			else if (in[i] == ')')
			{
				continue;
			}
			else if (in[i] == '.')
			{
				continue;
			}
			else if (in[i] == '^')
			{
				continue;
			}
			else if (in[i] <= 'z' && in[i] >= 'a') //英文小写字母
			{
				continue;
			}
			else if (in[i] <= 'Z' && in[i] >= 'A') //英文大写字母
			{
				continue;
			}
			else
			{
				cout << "输入的算式不符合规范！" << endl;
				in[0] = '\0';
				s = 0;
				return;	
			}
		}
	}
	else 
	{
		return;
	}
}







void Calc_2::changenega() {

	if (s)
	{
		in_2[0] = '\0';

		for (int i = 0; i < INPUT.size(); i++)
		{
			in_2[i] = INPUT[i];
		}	//将string INPUT转换为vector<char>


		int i = 0;

		if (in_2[0] == '-')
		{
			in_2.insert(in_2.begin(), '0');
			in_2.insert(in_2.begin(), '(');

			int p;
			for (int x = 3;; x++)
			{
				if ((int)in_2[x] != 46 && (int)in_2[x] < 48 && (int)in_2[x] > 57)  //寻找数组中从负号往后第一个不是小数点或数字的元素,插入'）'
				{
					p = x;
					in_2.insert(in_2.begin() + p, ')');
					break;
				}
				else if (((int)in_2[x] == 46 || ((int)in_2[x] >= 48 && (int)in_2[x] <= 57)) && in_2[x] == in_2.back())//或是直到数组的最后一个元素为止都是数字或小数点,将数组尾添加一个元素')'
				{
					in_2.insert(in_2.end(), ')');
					break;
				}
			}


		}

		for (i = 1; in_2[i] != in_2.back(); i++)
		{
			if ((int)in_2[i - 1] < 48 && (int)in_2[i - 1] > 57 && in_2[i] == '-')
			{
				in_2.insert(in_2.begin() + i, '0');
				in_2.insert(in_2.begin() + i, '(');

				int p = 0;
				for (int x = i + 3; ; x++)
				{
					if ((int)in_2[x] != 46 && (int)in_2[x] < 48 && (int)in_2[x] > 57)
					{
						p = x;
						in_2.insert(in_2.begin() + p, ')');
						break;
					}
					else if ((int)in_2[x] != 46 && (int)in_2[x] < 48 && (int)in_2[x] > 57 && in_2[x] == in_2.back())
					{
						in_2.insert(in_2.end(), ')');
						break;
					}
				}
				i = p + 1;
			}
		}
		in_2[0] = '\0';
	}
	else
		return;
};



void Calc_2::checkstr() {

	if (s) {

		in[0] = '\0';

		strcpy(in, INPUT.c_str());

		int front=0, back=0;	//	前后括号个数

		for (int i = 0; i < INPUT.size(); i++)
		{
			if((int)in[i]<=57 && (int)in[i] >= 48) //数字1～9
			{
				continue;
			}
			else if (in[i] == '+')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;	// '+'不可以作为第一个字符或最后一个字符
				}
				else if (((int)in[i + 1] - (int)in[i] > 14 || (int)in[i + 1] - (int)in[i] <= 5) && ((int)in[i + 1] - (int)in[i] != -3)) 
				{ 
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return ;	//'+'号后面不可以有除数字和'('以外的其他字符
				}
				else
					continue;
			}
			else if (in[i] == '-')
			{
				if (i == 0 ||i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;	// '-'不可以作为第一个或最后一个字符
				}
				else if (((int)in[i + 1] - (int)in[i] > 13 || (int)in[i + 1] - (int)in[i] <= 3) && ((int)in[i + 1] - (int)in[i] != -5))
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return ;	//'-'号后面不可以有除数字和'('以外的其他字符
				}
				else
					continue;
			}
			else if (in[i] == '*')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;	// '*'不可以作为第一个字符或最后一个字符
				}
				else if (((int)in[i + 1] - (int)in[i] > 15 || (int)in[i + 1] - (int)in[i] <= 6) && (int)in[i + 1] - (int)in[i] != -2)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return ;	//'*'号后面不可以有除数字以外和'('以外的其他字符
				}
				else
					continue;
			}
			else if (in[i] == '/')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;	// '/'不可以作为第一个字符或最后一个字符
				}
				else if (((int)in[i + 1] - (int)in[i] > 10 || (int)in[i + 1] - (int)in[i] <= 0) && (int)in[i + 1] - (int)in[i] != -7)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return ;	//'/'号后面不可以有除数字以外和'('以外的其他字符
				}
				else if ((int)in[i + 1] - (int)in[i] == 1)
				{
					int w = 1;
					for (int x = i + 1; x < INPUT.size(); x++)
					{
						if (in[x] == '0' || in[x] == '.')
						{
							continue;
						}
						else if(in[x]<='9' && in[x]>='1')
						{
							w=0;
							continue;
						}
						else
						{
							break;
						}
						
					}

					if (w) {
						cout << "输入的算式不符合规范！" << endl;
						s = 0;
						return; // '/'号后面的数值不可以是'0'
					}


				}
				else
					continue;
			}
			else if (in[i] == '(')
			{
				front++;

				if (i == 0) 
				{
					if ((int)in[i + 1] - (int)in[i] > 17 || (int)in[i + 1] - (int)in[i] <= 8)
					{
						cout << "输入的算式不符合规范！" << endl;
						s = 0;
						return;	//'('号后面不可以有除数字以外的其他字符
					}
					else
						continue;
				}
				else if (i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;	//'('不可以是最后一个字符
				}
				else  
				{
					if (in[i - 1] > '0' && in[i - 1] < '9') 
					{
						cout << "输入的算式不符合规范！" << endl;
						s = 0;
						return;	//'('号前面不可以有数字
					}
					else if ((int)in[i + 1] - (int)in[i] > 17 || (int)in[i + 1] - (int)in[i] <= 8)
					{
						cout << "输入的算式不符合规范！" << endl;
						s = 0;
						return;	//'('号后面不可以有除数字以外的其他字符
					}
					else
						continue;
				}
				
			}
			else if (in[i] == ')')
			{
				back++;
				
				if (i == 0)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;	// ')'号不可以作为第一个字符
				}
				else if (i == INPUT.size() - 1)
				{
					if (in[i - 1]<'0' || in[i - 1]>'9')
					{
						cout << "输入的算式不符合规范！"  << endl;
						s = 0;
						return ;	// ')'号前面不可以有除数字以外的其他字符
					}
					else
						continue;
					
				}
				else if(in[i - 1]<'0' || in[i - 1]>'9' || (in[i + 1] >= '0' && in[i + 1] <= '9'))
				{
						cout << "输入的算式不符合规范！" << endl;
						s = 0;
						return;	// ')'号前面不可以有出数字以外的其他字符,后面不可以有数字
				}
				else if(front<back)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;	// ')'号的个数不能比现有的'('个数要多
				}
				else
					continue;

			}
			else if (in[i] == '.')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;	// 小数点不可以作为第一个字符或最后一个字符
				}
				else if (in[i + 1]<'0' || in[i + 1]>'9')
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;	//小数点后面不可以有数字以外的其他字符
				}
				else
				{
					for (int x = i+1; x < INPUT.size(); x++)
					{
						if ((in[x]<'0' || in[x]>'9') && in[x]!='.') {
							break;
						}
						else if (in[x] == '.')
						{
							cout << "输入的算式不符合规范！" << endl;
							s = 0;
							return;	//一串数字中不可以有多个小数点
						}
					}
					continue;
				}
					

			}
			else 
			{
				cout << "输入的算式不符合规范！" << endl;
				s = 0;
				return;	//含有四则运算符和数字以外的非法字符
			}
		}
		if (front != back)
		{
			cout << "输入的算式不符合规范！" << endl;
			s = 0;
			return;	//前后括号个数不等
		}
	}
	else  return ; 

}

string Calc_2::getINPUT() {
	if (s) {
		return INPUT;
	}
	else return "输入的算式不符合规范！";
}

Calc_2::~Calc_2() {};




