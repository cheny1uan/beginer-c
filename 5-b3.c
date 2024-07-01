/*2351892 信11 陈奕炫*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int is_leap(int a) {

    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0) {
        return 1;
    }

    else {
        return 0;
    }

}
int month_days(int month, int leap)
{
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (leap == 1) {
        days[1] += 1;
    }
    
    return days[month-1];

}



int main()
{
    int year, month, day,days;
    int leap;
    int i=1;
    printf("请输入年，月，日\n");
    scanf("%d %d %d", &year, &month, &day);
    
    leap = is_leap(year);
    if (month > 12 || month < 1) {
        printf("输入错误-月份不正确\n");
        return 0;
    }
    if (day > month_days(month, leap) || day < 1) {
        printf("输入错误-日与月的关系非法\n");
        return 0;
     }
    for (days = 0; i<month; i++) {
        days += month_days(i, leap);
    }
    days += day;
    printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
    return 0;
}