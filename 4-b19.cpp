/* 2351892 信11 陈奕炫*/
#include<iostream>
using namespace std;

int min(int a, int b, int c = 2147483647, int d = 2147483647)
{
	int x, y;
	x = (a < b ? a : b);
	y = (c < d ? c : d);
	return x < y ? x : y;
}



int main()
{
	int n, a, b, c, d, my_min = 0;
	while (1) {
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> n;
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
			if (cin.fail() || a <= 0 || b <= 0) {
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			c = 0;
			d = 0;
			break;
		}
		else if (n == 3) {
			cin >> a >> b >> c;
			if (cin.fail() || a <= 0 || b <= 0 || c <= 0) {
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			d = 0;
			break;
		}
		else if (n == 4) {
			cin >> a >> b >> c >> d;
			if (cin.fail() || a <= 0 || b <= 0 || c <= 0 || d <= 0) {
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
		my_min = min(a, b);
	}
	else if (n == 3) {
		my_min = min(a, b, c);
	}
	else if (n == 4) {
		my_min = min(a, b, c, d);
	}
	cout << "min=" << my_min << endl;
	return 0;
}