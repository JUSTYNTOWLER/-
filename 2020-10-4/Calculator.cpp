#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include "MAIN.h"

using namespace std;



void main() {

	Calc C, Ca, Cb;
	int S;
	bool U,K;

	for (;;)
	{

		
		cout << "��ѡ��Ҫ���еĲ�����" << endl;
		cout << "1.������ʽ��" << endl;
		cout << "2.ѡ��������ƣ�" << endl;
		cout << "3.������⣻" << endl;
		cout << "4.�Ƚϴ�С��" << endl;

		cin >> S;
		cout << endl;

		switch (S)
		{
		case 1:
		{
			C.setA();
			C.CIN();//����

			C.checkroom();// �жϴ�С�������ַ���ת�ַ����飨�ڽ��к�������֮ǰ
			C.checkstr0();	//����Ƿ��зǷ��ַ����ڼ��㺯����ת������֮ǰ

			C.checkhex(); //�ж��Ƿ��зǷ��Ľ�������
			C.calchex(); //��ʮ���������ַ���תΪʮ�������ַ���

			C.checkoct(); //�ж��Ƿ��зǷ��Ľ�������
			C.calcoct(); //���˽������ַ���תΪʮ�������ַ���

			C.checkbit(); //�ж��Ƿ��зǷ��Ľ�������
			C.calcbit(); //�����������ַ���תΪʮ�������ַ���

			C.calclog();//��������

			C.calcpow();//�ݺ���

			C.checkSC();//������Ǻ����ĺϷ��ԣ���������һ���Ϸ���
			C.calcSC();//�������Ǻ������ü����������ԭ��ʽ�е����Ǻ���

			C.changenega();	//�����еĸ���-a��Ϊ(0-a) (�ڼ��㺯����ת������֮��

			C.checkstr(); // ����Ƿ��зǷ��ַ����ڼ������Ǻ������ݺ�������������֮��
							 //�˴��ķǷ��ַ�ָ���������㡢���֡���������������κ��ַ�
							 //ͬʱһ�������������Ƿ��ʵ���ʹ��


			C.m_init();//��ʼ��
			C.setIN(C.getINPUT());
			C.getSuffix();//��ȡ��׺���ʽ
			C.Calc_Suffix();//�����׺���ʽ

			cout << "��ʽ������ = " << C.Calc_Suffix() << endl;
			cout << endl;
			break;
		}
		case 2:
		{
			do {
				U = 1;
				cout << "��ѡ������ļ��������ƣ�" << endl;
				cout << "1.�����ƣ�" << endl;
				cout << "2.�˽��ƣ�" << endl;
				cout << "3.ʮ���ƣ�Ĭ�ϣ���" << endl;
				cout << "4.ʮ�����ƣ�" << endl;
				cout << "5.���أ�" << endl;

				cin >> S;
				cout << endl;

				switch (S)
				{
				case 1:
				{
					C.R = 2;
					break;
				}
				case 2:
				{
					C.R = 8;
					break;
				}
				case 3:
				{
					C.R = 10;
					break;
				}
				case 4:
				{
					C.R = 16;
					break;
				}
				case 5:
				{
					break;
				}
				default:
				{
					cout << "��Ч��ѡ�����������롣" << endl;
					cin.clear();
					cin.ignore(1024, '\n');
					U = 0;
					cout << endl;
					cout << endl;
					break;
				}
				}
			} while (U==0);

			break;
		}
		case 3:
		{
			do {
				U = 1;
				cout << "��ѡ��Ҫ���еĲ�����" << endl;
				cout << "1.���һԪһ�η��̣�" << endl;
				cout << "2.���һԪ���η��̣�" << endl;
				cout << "3.���ָ���������̣�" << endl;
				cout << "4.�������������̣�" << endl;
				cout << "5.���أ�" << endl;

				cin >> S;
				cout << endl;

				switch (S)
				{
				case 1:
				{
					C.Calcfun1();
					break;
				}
				case 2:
				{
					C.Calcfun2();
					break;
				}
				case 3:
				{
					do {
						K = 1;
						cout << "��ѡ��Ҫ���еĲ�����" << endl;
						cout << "1.������� a^x=b ��ָ���������̣�" << endl;
						cout << "2.������� x^a=b ��ָ���������̣�" << endl;
						cout << "3.���أ�" << endl;

						cin >> S;
						cout << endl;

						switch (S)
						{
						case 1:
						{
							C.Calcfun31();
							break;
						}
						case 2:
						{
							C.Calcfun32();
							break;
						}
						case 3:
						{
							U = 0;
							break;
						}
						default:
						{
							cout << "��Ч��ѡ�����������롣" << endl;
							cin.clear();
							cin.ignore(1024, '\n');
							K = 0;
							cout << endl;
							cout << endl;
							break;
						}
						}
					} while (K == 0);

					break;

				}
				case 4:
				{
					do {
						K = 1;
						cout << "��ѡ��Ҫ���еĲ�����" << endl;
						cout << "1.������� log x(a)=b ��ָ���������̣�" << endl;
						cout << "2.������� log a(x)=b ��ָ���������̣�" << endl;
						cout << "3.���أ�" << endl;

						cin >> S;
						cout << endl;

						switch (S)
						{
						case 1:
						{
							C.Calcfun41();
							break;
						}
						case 2:
						{
							C.Calcfun42();
							break;
						}
						case 3:
						{
							U = 0;
							break;
						}
						default:
						{
							cout << "��Ч��ѡ�����������롣" << endl;
							cin.clear();
							cin.ignore(1024, '\n');
							K = 0;
							cout << endl;
							cout << endl;
							break;
						}
						}
					} while (K == 0);

					break;
				}
				case 5:
				{
					break;
				}
				default:
				{
					cout << "��Ч��ѡ�����������롣" << endl;
					cin.clear();
					cin.ignore(1024, '\n');
					cout << endl;
					cout << endl;
					break;
				}
				}
			}while (U == 0);
			break;
		}
		case 4:
		{
			cout << "������Ҫ�Ƚϵ���A��" << endl;
			Ca.setA();
			Ca.CIN();//����

			cout << "������Ҫ�Ƚϵ���B��" << endl;

			Cb.setA();
			Cb.CIN();//����



			Ca.checkroom();// �жϴ�С�������ַ���ת�ַ����飨�ڽ��к�������֮ǰ
			Ca.checkstr0();	//����Ƿ��зǷ��ַ����ڼ��㺯����ת������֮ǰ

			Ca.checkhex(); //�ж��Ƿ��зǷ��Ľ�������
			Ca.calchex(); //��ʮ���������ַ���תΪʮ�������ַ���

			Ca.checkoct(); //�ж��Ƿ��зǷ��Ľ�������
			Ca.calcoct(); //���˽������ַ���תΪʮ�������ַ���

			Ca.checkbit(); //�ж��Ƿ��зǷ��Ľ�������
			Ca.calcbit(); //�����������ַ���תΪʮ�������ַ���

			Ca.calclog();//��������

			Ca.calcpow();//�ݺ���

			Ca.checkSC();//������Ǻ����ĺϷ��ԣ���������һ���Ϸ���
			Ca.calcSC();//�������Ǻ������ü����������ԭ��ʽ�е����Ǻ���

			Ca.changenega();	//�����еĸ���-a��Ϊ(0-a) (�ڼ��㺯����ת������֮��

			Ca.checkstr(); // ����Ƿ��зǷ��ַ����ڼ������Ǻ������ݺ�������������֮��
							 //�˴��ķǷ��ַ�ָ���������㡢���֡���������������κ��ַ�
							 //ͬʱһ�������������Ƿ��ʵ���ʹ��

			Ca.m_init();//��ʼ��
			Ca.setIN(C.getINPUT());
			Ca.getSuffix();//��ȡ��׺���ʽ
			Ca.Calc_Suffix();//�����׺���ʽ
			
			

			Cb.checkroom();// �жϴ�С�������ַ���ת�ַ����飨�ڽ��к�������֮ǰ
			Cb.checkstr0();	//����Ƿ��зǷ��ַ����ڼ��㺯����ת������֮ǰ

			Cb.checkhex(); //�ж��Ƿ��зǷ��Ľ�������
			Cb.calchex(); //��ʮ���������ַ���תΪʮ�������ַ���

			Cb.checkoct(); //�ж��Ƿ��зǷ��Ľ�������
			Cb.calcoct(); //���˽������ַ���תΪʮ�������ַ���

			Cb.checkbit(); //�ж��Ƿ��зǷ��Ľ�������
			Cb.calcbit(); //�����������ַ���תΪʮ�������ַ���

			Cb.calclog();//��������

			Cb.calcpow();//�ݺ���

			Cb.checkSC();//������Ǻ����ĺϷ��ԣ���������һ���Ϸ���
			Cb.calcSC();//�������Ǻ������ü����������ԭ��ʽ�е����Ǻ���

			Cb.changenega();	//�����еĸ���-a��Ϊ(0-a) (�ڼ��㺯����ת������֮��

			Cb.checkstr(); // ����Ƿ��зǷ��ַ����ڼ������Ǻ������ݺ�������������֮��
							 //�˴��ķǷ��ַ�ָ���������㡢���֡���������������κ��ַ�
							 //ͬʱһ�������������Ƿ��ʵ���ʹ��

			Cb.m_init();//��ʼ��
			Cb.setIN(C.getINPUT());
			Cb.getSuffix();//��ȡ��׺���ʽ
			Cb.Calc_Suffix();//�����׺���ʽ

			if (Ca.checkS() != 0 && Cb.checkS() != 0)
			{

				if (Ca.Calc_Suffix() > Cb.Calc_Suffix())
				{
					cout << "A > B;" << endl;
					cout << endl;
				}
				else if (Ca.Calc_Suffix() < Cb.Calc_Suffix())
				{
					cout << "A < B;" << endl;
					cout << endl;
				}
				else if (Ca.Calc_Suffix() == Cb.Calc_Suffix())
				{
					cout << "A = B;" << endl;
					cout << endl;
				}
			}
			
			break;

		}
		default:
		{
			cout << "��Ч��ѡ�����������롣" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
			cout << endl;
			break;
		}
		}
	}
}


