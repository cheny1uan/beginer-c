/* 2351892 陈奕炫 信11*/
#include<iostream>
#include<cmath>

using namespace std;

void condition_2(double a, double b)//delta==0的情况
{
	double x;
	cout << "有两个相等实根：" << endl;
	x = -b / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "x1=x2=" << x << endl;
}