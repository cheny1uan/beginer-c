/*2351892 ��11 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	int a, b, c, d, e, f;
	printf( "������һ��[1..30000]�������:\n" );
	scanf( "%d",&a);
	b = a / 10000;
	c = a % 10000 / 1000;
	d = a % 1000 / 100;
	e = a % 100 / 10;
	f = a % 10;
	printf("��λ : %d\n", b);
	printf("ǧλ : %d\n", c);
	printf("��λ : %d\n", d);
	printf("ʮλ : %d\n", e);
	printf("��λ : %d\n", f);
	return 0;
}