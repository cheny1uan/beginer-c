/*2351892 ��11 ������*/
#include<iostream>
#include<limits>
#include <iomanip>

using namespace std;



int zeller(int y, int m, int d) 
{
	int w, y_, c;//wΪ���ڣ�y_Ϊ��ݺ���λ��cΪ���ǰ��λ
	if (m == 1 || m == 2) {
		y = y - 1;
		m = m + 12;
	}
	y_ = y % 100;
	c = (y - y_) / 100;
	w = y_ + y_ / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	if (w < 0) {
		while (w < 0) {
			w = w + 7;
		}
	}
	w = w % 7;
	return w;
}
//������һ��ͨ���������������ظ����������ĺ���monthdays
int monthdays(int year,int month){
	int days;
	switch (month) {
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
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
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
			break;
	}
	return days;
}
void calender(int year, int month)
{
	int day1, days;
	int i, j, k, n=0;
	day1 = zeller(year, month, 1);
	days = monthdays(year, month);
	/* ������Ӵ��� */
	cout << year << "��" << month << "��" << endl;
	/* ͷ���ָ��ߣ������� */
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << "======================================================" << endl;
	for (i = 0; i < day1; i++) {
		cout << "        ";//8���ո�
	}
	for (j = 1; j <= (7 - day1); j++) {
		cout << setiosflags(ios::right) << setw(4) << j << "    ";
	}
	cout << endl;
	for (k = (8 - day1); k <= days; k++) {
		cout << setiosflags(ios::right) << setw(4) << k << "    ";
		n++;
		if (k == days) {
			cout << endl;
			break;
		}
		if (n % 7 == 0 && n != 0) {
			cout << endl;
		}
	}



	/* ������Ӵ��� */

	/* β���ָ��ߣ������� */
	cout << "======================================================" << endl;
}


int main() 
{
	int y, m;

	while (1) {
		cout << "��������[1900-2100]����" << endl;
		cin >> y >> m ;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������������" << endl;
		}
		else {
			if (y < 1900 || y>2100) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "��ݲ���ȷ������������" << endl;
				continue;
			}
			if (m < 1 || m>12) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "�·ݲ���ȷ������������" << endl;
				continue;
			}
			break;
		}
	}
	cout << endl;
	calender(y, m);
	return 0; 
}
