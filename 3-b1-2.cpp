/* 2351892 ��11 ������*/
#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;

int main()
{
    double r, h, c, s1, s2, v1, v2;
    const double pi = 3.14159;
    cout << "������뾶�͸߶�" << endl;
    cin >> r >> h;
    c = 2 * pi * r;
    s1 = pi * r * r;
    s2 = 4 * pi * r * r;
    v1 = 4 * pi * r * r * r / 3;
    v2 = s1 * h;
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << "Բ�ܳ�     : " << c << endl;
    cout << "Բ���     : " << s1 << endl;
    cout << "Բ������ : " << s2 << endl;
    cout << "Բ�����   : " << v1 << endl;
    cout << "Բ�����   : " << v2 << endl;
    return 0;
}