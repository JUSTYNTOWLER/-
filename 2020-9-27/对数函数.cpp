#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "对数函数.h"
#include "全局父类.h"

using namespace std;

void Calc_log::calclog() {

	if (s)
	{
		const string LOG = "log";

		int pos;
		int q1,q2;
		double v1 = 0, v2 = 0 ,result;
		string L1;
		char input[100];

		pos = INPUT.find(LOG);	

		int p = pos + 3,p2;

		while (pos != -1)
		{
			if (pos = INPUT.size() - 3)
			{
				cout << "输入的算式不符合规范！" << endl;
				s = 0;
				return;
			}


			for (int x = pos + 3; x < INPUT.size(); x++)
			{
				if (((int)in[x] <= 57 && (int)in[x] >= 48) || in[x] == '.') //数字0-9或小数点
				{
					if (x == INPUT.size() - 1)
					{
						cout << "输入的算式不符合规范！" << endl;
						s = 0;
						return;
					}
					else
						continue;
				}
				else if (in[x] == '(' && x != INPUT.size()-1)
				{
					if (in[x - 1] == 'g')
					{
						cout << "输入的算式不符合规范！" << endl;
						s = 0;
						return;	//log后不可直接跟'('
					}
					else
					{
						p2 = x + 1;
						q1 = x - p;	//第一个参数的长度

						for (int y = x+1; y < INPUT.size(); y++)
						{
							if (((int)in[y] <= 57 && (int)in[y] >= 48) || in[y] == '.') //数字0-9或小数点
							{
								if (y == INPUT.size() - 1)
								{
									cout << "输入的算式不符合规范！" << endl;
									s = 0;
									return;
								}
								else
									continue;
							}
							else if (in[y] == ')')
							{
								q2 = y - x - 1;	//第二个参数的长度
								break;
								
							}
							else
							{
								cout << "输入的算式不符合规范！" << endl;
								s = 0;
								return;
							}
						}
					}
					break;
				}
				else
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;
				}
			}
			v1 = 0;
			v2 = 0;
			input[0] = '\0';

			L1 = INPUT.substr(p, q1);
			convertFromString(v1, L1);

			L1 = INPUT.substr(p2, q2);
			convertFromString(v2, L1);

			result = log(v2)/log(v1);

			sprintf(input, "%.6lf", result);

			INPUT.replace(pos, q1+q2 + 5, input);

			pos = INPUT.find(LOG);

		}

	}

}

