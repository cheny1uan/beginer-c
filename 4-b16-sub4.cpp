/* 2351892 陈奕炫 信11*/
#include<iostream>
#include<cmath>

using namespace std;

void condition_3(double a, double b, double delta)
{
	cout << "有两个虚根：" << endl;
	delta = -delta;
	if (fabs(-b / (2 * a)) < 1e-6) {
		b = 0;
	}
	if (fabs(fabs(sqrt(delta) / (2 * a)) - 1) < 1e-6) {
		if (b != 0) {
			cout << "x1=" << (-b / (2 * a)) << "+" << "i" << endl;
			cout << "x2=" << (-b / (2 * a)) << "-" << "i" << endl;
		}
		else {
			cout << "x1=" << "i" << endl;
			cout << "x2=-" << "i" << endl;
		}
	}
	else {
		if (b != 0) {
			cout << "x1=" << (-b / (2 * a)) << "+" << (fabs(sqrt(delta) / (2 * a))) << "i" << endl;
			cout << "x2=" << (-b / (2 * a)) << "-" << (fabs(sqrt(delta) / (2 * a))) << "i" << endl;
		}
		else {
			cout << "x1=" << (fabs(sqrt(delta) / (2 * a))) << "i" << endl;
			cout << "x2=-" << (fabs(sqrt(delta) / (2 * a))) << "i" << endl;
		}
	}
}