/*2351892 信11 陈奕炫*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a;
	int b, c, d, e, f, g, h, i, j, k, m, n, p;
	printf("请输入[0-100亿)之间的数字:\n");
	scanf("%lf", &a);
	b = (int)(a / 10);
	a = (a - (double)(b) * 10) * 100;
	c = b / 100000000;
	d = b % 100000000 / 10000000;
	e = b % 10000000 / 1000000;
	f = b % 1000000 / 100000;
	g = b % 100000 / 10000;
	h = b % 10000 / 1000;
	i = b % 1000 / 100;
	j = b % 100 / 10;
	k = b % 10;
	m = (int)(a / 100);
	n = (int)(a + 0.0001) % 100 / 10;
	p = (int)(a + 0.0001) % 10;
	printf("十亿位 : %d\n", c);
	printf("亿位   : %d\n", d);
	printf("千万位 : %d\n", e);
	printf("百万位 : %d\n", f);
	printf("十万位 : %d\n", g);
	printf("万位   : %d\n", h);
	printf("千位   : %d\n", i);
	printf("百位   : %d\n", j);
	printf("十位   : %d\n", k);
	printf("圆     : %d\n", m);
	printf("角     : %d\n", n);
	printf("分     : %d\n", p);
	return 0;
}
