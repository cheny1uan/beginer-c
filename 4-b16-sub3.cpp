/* 2351892 ������ ��11*/
#include<iostream>
#include<cmath>

using namespace std;

void condition_2(double a, double b)//delta==0�����
{
	double x;
	cout << "���������ʵ����" << endl;
	x = -b / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "x1=x2=" << x << endl;
}