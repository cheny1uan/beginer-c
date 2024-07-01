/*2351892 信11 陈奕炫*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    double a;
    int b, c, d, e, f, g, h, i, j, k, m, n;
    printf("请输入找零值：\n");
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
    printf("共%d张找零，具体如下：\n", n);
    if (c != 0) {
        printf("50元 : %d张\n", c);
    }
    if (d != 0) {
        printf("20元 : %d张\n", d);
    }
    if (e != 0) {
        printf("10元 : %d张\n", e);
    }
    if (f != 0) {
        printf("5元  : %d张\n", f);
    }
    if (g != 0) {
        printf("1元  : %d张\n", g);
    }
    if (h != 0) {
        printf("5角  : %d张\n", h);
    }
    if (i != 0) {
        printf("1角  : %d张\n", i);
    }
    if (j != 0) {
        printf("5分  : %d张\n", j);
    }
    if (k != 0) {
        printf("2分  : %d张\n", k);
    }
    if (m != 0) {
        printf("1分  : %d张\n", m);
    }
    return 0;
}