/* 2351892 ��11 ������ */
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>

using namespace std;

int main()
{
	int a[21] = { 0 };
	int i=0,count=0;//countΪ����ԭ���������ֵĸ���
	int num,num_new;


	cout << "��������������������������20������0������������" << endl;
	while (count < 20) {
		cin >> num;
		
		if (num<= 0) {
			break;
		}
		a[i] = num;
		i++;
		count++;
	}
	if (count == 0) {
		cout << "����Ч����" << endl;
		return 0;
	}
	cout << "ԭ����Ϊ��" << endl;
	for (i = 0; i < count; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cin.ignore(65536, '\n');//���������������Ӱ����������
	cout << "������Ҫ�����������" << endl;
	cin >> num_new;
	a[count] = num_new;
	int insert=count;
	while (insert > 0 && a[insert - 1] > num_new) {
		a[insert] = a[insert - 1];
		insert--;
	}
	a[insert] = num_new;
	cout << "����������Ϊ��" << endl;
	for (i = 0; i <=count;i++) {
		cout << a[i] << " ";
	}
	cout << endl;



	return 0;
}