/*2351892 ��11 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    int a, b, c, er;
    int d = 0; // aΪ�꣬bΪ�£�cΪ�գ�dΪ�·�ǰ��������erΪ2�µ�����,dayΪ������
    int year;
    int day;
    printf("�����룬�꣬�£���\n");
    scanf("%d %d %d", &a, &b, &c);
    year = a % 4 == 0 && a % 100 != 0 || a % 400 == 0;
    if (year) {
        er = 29;
    }
    else {
        er = 28;
    }
    if (b > 12 || b < 1) {
        printf("�������-�·ݲ���ȷ\n");
        return 0;
    }
    switch (b) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (c > 31 || c < 1) {
                printf("�������-�����µĹ�ϵ�Ƿ�\n");
                return 0;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (c > 30 || c < 1) {
                printf("�������-�����µĹ�ϵ�Ƿ�\n");
                return 0;
            }
            break;
        case 2:
            if (c > er || c < 1) {
                printf("�������-�����µĹ�ϵ�Ƿ�\n");
                return 0;
            }
            break;
    }
    switch (b) {
        case 1:
            d = c;
            break;
        case 2:
            d = 31;
            break;
        case 3:
            d = 31 + er;
            break;
        case 4:
            d = 31 * 2 + er;
            break;
        case 5:
            d = 31 * 2 + 30 + er;
            break;
        case 6:
            d = 31 * 3 + 30 + er;
            break;
        case 7:
            d = 31 * 3 + 30 * 2 + er;
            break;
        case 8:
            d = 31 * 4 + 30 * 2 + er;
            break;
        case 9:
            d = 31 * 5 + 30 * 2 + er;
            break;
        case 10:
            d = 31 * 5 + 30 * 3 + er;
            break;
        case 11:
            d = 31 * 6 + 30 * 3 + er;
            break;
        case 12:
            d = 31 * 7 + 30 * 3 + er;
            break;
    }
    day = d + c;
    printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, day);
    return 0;
}