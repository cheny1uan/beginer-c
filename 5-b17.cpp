/* 2351892 ��11 ������ */

#include<iostream>
#include <time.h>
#include <windows.h>
#include<cstring>

#define PASSWORDS_NUM 10
#define PASSWORDS_LEN_MAX 16
#define PASSWORDS_LEN_MIN 12
using namespace std;

static const char other[] = "~!@#$%^&*()-_=+[],.?";

bool input_num(int num[])
{
	int i;
	for (i = 0; i < 5; i++) {
		cin >> num[i];
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			return false;
		}
	}
	return true;
}

bool check_num(int num[])
{
	//������볤��
	if (num[0] < PASSWORDS_LEN_MIN || num[0]>PASSWORDS_LEN_MAX) {
		cout << "���볤��[" << num[0] << "]����ȷ" << endl;
		return false;
	}
	//����д��ĸ����
	if (num[1] < 2) {
		cout << "��д��ĸ����[" << num[1] << "]����ȷ" << endl;
		return false;
	}
	//���Сд��ĸ����
	if (num[2] < 2) {
		cout << "Сд��ĸ����[" << num[2] << "]����ȷ" << endl;
		return false;
	}
	//������ָ���
	if (num[3]< 2) {
		cout << "���ָ���[" << num[3] << "]����ȷ" << endl;
		return false;
	}
	//����������Ÿ���
	if (num[4] < 2) {
		cout << "�������Ÿ���[" << num[4] << "]����ȷ" << endl;
		return false;
	}
	//����ַ�����֮�����ܳ���
	if (num[1] + num[2] + num[3] + num[4] > num[0]) {
		cout << "�����ַ�����֮��[" << num[1] << "+" << num[2] << "+" << num[3] << "+" << num[4] << "]���������볤��[" << num[0] << "]" << endl;
		return false;
	}
	return true;
}
void output_password(int num[])
{
	int num_capital, num_lower, num_figure, num_other;
	int i = 0;
	int j,k;
	char password[PASSWORDS_LEN_MAX+1] = { 0 };
	while (i < PASSWORDS_NUM) {
		num_capital=0;
		num_lower = 0;
		num_figure=0;
		num_other=0;	
		for (j = 0; j < num[0]; j++) {
			password[j]= rand() % 94 + 33;//�պ�����33-126�ɼ��ַ���Χ
		}
		for (j = 0; j < num[0]; j++) {
			if (password[j] >= 'A' && password[j] <= 'Z')
				num_capital++;
			if (password[j] >= 'a' && password[j] <= 'z')
				num_lower++;
			if (password[j] >= '0' && password[j] <= '9')
				num_figure++;
			for (k = 0; k < 21; k++) {
				if (password[j] == other[k]) {
					num_other++;
					break;
				}
			}
			

		}
		if (num_capital >= num[1] && num_lower >= num[2] && num_figure >= num[3] && num_other >= num[4]) {
			i++;
			cout << password << endl;
		}

	}
}

int main()
{
	srand((unsigned int)(time(0)));
	int num[5];//0-4�ֱ�Ϊ���볤�ȣ���д��ĸ������Сд��ĸ���������ָ������������Ÿ���
	bool is_right;
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	is_right = input_num(num);
	if (!is_right) {
		cout << "����Ƿ�" << endl;
		return 0;
	}
	else {
		is_right = check_num(num);
		if (!is_right) {
			return 0;
		}
	}
	cout << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << " " << num[4] << endl;
	output_password(num);
	return 0;
}