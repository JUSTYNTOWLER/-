#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


class Calc_G
{
public:
	char in[300];
	vector<char> in_2;
	string INPUT;
	bool s = 0, t = 0;
	double a, b, c;

	template <class T>
	void convertFromString(T& value, const string& s) {
		stringstream ss(s);
		ss >> value;
	}

private:


};

