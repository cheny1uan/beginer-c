/* 2351892 ������ ��11*/
#include<iostream>
#include<cmath>

using namespace std;

void condition_1(double a, double b, double delta)//delta>0�����
{
	double x1, x2;
	cout << "����������ʵ����" << endl;
	x1 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < 1e-6)
		x1 = 0;
	x2 = (-b + sqrt(delta)) / (2 * a);
	if (fabs(x2) < 1e-6)
		x2 = 0;
	cout << "x1=" << (x1 >= x2 ? x1 : x2) << endl;
	cout << "x2=" << (x1 <= x2 ? x1 : x2) << endl;
}