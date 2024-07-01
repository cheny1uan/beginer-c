/*2351892 信11 陈奕炫*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

int main()
{
	int a, b, c;
	float s;
	double d;
	const double pi = 3.14159;
	printf( "请输入三角形的两边及其夹角(角度)\n");
	scanf("%d %d %d",&a,&b,&c);
	d = c * pi / 180;
	s = (float)(a * b * sin(d) / 2);
	printf( "三角形的面积为 : %.3f\n", s);
	return 0;
}