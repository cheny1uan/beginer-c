/* 2351892 ��11 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
    double r, h, c, s1, s2, v1, v2;
    const double pi = 3.14159;
    printf( "������뾶�͸߶�\n");
    scanf("%lf %lf",&r,&h);
    c = 2 * pi * r;
    s1 = pi * r * r;
    s2 = 4 * pi * r * r;
    v1 = 4 * pi * r * r * r / 3;
    v2 = s1 * h;
    printf("Բ�ܳ�     : %.2lf\n",c) ;
    printf("Բ���     : %.2lf\n", s1);
    printf("Բ������ : %.2lf\n", s2);
    printf("Բ�����   : %.2lf\n", v1);
    printf("Բ�����   : %.2lf\n", v2);
    return 0;
}