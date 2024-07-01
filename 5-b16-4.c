/* 信11 2351892 陈奕炫 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


#define STU_NUM 10
#define ID_LEN 8
#define NAME_LEN 9
#define PASS_GRADE 60

void input_stu(char stu_id[][ID_LEN], char stu_name[][NAME_LEN], int stu_grade[])
{
	int i;
	for (i = 1; i <= STU_NUM; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i);
		scanf("%s", stu_id[i - 1]);
		scanf("%s", stu_name[i - 1]);
		scanf("%d", &stu_grade[i - 1]);
	}
}

void stu_sort(char stu_id[][ID_LEN], char stu_name[][NAME_LEN], int stu_grade[])
{

	int i, j;
	int t = 0;
	char tmp[20] = { 0 };
	for (i = STU_NUM - 1; i >= 0; i--) {

		for (j = 0; j < i; j++) {
			if (stu_grade[j]<stu_grade[j+1]) {
				strcpy(tmp, stu_id[j]);
				strcpy(stu_id[j], stu_id[j + 1]);
				strcpy(stu_id[j + 1], tmp);
				strcpy(tmp, stu_name[j]);
				strcpy(stu_name[j], stu_name[j + 1]);
				strcpy(stu_name[j + 1], tmp);
				t = stu_grade[j];
				stu_grade[j] = stu_grade[j + 1];
				stu_grade[j + 1] = t;
			}
		}
	}
}

void output_stu(char stu_id[][ID_LEN], char stu_name[][NAME_LEN], int stu_grade[])
{
	int i = 0;
	printf("全部学生(成绩降序):\n");
	for (i = 0; i < STU_NUM; i++) {
		
			printf("%s %s %d\n", stu_name[i], stu_id[i], stu_grade[i]);
		}
	
}

int main()
{
	char stu_id[STU_NUM][ID_LEN] = { 0 };
	char stu_name[STU_NUM][NAME_LEN] = { 0 };
	int stu_grade[STU_NUM] = { 0 };
	input_stu(stu_id, stu_name, stu_grade);
	stu_sort(stu_id, stu_name, stu_grade);
	output_stu(stu_id, stu_name, stu_grade);

	return 0;
}