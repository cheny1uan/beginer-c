/* 2351892 ������ ��11*/
#include<iostream>
#include<cmath>

using namespace std;

void is_it_quadratic()//�ж��Ƿ�ΪһԪ���η���
{
	cout << "����һԪ���η���" << endl;
}

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

void condition_2(double a, double b)//delta==0�����
{
	double x;
	cout << "���������ʵ����" << endl;
	x = -b / (2 * a);
	if (fabs(x) < 1e-6)
		x = 0;
	cout << "x1=x2=" << x << endl;
}

void condition_3(double a, double b, double delta)
{
	cout << "�����������" << endl;
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
