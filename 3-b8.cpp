/*2351892 ��11 ������*/
#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;

int main() {
	int x;
	double ex=1, t=0, s=1;//exΪ���պͣ�tΪ����ָ��,sΪÿһ��
	while (1) {
		cout << "������x��ֵ[-10 ~ +65]" << endl;
		cin >> x;
		if ((x < -10) || (x > 65)) {
			cout << "����Ƿ�������������" << endl;
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