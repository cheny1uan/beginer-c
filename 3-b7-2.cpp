/*2351892 信11 陈奕炫*/
#include<iostream>
using namespace std;

int main()
{
	double a;
	int b,c,d,e,f,g,h,i,j,k,m,n;
	cout << "请输入找零值：" << endl;
	cin >> a;
	b = int((a+0.0001) * 100);
	c = b / 5000;
	d = (b-c*5000)/ 2000;
	e = (b-c*5000-d*2000)/ 1000;
	f = (b- c * 5000 - d * 2000-e*1000)/500;
	g = (b - c * 5000 - d * 2000 - e * 1000-f*500) / 100;
	h = (b - c * 5000 - d * 2000 - e * 1000 - f * 500-g*100) / 50;
	i = (b - c * 5000 - d * 2000 - e * 1000 - f * 500 - g * 100-h*50) / 10;
	j = (b - c * 5000 - d * 2000 - e * 1000 - f * 500 - g * 100 - h * 50-i*10) / 5;
	k = (b - c * 5000 - d * 2000 - e * 1000 - f * 500 - g * 100 - h * 50 - i * 10 -j*5)/2;
	m = b - c * 5000 - d * 2000 - e * 1000 - f * 500 - g * 100 - h * 50 - i * 10 - j * 5-k*2;
	n = c + d + e + f + g + h + i + j + k+m;
	cout << "共" << n << "张找零，具体如下：" << endl;
	if (c != 0) {
		cout << "50元 : " << c << "张" << endl;
	}
	if (d != 0) {
		cout << "20元 : " << d << "张" << endl;
	}
	if (e != 0) {
		cout << "10元 : " << e << "张" << endl;
	}
	if (f != 0) {
		cout << "5元  : " << f << "张" << endl;
	}
	if (g != 0) {
		cout << "1元  : " << g << "张" << endl;
	}
	if (h != 0) {
		cout << "5角  : " << h << "张" << endl;
	}
	if (i != 0) {
		cout << "1角  : " << i << "张" << endl;
	}
	if (j != 0) {
		cout << "5分  : " << j << "张" << endl;
	}
	if (k != 0) {
		cout << "2分  : " << k << "张" << endl;
	}
	if (m != 0) {
		cout << "1分  : " << m << "张" << endl;
	}
	return 0;
}