/* 2351892 ������ ��11 */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <iostream>
#include<iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	bool choose_1 = false;
	bool choose_2 = false;
	friend class stu_list;

public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */
	int check_merge(stu_merge list_merge[], int no);
	void merge_list(student list_round_1[], student list_round_2[], stu_merge list_merge[]);
	void sort_list(stu_merge list_merge[]);
	void dipose_list()
	{
		merge_list(list_round_1, list_round_2, list_merge);
		sort_list(list_merge);
	}
};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */
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
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
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
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ��� " << endl;
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
				cout << "�˿�" << endl;
		}
		else
		{
			if (list_merge[i].choose_1 == true)
				cout << "Y" << endl;
			else
				cout << "��ѡ" << endl;
		}
	}
	cout << "============================================================" << endl;
	

	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.dipose_list();
	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}

