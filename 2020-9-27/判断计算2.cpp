#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "�жϼ���2.h"
#include "ȫ�ָ���.h"

using namespace std;


Calc_BIT::Calc_BIT() {};


void Calc_BIT::checkbit()
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
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return;
				}

				for (int x = i + 1; x < INPUT.size(); x++)
				{
					if (in[x] == '0' || in[x] == '1') //����0��1
					{
						continue;
					}
					else if ((in[x] <= 'z' && in[x] >= 'a') || (in[x] >= 'A' && in[x] <= 'Z')|| ((int)in[x] <= 57 && (int)in[x] >= 51))
					{
						cout << "�������ʽ�����Ϲ淶��" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 1)
						{
							cout << "�������ʽ�����Ϲ淶��" << endl;
							s = 0;
							return;
						}
						else if (in[x] == '.')
						{
							d++;
							if (x == INPUT.size() - 1)
							{
								cout << "�������ʽ�����Ϲ淶��" << endl;
								s = 0;
								return;	//С���㲻��Ϊ���һλ
							}
							else if (d == 1)
							{
								continue;
							}
							else
							{
								cout << "�������ʽ�����Ϲ淶��" << endl;
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



void Calc_BIT::calcbit() {

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