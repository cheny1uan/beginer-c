/* ��11 2351892 ������ */
#include <iostream>
#include <iomanip>
#include<limits>
 
using namespace std;

int main()
{
	int nian, yue, days = 0, day1;
	int i, j, k, n = 0;
	while (1) {
		cout << "���������(2000-2030)���·�(1-12) :";
		cin >> nian >> yue;
		if (cin.fail()) {
			cin.clear();//����������Ĵ����־���Ա������ȡ���롣
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//������������ֱ����ĩβ���������ݣ��������з�('\n')����ȷ������������ղ�׼�������µ�����
			cout << "����Ƿ�������������" << endl;
		}
		else {

			if ((nian >= 2000) && (nian <= 2030) && (yue >= 1) && (yue <= 12))
				break;
			else {
				cout << "����Ƿ�������������" << endl;
				continue;
			}
		}
	}
	while (1) {
		cout << "������" << nian << "��" << yue << "��1�յ�����(0 - 6��ʾ������ - ������) :";
		cin >> day1;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "����Ƿ�������������" << endl;
		}
		else {

			if (day1 >= 0 && day1 <= 6)
				break;
			else {
				cout << "����Ƿ�������������" << endl;
				continue;
			}
		}
	}
	switch (yue) {
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
			if (nian % 4 == 0 && nian % 100 != 0 || nian % 400 == 0) {
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

	}

	cout << endl;
	cout << nian << "��" << yue << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
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
		if (n % 7 == 0 && n != 0) {
			cout << endl;
		}
	}
	//if (days - 7 + day1) {
	//	;
	//}
	//else {
		cout << endl;
	//}


	
		return 0;
}
