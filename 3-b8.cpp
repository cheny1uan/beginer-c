/*2351892 信11 陈奕炫*/
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main() {
	int x;
	double ex=1, t=0, s=1;//ex为最终和，t为分子指数,s为每一项
	while (1) {
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
		if ((x < -10) || (x > 65)) {
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		else {
			while (fabs(s) >= 1e-6) {
				t++;
				s = s * x / t;
				if (fabs(s) < 1e-6) {
					break;
				}
				ex = ex + s;
			}
			break;
		}
	}
	cout << setprecision(10) << "e^" << x << "=" << ex << endl;
	return 0;
}