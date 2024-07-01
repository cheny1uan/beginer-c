/* 2351892 信11 陈奕炫*/
#include<iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

int max(int a,int b, int c)
{
	int t;
	t = (a > b ? a : b);
	return t > c ? t : c;
}

int max(int a, int b, int c,int d)
{
	int m, n;
	m= (a > b ? a : b);
	n= (c > d ? c : d);
	return m > n ? m : n;
}

int main()
{
	int n, a, b, c,d,my_max=0;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> n ;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else if (n < 2 || n>4) {
			cout << "个数输入错误" << endl;
			return 0;
		}
		else if (n == 2) {
			cin >> a >> b;
			if (cin.fail()||a<=0||b<=0) {
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			c = 0;
			d = 0;
			break;
		}
		else if (n == 3) {
			cin >> a >> b>>c;
			if (cin.fail()||a<=0||b<=0||c<=0) {
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			d = 0;
			break;
		}
		else if (n == 4) {
			cin >> a >> b >> c>>d;
			if (cin.fail() || a <= 0 || b <= 0 || c <= 0||d<=0) {
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			break;
		}
		else {
			break;
		}
	}
	if (n == 2) {
		my_max = max(a, b);
	}
	else if (n == 3) {
		my_max = max(a, b,c);
	}
	else if (n == 4) {
		my_max = max(a, b, c,d);
	}
	cout << "max=" << my_max << endl;
	return 0;
}