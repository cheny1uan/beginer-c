/* 2351892 陈奕炫 信11*/
#include<iostream>
#include<cmath>

using namespace std;

void is_it_quadratic()//判断是否为一元二次方程
{	
		cout << "不是一元二次方程" << endl;	
}

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

void condition_2(double a, double b)//delta==0的情况
{
	double x;
	cout << "有两个相等实根：" << endl;
	x= -b / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "x1=x2=" << x << endl;
}

void condition_3(double a, double b, double delta)
{
	cout << "有两个虚根：" << endl;
	delta = -delta;
	if (fabs(-b / (2 * a)) < 1e-6) {
		b = 0;
	}
	if (fabs(fabs(sqrt(delta) / (2 * a))-1) < 1e-6) {                              
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



int main()
{	
	double a, b, c,delta;
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	cin>> a >> b >> c;
	if (fabs(a) < 1e-6)
		a = 0;
	if (fabs(b) < 1e-6)
		b = 0;
	if (fabs(c) < 1e-6)
		c = 0;
	
	if (a== 0) {
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