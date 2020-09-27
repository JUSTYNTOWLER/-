#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "函数求解.h"
#include "全局父类.h"

using namespace std;


void  Calc_func::Calcfun1() {

	double result;

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


void  Calc_func::Calcfun2() {

	double result,result2;
	double T1, T2, T3 ;

	cout << "分别输入 ax^2+bx+c=0 的参数a、b、c" << endl;
	cin >> a >> b >> c;

	if (a == 0 && b==0)
	{
		cout << "函数式错误，无法求解。" << endl;
		return;
	}
	else if (a == 0 && b != 0)
	{
		result = -c / b;
		cout << "解得x=" << result << endl;	//	只有a为0时，为一元一次方程
	}
	else {
		T1 = b * b - 4*a*c;

		if (T1 == 0) {
			result = -b / 2*a;
			cout << "解得x=" << result << endl;
		}
		else if(T1 < 0) {
			cout << "函数式错误，无法求解。" << endl;
			return;
		}
		else 
		{
			T2 = -b + pow(T1, 0.5);
			T3 = -b - pow(T1, 0.5);
			result = T2 / 2 * a;
			result2 = T3 / 2 * a;

			cout << "解得x=" << result <<" 或x="<< result2 << endl;
		}
	}
}


void  Calc_func::Calcfun31() {

	double result;

	cout << "分别输入 a^x=b 的参数a、b(a>0，b>0)" << endl;
	cin >> a >> b;

	if (a == 0 || b == 0 || a<=0 || b<=0 || a==1)
	{
		cout << "函数式错误，无法求解。" << endl;
		return;
	}
	else
	{
		result = log(b)/log(a);
		cout << "解得x=" << result << endl;
	}	
}


void  Calc_func::Calcfun32() {

	double result;

	cout << "分别输入 x^a=b 的参数a、b(b>=0)" << endl;
	cin >> a >> b;

	if (a == 0 || b<0)
	{
		cout << "函数式错误，无法求解。" << endl;
		return;
	}
	else if (b==0)
	{
		cout << "解得x=0"  << endl;
	}
	else
	{
		result = pow(b,1/a);

		if (a == (double)((int)a) && (int)a % 2 == 0)
		{
			cout << "解得x= " << result <<" 或 "<< -result << endl;

		}else
		cout << "解得x=" << result << endl;	
	}
}

void  Calc_func::Calcfun41() {

	double result;

	cout << "分别输入 log x(a)=b 的参数a、b(a>0)" << endl;
	cin >> a >> b;

	if (b == 0 || a <= 0 )
	{
		cout << "函数式错误，无法求解。" << endl;
		return;
	}
	else if(a==0)
	{
		cout << "解得x=0" << endl;
		return;

	}else
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


void  Calc_func::Calcfun42() {

	double result;

	cout << "分别输入 log a(x)=b 的参数a、b(a>0)" << endl;
	cin >> a >> b;

	if (a < 0 || (a==0 && b==0))
	{
		cout << "函数式错误，无法求解。" << endl;
		return;
	}
	else if (a == 0 && b!=0)
	{
		cout << "解得x=0" << endl;
		return;

	}
	else if (b==0 && a!=0)
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





void  Calc_func::Calcfun5() {

	double result;

	cout << "分别输入 a/x+b=0 的参数a、b" << endl;
	cin >> a >> b;

	if (a == 0 || b==0 )
	{
		cout << "方程式错误，无法求解。" << endl;
		return;
	}
	result = -a / b;

	cout << "解得x=" << result << endl;
}