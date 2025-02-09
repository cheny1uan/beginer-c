/* 2351892 信11 陈奕炫*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{
    double r, h, c, s1, s2, v1, v2;
    const double pi = 3.14159;
    cout << "请输入半径和高度" << endl;
    cin >> r >> h;
    c = 2 * pi * r;
    s1 = pi * r * r;
    s2 = 4 * pi * r * r;
    v1 = 4 * pi * r * r * r / 3;
    v2 = s1 * h;
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "圆周长     : " << c << endl;
    cout << "圆面积     : " << s1 << endl;
    cout << "圆球表面积 : " << s2 << endl;
    cout << "圆球体积   : " << v1 << endl;
    cout << "圆柱体积   : " << v2 << endl;
    return 0;
}