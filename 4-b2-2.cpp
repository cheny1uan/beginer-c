/* ��11 2351892 ������ */
#include <iostream>
#include<limits>
using namespace std;
int zeller(int y, int m, int d) 
{
	int w, y_, c;//wΪ���ڣ�y_Ϊ��ݺ���λ��cΪ���ǰ��λ
	if (m == 1 || m == 2) {
		y = y - 1;
		m = m + 12;
	}
	y_ = y % 100;
	c = (y - y_)/100;
	w = y_ + y_ / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	if (w < 0) {
		while (w < 0) {
			w = w + 7;
		}
	}
	w = w % 7;
	return w;
}






int main()
{

	int y,m,d,w;

	while (1) {
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y>>m>>d;   
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
			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
				if (d > 31 || d < 1) {
					cout << "�ղ���ȷ������������" << endl;
					continue;
				}
				else {
					break;
				}
			}
			else if (m == 4 || m == 6 || m == 9 || m == 11) {
				if (d > 30 || d < 1) {
					cout << "�ղ���ȷ������������" << endl;
					continue;
				}
				else {
					break;
				}
			}
			else {
				if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
					if (d > 29 || d < 1) {
						cout << "�ղ���ȷ������������" << endl;
						continue;
					}
					else {
						break;
					}
				}
				else {
					if (d > 28 || d < 1) {
						cout << "�ղ���ȷ������������" << endl;
						continue;
					}
					else {
						break;
					}
				}
			}		
		}
	}
	w = zeller(y, m, d);
	switch (w) {
		case 0:
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
	}
	return 0;
}