#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "判断计算16.h"
#include "全局父类.h"

using namespace std;


Calc_HEX::Calc_HEX() {};

void Calc_HEX::checkhex()
{
	if (s)
	{
		in[0] = '\0';
		int d = 0;

		strcpy(in, INPUT.c_str());

		for (int i = 0; i < INPUT.size(); i++)
		{
			if (in[i] == 'H')
			{
				d = 0;

				if (i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;
				}

				for (int x = i + 1; x < INPUT.size(); x++)
				{
					if (((int)in[x] <= 57 && (int)in[x] >= 48) || (in[x] <= 'f' && in[x] >= 'a')) //数字或小写字母a到f
					{
						continue;
					}
					else if (in[x] >= 'A' && in[x] <= 'F') //大写字母A到F
					{
						in[x] += 32;
						INPUT[x] = in[x];
						continue;
					}
					else if ((in[x] > 'f' && in[x] <= 'z') || (in[x] > 'F' && in[x] <= 'Z'))	//小写或大写的G到Z
					{
						cout << "输入的算式不符合规范！" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 1)
						{
							cout << "输入的算式不符合规范！" << endl;
							s = 0;
							return;
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
								return;	//不能含有多个小数点
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
	}
	else  return;
}



void Calc_HEX::calchex() {

	if (s)
	{
		char input[100];
		input[0] = '\0';
		in[0] = '\0';
		double n = 0;
		int p=0;

		strcpy(in, INPUT.c_str());

		for (int i = 0; i < INPUT.size(); i++)
		{
			if (in[i] == 'H')
			{
				for (int x = i + 1; x < INPUT.size(); x++)
				{
					if ((in[x] >= '0' && in[x] <= '9') || (in[x] >= 'a' && in[x] <= 'f'))
					{
						if (in[x] >= 'a' && in[x] <= 'f')
						{
							n = 16 * n + (10 + ((double)in[x] - (double)'a'));

							if (x == INPUT.size() - 1)	//	若是最后一位
							{
								p = x - i + 1;
								break;
							}
						}
						else
						{
							n = 16 * n + ((double)in[x] - (double)'0');

							if (x == INPUT.size() - 1)	//	若是最后一位
							{
								p = x - i + 1;
								break;
							}
						}
					}
					else if (in[x] == '.')
					{
						double a;

						for (int y = x + 1; y < INPUT.size(); y++)
						{
							a = (double)x - (double)y;

							if (in[y] >= 'a' && in[y] <= 'f')
							{
								n = n + (10 + (double)in[y] - (double)'a') * pow(0.0625, a);

								if (y == INPUT.size() - 1)	//	若是最后一位
								{
									p = y - i + 1;
									break;
								}
								
							}
							else if (in[y] >= '0' && in[y] <= '9')
							{
								n = n + ((double)in[y] - (double)'0') * pow(0.0625, a);

								if (y == INPUT.size() - 1)	//	若是最后一位
								{
									p = y - i + 1;
									break;
								}
							}
							else
							{
								p = y - i;
								break;
							}
							
						}

						break;
					}
					else 
					{
						p = x - i;
						break;
					}

				}

				sprintf(input, "%.6lf", n);

				INPUT.replace(i, p, input);

			}
		}
	}
}










