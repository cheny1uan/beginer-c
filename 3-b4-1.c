/*2351892 ��11 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>

int main()
{
	int a, b, c;
	float s;
	double d;
	const double pi = 3.14159;
	printf( "�����������ε����߼���н�(�Ƕ�)\n");
	scanf("%d %d %d",&a,&b,&c);
	d = c * pi / 180;
	s = (float)(a * b * sin(d) / 2);
	printf( "�����ε����Ϊ : %.3f\n", s);
	return 0;
}