/*2351892 ��11 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    double a;
    int b, c, d, e, f, g, h, i, j, k, m, n;
    printf("����������ֵ��\n");
    scanf("%lf", &a);
    b = (int)(a * 100 + 0.0001);
    c = b / 5000;
    d = (b - c * 5000) / 2000;
    e = (b - c * 5000 - d * 2000) / 1000;
    f = (b - c * 5000 - d * 2000 - e * 1000) / 500;
    g = (b - c * 5000 - d * 2000 - e * 1000 - f * 500) / 100;
    h = (b - c * 5000 - d * 2000 - e * 1000 - f * 500 - g * 100) / 50;
    i = (b - c * 5000 - d * 2000 - e * 1000 - f * 500 - g * 100 - h * 50) / 10;
    j = (b - c * 5000 - d * 2000 - e * 1000 - f * 500 - g * 100 - h * 50 - i * 10) / 5;
    k = (b - c * 5000 - d * 2000 - e * 1000 - f * 500 - g * 100 - h * 50 - i * 10 - j * 5) / 2;
    m = b - c * 5000 - d * 2000 - e * 1000 - f * 500 - g * 100 - h * 50 - i * 10 - j * 5 - k * 2;
    n = c + d + e + f + g + h + i + j + k + m;
    printf("��%d�����㣬�������£�\n", n);
    if (c != 0) {
        printf("50Ԫ : %d��\n", c);
    }
    if (d != 0) {
        printf("20Ԫ : %d��\n", d);
    }
    if (e != 0) {
        printf("10Ԫ : %d��\n", e);
    }
    if (f != 0) {
        printf("5Ԫ  : %d��\n", f);
    }
    if (g != 0) {
        printf("1Ԫ  : %d��\n", g);
    }
    if (h != 0) {
        printf("5��  : %d��\n", h);
    }
    if (i != 0) {
        printf("1��  : %d��\n", i);
    }
    if (j != 0) {
        printf("5��  : %d��\n", j);
    }
    if (k != 0) {
        printf("2��  : %d��\n", k);
    }
    if (m != 0) {
        printf("1��  : %d��\n", m);
    }
    return 0;
}