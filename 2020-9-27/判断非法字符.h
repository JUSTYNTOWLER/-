#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include "ȫ�ָ���.h"


using namespace std;

class Calc_2:public Calc_G
{
public:
	Calc_2(string a);	// �жϴ�С�������ַ���ת�ַ����飨�ڽ��к�������֮ǰ

	void checkstr0();	//����Ƿ��зǷ��ַ����ڼ��㺯����ת������֮ǰ





	void changenega();	//�����еĸ���-a��Ϊ(0-a) (�ڼ��㺯����ת������֮��

	void checkstr(); // ����Ƿ��зǷ��ַ����ڼ������Ǻ������ݺ�������������֮��
					 //�˴��ķǷ��ַ�ָ���������㡢���֡���������������κ��ַ�
					 //ͬʱһ�������������Ƿ��ʵ���ʹ��

	string getINPUT(); // ��ü������޷Ƿ��ַ����������ʽ�����������������

	~Calc_2();

private:

};


