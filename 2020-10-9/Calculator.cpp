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

	cout << "*******************************************************" << endl;
	cout << "919113590116 �����ͣ�������Ŀѡ�⣺��������" << endl;
	cout << "��1�����Զ�ʶ������Ľ��ƣ���ʽΪ����������ǰ��B���˽�����ǰ��O��ʮ������ǰ��H (����B101+H5f)��" << endl;
	cout << "��2��֧�����Ǻ���������������ָ��������������ֱ�Ӱ�������ʽ�У�����sin10+log2(4)*3^5����" << endl;
	cout << "��3���Ƚϴ�С�͹�Լ��������������Ĺ�����֧��������ʽ�����Ҳ���ԱȽ�������ʽ�Ľ����С��" << endl;
	cout << "��4�������������/�޽������£������������ʾ���ҽ���Զ����㣻" << endl;
	cout << "��5��Ϊ����鿴���û����룬���н�����������Ҫ���Ƿ���λ������ʹ�ø��ű�ʾ���ɣ�" << endl;
	cout << "*******************************************************" << endl;



	for (;;)
	{

		
		cout << "��ѡ��Ҫ���еĲ�����" << endl;
		cout << "1.������ʽ��" << endl;
		cout << "2.ѡ��������ƣ�" << endl;
		cout << "3.������⣻" << endl;
		cout << "4.�Ƚϴ�С��" << endl;
		cout << "5.��Լ�������������㣻" << endl;

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

			C.COUT();


			C.m_init();//��ʼ��
			C.setIN(C.getINPUT());
			C.getSuffix();//��ȡ��׺���ʽ
			C.Calc_Suffix();//�����׺���ʽ

			cout << "������ = ";

			C.RADIX(C.Calc_Suffix());

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
			double A2, B2;
			bool S1, S2;

			cout << "������Ҫ�Ƚϵ���A��" << endl;
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

			C.COUT();


			C.m_init();//��ʼ��
			C.setIN(C.getINPUT());
			C.getSuffix();//��ȡ��׺���ʽ
			C.Calc_Suffix();//�����׺���ʽ

			A2 = C.Calc_Suffix();
			S1 = C.checkS();

			cout << "������Ҫ�Ƚϵ���B��" << endl;

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

			C.COUT();


			C.m_init();//��ʼ��
			C.setIN(C.getINPUT());
			C.getSuffix();//��ȡ��׺���ʽ
			C.Calc_Suffix();//�����׺���ʽ

			B2 = C.Calc_Suffix();
			S2 = C.checkS();

			

			if (S1 != 0 && S2 != 0)
			{

				if (A2 > B2)
				{
					cout << "A > B;" << endl;
					cout << endl;
				}
				else if (A2 < B2)
				{
					cout << "A < B;" << endl;
					cout << endl;
				}
				else if (A2 == B2)
				{
					cout << "A = B;" << endl;
					cout << endl;
				}
			}
			
			break;

		}
		case 5:
		{
			double A1, B1;
			int AA, BB;

			cout << "������Ҫ�Ƚϵ�������A��" << endl;
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

			A1= C.Calc_Suffix();
			AA = (int)C.Calc_Suffix();


			cout << "������Ҫ�Ƚϵ�������B��" << endl;

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

			B1 = C.Calc_Suffix();
			BB = (int)C.Calc_Suffix();



			if (BB != B1 || AA != A1 || AA<= 0 || BB <= 0)
			{
				cout << "�����������ʽ�Ľ��������������" << endl;
				break;
			}

			int C1 = AA < BB ? AA : BB;	//ȡ��С��ΪC
			for (int m = C1; m > 0; m--) {	//��A��1�����Ѱ�����Լ��
				if (AA % m == 0 && BB % m == 0) {

					C1 = m;
					break;
				}
			}


			cout << "�����������Լ���ǣ�";
			C.RADIX(C1);

			int D1 = AA > BB ? AA : BB;	//ȡ�ϴ���ΪC
			for (int m = D1;; m++) {	//������Ѱ����С������
				if (m % AA == 0 && m % BB == 0) {

					D1 = m;
					break;
				}
			}

			cout << "����������С�������ǣ�";
			C.RADIX(D1);

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


