/*2351892 ��11 ������*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a, b, c, d, e, f;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> a ;
	b = a/10000;
	c = a%10000/1000;
	d = a%1000/100;
	e = a%100/10;
	f = a%10;
	cout << "��λ : " << b << endl;
	cout << "ǧλ : " << c << endl;
	cout << "��λ : " << d << endl;
	cout << "ʮλ : " << e << endl;
	cout << "��λ : " << f << endl;
	return 0;
}