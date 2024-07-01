/* 2351892 陈奕炫 信11 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#include <iostream>
#include<iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//定义文件名的最大长度

/* stu_metge 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_merge {
private:
	int  stu_no;					//学号
	char stu_name[MAX_NAME_LEN];  //姓名

	/* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	bool choose_1 = false;
	bool choose_2 = false;
	friend class stu_list;

public:
	//本类不允许定义任何的公有数据成员及成员函数
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//第一轮选课的学生名单（不排序、不去重）
	int list_num_1;						//第一轮选课的学生人数

	student list_round_2[MAX_STU_NUM];	//第二轮选课的学生名单（不排序、不去重）
	int list_num_2;						//第二轮选课的学生人数

	stu_merge list_merge[MAX_STU_NUM];	//合并后的学生名单（去重，按升序排列）
	int list_merge_num;					//合并后的学生人数（目前不打印，但可用于内部管理，如果不需要，也不要删除）

	/* 允许按需加入private数据成员和成员函数
	   注意，不允许加入array / set / map / vector等STL容器 */

public:
	stu_list();										//构造函数，按需完成初始化功能，如果不需要，保留空函数即可
	int read(const char* filename, const int round);	//从文件中读入选课信息，round为1/2，表示选课轮次
	int print(const char* prompt = NULL);				//打印最终的选课名单

	/* 允许按需加入其它public成员函数（提示：合并、去重、排序等）
	   不允许定义公有的数据成员
	   不允许在成员函数中使用array / set / map / vector等STL容器 */
	int check_merge(stu_merge list_merge[], int no);
	void merge_list(student list_round_1[], student list_round_2[], stu_merge list_merge[]);
	void sort_list(stu_merge list_merge[]);
	void dipose_list()
	{
		merge_list(list_round_1, list_round_2, list_merge);
		sort_list(list_merge);
	}
};

/* --- 下面可以给出stu_merge/stu_list两个类的成员函数的体外实现 --- */
int stu_list::check_merge(stu_merge list_merge[], int no)
{
	for (int i=0; list_merge[i].stu_no != 0; i++) {

		if (no == list_merge[i].stu_no) {
			return i;
		}
	}
	return -1;
}
void stu_list::merge_list(student list_round_1[], student list_round_2[], stu_merge list_merge[])
{
	 
	for (int i=0; i < list_num_1; i++) {
		if (check_merge(list_merge, list_round_1[i].no)<0) {
			list_merge[list_merge_num].stu_no = list_round_1[i].no;
			for (int j = 0; list_round_1[i].name[j] != 0; j++) {
				list_merge[list_merge_num].stu_name[j] = list_round_1[i].name[j];
			}
			list_merge[list_merge_num].choose_1 = true;
			list_merge_num++;
		}
		else {
			;
		}
	}
	for (int i=0; i < list_num_2; i++) {
		if (check_merge(list_merge, list_round_2[i].no)<0) {
			list_merge[list_merge_num].stu_no = list_round_2[i].no;
			for (int j = 0; list_round_2[i].name[j] != 0; j++) {
				list_merge[list_merge_num].stu_name[j] = list_round_2[i].name[j];
			}
			list_merge[list_merge_num].choose_2 = true;
			list_merge_num++;
		}
		else {
			list_merge[check_merge(list_merge, list_round_2[i].no)].choose_2 = true;
		}
	}
}
void stu_list::sort_list(stu_merge list_merge[])
{
	for (int i = 0; i < list_merge_num;i++) {
		for (int j = 0; j < list_merge_num - i - 1; j++) {
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no) {
				stu_merge tmp;
				tmp = list_merge[j];
				list_merge[j] = list_merge[j + 1];
				list_merge[j + 1] = tmp;
			}

		}
	}

}

/***************************************************************************
  函数名称：
  功    能：从文件中读入选课信息，round为1/2，表示选课轮次
  输入参数：
  返 回 值：
  说    明：构造函数，按需完成初始化功能，如果不需要，保留空函数即可
***************************************************************************/
stu_list::stu_list()
{

	for (list_num_1 = 0; list_num_1 < MAX_STU_NUM - 1; list_num_1++) {
		if (list_round_1[list_num_1].no == 0) {
			break;
		}
	}
	for (list_num_2 = 0; list_num_2 < MAX_STU_NUM - 1; list_num_2++) {
		if (list_round_2[list_num_2].no == 0) {
			break;
		}
	}
	for (int i = 0; i < MAX_STU_NUM; i++) {
		list_merge[i].stu_no = 0;
		for (int j = 0; j < MAX_NAME_LEN; j++) {
			list_merge[i].stu_name[j] = 0;
		}
	}

	list_merge_num = 0;
}

/***************************************************************************
  函数名称：
  功    能：演示静态链接库的使用，本函数中调用静态链接库中的预置函数
  输入参数：
  返 回 值：
  说    明：本函数不需要修改
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* 读取第1/2轮的选课名单并打印 */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("第一轮选课名单：", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("第二轮选课名单：", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：打印最终的选课名单
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "============================================================" << endl;
	cout << "序号 学号     姓名                            第一轮 第二轮 " << endl;
	cout << "============================================================" << endl;
	int order = 1;
	for (int i = 0; i < list_merge_num; i++, order++) {
		cout << setiosflags(ios::left) << setw(5) << order << list_merge[i].stu_no << "  " << setw(32) << list_merge[i].stu_name;
		if (list_merge[i].choose_1 == true)
			cout << "Y      ";
		else
			cout << "/      ";
		if (list_merge[i].choose_2 == false)
		{
			if (list_merge[i].choose_1 == true)
				cout << "退课" << endl;
		}
		else
		{
			if (list_merge[i].choose_1 == true)
				cout << "Y" << endl;
			else
				cout << "补选" << endl;
		}
	}
	cout << "============================================================" << endl;
	

	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	gets_s(file1); //cin不能读有空格的文件

	cout << "请输入后一轮选课的数据文件 : ";
	gets_s(file2);

	stu_list list;

	/* 读入数据 */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* 处理数据 */
	list.dipose_list();
	/* 打印 */
	list.print("最终选课名单");

	return 0;
}

