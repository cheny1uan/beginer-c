/*2351892 ��11 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	char ch;
	int a[1000] = { 0 };
	int count = 0;
	int num,i=0,k=0;
	printf("������ɼ������1000������������������\n");
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
		printf("����Ч����\n");
		return 0;
	}
	printf("���������Ϊ:\n");
	for (i = 0; i < count; i++) {
		printf("%d ", a[i]);
		if (((i + 1) % 10 == 0)&&(i+1)!=count) {
			printf("\n");
		}
		if (i + 1 == count) {
			printf("\n");
		}
	}
	while (ch = getchar() != '\n' && ch != EOF);//��ջ�����
	
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
	printf("�����������Ķ�Ӧ��ϵΪ:\n");
	for (k = 100; k >= 0; k--) {
		if (b[k] != 0) {
			printf("%d %d\n", k, b[k]);
		}
	}



	return 0;
}