/* 2351892 ������ ��11*/
#include<iostream>
#include<cmath>

using namespace std;
void is_it_quadratic();//�ж��Ƿ�ΪһԪ���η���
void condition_1(double a, double b, double delta);//delta>0�����
void condition_2(double a, double b);//delta==0�����
void condition_3(double a, double b, double delta);

int main()
{
	double a, b, c, delta;
	cout << "������һԪ���η��̵�����ϵ��a,b,c:" << endl;
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