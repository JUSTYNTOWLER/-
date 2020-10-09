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
	cout << "919113590116 傅沐晖；个人项目选题：计算器；" << endl;
	cout << "※1：可自动识别输入的进制，格式为：二进制数前加B，八进制数前加O，十六进制前加H (例：B101+H5f)；" << endl;
	cout << "※2：支持三角函数，对数函数和指数函数，函数可直接包含在算式中（例：sin10+log2(4)*3^5）；" << endl;
	cout << "※3：比较大小和公约数、公倍数计算的功能中支持输入算式，因此也可以比较两个算式的结果大小；" << endl;
	cout << "※4：所有输入错误/无解的情况下，会给出错误提示并且结果自动置零；" << endl;
	cout << "※5：为方便查看和用户输入，所有进制数均不需要考虑符号位，负数使用负号表示即可；" << endl;
	cout << "*******************************************************" << endl;



	for (;;)
	{

		
		cout << "请选择要进行的操作：" << endl;
		cout << "1.计算算式；" << endl;
		cout << "2.选择输出进制；" << endl;
		cout << "3.方程求解；" << endl;
		cout << "4.比较大小；" << endl;
		cout << "5.公约数、公倍数计算；" << endl;

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

			C.COUT();


			C.m_init();//初始化
			C.setIN(C.getINPUT());
			C.getSuffix();//获取后缀表达式
			C.Calc_Suffix();//计算后缀表达式

			cout << "计算结果 = ";

			C.RADIX(C.Calc_Suffix());

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
			double A2, B2;
			bool S1, S2;

			cout << "请输入要比较的数A：" << endl;
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

			C.COUT();


			C.m_init();//初始化
			C.setIN(C.getINPUT());
			C.getSuffix();//获取后缀表达式
			C.Calc_Suffix();//计算后缀表达式

			A2 = C.Calc_Suffix();
			S1 = C.checkS();

			cout << "请输入要比较的数B：" << endl;

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

			C.COUT();


			C.m_init();//初始化
			C.setIN(C.getINPUT());
			C.getSuffix();//获取后缀表达式
			C.Calc_Suffix();//计算后缀表达式

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

			cout << "请输入要比较的正整数A：" << endl;
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

			A1= C.Calc_Suffix();
			AA = (int)C.Calc_Suffix();


			cout << "请输入要比较的正整数B：" << endl;

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

			B1 = C.Calc_Suffix();
			BB = (int)C.Calc_Suffix();



			if (BB != B1 || AA != A1 || AA<= 0 || BB <= 0)
			{
				cout << "输入的数或算式的结果不是正整数！" << endl;
				break;
			}

			int C1 = AA < BB ? AA : BB;	//取较小者为C
			for (int m = C1; m > 0; m--) {	//从A到1逐减，寻找最大公约数
				if (AA % m == 0 && BB % m == 0) {

					C1 = m;
					break;
				}
			}


			cout << "这两数的最大公约数是：";
			C.RADIX(C1);

			int D1 = AA > BB ? AA : BB;	//取较大者为C
			for (int m = D1;; m++) {	//逐增，寻找最小公倍数
				if (m % AA == 0 && m % BB == 0) {

					D1 = m;
					break;
				}
			}

			cout << "这两数的最小公倍数是：";
			C.RADIX(D1);

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


