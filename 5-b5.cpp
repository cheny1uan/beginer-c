/* 2351892 ��11 ������ */
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>

using namespace std;

void select_sort(int array[], int n)//ʹ��ѡ������
{
	int i, j, k, t;
	for (i = 0; i < n; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (array[j]>array[k]) {
				k = j;
			}
		}
			t = array[k];
			array[k] = array[i];
			array[i] = t;	
	}
}

int main()
{
	int a[1000] = { 0 };
	int count = 0;
	int num;
	int i = 0,k;

	cout << "������ɼ������1000������������������" << endl;
	while (count < 1000) {
		cin >> num;

		if (num < 0) {
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
	cout << "���������Ϊ:" << endl;
	for (i = 0; i < count; i++) {
		cout << a[i] << " ";
		if (((i + 1) % 10 == 0) && (i + 1) != count) {
			cout << endl;
		}
		if (i + 1 == count) {
			cout << endl;
		}
	}
	cin.ignore(65536, '\n');
	
	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;;
	
	int b[100] = { 0 };
	for (k = 1; k <= 100; k++) {
		b[k - 1] = k;
	}
	
	
	select_sort(a, count);


	for (i = 0; i < count; i++) {
		cout << a[i] << " ";
		if (i > 0) {
			if (a[i] == a[i - 1]) {
				b[i] = b[i - 1];
			}
		}
		cout << b[i] << endl;
	}

	return 0;
}