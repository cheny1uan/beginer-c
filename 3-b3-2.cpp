/*2351892 ��11 ������*/
#include <iostream>
#include<iomanip>
	using namespace std;
int main()

{
	double a;
	int b, c, d, e, f, g, h, i, j, k, m, n, p;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	b = int(a / 10);
	a=(a-double(b)*10)*100;
	c = b / 100000000;
	d = b % 100000000 / 10000000;
	e = b % 10000000 / 1000000;
	f = b % 1000000 / 100000;
	g = b % 100000 / 10000;
	h = b % 10000 / 1000;
	i = b % 1000 / 100;
	j = b % 100 / 10;
	k = b % 10;
	m =int(a/100);
	n = int(a + 0.0001) % 100 / 10;
	p=int(a+0.0001)%10;
	cout << "ʮ��λ : " << c << endl;
	cout << "��λ   : " << d << endl;
	cout << "ǧ��λ : " << e << endl;
	cout << "����λ : " << f << endl;
	cout << "ʮ��λ : " << g << endl;
	cout << "��λ   : " << h << endl;
	cout << "ǧλ   : " << i << endl;
	cout << "��λ   : " << j << endl;
	cout << "ʮλ   : " << k <<endl;
	cout << "Բ     : " << m << endl;
	cout << "��     : " << n << endl;
	cout << "��     : " << p << endl;
	return 0;
}
