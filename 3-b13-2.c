/* 信11 2351892 陈奕炫 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret1,ret2=0,nian, yue, days = 0, day1;
	int i, j, k, n = 0;
	char ch = 0;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) :");
		ret1 = scanf("%d %d", &nian,&yue); 
		if (ret1 == 2 && (nian>=2000 && nian <= 2030)&&(yue>=1&&yue<=12)) {
			break;
		}
		else if (ret1 == 2 && (nian < 2000 || nian > 2030) || (yue < 1 || yue > 12)) {
			printf("输入非法，请重新输入\n");
			continue;
		}
		else {
			printf("输入非法，请重新输入\n"); 
			while (ch = getchar() != '\n' && ch != EOF);
		}
		continue;
	}
	while (1) {
		printf("请输入%d年%d月1日的星期(0 - 6表示星期日 - 星期六) :",nian,yue);
		ret2=scanf("%d", &day1);
		if (ret2!=1) {
			printf("输入非法，请重新输入\n");
			while (ch = getchar() != '\n' && ch != EOF);
		}
		else {

			if (day1 >= 0 && day1 <= 6)
				break;
			else {
				printf("输入非法，请重新输入\n");
				continue;
			}
		}
	}
	switch (yue) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days = 31;
			break;
		case 2:
			if (nian % 4 == 0 && nian % 100 != 0 || nian % 400 == 0) {
				days = 29;
			}
			else {
				days = 28;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days = 30;

	}

	printf("\n");
	printf("%d年%d月的月历为:\n",nian,yue);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	for (i = 0; i < day1; i++) {
		printf("        ");//8个空格
	}
	for (j = 1; j <= (7 - day1); j++) {
		printf("%4d    ",j);
	}
	printf("\n");
	for (k = (8 - day1); k <= days; k++) {
		printf("%4d    ",k );
		n++;
		if (n % 7 == 0 && n != 0) {
			printf("\n");
		}
	}
	//if (days - 7 + day1) {
	//	;
	//}
	//else {
	printf("\n");
	//}



	return 0;
}
