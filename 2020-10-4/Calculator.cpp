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

		
		cout << "请选择要进行的操作：" << endl;
		cout << "1.计算算式；" << endl;
		cout << "2.选择输出进制；" << endl;
		cout << "3.方程求解；" << endl;
		cout << "4.比较大小；" << endl;

		cin >> S;
		cout << endl;

		switch (S)
		{
		case 1:
		{
			C.setA();
			C.CIN();//输入

			C.checkroom();// 判断大小，并将字符串转字符数组（在进行函数计算之前
			C.checkstr0();	//检查是否有非法字符（在计算函数和转换进制之前

			C.checkhex(); //判断是否有非法的进制运算
			C.calchex(); //将十六进制数字符串转为十进制数字符串

			C.checkoct(); //判断是否有非法的进制运算
			C.calcoct(); //将八进制数字符串转为十进制数字符串

			C.checkbit(); //判断是否有非法的进制运算
			C.calcbit(); //将二进制数字符串转为十进制数字符串

			C.calclog();//对数函数

			C.calcpow();//幂函数

			C.checkSC();//检查三角函数的合法性：其后必须有一个合法数
			C.calcSC();//计算三角函数，用计算后的数替代原算式中的三角函数

			C.changenega();	//将所有的负数-a改为(0-a) (在计算函数和转换进制之后

			C.checkstr(); // 检查是否有非法字符（在计算三角函数、幂函数、对数函数之后
							 //此处的非法字符指除四则运算、数字、括号以外的其他任何字符
							 //同时一并检查运算符号是否被适当地使用


			C.m_init();//初始化
			C.setIN(C.getINPUT());
			C.getSuffix();//获取后缀表达式
			C.Calc_Suffix();//计算后缀表达式

			cout << "算式计算结果 = " << C.Calc_Suffix() << endl;
			cout << endl;
			break;
		}
		case 2:
		{
			do {
				U = 1;
				cout << "请选择输出的计算结果进制：" << endl;
				cout << "1.二进制；" << endl;
				cout << "2.八进制；" << endl;
				cout << "3.十进制（默认）；" << endl;
				cout << "4.十六进制；" << endl;
				cout << "5.返回；" << endl;

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
					cout << "无效的选择。请重新输入。" << endl;
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
				cout << "请选择要进行的操作：" << endl;
				cout << "1.求解一元一次方程；" << endl;
				cout << "2.求解一元二次方程；" << endl;
				cout << "3.求解指数函数方程；" << endl;
				cout << "4.求解对数函数方程；" << endl;
				cout << "5.返回；" << endl;

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
						cout << "请选择要进行的操作：" << endl;
						cout << "1.求解形似 a^x=b 的指数函数方程；" << endl;
						cout << "2.求解形似 x^a=b 的指数函数方程；" << endl;
						cout << "3.返回；" << endl;

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
							cout << "无效的选择。请重新输入。" << endl;
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
						cout << "请选择要进行的操作：" << endl;
						cout << "1.求解形似 log x(a)=b 的指数函数方程；" << endl;
						cout << "2.求解形似 log a(x)=b 的指数函数方程；" << endl;
						cout << "3.返回；" << endl;

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
							cout << "无效的选择。请重新输入。" << endl;
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
					cout << "无效的选择。请重新输入。" << endl;
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
			cout << "请输入要比较的数A：" << endl;
			Ca.setA();
			Ca.CIN();//输入

			cout << "请输入要比较的数B：" << endl;

			Cb.setA();
			Cb.CIN();//输入



			Ca.checkroom();// 判断大小，并将字符串转字符数组（在进行函数计算之前
			Ca.checkstr0();	//检查是否有非法字符（在计算函数和转换进制之前

			Ca.checkhex(); //判断是否有非法的进制运算
			Ca.calchex(); //将十六进制数字符串转为十进制数字符串

			Ca.checkoct(); //判断是否有非法的进制运算
			Ca.calcoct(); //将八进制数字符串转为十进制数字符串

			Ca.checkbit(); //判断是否有非法的进制运算
			Ca.calcbit(); //将二进制数字符串转为十进制数字符串

			Ca.calclog();//对数函数

			Ca.calcpow();//幂函数

			Ca.checkSC();//检查三角函数的合法性：其后必须有一个合法数
			Ca.calcSC();//计算三角函数，用计算后的数替代原算式中的三角函数

			Ca.changenega();	//将所有的负数-a改为(0-a) (在计算函数和转换进制之后

			Ca.checkstr(); // 检查是否有非法字符（在计算三角函数、幂函数、对数函数之后
							 //此处的非法字符指除四则运算、数字、括号以外的其他任何字符
							 //同时一并检查运算符号是否被适当地使用

			Ca.m_init();//初始化
			Ca.setIN(C.getINPUT());
			Ca.getSuffix();//获取后缀表达式
			Ca.Calc_Suffix();//计算后缀表达式
			
			

			Cb.checkroom();// 判断大小，并将字符串转字符数组（在进行函数计算之前
			Cb.checkstr0();	//检查是否有非法字符（在计算函数和转换进制之前

			Cb.checkhex(); //判断是否有非法的进制运算
			Cb.calchex(); //将十六进制数字符串转为十进制数字符串

			Cb.checkoct(); //判断是否有非法的进制运算
			Cb.calcoct(); //将八进制数字符串转为十进制数字符串

			Cb.checkbit(); //判断是否有非法的进制运算
			Cb.calcbit(); //将二进制数字符串转为十进制数字符串

			Cb.calclog();//对数函数

			Cb.calcpow();//幂函数

			Cb.checkSC();//检查三角函数的合法性：其后必须有一个合法数
			Cb.calcSC();//计算三角函数，用计算后的数替代原算式中的三角函数

			Cb.changenega();	//将所有的负数-a改为(0-a) (在计算函数和转换进制之后

			Cb.checkstr(); // 检查是否有非法字符（在计算三角函数、幂函数、对数函数之后
							 //此处的非法字符指除四则运算、数字、括号以外的其他任何字符
							 //同时一并检查运算符号是否被适当地使用

			Cb.m_init();//初始化
			Cb.setIN(C.getINPUT());
			Cb.getSuffix();//获取后缀表达式
			Cb.Calc_Suffix();//计算后缀表达式

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
			cout << "无效的选择。请重新输入。" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			cout << endl;
			cout << endl;
			break;
		}
		}
	}
}


