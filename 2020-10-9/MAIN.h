#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Calc
{
public:
	
	void setA();
	void CIN();//����

	void checkroom();// �жϴ�С�������ַ���ת�ַ����飨�ڽ��к�������֮ǰ
	void checkstr0();	//����Ƿ��зǷ��ַ����ڼ��㺯����ת������֮ǰ

	void checkhex(); //�ж��Ƿ��зǷ��Ľ�������
	void calchex(); //��ʮ���������ַ���תΪʮ�������ַ���

	void checkoct(); //�ж��Ƿ��зǷ��Ľ�������
	void calcoct(); //���˽������ַ���תΪʮ�������ַ���

	void checkbit(); //�ж��Ƿ��зǷ��Ľ�������
	void calcbit(); //�����������ַ���תΪʮ�������ַ���

	void checkSC();//������Ǻ����ĺϷ��ԣ���������һ���Ϸ���
	void calcSC();//�������Ǻ������ü����������ԭ��ʽ�е����Ǻ���

	void calclog();//��������

	void calcpow();//�ݺ���

	void changenega();	//�����еĸ���-a��Ϊ(0-a) (�ڼ��㺯����ת������֮��

	void COUT();

	void checkstr(); // ����Ƿ��зǷ��ַ����ڼ������Ǻ������ݺ�������������֮��
					 //�˴��ķǷ��ַ�ָ���������㡢���֡���������������κ��ַ�
					 //ͬʱһ�������������Ƿ��ʵ���ʹ��

	string getINPUT(); // ��ü������޷Ƿ��ַ����������ʽ�����������������

	void m_init();//��ʼ��
	void setIN(string a);
	void getSuffix();//��ȡ��׺���ʽ
	double Calc_Suffix();//�����׺���ʽ

	void RADIX(double a);


	void Calcfun1();	//	һԪһ�κ���

	void Calcfun2();	//	һԪ���κ���

	void Calcfun31();	//	ָ������a^x

	void Calcfun32();	//	ָ������x^a

	void Calcfun41();	//	��������log x(a)

	void Calcfun42();	//	��������log a(x)

	void Calcfun5();	//	����������

	int checkS();

	int R = 0;//�ж�����Ľ���

	

private:

	char in[300];//������ַ�����char��������
	vector<char> in_2;//������ַ�����vector��������
	string INPUT;//������ַ���
	bool s = 0;	//�ַ����Ƿ�Ϸ����ж�����
	double a=0, b=0, c=0;//��������
	

	template <class T>
	void convertFromString(T& value, const string& s) {
		stringstream ss(s);
		ss >> value;
	}


	char IN[100];//����ı��ʽ
	stack<char> s1;//��׺���ʽת��Ϊ��׺���ʽʱ�õ���ջ
	vector<string> out;//��׺���ʽ
	stack<float> s2;//��׺���ʽ������ʱ�õ���ջ
	double result = 0;//������

};
