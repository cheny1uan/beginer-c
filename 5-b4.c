/*2351892 信11 陈奕炫*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char ch;
	int a[1000] = { 0 };
	int count = 0;
	int num,i=0,k=0;
	printf("请输入成绩（最多1000个），负数结束输入\n");
	while (count < 1000) {
		scanf("%d", &num);
		if (num < 0) {
			break;
		}
		a[i] = num;
		i++;
		count++;
	}
	if (count == 0) {
		printf("无有效输入\n");
		return 0;
	}
	printf("输入的数组为:\n");
	for (i = 0; i < count; i++) {
		printf("%d ", a[i]);
		if (((i + 1) % 10 == 0)&&(i+1)!=count) {
			printf("\n");
		}
		if (i + 1 == count) {
			printf("\n");
		}
	}
	while (ch = getchar() != '\n' && ch != EOF);//清空缓冲区
	
	int b[101];
	for (k = 0; k <= 100; k++) {
		b[k] = 0;
	}
	for (k = 0; k <= 100; k++) {
		for (i = 0; i < count; i++) {
			if (a[i] == k) {
				b[k] += 1;
			}
		}
	}
	printf("分数与人数的对应关系为:\n");
	for (k = 100; k >= 0; k--) {
		if (b[k] != 0) {
			printf("%d %d\n", k, b[k]);
		}
	}



	return 0;
}