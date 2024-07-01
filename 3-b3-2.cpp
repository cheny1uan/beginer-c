/*2351892 信11 陈奕炫*/
#include <iostream>
#include<iomanip>
	using namespace std;
int main()

{
	double a;
	int b, c, d, e, f, g, h, i, j, k, m, n, p;
	cout << "请输入[0-100亿)之间的数字:" << endl;
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
	cout << "十亿位 : " << c << endl;
	cout << "亿位   : " << d << endl;
	cout << "千万位 : " << e << endl;
	cout << "百万位 : " << f << endl;
	cout << "十万位 : " << g << endl;
	cout << "万位   : " << h << endl;
	cout << "千位   : " << i << endl;
	cout << "百位   : " << j << endl;
	cout << "十位   : " << k <<endl;
	cout << "圆     : " << m << endl;
	cout << "角     : " << n << endl;
	cout << "分     : " << p << endl;
	return 0;
}
