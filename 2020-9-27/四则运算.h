#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include "ȫ�ָ���.h"

using namespace std;

class Calc_1
{
public:
	Calc_1(string a);

	void getSuffix();//��ȡ��׺���ʽ
	float Calc_Suffix();//�����׺���ʽ
	void m_init();//��ʼ��
	~Calc_1();

private:
	char in[100];//����ı��ʽ
	stack<char> s1;//��׺���ʽת��Ϊ��׺���ʽʱ�õ���ջ
	vector<string> out;//��׺���ʽ
	stack<float> s2;//��׺���ʽ������ʱ�õ���ջ
	float result=0;//������

};