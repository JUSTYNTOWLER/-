#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "�жϷǷ��ַ�.h"
#include "ȫ�ָ���.h"

using namespace std;


Calc_2::Calc_2(string a) {

	in[0] = '\0';
	in_2[0] = '\0';

	if (a.size() > 99) {
		cout << "��ʽ������" << endl;
		s = 0;
	}
	else if (a.size() < 1) {
		cout << "��ʽ���̣�" << endl;
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
				cout << "�������ʽ�����Ϲ淶��" << endl;
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
		}	//��string INPUTת��Ϊvector<char>


		int i = 0;

		if (in_2[0] == '-')
		{
			in_2.insert(in_2.begin(), '0');
			in_2.insert(in_2.begin(), '(');

			int p;
			for (int x = 3;; x++)
			{
				if ((int)in_2[x] != 46 && (int)in_2[x] < 48 && (int)in_2[x] > 57)  //Ѱ�������дӸ��������һ������С��������ֵ�Ԫ��,����'��'
				{
					p = x;
					in_2.insert(in_2.begin() + p, ')');
					break;
				}
				else if (((int)in_2[x] == 46 || ((int)in_2[x] >= 48 && (int)in_2[x] <= 57)) && in_2[x] == in_2.back())//����ֱ����������һ��Ԫ��Ϊֹ�������ֻ�С����,������β���һ��Ԫ��')'
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

		int front=0, back=0;	//	ǰ�����Ÿ���

		for (int i = 0; i < INPUT.size(); i++)
		{
			if((int)in[i]<=57 && (int)in[i] >= 48) //����1��9
			{
				continue;
			}
			else if (in[i] == '+')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return;	// '+'��������Ϊ��һ���ַ������һ���ַ�
				}
				else if (((int)in[i + 1] - (int)in[i] > 14 || (int)in[i + 1] - (int)in[i] <= 5) && ((int)in[i + 1] - (int)in[i] != -3)) 
				{ 
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return ;	//'+'�ź��治�����г����ֺ�'('����������ַ�
				}
				else
					continue;
			}
			else if (in[i] == '-')
			{
				if (i == 0 ||i == INPUT.size() - 1)
				{
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return;	// '-'��������Ϊ��һ�������һ���ַ�
				}
				else if (((int)in[i + 1] - (int)in[i] > 13 || (int)in[i + 1] - (int)in[i] <= 3) && ((int)in[i + 1] - (int)in[i] != -5))
				{
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return ;	//'-'�ź��治�����г����ֺ�'('����������ַ�
				}
				else
					continue;
			}
			else if (in[i] == '*')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return;	// '*'��������Ϊ��һ���ַ������һ���ַ�
				}
				else if (((int)in[i + 1] - (int)in[i] > 15 || (int)in[i + 1] - (int)in[i] <= 6) && (int)in[i + 1] - (int)in[i] != -2)
				{
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return ;	//'*'�ź��治�����г����������'('����������ַ�
				}
				else
					continue;
			}
			else if (in[i] == '/')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return;	// '/'��������Ϊ��һ���ַ������һ���ַ�
				}
				else if (((int)in[i + 1] - (int)in[i] > 10 || (int)in[i + 1] - (int)in[i] <= 0) && (int)in[i + 1] - (int)in[i] != -7)
				{
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return ;	//'/'�ź��治�����г����������'('����������ַ�
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
						cout << "�������ʽ�����Ϲ淶��" << endl;
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
					if ((int)in[i + 1] - (int)in[i] > 17 || (int)in[i + 1] - (int)in[i] <= 8)
					{
						cout << "�������ʽ�����Ϲ淶��" << endl;
						s = 0;
						return;	//'('�ź��治�����г���������������ַ�
					}
					else
						continue;
				}
				else if (i == INPUT.size() - 1)
				{
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return;	//'('�����������һ���ַ�
				}
				else  
				{
					if (in[i - 1] > '0' && in[i - 1] < '9') 
					{
						cout << "�������ʽ�����Ϲ淶��" << endl;
						s = 0;
						return;	//'('��ǰ�治����������
					}
					else if ((int)in[i + 1] - (int)in[i] > 17 || (int)in[i + 1] - (int)in[i] <= 8)
					{
						cout << "�������ʽ�����Ϲ淶��" << endl;
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
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return;	// ')'�Ų�������Ϊ��һ���ַ�
				}
				else if (i == INPUT.size() - 1)
				{
					if (in[i - 1]<'0' || in[i - 1]>'9')
					{
						cout << "�������ʽ�����Ϲ淶��"  << endl;
						s = 0;
						return ;	// ')'��ǰ�治�����г���������������ַ�
					}
					else
						continue;
					
				}
				else if(in[i - 1]<'0' || in[i - 1]>'9' || (in[i + 1] >= '0' && in[i + 1] <= '9'))
				{
						cout << "�������ʽ�����Ϲ淶��" << endl;
						s = 0;
						return;	// ')'��ǰ�治�����г���������������ַ�,���治����������
				}
				else if(front<back)
				{
					cout << "�������ʽ�����Ϲ淶��" << endl;
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
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return;	// С���㲻������Ϊ��һ���ַ������һ���ַ�
				}
				else if (in[i + 1]<'0' || in[i + 1]>'9')
				{
					cout << "�������ʽ�����Ϲ淶��" << endl;
					s = 0;
					return;	//С������治��������������������ַ�
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
							cout << "�������ʽ�����Ϲ淶��" << endl;
							s = 0;
							return;	//һ�������в������ж��С����
						}
					}
					continue;
				}
					

			}
			else 
			{
				cout << "�������ʽ�����Ϲ淶��" << endl;
				s = 0;
				return;	//�����������������������ķǷ��ַ�
			}
		}
		if (front != back)
		{
			cout << "�������ʽ�����Ϲ淶��" << endl;
			s = 0;
			return;	//ǰ�����Ÿ�������
		}
	}
	else  return ; 

}

string Calc_2::getINPUT() {
	if (s) {
		return INPUT;
	}
	else return "�������ʽ�����Ϲ淶��";
}

Calc_2::~Calc_2() {};




