/*2351892 ��11 ������*/
/* ѧ�� ���� �༶ */
#include <iostream>
#include<limits>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
/*���ȶ����ֽ��зֽ�*/
double a;
int b, c, d, e, f, g, h, i, j, k, m, n, p;
int x, y, z;
while (1) {
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	if (cin.fail()) {
		cin.clear();//����������Ĵ����־���Ա������ȡ���롣
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//������������ֱ����ĩβ���������ݣ��������з�('\n')����ȷ������������ղ�׼�������µ�����
	}
	else {

		if (a >= 0 && a < 10000000000)
			break;
		else {
			continue;
		}
	}
}
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
x = c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0;
z = c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k==0 && m == 0;
int state_1 = 0, state_2 = 0, state_3 = 0;/*����state_n����ʼΪ0����һ�������1*/
if (a == 0 && b == 0) {
	daxie(m, 1);
	cout << "Բ��";
}

else {
	//�Ƚ���ʰ�ڵ��ڣ�state_1��Ϊ0
	daxie(c, state_1);
	if (c != 0) {
		cout << "ʰ";
	}
	daxie(d, state_2);
	if (!y) {
		cout << "��";
	}
	//�ٽ���Ǫ����state_2����0��1����λʼ��Ϊ0

	if (f != 0) {
		state_2 = 1;
	}
	if (y) {
		state_2 = 0;
	}
	daxie(e, state_2);
	state_2 = 0;
	if (e != 0) {
		cout << "Ǫ";
	}
	if (g != 0) {
		state_2 = 1;
	}
	if (y && e == 0) {
		state_2 = 0;
	}
	daxie(f, state_2);
	
	if (f != 0) {
		cout << "��";
	}
	if (h != 0) {
		state_2 = 1;
	}
	if (y && e == 0&&f==0) {
		state_2 = 0;
	}
	daxie(g, state_2);
	
	if (g != 0) {
		cout << "ʰ";
	}
	daxie(h, 0);
	if (e != 0 || f != 0 || g != 0 || h != 0) {
		cout << "��";
	}
	//�ٽ���Ǫ��Բ��state_3����0��1��Բλʼ��Ϊ0

	if (j != 0) {
		state_3 = 1;
	}
	if (x) {
		state_3 = 0;
	}
	daxie(i, state_3);
	state_3 = 0;
	if (i != 0) {
		cout << "Ǫ";
	}
	if (k != 0) {
		state_3 = 1;
	}
	if (x && i == 0) {
		state_3 = 0;
	}
	daxie(j, state_3);

	if (j != 0) {
		cout << "��";
	}
	if (m != 0) {
		state_3 = 1;
	}
	if (x && i == 0&&j==0) {
		state_3 = 0;
	}
	daxie(k, state_3);

	if (k != 0) {
		cout << "ʰ";
	}
	daxie(m, 0);
	if (!z) {
		cout << "Բ";
	}
	//�ٽ���С��λ
	if (!z) {
		if (n == 0 && p == 0) {
			cout << "��";
		}
		else if (n != 0 && p == 0) {
			daxie(n, 0);
			cout << "����";
		}
		else if (n == 0 && p != 0) {
			daxie(n, 1);
			daxie(p, 0);
			cout << "��";
		}
		else {
			daxie(n, 0);
			cout << "��";
			daxie(p, 0);
			cout << "��";
		}

	}
	else {
		if (n != 0 && p == 0) {
			daxie(n, 0);
			cout << "����";
		}
		else if (n == 0 && p != 0) {
			daxie(n, 0);
			daxie(p, 0);
			cout << "��";
		}
		else {
			daxie(n, 0);
			cout << "��";
			daxie(p, 0);
			cout << "��";
		}

	}
}
cout << endl;

	/* ������� */
	return 0;
}
