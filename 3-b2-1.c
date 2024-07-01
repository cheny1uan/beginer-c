/*2351892 信11 陈奕炫*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	int a, b, c, d, e, f;
	printf( "请输入一个[1..30000]间的整数:\n" );
	scanf( "%d",&a);
	b = a / 10000;
	c = a % 10000 / 1000;
	d = a % 1000 / 100;
	e = a % 100 / 10;
	f = a % 10;
	printf("万位 : %d\n", b);
	printf("千位 : %d\n", c);
	printf("百位 : %d\n", d);
	printf("十位 : %d\n", e);
	printf("个位 : %d\n", f);
	return 0;
}