#include <iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	int a, b, c;
	float s;
	double d;
	const double pi = 3.14159;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a >> b >> c;
	d = c * pi / 180;
	s = float(a * b * sin(d) / 2);
	cout << setiosflags(ios::fixed)<< setprecision(3)<<"�����ε����Ϊ : " << s << endl;
	return 0;
}
