#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "�������.h"
#include "ȫ�ָ���.h"

using namespace std;


void  Calc_func::Calcfun1() {

	double result;

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


void  Calc_func::Calcfun2() {

	double result,result2;
	double T1, T2, T3 ;

	cout << "�ֱ����� ax^2+bx+c=0 �Ĳ���a��b��c" << endl;
	cin >> a >> b >> c;

	if (a == 0 && b==0)
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
		T1 = b * b - 4*a*c;

		if (T1 == 0) {
			result = -b / 2*a;
			cout << "���x=" << result << endl;
		}
		else if(T1 < 0) {
			cout << "����ʽ�����޷���⡣" << endl;
			return;
		}
		else 
		{
			T2 = -b + pow(T1, 0.5);
			T3 = -b - pow(T1, 0.5);
			result = T2 / 2 * a;
			result2 = T3 / 2 * a;

			cout << "���x=" << result <<" ��x="<< result2 << endl;
		}
	}
}


void  Calc_func::Calcfun31() {

	double result;

	cout << "�ֱ����� a^x=b �Ĳ���a��b(a>0��b>0)" << endl;
	cin >> a >> b;

	if (a == 0 || b == 0 || a<=0 || b<=0 || a==1)
	{
		cout << "����ʽ�����޷���⡣" << endl;
		return;
	}
	else
	{
		result = log(b)/log(a);
		cout << "���x=" << result << endl;
	}	
}


void  Calc_func::Calcfun32() {

	double result;

	cout << "�ֱ����� x^a=b �Ĳ���a��b(b>=0)" << endl;
	cin >> a >> b;

	if (a == 0 || b<0)
	{
		cout << "����ʽ�����޷���⡣" << endl;
		return;
	}
	else if (b==0)
	{
		cout << "���x=0"  << endl;
	}
	else
	{
		result = pow(b,1/a);

		if (a == (double)((int)a) && (int)a % 2 == 0)
		{
			cout << "���x= " << result <<" �� "<< -result << endl;

		}else
		cout << "���x=" << result << endl;	
	}
}

void  Calc_func::Calcfun41() {

	double result;

	cout << "�ֱ����� log x(a)=b �Ĳ���a��b(a>0)" << endl;
	cin >> a >> b;

	if (b == 0 || a <= 0 )
	{
		cout << "����ʽ�����޷���⡣" << endl;
		return;
	}
	else if(a==0)
	{
		cout << "���x=0" << endl;
		return;

	}else
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


void  Calc_func::Calcfun42() {

	double result;

	cout << "�ֱ����� log a(x)=b �Ĳ���a��b(a>0)" << endl;
	cin >> a >> b;

	if (a < 0 || (a==0 && b==0))
	{
		cout << "����ʽ�����޷���⡣" << endl;
		return;
	}
	else if (a == 0 && b!=0)
	{
		cout << "���x=0" << endl;
		return;

	}
	else if (b==0 && a!=0)
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





void  Calc_func::Calcfun5() {

	double result;

	cout << "�ֱ����� a/x+b=0 �Ĳ���a��b" << endl;
	cin >> a >> b;

	if (a == 0 || b==0 )
	{
		cout << "����ʽ�����޷���⡣" << endl;
		return;
	}
	result = -a / b;

	cout << "���x=" << result << endl;
}