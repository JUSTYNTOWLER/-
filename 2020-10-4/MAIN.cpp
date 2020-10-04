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
	cout << "����������ʽ��";
	cin >> INPUT;



}

void Calc::checkroom() {

	string a = INPUT;
	

	if (a.size() > 99) {
		cout << "��ʽ������" << endl;
		s = 0;
	}
	else if (a.size() < 1) {
		cout << "��ʽ���̣�" << endl;
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
			if ((int)in[i] <= 57 && (int)in[i] >= 48) //����1��9
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
			else if (in[i] <= 'z' && in[i] >= 'a') //Ӣ��Сд��ĸ
			{
				continue;
			}
			else if (in[i] <= 'Z' && in[i] >= 'A') //Ӣ�Ĵ�д��ĸ
			{
				continue;
			}
			else
			{
				cout << "�������ʽ�����Ϲ淶��1" << endl;
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
					cout << "�������ʽ�����Ϲ淶��2" << endl;
					s = 0;
					return;
				}

				for (int x = i + 1; x < INPUT.size(); x++)
				{
					if (((int)in[x] <= 57 && (int)in[x] >= 48) || (in[x] <= 'f' && in[x] >= 'a')) //���ֻ�Сд��ĸa��f
					{
						continue;
					}
					else if (in[x] >= 'A' && in[x] <= 'F') //��д��ĸA��F
					{
						in[x] += 32;
						INPUT[x] = in[x];
						continue;
					}
					else if ((in[x] > 'f' && in[x] <= 'z') || (in[x] > 'F' && in[x] <= 'Z'))	//Сд���д��G��Z
					{
						cout << "�������ʽ�����Ϲ淶��3" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 1)
						{
							cout << "�������ʽ�����Ϲ淶��4" << endl;
							s = 0;
							return;
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "�������ʽ�����Ϲ淶��5" << endl;
								s = 0;
								return;	//С���㲻��Ϊ���һλ
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "�������ʽ�����Ϲ淶��6" << endl;
								s = 0;
								return;	//���ܺ��ж��С����
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

							if (x == INPUT.size() - 1)	//	�������һλ
							{
								p = x - i + 1;
								break;
							}
						}
						else
						{
							n = 16 * n + ((double)in[x] - (double)'0');

							if (x == INPUT.size() - 1)	//	�������һλ
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

								if (y == INPUT.size() - 1)	//	�������һλ
								{
									p = y - i + 1;
									break;
								}

							}
							else if (in[y] >= '0' && in[y] <= '9')
							{
								n = n + ((double)in[y] - (double)'0') * pow(0.0625, a);

								if (y == INPUT.size() - 1)	//	�������һλ
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
					cout << "�������ʽ�����Ϲ淶��7" << endl;
					s = 0;
					return;
				}

				for (int x = i + 1; x < INPUT.size(); x++)
				{
					if ((int)in[x] <= 55 && (int)in[x] >= 48) //����0-7
					{
						continue;
					}
					else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z') || ((int)in[x] >= 56 && (int)in[x] <= 57))
					{
						cout << "�������ʽ�����Ϲ淶��8" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 1)
						{
							cout << "�������ʽ�����Ϲ淶��9" << endl;
							s = 0;
							return;
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "�������ʽ�����Ϲ淶��10" << endl;
								s = 0;
								return;	//С���㲻��Ϊ���һλ
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "�������ʽ�����Ϲ淶��11" << endl;
								s = 0;
								return; //���ܺ��ж��С����
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

						if (x == INPUT.size() - 1)	//	�������һλ
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

								if (y == INPUT.size() - 1)	//	�������һλ
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
					cout << "�������ʽ�����Ϲ淶��12" << endl;
					s = 0;
					return;
				}

				for (int x = i + 1; x < INPUT.size(); x++)
				{
					if (in[x] == '0' || in[x] == '1') //����0��1
					{
						continue;
					}
					else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z') || ((int)in[x] <= 57 && (int)in[x] >= 51))
					{
						cout << "�������ʽ�����Ϲ淶��13" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 1)
						{
							cout << "�������ʽ�����Ϲ淶��14" << endl;
							s = 0;
							return;
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "�������ʽ�����Ϲ淶��15" << endl;
								s = 0;
								return;	//С���㲻��Ϊ���һλ
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "�������ʽ�����Ϲ淶��16" << endl;
								s = 0;
								return; //���ܺ��ж��С����
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

						if (x == INPUT.size() - 1)	//	�������һλ
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

								if (y == INPUT.size() - 1)	//	�������һλ
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
					cout << "�������ʽ�����Ϲ淶��17" << endl;
					s = 0;
					return;	//sin������Ϊ�ַ����Ľ�β
				}

				for (int x = i + 3; x < INPUT.size(); x++)
				{
					if ((int)in[x] <= 57 && (int)in[x] >= 48) //����0-9
					{
						continue;
					}
					else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z'))
					{
						cout << "�������ʽ�����Ϲ淶��18" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 3)
						{
							cout << "�������ʽ�����Ϲ淶��19" << endl;
							s = 0;
							return;	//sin��û����ֵ��ֱ����'+''('�ȷǷ��ַ�
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "�������ʽ�����Ϲ淶��20" << endl;
								s = 0;
								return;	//С���㲻��Ϊ���һλ
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "�������ʽ�����Ϲ淶��21" << endl;
								s = 0;
								return; //���ܺ��ж��С����
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

		// ���sin�ĺϷ���



		for (int i = 0; i < INPUT.size() - 2 && INPUT.size() >3; i++)
		{
			if (INPUT.substr(i, 3) == "cos" && INPUT.size() > 3)
			{
				d = 0;

				if (i == INPUT.size() - 3)
				{
					cout << "�������ʽ�����Ϲ淶��22" << endl;
					s = 0;
					return;	//cos������Ϊ�ַ����Ľ�β
				}

				for (int x = i + 3; x < INPUT.size(); x++)
				{
					if ((int)in[x] <= 57 && (int)in[x] >= 48) //����0-9
					{
						continue;
					}
					else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z'))
					{
						cout << "�������ʽ�����Ϲ淶��23" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 3)
						{
							cout << "�������ʽ�����Ϲ淶��24" << endl;
							s = 0;
							return;	//cos��û����ֵ��ֱ����'+''('�ȷǷ��ַ�
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "�������ʽ�����Ϲ淶��25" << endl;
								s = 0;
								return;	//С���㲻��Ϊ���һλ
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "�������ʽ�����Ϲ淶��26" << endl;
								s = 0;
								return; //���ܺ��ж��С����
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

		// ���cos�ĺϷ���




		for (int i = 0; i < INPUT.size() - 2 && INPUT.size() >3; i++)
		{
			if (INPUT.substr(i, 3) == "tan" && INPUT.size() > 3)
			{
				d = 0;

				if (i == INPUT.size() - 3)
				{
					cout << "�������ʽ�����Ϲ淶��27" << endl;
					s = 0;
					return;	//tan������Ϊ�ַ����Ľ�β
				}

				for (int x = i + 3; x < INPUT.size(); x++)
				{
					if ((int)in[x] <= 57 && (int)in[x] >= 48) //����0-9
					{
						continue;
					}
					else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z'))
					{
						cout << "�������ʽ�����Ϲ淶��28" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 3)
						{
							cout << "�������ʽ�����Ϲ淶��29" << endl;
							s = 0;
							return;	//tan��û����ֵ��ֱ����'+''('�ȷǷ��ַ�
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "�������ʽ�����Ϲ淶��30" << endl;
								s = 0;
								return;	//С���㲻��Ϊ���һλ
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "�������ʽ�����Ϲ淶��31" << endl;
								s = 0;
								return; //���ܺ��ж��С����
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

		// ���tan�ĺϷ���
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

		pos = INPUT.find(SIN);	//����sin

		int p = pos + 3;

		while (pos != -1)
		{
			for (int x = pos + 3; x < INPUT.size(); x++)
			{
				if ((in[x] <= '9' && in[x] >= '0') || in[x] == '.') //����0-9��С����
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
		pos = INPUT.find(COS);	//����cos
		p = pos + 3;

		while (pos != -1)
		{
			for (int x = pos + 3; x < INPUT.size(); x++)
			{
				if ((in[x] <= '9' && in[x] >= '0') || in[x] == '.') //����0-9��С����
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
		pos = INPUT.find(TAN);	//����tan
		p = pos + 3;

		while (pos != -1)
		{
			for (int x = pos + 3; x < INPUT.size(); x++)
			{
				if (((int)in[x] <= 57 && (int)in[x] >= 48) || in[x] == '.') //����0-9��С����
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
				cout << "�������ʽ�����Ϲ淶��32" << endl;
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
				cout << "�������ʽ�����Ϲ淶��33" << endl;
				s = 0;
				return;
			}


			for (int x = pos + 3; x < INPUT.size(); x++)
			{
				if ((in[x] <= '9' && in[x] >= '0') || in[x] == '.') //����0-9��С����
				{
					if (x == INPUT.size() - 1)
					{
						cout << "�������ʽ�����Ϲ淶��34" << endl;
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
						cout << "�������ʽ�����Ϲ淶��35" << endl;
						s = 0;
						return;	//log�󲻿�ֱ�Ӹ�'('
					}
					else
					{
						p2 = x + 1;
						q1 = x - p;	//��һ�������ĳ���

						for (int y = x + 1; y < INPUT.size(); y++)
						{
							if (((int)in[y] <= 57 && (int)in[y] >= 48) || in[y] == '.') //����0-9��С����
							{
								if (y == INPUT.size() - 1)
								{
									cout << "�������ʽ�����Ϲ淶��36" << endl;
									s = 0;
									return;
								}
								else
									continue;
							}
							else if (in[y] == ')')
							{
								q2 = y - x - 1;	//�ڶ��������ĳ���
								break;

							}
							else
							{
								cout << "�������ʽ�����Ϲ淶��37" << endl;
								s = 0;
								return;
							}
						}
					}
					break;
				}
				else
				{
					cout << "�������ʽ�����Ϲ淶��38" << endl;
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
					cout << "�������ʽ�����Ϲ淶��39" << endl;
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
						cout << "�������ʽ�����Ϲ淶��40" << endl;
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
						cout << "�������ʽ�����Ϲ淶��41" << endl;
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

		int front = 0, back = 0;	//	ǰ�����Ÿ���

		for (int i = 0; i < INPUT.size(); i++)
		{
			if ((int)in[i] <= 57 && (int)in[i] >= 48) //����1��9
			{
				continue;
			}
			else if (in[i] == '+')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "�������ʽ�����Ϲ淶��42" << endl;
					s = 0;
					return;	// '+'��������Ϊ��һ���ַ������һ���ַ�
				}
				else if ((in[i + 1] > '9' || in[i + 1]< '0') && in[i + 1]!= '(')
				{
					cout << "�������ʽ�����Ϲ淶��43" << endl;
					s = 0;
					return;	//'+'�ź��治�����г����ֺ�'('����������ַ�
				}
				else
					continue;
			}
			else if (in[i] == '-')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "�������ʽ�����Ϲ淶��44" << endl;
					s = 0;
					return;	// '-'��������Ϊ��һ�������һ���ַ�
				}
				else if ((in[i+1]>'9' || in[i + 1]< '0') && in[i+1]!='(')
				{
					cout << "�������ʽ�����Ϲ淶��45" << endl;
					s = 0;
					return;	//'-'�ź��治�����г����ֺ�'('����������ַ�
				}
				else
					continue;
			}
			else if (in[i] == '*')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "�������ʽ�����Ϲ淶��46" << endl;
					s = 0;
					return;	// '*'��������Ϊ��һ���ַ������һ���ַ�
				}
				else if ((in[i + 1] > '9' || in[i + 1] < '0') && in[i + 1] != '(')
				{
					cout << "�������ʽ�����Ϲ淶��47" << endl;
					s = 0;
					return;	//'*'�ź��治�����г����������'('����������ַ�
				}
				else
					continue;
			}
			else if (in[i] == '/')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "�������ʽ�����Ϲ淶��48" << endl;
					s = 0;
					return;	// '/'��������Ϊ��һ���ַ������һ���ַ�
				}
				else if ((in[i + 1] > '9' || in[i + 1] < '0') && in[i + 1] != '(')
				{
					cout << "�������ʽ�����Ϲ淶��49" << endl;
					s = 0;
					return;	//'/'�ź��治�����г����������'('����������ַ�
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
						cout << "�������ʽ�����Ϲ淶��50" << endl;
						s = 0;
						return; // '/'�ź������ֵ��������'0'
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
						cout << "�������ʽ�����Ϲ淶��51" << endl;
						s = 0;
						return;	//'('�ź��治�����г���������������ַ�
					}
					else
						continue;
				}
				else if (i == INPUT.size() - 1)
				{
					cout << "�������ʽ�����Ϲ淶��52" << endl;
					s = 0;
					return;	//'('�����������һ���ַ�
				}
				else
				{
					if (in[i - 1] > '0' && in[i - 1] < '9')
					{
						cout << "�������ʽ�����Ϲ淶��53" << endl;
						s = 0;
						return;	//'('��ǰ�治����������
					}
					else if ((in[i + 1] > '9' || in[i + 1] < '0') && in[i+1] != '(')
					{
						cout << "�������ʽ�����Ϲ淶��54" << endl;
						s = 0;
						return;	//'('�ź��治�����г���������������ַ�
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
					cout << "�������ʽ�����Ϲ淶��55" << endl;
					s = 0;
					return;	// ')'�Ų�������Ϊ��һ���ַ�
				}
				else if (i == INPUT.size() - 1)
				{
					if (in[i - 1]<'0' || in[i - 1]>'9')
					{
						cout << "�������ʽ�����Ϲ淶��56" << endl;
						s = 0;
						return;	// ')'��ǰ�治�����г���������������ַ�
					}
					else
						continue;

				}
				else if (in[i - 1]<'0' || in[i - 1]>'9' || (in[i + 1] >= '0' && in[i + 1] <= '9'))
				{
					cout << "�������ʽ�����Ϲ淶��57" << endl;
					s = 0;
					return;	// ')'��ǰ�治��������������������ַ�,���治����������
				}
				else if (front < back)
				{
					cout << "�������ʽ�����Ϲ淶��58" << endl;
					s = 0;
					return;	// ')'�ŵĸ������ܱ����е�'('����Ҫ��
				}
				else
					continue;

			}
			else if (in[i] == '.')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "�������ʽ�����Ϲ淶��59" << endl;
					s = 0;
					return;	// С���㲻������Ϊ��һ���ַ������һ���ַ�
				}
				else if (in[i + 1]<'0' || in[i + 1]>'9')
				{
					cout << "�������ʽ�����Ϲ淶��60" << endl;
					s = 0;
					return;	//С������治��������������������ַ�
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
							cout << "�������ʽ�����Ϲ淶��61" << endl;
							s = 0;
							return;	//һ�������в������ж��С����
						}
					}
					continue;
				}


			}
			else
			{
				cout << "�������ʽ�����Ϲ淶��62" << endl;
				s = 0;
				return;	//�����������������������ķǷ��ַ�
			}
		}
		if (front != back)
		{
			cout << "�������ʽ�����Ϲ淶��63" << endl;
			s = 0;
			return;	//ǰ�����Ÿ�������
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


void Calc::getSuffix()	//��ȡ��׺���ʽ
{
	for (int i = 0; IN[i] != '\0'; i++)
	{
		if ((IN[i] >= '0' && IN[i] <= '9') || IN[i] == '.')//1,����ֱ�����
		{
			string str;
			for (; (IN[i] >= '0' && IN[i] <= '9') || IN[i] == '.'; i++)
			{
				//��һ�����ִ洢���ַ�����
				char s = IN[i];
				str.push_back(s);
			}
			//���ַ������
			out.push_back(str);
			i--;
		}
		else if (s1.empty())//2,����������ʱ, �����ջΪ�գ���ֱ�ӰѸ��ַ������ջ
		{
			s1.push(IN[i]);
		}
		else if (IN[i] == '+' || IN[i] == '-')
			//2.1,�����+��- ��ô������ջջ��Ԫ�� һֱ������ȼ�>=�Ӽ��� �����ջ����+-*/,
			//�����������ַ�ʱ���������ţ����ջ��ʱbreak
		{
			while (!s1.empty()) {
				if (s1.top() == '+' || s1.top() == '-' || s1.top() == '*' || s1.top() == '/') {
					//���ַ�ת��Ϊ�ַ������
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
			//2.2,�����*��/ ��ô������ջջ��Ԫ�� һֱ������ȼ�>=�˳��� �����ջ����*/,
			//�����������ַ�ʱ���������ţ����ţ����ţ����ջ��ʱbreak
		{
			while (!s1.empty()) {
				if (s1.top() == '*' || s1.top() == '/') {
					//���ַ�ת��Ϊ�ַ������
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
			//2.3,������ַ���������ʱ��һֱ���ջ��Ԫ�أ�ֱ������������Ϊֹbreak:
		{
			while (!s1.empty()) {
				if (s1.top() == '(') {
					s1.pop();
					break;
				}
				//���ַ�ת��Ϊ�ַ������
				char x;
				x = s1.top();
				s1.pop();
				string str;
				str.push_back(x);
				out.push_back(str);
			}
		}
		else if (IN[i] == '(')
			//2.4,������ַ���������ʱ��ֱ�ӷ����ջ
		{
			s1.push(IN[i]);
		}
	}
	//�ַ���ѭ�������� �������ջ��ʣ�������
	while (!s1.empty()) {
		//���ַ�ת��Ϊ�ַ������
		char x;
		x = s1.top();
		s1.pop();
		string str;
		str.push_back(x);
		out.push_back(str);
	}
	//�����׺���ʽ
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
		if (s >> t)//��������֣�ֱ����ջ
		{
			s2.push(t);
		}
		else if (out[i] == "+" || out[i] == "-" || out[i] == "*" || out[i] == "/")//��������������ջ���Σ����������㣬����󣬽����ջ
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
					cout << "�������ʽ�����Ϲ淶�����������" << endl;
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

	cout << "�ֱ����� ax+b=0 �Ĳ���a��b" << endl;
	cin >> a >> b;

	if (a == 0)
	{
		cout << "����ʽ�����޷���⡣" << endl;
		return;
	}
	result = -b / a;

	cout << "���x=" << result << endl;
}


void  Calc::Calcfun2() {

	double result, result2;
	double T1, T2, T3;
	a = 0; b = 0; c = 0;

	cout << "�ֱ����� ax^2+bx+c=0 �Ĳ���a��b��c" << endl;
	cin >> a >> b >> c;

	if (a == 0 && b == 0)
	{
		cout << "����ʽ�����޷���⡣" << endl;
		return;
	}
	else if (a == 0 && b != 0)
	{
		result = -c / b;
		cout << "���x=" << result << endl;	//	ֻ��aΪ0ʱ��ΪһԪһ�η���
	}
	else {
		T1 = b * b - 4 * a * c;

		if (T1 == 0) {
			result = -b / 2 * a;
			cout << "���x=" << result << endl;
		}
		else if (T1 < 0) {
			cout << "����ʽ�����޷���⡣" << endl;
			return;
		}
		else
		{
			T2 = -b + pow(T1, 0.5);
			T3 = -b - pow(T1, 0.5);
			result = T2 / 2 * a;
			result2 = T3 / 2 * a;

			cout << "���x=" << result << " ��x=" << result2 << endl;
		}
	}
}


void  Calc::Calcfun31() {

	double result;
	a = 0; b = 0; c = 0;

	cout << "�ֱ����� a^x=b �Ĳ���a��b(a>0��b>0):" << endl;
	cin >> a >> b;

	if (a == 0 || b == 0 || a <= 0 || b <= 0 || a == 1)
	{
		cout << "����ʽ�����޷���⡣" << endl;
		return;
	}
	else
	{
		result = log(b) / log(a);
		cout << "���x=" << result << endl;
	}
}


void  Calc::Calcfun32() {

	double result;
	a = 0; b = 0; c = 0;

	cout << "�ֱ����� x^a=b �Ĳ���a��b(b>=0):" << endl;
	cin >> a >> b;

	if (a == 0 || b < 0)
	{
		cout << "����ʽ�����޷���⡣" << endl;
		return;
	}
	else if (b == 0)
	{
		cout << "���x=0" << endl;
	}
	else
	{
		result = pow(b, 1 / a);

		if (a == (double)((int)a) && (int)a % 2 == 0)
		{
			cout << "���x= " << result << " �� " << -result << endl;

		}
		else
			cout << "���x=" << result << endl;
	}
}

void  Calc::Calcfun41() {

	double result;
	a = 0; b = 0; c = 0;

	cout << "�ֱ����� log x(a)=b �Ĳ���a��b(a>0)" << endl;
	cin >> a >> b;

	if (b == 0 || a <= 0)
	{
		cout << "����ʽ�����޷���⡣" << endl;
		return;
	}
	else if (a == 0)
	{
		cout << "���x=0" << endl;
		return;

	}
	else
	{
		result = pow(a, 1 / b);
		if (b == (double)((int)b) && (int)b % 2 == 0)
		{
			cout << "���x= " << result << " �� " << -result << endl;
		}
		else
			cout << "���x=" << result << endl;
	}
}


void  Calc::Calcfun42() {

	double result;
	a = 0; b = 0; c = 0;

	cout << "�ֱ����� log a(x)=b �Ĳ���a��b(a>0)" << endl;
	cin >> a >> b;

	if (a < 0 || (a == 0 && b == 0))
	{
		cout << "����ʽ�����޷���⡣" << endl;
		return;
	}
	else if (a == 0 && b != 0)
	{
		cout << "���x=0" << endl;
		return;

	}
	else if (b == 0 && a != 0)
	{
		cout << "���x=1" << endl;
		return;
	}
	else
	{
		result = pow(a, b);
		cout << "���x=" << result << endl;
	}
}





void  Calc::Calcfun5() {

	double result;
	a = 0; b = 0; c = 0;

	cout << "�ֱ����� a/x+b=0 �Ĳ���a��b" << endl;
	cin >> a >> b;

	if (a == 0 || b == 0)
	{
		cout << "����ʽ�����޷���⡣" << endl;
		return;
	}
	result = -a / b;

	cout << "���x=" << result << endl;
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