/* 2351892 陈奕炫 信11 */
#include <iostream>
#include <cstring>

#define STU_NUM 10
#define PASS_GRADE 60
using namespace std;

void input_stu(string stu_id[], string stu_name[], int stu_grade[])
{
	int i;
	for (i = 1; i <= STU_NUM; i++) {
		cout << "请输入第"<<i<<"个人的学号、姓名、成绩" << endl;
		cin >> stu_id[i - 1];
		cin>>stu_name[i - 1];
		cin>>stu_grade[i - 1];
	}
}

void stu_sort(string stu_id[], string stu_name[], int stu_grade[])
{

	int i, j;
	int t = 0;
	string tmp;
	for (i = STU_NUM - 1; i >= 0; i--) {

		for (j = 0; j < i; j++) {
			if (stu_grade[j]>stu_grade[j+1]) {
				tmp=stu_id[j];
				stu_id[j]=stu_id[j + 1];
				stu_id[j + 1]=tmp;
				tmp=stu_name[j];
				stu_name[j]=stu_name[j + 1];
				stu_name[j + 1]=tmp;
				t = stu_grade[j];
				stu_grade[j] = stu_grade[j + 1];
				stu_grade[j + 1] = t;
			}
		}
	}
}

void output_stu(string stu_id[], string stu_name[], int stu_grade[])
{
	int i;
	cout << "不及格名单(成绩升序):" << endl;
	for (i = 0; i < STU_NUM; i++) {
		if (stu_grade[i]<PASS_GRADE) {			
			cout << stu_name[i] << " " << stu_id[i] << " " << stu_grade[i] << endl;;
		}
	}
}

int main()
{
	string stu_id[STU_NUM];
	string stu_name[STU_NUM];
	int stu_grade[STU_NUM] = { 0 };
	input_stu(stu_id, stu_name, stu_grade);
	stu_sort(stu_id, stu_name, stu_grade);
	output_stu(stu_id, stu_name, stu_grade);

	return 0;

}