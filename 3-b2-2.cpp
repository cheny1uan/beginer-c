/*2351892 信11 陈奕炫*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a, b, c, d, e, f;
	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> a ;
	b = a/10000;
	c = a%10000/1000;
	d = a%1000/100;
	e = a%100/10;
	f = a%10;
	cout << "万位 : " << b << endl;
	cout << "千位 : " << c << endl;
	cout << "百位 : " << d << endl;
	cout << "十位 : " << e << endl;
	cout << "个位 : " << f << endl;
	return 0;
}