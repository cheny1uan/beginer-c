/*2351892 ��11 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a;
	int b, c, d, e, f, g, h, i, j, k, m, n, p;
	printf("������[0-100��)֮�������:\n");
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
	printf("ʮ��λ : %d\n", c);
	printf("��λ   : %d\n", d);
	printf("ǧ��λ : %d\n", e);
	printf("����λ : %d\n", f);
	printf("ʮ��λ : %d\n", g);
	printf("��λ   : %d\n", h);
	printf("ǧλ   : %d\n", i);
	printf("��λ   : %d\n", j);
	printf("ʮλ   : %d\n", k);
	printf("Բ     : %d\n", m);
	printf("��     : %d\n", n);
	printf("��     : %d\n", p);
	return 0;
}
