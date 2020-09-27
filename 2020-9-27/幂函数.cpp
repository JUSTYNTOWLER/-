#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include "幂函数.h"
#include "全局父类.h"

using namespace std;

void Calc_pow::calcpow() {

	if (s) {
		int p1,p2,p;
		int q1, q2;
		double v1 = 0, v2 = 0, result;
		string L1;
		char input[100];

		for (int i = 0; i < INPUT.size(); i++) {

			if (in[i] == '^')
			{
				if (i == 0 || i == INPUT.size() - 1)
				{
					cout << "输入的算式不符合规范！" << endl;
					s = 0;
					return;
				}

				for (int x = i-1;;x--) {

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
					else if (in[x] == '+' || in[x] == '-' || in[x - 1] == '*' || in[x - 1] == '/' || in[x - 1] == '(')
					{
						p = x + 2;
						p1 = x + 1;
						q1 = i - x - 1;
						break;
					}
					else {
						cout << "输入的算式不符合规范！" << endl;
						s = 0;
						return;
					}
				}

				for (int x = i + 1;; x++) {

					if ((in[x] <= '9' && in[x] >= '0') || in[x] == '.')
					{
						if (x == INPUT.size()-1)
						{
							p2 = i+1;
							q2 = x-i;
							break;
						}
						else
							continue;
					}
					else if (in[x] == '+' || in[x] == '-' || in[x - 1] == '*' || in[x - 1] == '/' || in[x - 1] == '(')
					{
						p2 = i + 1;
						q2 = x-i - 1;
						break;
					}
					else {
						cout << "输入的算式不符合规范！" << endl;
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

				result = pow(v1,v2);

				sprintf(input, "%.6lf", result);

				INPUT.replace(p1, q1 + q2 + 1, input);

				i = p;
			}
		}
	}
}