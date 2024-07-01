/* 2351892 陈奕炫 信11*/
#include<iostream>
#include<cmath>

using namespace std;

double a, b, c, delta;

void is_it_quadratic();//判断是否为一元二次方程
void condition_1();//delta>0的情况
void condition_2();//delta==0的情况
void condition_3();

int main()
{
	
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
			condition_1();
		}
		else if (delta == 0) {
			condition_2();
		}
		else {
			condition_3();
		}
	}
	return 0;
}