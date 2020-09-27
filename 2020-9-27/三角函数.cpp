#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "三角函数.h"
#include "全局父类.h"

using namespace std;

Calc_SC::Calc_SC() {};

void Calc_SC::checkSC() {

	if (s)
	{
		in[0] = '\0';
		int d = 0;

		strcpy(in, INPUT.c_str());

		for (int i = 0; i < INPUT.size()-2; i++)
		{
			if (INPUT.substr(i, 3) == "sin")
			{
				d = 0;

				if (i == INPUT.size() - 3)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;	//sin不能作为字符串的结尾
				}

				for (int x = i + 3; x < INPUT.size(); x++)
				{
					if ((int)in[x] <= 57 && (int)in[x] >= 48) //数字0-9
					{
						continue;
					}
					else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z'))
					{
						cout << "输入的算式不符合规范！" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 3)
						{
							cout << "输入的算式不符合规范！" << endl;
							s = 0;
							return;	//sin后没有数值，直接是'+''('等非法字符
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "输入的算式不符合规范！" << endl;
								s = 0;
								return;	//小数点不能为最后一位
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "输入的算式不符合规范！" << endl;
								s = 0;
								return; //不能含有多个小数点
							}
						}
						else
						{
							break;
						}
					}
				}
			}
		}
		in[0] = '\0';

		// 检查sin的合法性



		for (int i = 0; i < INPUT.size() - 2; i++)
		{
			if (INPUT.substr(i, 3) == "cos")
			{
				d = 0;

				if (i == INPUT.size() - 3)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;	//cos不能作为字符串的结尾
				}

				for (int x = i + 3; x < INPUT.size(); x++)
				{
					if ((int)in[x] <= 57 && (int)in[x] >= 48) //数字0-9
					{
						continue;
					}
					else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z'))
					{
						cout << "输入的算式不符合规范！" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 3)
						{
							cout << "输入的算式不符合规范！" << endl;
							s = 0;
							return;	//cos后没有数值，直接是'+''('等非法字符
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "输入的算式不符合规范！" << endl;
								s = 0;
								return;	//小数点不能为最后一位
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "输入的算式不符合规范！" << endl;
								s = 0;
								return; //不能含有多个小数点
							}
						}
						else
						{
							break;
						}
					}
				}
			}
		}
		in[0] = '\0';

		// 检查cos的合法性

		


		for (int i = 0; i < INPUT.size() - 2; i++)
		{
			if (INPUT.substr(i, 3) == "tan")
			{
				d = 0;

				if (i == INPUT.size() - 3)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;	//tan不能作为字符串的结尾
				}

				for (int x = i + 3; x < INPUT.size(); x++)
				{
					if ((int)in[x] <= 57 && (int)in[x] >= 48) //数字0-9
					{
						continue;
					}
					else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z'))
					{
						cout << "输入的算式不符合规范！" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 3)
						{
							cout << "输入的算式不符合规范！" << endl;
							s = 0;
							return;	//tan后没有数值，直接是'+''('等非法字符
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "输入的算式不符合规范！" << endl;
								s = 0;
								return;	//小数点不能为最后一位
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "输入的算式不符合规范！" << endl;
								s = 0;
								return; //不能含有多个小数点
							}
						}
						else
						{
							break;
						}
					}
				}
			}
		}
		in[0] = '\0';

		// 检查tan的合法性
	}
	else return;

}




void Calc_SC::calcSC() {

	if (s)
	{
		const string SIN = "sin";
		const string COS = "cos";
		const string TAN = "tan";

		int pos;
		int q =0;
		double v = 0 , result ;
		string SC;
		char input[100];

		pos = INPUT.find(SIN);	//计算sin

		int p = pos + 3;

		while (pos != -1)
		{
			for (int x = pos + 3; x < INPUT.size(); x++)
			{
				if (((int)in[x] <= 57 && (int)in[x] >= 48) || in[x] == '.') //数字0-9或小数点
				{
					if (x == INPUT.size() - 1) 
					{
						q = x - p + 1;
						break;
					}
					else
					continue;
				}
				else
				{
					q = x - p;
					break;
				}
			}
			v = 0;
			input[0] = '\0';

			SC = INPUT.substr(p,q);
			convertFromString(v, SC);
			result = sin(v);
			sprintf(input, "%.20lf", result);

			INPUT.replace(pos, q+3, input);

			pos = INPUT.find(SIN);
		}



		pos = INPUT.find(COS);	//计算cos

		while (pos != -1)
		{
			for (int x = pos + 3; x < INPUT.size(); x++)
			{
				if (((int)in[x] <= 57 && (int)in[x] >= 48) || in[x] == '.') //数字0-9或小数点
				{
					if (x == INPUT.size() - 1)
					{
						q = x - p + 1;
						break;
					}
					else
						continue;
				}
				else
				{
					q = x - p;
					break;
				}
			}
			v = 0;
			input[0] = '\0';

			SC = INPUT.substr(p, q);
			convertFromString(v, SC);
			result = cos(v);
			sprintf(input, "%.20lf", result);

			INPUT.replace(pos, q + 3, input);


			pos = INPUT.find(SIN);
		}



		pos = INPUT.find(TAN);	//计算tan

		while (pos != -1)
		{
			for (int x = pos + 3; x < INPUT.size(); x++)
			{
				if (((int)in[x] <= 57 && (int)in[x] >= 48) || in[x] == '.') //数字0-9或小数点
				{
					if (x == INPUT.size() - 1)
					{
						q = x - p + 1;
						break;
					}
					else
						continue;
				}
				else
				{
					q = x - p;
					break;
				}
			}
			v = 0;
			input[0] = '\0';

			SC = INPUT.substr(p, q);
			convertFromString(v, SC);

			if (cos(v) == 0)
			{
				cout << "输入的算式不符合规范！" << endl;
				s = 0;
				return;
			}
			else
			result = tan(v);

			sprintf(input, "%.20lf", result);
			INPUT.replace(pos, q + 3, input);

			pos = INPUT.find(SIN);
		}
	}
}