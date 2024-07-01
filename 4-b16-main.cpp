/* 2351892 陈奕炫 信11*/
#include<iostream>
#include<cmath>
#include"4-b16.h"

using namespace std;


int main()
{
	double a, b, c, delta;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;

	if (a == 0) {
		is_it_quadratic();
	}
	else {
		delta = b * b - 4 * a * c;
		if (fabs(delta) < 1e-6)
			delta = 0;
		if (delta > 0) {
			condition_1(a, b, delta);
		}
		else if (delta == 0) {
			condition_2(a, b);
		}
		else {
			condition_3(a, b, delta);
		}
	}
	return 0;
}