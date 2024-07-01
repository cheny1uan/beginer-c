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
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a >> b >> c;
	d = c * pi / 180;
	s = float(a * b * sin(d) / 2);
	cout << setiosflags(ios::fixed)<< setprecision(3)<<"三角形的面积为 : " << s << endl;
	return 0;
}
