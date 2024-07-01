/* 2351892 陈奕炫 信11*/
#include<iostream>
#include<cmath>

using namespace std;

void condition_1(double a, double b, double delta)//delta>0的情况
{
	double x1, x2;
	cout << "有两个不等实根：" << endl;
	x1 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < 1e-6)
		x1 = 0;
	x2 = (-b + sqrt(delta)) / (2 * a);
	if (fabs(x2) < 1e-6)
		x2 = 0;
	cout << "x1=" << (x1 >= x2 ? x1 : x2) << endl;
	cout << "x2=" << (x1 <= x2 ? x1 : x2) << endl;
}