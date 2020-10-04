#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include "MAIN.h"

using namespace std;

void Calc::setA() {

	in_2.resize(300);
	in[0] = '\0';
	in_2[0] = '\0';



}

void Calc::CIN() {

	INPUT = '\0';
	cout << "输入数或算式：";
	cin >> INPUT;



}

void Calc::checkroom() {

	string a = INPUT;
	

	if (a.size() > 99) {
		cout << "算式过长！" << endl;
		s = 0;
	}
	else if (a.size() < 1) {
		cout << "算式过短！" << endl;
		s = 0;
	}
	else {
		
		strcpy(in, INPUT.c_str());
		s = 1;
	}

}


void Calc::checkstr0() {

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
				cout << "输入的算式不符合规范！1" << endl;
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


void Calc::checkhex()
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
					cout << "输入的算式不符合规范！2" << endl;
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
						cout << "输入的算式不符合规范！3" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 1)
						{
							cout << "输入的算式不符合规范！4" << endl;
							s = 0;
							return;
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "输入的算式不符合规范！5" << endl;
								s = 0;
								return;	//小数点不能为最后一位
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "输入的算式不符合规范！6" << endl;
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



void Calc::calchex() {

	if (s)
	{
		char input[100];
		input[0] = '\0';
		in[0] = '\0';
		double n = 0;
		int p = 0;

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



void Calc::checkoct()
{
	if (s)
	{
		in[0] = '\0';
		int d = 0;

		strcpy(in, INPUT.c_str());

		for (int i = 0; i < INPUT.size(); i++)
		{
			if (in[i] == 'O')
			{
				d = 0;

				if (i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！7" << endl;
					s = 0;
					return;
				}

				for (int x = i + 1; x < INPUT.size(); x++)
				{
					if ((int)in[x] <= 55 && (int)in[x] >= 48) //数字0-7
					{
						continue;
					}
					else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z') || ((int)in[x] >= 56 && (int)in[x] <= 57))
					{
						cout << "输入的算式不符合规范！8" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 1)
						{
							cout << "输入的算式不符合规范！9" << endl;
							s = 0;
							return;
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "输入的算式不符合规范！10" << endl;
								s = 0;
								return;	//小数点不能为最后一位
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "输入的算式不符合规范！11" << endl;
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
	}
	else  return;
}


void Calc::calcoct() {

	if (s)
	{
		char input[100];
		in[0] = '\0';
		double n = 0;
		int p;

		strcpy(in, INPUT.c_str());

		for (int i = 0; i < INPUT.size(); i++)
		{
			if (in[i] == 'O')
			{
				for (int x = i + 1;; x++)
				{

					if (in[x] >= '0' && in[x] <= '7')
					{

						n = 8 * n + ((double)in[x] - (double)'0');

						if (x == INPUT.size() - 1)	//	若是最后一位
						{
							p = x - i + 1;
							break;
						}

					}
					else if (in[x] == '.')
					{
						double a;
						for (int y = x + 1;; y++)
						{
							a = (double)x - (double)y;

							if (in[y] >= '0' && in[y] <= '7')
							{
								n = n + ((double)in[y] - (double)'0') * pow(0.125, a);

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


void Calc::checkbit()
{
	if (s)
	{
		in[0] = '\0';
		int d = 0;

		strcpy(in, INPUT.c_str());

		for (int i = 0; i < INPUT.size(); i++)
		{
			if (in[i] == 'B')
			{
				d = 0;

				if (i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！12" << endl;
					s = 0;
					return;
				}

				for (int x = i + 1; x < INPUT.size(); x++)
				{
					if (in[x] == '0' || in[x] == '1') //数字0或1
					{
						continue;
					}
					else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z') || ((int)in[x] <= 57 && (int)in[x] >= 51))
					{
						cout << "输入的算式不符合规范！13" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 1)
						{
							cout << "输入的算式不符合规范！14" << endl;
							s = 0;
							return;
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "输入的算式不符合规范！15" << endl;
								s = 0;
								return;	//小数点不能为最后一位
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "输入的算式不符合规范！16" << endl;
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
	}
	else  return;
}



void Calc::calcbit() {

	if (s)
	{
		char input[100];
		in[0] = '\0';
		double n = 0;
		int p;

		strcpy(in, INPUT.c_str());

		for (int i = 0; i < INPUT.size(); i++)
		{
			if (in[i] == 'B')
			{
				for (int x = i + 1;; x++)
				{

					if (in[x] == '0' || in[x] == '1')
					{

						n = 2 * n + ((double)in[x] - (double)'0');

						if (x == INPUT.size() - 1)	//	若是最后一位
						{
							p = x - i + 1;
							break;
						}

					}
					else if (in[x] == '.')
					{
						double a;
						for (int y = x + 1;; y++)
						{
							a = (double)x - (double)y;

							if (in[y] == '0' || in[y] == '1')
							{
								n = n + ((double)in[y] - (double)'0') * pow(0.5, a);

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


void Calc::checkSC() {

	if (s)
	{
		in[0] = '\0';
		int d = 0;

		strcpy(in, INPUT.c_str());

		for (int i = 0; i < INPUT.size() - 2 && INPUT.size() >3; i++)
		{
			if (INPUT.substr(i, 3) == "sin" && i < INPUT.size() - 2)
			{
				d = 0;

				if (i == INPUT.size() - 3)
				{
					cout << "输入的算式不符合规范！17" << endl;
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
						cout << "输入的算式不符合规范！18" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 3)
						{
							cout << "输入的算式不符合规范！19" << endl;
							s = 0;
							return;	//sin后没有数值，直接是'+''('等非法字符
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "输入的算式不符合规范！20" << endl;
								s = 0;
								return;	//小数点不能为最后一位
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "输入的算式不符合规范！21" << endl;
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



		for (int i = 0; i < INPUT.size() - 2 && INPUT.size() >3; i++)
		{
			if (INPUT.substr(i, 3) == "cos" && INPUT.size() > 3)
			{
				d = 0;

				if (i == INPUT.size() - 3)
				{
					cout << "输入的算式不符合规范！22" << endl;
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
						cout << "输入的算式不符合规范！23" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 3)
						{
							cout << "输入的算式不符合规范！24" << endl;
							s = 0;
							return;	//cos后没有数值，直接是'+''('等非法字符
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "输入的算式不符合规范！25" << endl;
								s = 0;
								return;	//小数点不能为最后一位
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "输入的算式不符合规范！26" << endl;
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




		for (int i = 0; i < INPUT.size() - 2 && INPUT.size() >3; i++)
		{
			if (INPUT.substr(i, 3) == "tan" && INPUT.size() > 3)
			{
				d = 0;

				if (i == INPUT.size() - 3)
				{
					cout << "输入的算式不符合规范！27" << endl;
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
						cout << "输入的算式不符合规范！28" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 3)
						{
							cout << "输入的算式不符合规范！29" << endl;
							s = 0;
							return;	//tan后没有数值，直接是'+''('等非法字符
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "输入的算式不符合规范！30" << endl;
								s = 0;
								return;	//小数点不能为最后一位
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "输入的算式不符合规范！31" << endl;
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




void Calc::calcSC() {

	if (s)
	{
		const string SIN = "sin";
		const string COS = "cos";
		const string TAN = "tan";

		int pos;
		int q = 0;
		double v = 0, resultSC;
		string SC;
		char input[100];

		strcpy(in, INPUT.c_str());

		pos = INPUT.find(SIN);	//计算sin

		int p = pos + 3;

		while (pos != -1)
		{
			for (int x = pos + 3; x < INPUT.size(); x++)
			{
				if ((in[x] <= '9' && in[x] >= '0') || in[x] == '.') //数字0-9或小数点
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
			resultSC = sin(v);
			sprintf(input, "%.6lf", resultSC);

			INPUT.replace(pos, q + 3, input);

			p = 0; q = 0; v = 0;
			in[0] = '\0';
			strcpy(in, INPUT.c_str());

			pos = INPUT.find(SIN);
			p = pos + 3;
		}


		in[0] = '\0';
		strcpy(in, INPUT.c_str());
		pos = INPUT.find(COS);	//计算cos
		p = pos + 3;

		while (pos != -1)
		{
			for (int x = pos + 3; x < INPUT.size(); x++)
			{
				if ((in[x] <= '9' && in[x] >= '0') || in[x] == '.') //数字0-9或小数点
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
			resultSC = cos(v);
			sprintf(input, "%.6lf", resultSC);

			INPUT.replace(pos, q + 3, input);

			p = 0; q = 0; v = 0;
			in[0] = '\0';
			strcpy(in, INPUT.c_str());

			pos = INPUT.find(COS);
			p = pos + 3;
		}


		in[0] = '\0';
		strcpy(in, INPUT.c_str());
		pos = INPUT.find(TAN);	//计算tan
		p = pos + 3;

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
				cout << "输入的算式不符合规范！32" << endl;
				s = 0;
				return;
			}
			else
				resultSC = tan(v);

			sprintf(input, "%.6lf", resultSC);
			INPUT.replace(pos, q + 3, input);

			p = 0; q = 0; v = 0;
			in[0] = '\0';
			strcpy(in, INPUT.c_str());

			pos = INPUT.find(TAN);
			p = pos + 3;
		}
	}
}


void Calc::calclog() {

	if (s)
	{
		const string LOG = "log";

		int pos;
		int q1 = 0, q2 = 0;
		double v1 = 0, v2 = 0, resultlog;
		string L1;
		char input[300];
		in[0] = '\0';
		strcpy(in, INPUT.c_str());

		pos = INPUT.find(LOG);

		int p = pos + 3, p2 = 0;

		while (pos != -1)
		{
			if (pos == INPUT.size() - 3)
			{
				cout << "输入的算式不符合规范！33" << endl;
				s = 0;
				return;
			}


			for (int x = pos + 3; x < INPUT.size(); x++)
			{
				if ((in[x] <= '9' && in[x] >= '0') || in[x] == '.') //数字0-9或小数点
				{
					if (x == INPUT.size() - 1)
					{
						cout << "输入的算式不符合规范！34" << endl;
						s = 0;
						return;
					}
					else
						continue;
				}
				else if (in[x] == '(' && x != INPUT.size() - 1)
				{
					if (in[x - 1] == 'g')
					{
						cout << "输入的算式不符合规范！35" << endl;
						s = 0;
						return;	//log后不可直接跟'('
					}
					else
					{
						p2 = x + 1;
						q1 = x - p;	//第一个参数的长度

						for (int y = x + 1; y < INPUT.size(); y++)
						{
							if (((int)in[y] <= 57 && (int)in[y] >= 48) || in[y] == '.') //数字0-9或小数点
							{
								if (y == INPUT.size() - 1)
								{
									cout << "输入的算式不符合规范！36" << endl;
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
								cout << "输入的算式不符合规范！37" << endl;
								s = 0;
								return;
							}
						}
					}
					break;
				}
				else
				{
					cout << "输入的算式不符合规范！38" << endl;
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

			resultlog = log(v2) / log(v1);

			sprintf(input, "%.6lf", resultlog);

			INPUT.replace(pos, q1 + q2 + 5, input);

			in[0] = '\0';
			strcpy(in, INPUT.c_str());
			pos = INPUT.find(LOG);
			p = pos + 3, p2 = 0;

		}

	}

}

void Calc::calcpow() {

	if (s) {
		int p1, p2, p;
		int q1, q2;
		double v1 = 0, v2 = 0, result;
		string L1;
		char input[100];
		in[0] = '\0';
		strcpy(in, INPUT.c_str());

		for (int i = 0; i < INPUT.size(); i++) {

			if (in[i] == '^')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！39" << endl;
					s = 0;
					return;
				}

				for (int x = i - 1;; x--) {

					if ((in[x] <= '9' && in[x] >= '0') || in[x] == '.')
					{
						if (x == 0)
						{
							p = 1;
							p1 = 0;
							q1 = i;
							break;
						}
						else
							continue;
					}
					else if (in[x] == '+' || in[x] == '-' || in[x] == '*' || in[x] == '/' || in[x] == '(')
					{
						p = x + 2;
						p1 = x + 1;
						q1 = i - x - 1;
						break;
					}
					else {
						cout << "输入的算式不符合规范！40" << endl;
						s = 0;
						return;
					}
				}

				for (int x = i + 1;; x++) {

					if ((in[x] <= '9' && in[x] >= '0') || in[x] == '.')
					{
						if (x == INPUT.size() - 1)
						{
							p2 = i + 1;
							q2 = x - i;
							break;
						}
						else
							continue;
					}
					else if (in[x] == '+' || in[x] == '-' || in[x] == '*' || in[x] == '/' || in[x] == ')')
					{
						p2 = i + 1;
						q2 = x - i - 1;
						break;
					}
					else {
						cout << "输入的算式不符合规范！41" << endl;
						s = 0;
						return;
					}
				}

				v1 = 0;
				v2 = 0;
				input[0] = '\0';

				L1 = INPUT.substr(p1, q1);
				convertFromString(v1, L1);

				L1 = INPUT.substr(p2, q2);
				convertFromString(v2, L1);

				result = pow(v1, v2);

				sprintf(input, "%.6lf", result);

				INPUT.replace(p1, q1 + q2 + 1, input);

				in[0] = '\0';
				strcpy(in, INPUT.c_str());
			}
		}
	}
}

void Calc::changenega() {

	if (s)
	{
		int p1, p2, p;
		int q1, q2;
		double v1 = 0, v2 = 0, result;
		string L, L1 = "(0", L2 = ")";
		char input[100];
		in[0] = '\0';
		strcpy(in, INPUT.c_str());


		if (in[0] == '-' && INPUT.size() > 1)
		{
			cout << '0' << endl;
			for (int i = 1; i < INPUT.size(); i++) {

				if (((in[i] >= '0' && in[i] <= '9') || in[i] == '.') && i < INPUT.size() - 1)
				{
					continue;
				}
				else if (((in[i] >= '0' && in[i] <= '9') || in[i] == '.') && i == INPUT.size() - 1)
				{
					L = INPUT.substr(0, i + 1);
					L1.append(L);
					L1.append(L2);
					INPUT.replace(0, i + 1, L1);
					in[0] = '\0';
					strcpy(in, INPUT.c_str());

					L1 = "(0";
					break;
				}
				else
				{
					L = INPUT.substr(0, i);
					L1.append(L);
					L1.append(L2);
					INPUT.replace(0, i, L1);
					in[0] = '\0';
					strcpy(in, INPUT.c_str());

					L1 = "(0";
					break;
				}
			}
		}

		for (int i = 1; i < INPUT.size(); i++)
		{
			if (in[i] == '-' && (in[i - 1] > '9' || in[i - 1] < '0') && in[i - 1] != ')' && i!=INPUT.size()-1)
			{
				for (int x = i + 1; x < INPUT.size(); x++) 
				{
					if (((in[x] >= '0' && in[x] <= '9') || in[x] == '.') && x < INPUT.size() - 1)
					{
						continue;
					}
					else if (((in[x] >= '0' && in[x] <= '9') || in[x] == '.') && x == INPUT.size() - 1)
					{
						L = INPUT.substr(i, x - i + 1);
						L1.append(L);
						L1.append(L2);
						INPUT.replace(i, x - i + 1, L1);
						in[0] = '\0';
						strcpy(in, INPUT.c_str());

						L1 = "(0";
						break;
					}
					else
					{
						L = INPUT.substr(i, x-i);
						L1.append(L);
						L1.append(L2);
						INPUT.replace(i, x-i, L1);
						in[0] = '\0';
						strcpy(in, INPUT.c_str());

						L1 = "(0";
						break;
					}
				}
			}
		}
	}
};


void Calc::COUT() {

	for (int i = 0; i < INPUT.size() && i < 300; i++)
	{
		cout << INPUT[i];
	}
	cout << endl;
}



void Calc::checkstr() {

	if (s) {

		in[0] = '\0';

		strcpy(in, INPUT.c_str());

		int front = 0, back = 0;	//	前后括号个数

		for (int i = 0; i < INPUT.size(); i++)
		{
			if ((int)in[i] <= 57 && (int)in[i] >= 48) //数字1～9
			{
				continue;
			}
			else if (in[i] == '+')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！42" << endl;
					s = 0;
					return;	// '+'不可以作为第一个字符或最后一个字符
				}
				else if ((in[i + 1] > '9' || in[i + 1]< '0') && in[i + 1]!= '(')
				{
					cout << "输入的算式不符合规范！43" << endl;
					s = 0;
					return;	//'+'号后面不可以有除数字和'('以外的其他字符
				}
				else
					continue;
			}
			else if (in[i] == '-')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！44" << endl;
					s = 0;
					return;	// '-'不可以作为第一个或最后一个字符
				}
				else if ((in[i+1]>'9' || in[i + 1]< '0') && in[i+1]!='(')
				{
					cout << "输入的算式不符合规范！45" << endl;
					s = 0;
					return;	//'-'号后面不可以有除数字和'('以外的其他字符
				}
				else
					continue;
			}
			else if (in[i] == '*')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！46" << endl;
					s = 0;
					return;	// '*'不可以作为第一个字符或最后一个字符
				}
				else if ((in[i + 1] > '9' || in[i + 1] < '0') && in[i + 1] != '(')
				{
					cout << "输入的算式不符合规范！47" << endl;
					s = 0;
					return;	//'*'号后面不可以有除数字以外和'('以外的其他字符
				}
				else
					continue;
			}
			else if (in[i] == '/')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！48" << endl;
					s = 0;
					return;	// '/'不可以作为第一个字符或最后一个字符
				}
				else if ((in[i + 1] > '9' || in[i + 1] < '0') && in[i + 1] != '(')
				{
					cout << "输入的算式不符合规范！49" << endl;
					s = 0;
					return;	//'/'号后面不可以有除数字以外和'('以外的其他字符
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
						else if (in[x] <= '9' && in[x] >= '1')
						{
							w = 0;
							continue;
						}
						else
						{
							break;
						}

					}

					if (w) {
						cout << "输入的算式不符合规范！50" << endl;
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
					if (in[i+1]>'9' || in[i + 1]<'0')
					{
						cout << "输入的算式不符合规范！51" << endl;
						s = 0;
						return;	//'('号后面不可以有除数字以外的其他字符
					}
					else
						continue;
				}
				else if (i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！52" << endl;
					s = 0;
					return;	//'('不可以是最后一个字符
				}
				else
				{
					if (in[i - 1] > '0' && in[i - 1] < '9')
					{
						cout << "输入的算式不符合规范！53" << endl;
						s = 0;
						return;	//'('号前面不可以有数字
					}
					else if ((in[i + 1] > '9' || in[i + 1] < '0') && in[i+1] != '(')
					{
						cout << "输入的算式不符合规范！54" << endl;
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
					cout << "输入的算式不符合规范！55" << endl;
					s = 0;
					return;	// ')'号不可以作为第一个字符
				}
				else if (i == INPUT.size() - 1)
				{
					if (in[i - 1]<'0' || in[i - 1]>'9')
					{
						cout << "输入的算式不符合规范！56" << endl;
						s = 0;
						return;	// ')'号前面不可以有除数字以外的其他字符
					}
					else
						continue;

				}
				else if (in[i - 1]<'0' || in[i - 1]>'9' || (in[i + 1] >= '0' && in[i + 1] <= '9'))
				{
					cout << "输入的算式不符合规范！57" << endl;
					s = 0;
					return;	// ')'号前面不可以有数字以外的其他字符,后面不可以有数字
				}
				else if (front < back)
				{
					cout << "输入的算式不符合规范！58" << endl;
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
					cout << "输入的算式不符合规范！59" << endl;
					s = 0;
					return;	// 小数点不可以作为第一个字符或最后一个字符
				}
				else if (in[i + 1]<'0' || in[i + 1]>'9')
				{
					cout << "输入的算式不符合规范！60" << endl;
					s = 0;
					return;	//小数点后面不可以有数字以外的其他字符
				}
				else
				{
					for (int x = i + 1; x < INPUT.size(); x++)
					{
						if ((in[x]<'0' || in[x]>'9') && in[x] != '.') {
							break;
						}
						else if (in[x] == '.')
						{
							cout << "输入的算式不符合规范！61" << endl;
							s = 0;
							return;	//一串数字中不可以有多个小数点
						}
					}
					continue;
				}


			}
			else
			{
				cout << "输入的算式不符合规范！62" << endl;
				s = 0;
				return;	//含有四则运算符和数字以外的非法字符
			}
		}
		if (front != back)
		{
			cout << "输入的算式不符合规范！63" << endl;
			s = 0;
			return;	//前后括号个数不等
		}
	}
	else  return;

}


string Calc::getINPUT() {
	if (s) {
		return INPUT;
	}
	else return "0";
}

void Calc::setIN(string a)
{
	strcpy(IN, a.c_str());
}


void Calc::getSuffix()	//获取后缀表达式
{
	for (int i = 0; IN[i] != '\0'; i++)
	{
		if ((IN[i] >= '0' && IN[i] <= '9') || IN[i] == '.')//1,数字直接输出
		{
			string str;
			for (; (IN[i] >= '0' && IN[i] <= '9') || IN[i] == '.'; i++)
			{
				//将一个数字存储到字符串中
				char s = IN[i];
				str.push_back(s);
			}
			//将字符串输出
			out.push_back(str);
			i--;
		}
		else if (s1.empty())//2,遇见非数字时, 如果堆栈为空，则直接把该字符放入堆栈
		{
			s1.push(IN[i]);
		}
		else if (IN[i] == '+' || IN[i] == '-')
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
			s1.push(IN[i]);
		}
		else if (IN[i] == '*' || IN[i] == '/')
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
			s1.push(IN[i]);
		}
		else if (IN[i] == ')')
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
		else if (IN[i] == '(')
			//2.4,如果该字符是左括号时，直接放入堆栈
		{
			s1.push(IN[i]);
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

double Calc::Calc_Suffix()
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
				if (x == 0) {
					cout << "输入的算式不符合规范！结果已置零" << endl;
					Calc::s = 0;
					return 0;
				}
				else
					s2.push(y / x);
			}
		}
	}
	float z = s2.top();
	s2.pop();
	result = z;
	return result;
}

void Calc::m_init()
{
	IN[0] = '\0';
	out.clear();
}

void Calc::RADIX() {






};



void  Calc::Calcfun1() {

	double result;
	a = 0; b = 0; c = 0;

	cout << "分别输入 ax+b=0 的参数a、b" << endl;
	cin >> a >> b;

	if (a == 0)
	{
		cout << "方程式错误，无法求解。" << endl;
		return;
	}
	result = -b / a;

	cout << "解得x=" << result << endl;
}


void  Calc::Calcfun2() {

	double result, result2;
	double T1, T2, T3;
	a = 0; b = 0; c = 0;

	cout << "分别输入 ax^2+bx+c=0 的参数a、b、c" << endl;
	cin >> a >> b >> c;

	if (a == 0 && b == 0)
	{
		cout << "方程式错误，无法求解。" << endl;
		return;
	}
	else if (a == 0 && b != 0)
	{
		result = -c / b;
		cout << "解得x=" << result << endl;	//	只有a为0时，为一元一次方程
	}
	else {
		T1 = b * b - 4 * a * c;

		if (T1 == 0) {
			result = -b / 2 * a;
			cout << "解得x=" << result << endl;
		}
		else if (T1 < 0) {
			cout << "方程式错误，无法求解。" << endl;
			return;
		}
		else
		{
			T2 = -b + pow(T1, 0.5);
			T3 = -b - pow(T1, 0.5);
			result = T2 / 2 * a;
			result2 = T3 / 2 * a;

			cout << "解得x=" << result << " 或x=" << result2 << endl;
		}
	}
}


void  Calc::Calcfun31() {

	double result;
	a = 0; b = 0; c = 0;

	cout << "分别输入 a^x=b 的参数a、b(a>0，b>0):" << endl;
	cin >> a >> b;

	if (a == 0 || b == 0 || a <= 0 || b <= 0 || a == 1)
	{
		cout << "方程式错误，无法求解。" << endl;
		return;
	}
	else
	{
		result = log(b) / log(a);
		cout << "解得x=" << result << endl;
	}
}


void  Calc::Calcfun32() {

	double result;
	a = 0; b = 0; c = 0;

	cout << "分别输入 x^a=b 的参数a、b(b>=0):" << endl;
	cin >> a >> b;

	if (a == 0 || b < 0)
	{
		cout << "方程式错误，无法求解。" << endl;
		return;
	}
	else if (b == 0)
	{
		cout << "解得x=0" << endl;
	}
	else
	{
		result = pow(b, 1 / a);

		if (a == (double)((int)a) && (int)a % 2 == 0)
		{
			cout << "解得x= " << result << " 或 " << -result << endl;

		}
		else
			cout << "解得x=" << result << endl;
	}
}

void  Calc::Calcfun41() {

	double result;
	a = 0; b = 0; c = 0;

	cout << "分别输入 log x(a)=b 的参数a、b(a>0)" << endl;
	cin >> a >> b;

	if (b == 0 || a <= 0)
	{
		cout << "方程式错误，无法求解。" << endl;
		return;
	}
	else if (a == 0)
	{
		cout << "解得x=0" << endl;
		return;

	}
	else
	{
		result = pow(a, 1 / b);
		if (b == (double)((int)b) && (int)b % 2 == 0)
		{
			cout << "解得x= " << result << " 或 " << -result << endl;
		}
		else
			cout << "解得x=" << result << endl;
	}
}


void  Calc::Calcfun42() {

	double result;
	a = 0; b = 0; c = 0;

	cout << "分别输入 log a(x)=b 的参数a、b(a>0)" << endl;
	cin >> a >> b;

	if (a < 0 || (a == 0 && b == 0))
	{
		cout << "方程式错误，无法求解。" << endl;
		return;
	}
	else if (a == 0 && b != 0)
	{
		cout << "解得x=0" << endl;
		return;

	}
	else if (b == 0 && a != 0)
	{
		cout << "解得x=1" << endl;
		return;
	}
	else
	{
		result = pow(a, b);
		cout << "解得x=" << result << endl;
	}
}





void  Calc::Calcfun5() {

	double result;
	a = 0; b = 0; c = 0;

	cout << "分别输入 a/x+b=0 的参数a、b" << endl;
	cin >> a >> b;

	if (a == 0 || b == 0)
	{
		cout << "方程式错误，无法求解。" << endl;
		return;
	}
	result = -a / b;

	cout << "解得x=" << result << endl;
}

int Calc::checkS() {

	if (Calc::s == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}