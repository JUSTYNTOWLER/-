#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "���Ǻ���.h"
#include "ȫ�ָ���.h"

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
					cout << "�������ʽ�����Ϲ淶��" << endl;
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
						cout << "�������ʽ�����Ϲ淶��" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 3)
						{
							cout << "�������ʽ�����Ϲ淶��" << endl;
							s = 0;
							return;	//sin��û����ֵ��ֱ����'+''('�ȷǷ��ַ�
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

		// ���sin�ĺϷ���



		for (int i = 0; i < INPUT.size() - 2; i++)
		{
			if (INPUT.substr(i, 3) == "cos")
			{
				d = 0;

				if (i == INPUT.size() - 3)
				{
					cout << "�������ʽ�����Ϲ淶��" << endl;
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
						cout << "�������ʽ�����Ϲ淶��" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 3)
						{
							cout << "�������ʽ�����Ϲ淶��" << endl;
							s = 0;
							return;	//cos��û����ֵ��ֱ����'+''('�ȷǷ��ַ�
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

		// ���cos�ĺϷ���

		


		for (int i = 0; i < INPUT.size() - 2; i++)
		{
			if (INPUT.substr(i, 3) == "tan")
			{
				d = 0;

				if (i == INPUT.size() - 3)
				{
					cout << "�������ʽ�����Ϲ淶��" << endl;
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
						cout << "�������ʽ�����Ϲ淶��" << endl;
						s = 0;
						return;
					}
					else
					{
						if (x == i + 3)
						{
							cout << "�������ʽ�����Ϲ淶��" << endl;
							s = 0;
							return;	//tan��û����ֵ��ֱ����'+''('�ȷǷ��ַ�
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

		// ���tan�ĺϷ���
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

		pos = INPUT.find(SIN);	//����sin

		int p = pos + 3;

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

			SC = INPUT.substr(p,q);
			convertFromString(v, SC);
			result = sin(v);
			sprintf(input, "%.20lf", result);

			INPUT.replace(pos, q+3, input);

			pos = INPUT.find(SIN);
		}



		pos = INPUT.find(COS);	//����cos

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
			result = cos(v);
			sprintf(input, "%.20lf", result);

			INPUT.replace(pos, q + 3, input);


			pos = INPUT.find(SIN);
		}



		pos = INPUT.find(TAN);	//����tan

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
				cout << "�������ʽ�����Ϲ淶��" << endl;
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