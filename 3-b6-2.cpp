/*2351892 ��11 ������*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a;
	int b, c, d, e, f, g, h, i, j, k, m, n, p;
	int x, y;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	cout << "��д�����:" << endl;
	b = int(a / 10);
	a = (a - double(b) * 10) * 100;
	c = b / 100000000;//ʮ��
	d = b % 100000000 / 10000000;//��
	e = b % 10000000 / 1000000;//ǧ��
	f = b % 1000000 / 100000;//����
	g = b % 100000 / 10000;//ʮ��
	h = b % 10000 / 1000;//��
	i = b % 1000 / 100;//ǧ
	j = b % 100 / 10;//��
	k = b % 10;//ʮ
	m = int(a / 100);//Բ
	n = int(a + 0.0001) % 100 / 10;//��
	p = int(a + 0.0001) % 10;//��
	y = c == 0 && d == 0;
	x = c == 0 && d == 0&&e == 0 && f == 0 && g == 0 && h == 0;
	if(c!=0||d!=0||e!=0||f!=0||g!=0||h!=0||i!=0||j!=0||k!=0||m!=0){
		if (c == 0 && d == 0) {
			;
		}
		else {
			switch (c) {
				case 9:
					cout << "��ʰ";
					break;
				case 8:
					cout << "��ʰ";
					break;
				case 7:
					cout << "��ʰ";
					break;
				case 6:
					cout << "½ʰ";
					break;
				case 5:
					cout << "��ʰ";
					break;
				case 4:
					cout << "��ʰ";
					break;
				case 3:
					cout << "��ʰ";
					break;
				case 2:
					cout << "��ʰ";
					break;
				case 1:
					cout << "Ҽʰ";
					break;
				case 0:
					break;
			}
			switch (d) {
				case 9:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 7:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 5:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 2:
					cout << "��";
					break;
				case 1:
					cout << "Ҽ";
					break;
				case 0:
					break;
			}
			cout << "��";
		}
		if (e == 0 && f == 0 && g == 0 && h == 0) {   //0000
			;
		}
		else if (e == 0 && f == 0 && g == 0 && h != 0) { //0001
			if (!y) {
				cout << "��";
			}
			else {
				;
			}
			switch (h) {
				case 9:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 7:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 5:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 2:
					cout << "��";
					break;
				case 1:
					cout << "Ҽ";
					break;
			}
			cout << "��";
		}
		else if (e != 0 && f == 0 && g == 0 && h == 0) { //1000
			switch (e) {
				case 9:
					cout << "��Ǫ";
					break;
				case 8:
					cout << "��Ǫ";
					break;
				case 7:
					cout << "��Ǫ";
					break;
				case 6:
					cout << "½Ǫ";
					break;
				case 5:
					cout << "��Ǫ";
					break;
				case 4:
					cout << "��Ǫ";
					break;
				case 3:
					cout << "��Ǫ";
					break;
				case 2:
					cout << "��Ǫ";
					break;
				case 1:
					cout << "ҼǪ";
					break;
			}
			cout << "��";
		}
		else if (e == 0 && f == 0 && g != 0 && h != 0) { //0011
			if (!y ) {
				cout << "��";
			}
			else {
				;
			}
			switch (g) {
				case 9:
					cout << "��ʰ";
					break;
				case 8:
					cout << "��ʰ";
					break;
				case 7:
					cout << "��ʰ";
					break;
				case 6:
					cout << "½ʰ";
					break;
				case 5:
					cout << "��ʰ";
					break;
				case 4:
					cout << "��ʰ";
					break;
				case 3:
					cout << "��ʰ";
					break;
				case 2:
					cout << "��ʰ";
					break;
				case 1:
					cout << "Ҽʰ";
					break;
			}
			switch (h) {
				case 9:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 7:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 5:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 2:
					cout << "��";
					break;
				case 1:
					cout << "Ҽ";
					break;
			}
			cout << "��";
		}
		else if (e != 0 && f == 0 && g == 0 && h != 0) { //1001
			switch (e) {
				case 9:
					cout << "��Ǫ";
					break;
				case 8:
					cout << "��Ǫ";
					break;
				case 7:
					cout << "��Ǫ";
					break;
				case 6:
					cout << "½Ǫ";
					break;
				case 5:
					cout << "��Ǫ";
					break;
				case 4:
					cout << "��Ǫ";
					break;
				case 3:
					cout << "��Ǫ";
					break;
				case 2:
					cout << "��Ǫ";
					break;
				case 1:
					cout << "ҼǪ";
					break;
			}
			cout << "��";
			switch (h) {
				case 9:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 7:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 5:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 2:
					cout << "��";
					break;
				case 1:
					cout << "Ҽ";
					break;
			}
			cout << "��";
		}
		else if (e != 0 && f != 0 && g == 0 && h == 0) { //1100
			switch (e) {
				case 9:
					cout << "��Ǫ";
					break;
				case 8:
					cout << "��Ǫ";
					break;
				case 7:
					cout << "��Ǫ";
					break;
				case 6:
					cout << "½Ǫ";
					break;
				case 5:
					cout << "��Ǫ";
					break;
				case 4:
					cout << "��Ǫ";
					break;
				case 3:
					cout << "��Ǫ";
					break;
				case 2:
					cout << "��Ǫ";
					break;
				case 1:
					cout << "ҼǪ";
					break;
			}
			switch (f) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ư�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
					break;
			}
			cout << "��";
		}
		else if (e == 0 && f != 0 && g == 0 && h == 0) { //0100
			if (!y) {
				cout << "��";
			}
			else {
				;
			}
			switch (f) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ư�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
					break;
			}
			cout << "��";
		}
		else if (e == 0 && f == 0 && g != 0 && h == 0) { //0010
			if (!y) {
				cout << "��";
			}
			else {
				;
			}
			switch (g) {
				case 9:
					cout << "��ʰ";
					break;
				case 8:
					cout << "��ʰ";
					break;
				case 7:
					cout << "��ʰ";
					break;
				case 6:
					cout << "½ʰ";
					break;
				case 5:
					cout << "��ʰ";
					break;
				case 4:
					cout << "��ʰ";
					break;
				case 3:
					cout << "��ʰ";
					break;
				case 2:
					cout << "��ʰ";
					break;
				case 1:
					cout << "Ҽʰ";
					break;
			}
			cout << "��";
		}
		else if (e == 0 && f != 0 && g == 0 && h != 0) { //0101
			if (!y) {
				cout << "��";
			}
			switch (f) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ư�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
			}
			cout << "��";
			switch (h) {
				case 9:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 7:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 5:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 2:
					cout << "��";
					break;
				case 1:
					cout << "Ҽ";
					break;
				case 0:
					break;
			}
			cout << "��";
		}
		else if (e == 0 && f != 0 && g != 0 && h == 0) { //0110
			if (!y ) {
				cout << "��";
			}
			switch (f) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ư�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
			}
			switch (g) {
				case 9:
					cout << "��ʰ";
					break;
				case 8:
					cout << "��ʰ";
					break;
				case 7:
					cout << "��ʰ";
					break;
				case 6:
					cout << "½ʰ";
					break;
				case 5:
					cout << "��ʰ";
					break;
				case 4:
					cout << "��ʰ";
					break;
				case 3:
					cout << "��ʰ";
					break;
				case 2:
					cout << "��ʰ";
					break;
				case 1:
					cout << "Ҽʰ";
					break;
				case 0:
					break;
			}
			cout << "��";
			}
		else {
			switch (e) {
				case 9:
					cout << "��Ǫ";
					break;
				case 8:
					cout << "��Ǫ";
					break;
				case 7:
					cout << "��Ǫ";
					break;
				case 6:
					cout << "½Ǫ";
					break;
				case 5:
					cout << "��Ǫ";
					break;
				case 4:
					cout << "��Ǫ";
					break;
				case 3:
					cout << "��Ǫ";
					break;
				case 2:
					cout << "��Ǫ";
					break;
				case 1:
					cout << "ҼǪ";
					break;
				case 0:
					cout << "��";
					break;
			}
			switch (f) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ư�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
				case 0:
					cout << "��";
					break;
			}
			switch (g) {
				case 9:
					cout << "��ʰ";
					break;
				case 8:
					cout << "��ʰ";
					break;
				case 7:
					cout << "��ʰ";
					break;
				case 6:
					cout << "½ʰ";
					break;
				case 5:
					cout << "��ʰ";
					break;
				case 4:
					cout << "��ʰ";
					break;
				case 3:
					cout << "��ʰ";
					break;
				case 2:
					cout << "��ʰ";
					break;
				case 1:
					cout << "Ҽʰ";
					break;
				case 0:
					break;
			}
			switch (h) {
				case 9:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 7:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 5:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 2:
					cout << "��";
					break;
				case 1:
					cout << "Ҽ";
					break;
				case 0:
					break;
			}
			cout << "��";
		}
		if (i == 0 && j == 0 && k == 0 && m == 0) {   //0000
			;
		}
		else if (i == 0 && j == 0 && k == 0 && m != 0) { //0001
			if (!x ) {
				cout << "��";
			}
			else {
				;
			}
			switch (m) {
				case 9:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 7:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 5:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 2:
					cout << "��";
					break;
				case 1:
					cout << "Ҽ";
					break;
				case 0:
					break;
			}
		}
		else if (i != 0 && j == 0 && k == 0 && m == 0) { //1000
			switch (i) {
				case 9:
					cout << "��Ǫ";
					break;
				case 8:
					cout << "��Ǫ";
					break;
				case 7:
					cout << "��Ǫ";
					break;
				case 6:
					cout << "½Ǫ";
					break;
				case 5:
					cout << "��Ǫ";
					break;
				case 4:
					cout << "��Ǫ";
					break;
				case 3:
					cout << "��Ǫ";
					break;
				case 2:
					cout << "��Ǫ";
					break;
				case 1:
					cout << "ҼǪ";
					break;
			}
		}
		else if (i == 0 && j == 0 && k != 0 && m != 0) { //0011
			if (!x) {
				cout << "��";
			}
			else {
				;
			}
			switch (k) {
				case 9:
					cout << "��ʰ";
					break;
				case 8:
					cout << "��ʰ";
					break;
				case 7:
					cout << "��ʰ";
					break;
				case 6:
					cout << "½ʰ";
					break;
				case 5:
					cout << "��ʰ";
					break;
				case 4:
					cout << "��ʰ";
					break;
				case 3:
					cout << "��ʰ";
					break;
				case 2:
					cout << "��ʰ";
					break;
				case 1:
					cout << "Ҽʰ";
					break;
			}
			switch (m) {
				case 9:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 7:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 5:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 2:
					cout << "��";
					break;
				case 1:
					cout << "Ҽ";
					break;
			}
		}
		else if (i != 0 && j == 0 && k == 0 && m != 0) { //1001
			switch (i) {
				case 9:
					cout << "��Ǫ";
					break;
				case 8:
					cout << "��Ǫ";
					break;
				case 7:
					cout << "��Ǫ";
					break;
				case 6:
					cout << "½Ǫ";
					break;
				case 5:
					cout << "��Ǫ";
					break;
				case 4:
					cout << "��Ǫ";
					break;
				case 3:
					cout << "��Ǫ";
					break;
				case 2:
					cout << "��Ǫ";
					break;
				case 1:
					cout << "ҼǪ";
					break;
			}
			cout << "��";
			switch (m) {
				case 9:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 7:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 5:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 2:
					cout << "��";
					break;
				case 1:
					cout << "Ҽ";
					break;
			}
		}
		else if (i != 0 && j != 0 && k == 0 && m == 0) { //1100
			switch (i) {
				case 9:
					cout << "��Ǫ";
					break;
				case 8:
					cout << "��Ǫ";
					break;
				case 7:
					cout << "��Ǫ";
					break;
				case 6:
					cout << "½Ǫ";
					break;
				case 5:
					cout << "��Ǫ";
					break;
				case 4:
					cout << "��Ǫ";
					break;
				case 3:
					cout << "��Ǫ";
					break;
				case 2:
					cout << "��Ǫ";
					break;
				case 1:
					cout << "ҼǪ";
					break;
			}
			switch (j) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ư�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
					break;
			}
		}
		else if (i == 0 && j != 0 && k == 0 && m == 0) { //0100
			if (!x) {
				cout << "��";
			}
			else {
				;
			}
			switch (j) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ư�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
					break;
			}
		}
		else if (i == 0 && j == 0 && k != 0 && m == 0) { //0010
			if (!x) {
				cout << "��";
			}
			else {
				;
			}
				switch (k) {
					case 9:
						cout << "��ʰ";
						break;
					case 8:
						cout << "��ʰ";
						break;
					case 7:
						cout << "��ʰ";
						break;
					case 6:
						cout << "½ʰ";
						break;
					case 5:
						cout << "��ʰ";
						break;
					case 4:
						cout << "��ʰ";
						break;
					case 3:
						cout << "��ʰ";
						break;
					case 2:
						cout << "��ʰ";
						break;
					case 1:
						cout << "Ҽʰ";
						break;
				}
			
		}
		else if (i == 0 && j != 0 && k == 0 && m != 0) { //0101
			if (!x) {
				cout << "��";
			}
			switch (j) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ư�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
			}
			cout << "��";
			switch (m) {
				case 9:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 7:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 5:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 2:
					cout << "��";
					break;
				case 1:
					cout << "Ҽ";
					break;
			}
		}
		else if (i == 0 && j != 0 && k != 0 && m == 0) { //0110
			if (!x) {
				cout << "��";
			}
			switch (j) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ư�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
			}
			switch (k) {
				case 9:
					cout << "��ʰ";
					break;
				case 8:
					cout << "��ʰ";
					break;
				case 7:
					cout << "��ʰ";
					break;
				case 6:
					cout << "½ʰ";
					break;
				case 5:
					cout << "��ʰ";
					break;
				case 4:
					cout << "��ʰ";
					break;
				case 3:
					cout << "��ʰ";
					break;
				case 2:
					cout << "��ʰ";
					break;
				case 1:
					cout << "Ҽʰ";
					break;
				case 0:
					break;
			}
			}
		else {
			switch (i) {
				case 9:
					cout << "��Ǫ";
					break;
				case 8:
					cout << "��Ǫ";
					break;
				case 7:
					cout << "��Ǫ";
					break;
				case 6:
					cout << "½Ǫ";
					break;
				case 5:
					cout << "��Ǫ";
					break;
				case 4:
					cout << "��Ǫ";
					break;
				case 3:
					cout << "��Ǫ";
					break;
				case 2:
					cout << "��Ǫ";
					break;
				case 1:
					cout << "ҼǪ";
					break;
				case 0:
					cout << "��";
					break;
			}
			switch (j) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ư�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
				case 0:
					cout << "��";
					break;
			}
			switch (k) {
				case 9:
					cout << "��ʰ";
					break;
				case 8:
					cout << "��ʰ";
					break;
				case 7:
					cout << "��ʰ";
					break;
				case 6:
					cout << "½ʰ";
					break;
				case 5:
					cout << "��ʰ";
					break;
				case 4:
					cout << "��ʰ";
					break;
				case 3:
					cout << "��ʰ";
					break;
				case 2:
					cout << "��ʰ";
					break;
				case 1:
					cout << "Ҽʰ";
					break;
				case 0:
					cout << "��";
			}
			switch (m) {
				case 9:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 7:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 5:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 2:
					cout << "��";
					break;
				case 1:
					cout << "Ҽ";
					break;
				case 0:
					break;
			}
		}
		cout << "Բ";
		if (p == 0) {
			switch (n) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ƽ�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
					break;
				case 0:
					break;
			}
			cout << "��";
		}
		else {
			switch (n) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ƽ�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
					break;
				case 0:
					cout << "��";
					break;
			}
			switch (p) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�Ʒ�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
					break;
				case 0:
					break;
			}
		}
	}
	else {
		if (n == 0 && p == 0) {
			cout << "��Բ��";
		}
		else if (n != 0 && p == 0) {
			switch (n) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ƽ�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
					break;
				case 0:
					break;
			}
			cout << "��";
		}
		else {
			switch (n) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�ƽ�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
					break;
				case 0:
					break;
			}
			switch (p) {
				case 9:
					cout << "����";
					break;
				case 8:
					cout << "�Ʒ�";
					break;
				case 7:
					cout << "���";
					break;
				case 6:
					cout << "½��";
					break;
				case 5:
					cout << "���";
					break;
				case 4:
					cout << "����";
					break;
				case 3:
					cout << "����";
					break;
				case 2:
					cout << "����";
					break;
				case 1:
					cout << "Ҽ��";
					break;
				case 0:
					break;
			}
		}
	}
	cout << endl;

	return 0;
}