/*2351892 ��11 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a;
	int b, c, d, e, f, g, h, i, j, k, m, n, p;
	int x, y;
	printf( "������[0-100��)֮�������:\n");
	scanf("%lf",&a);
	printf("��д�����:\n") ;
	b = (int)(a / 10);
	a = (a - (double)(b) * 10) * 100;
	c = b / 100000000;//ʮ��
	d = b % 100000000 / 10000000;//��
	e = b % 10000000 / 1000000;//ǧ��
	f = b % 1000000 / 100000;//����
	g = b % 100000 / 10000;//ʮ��
	h = b % 10000 / 1000;//��
	i = b % 1000 / 100;//ǧ
	j = b % 100 / 10;//��
	k = b % 10;//ʮ
	m = (int)(a / 100);//Բ
	n = (int)(a + 0.0001) % 100 / 10;//��
	p = (int)(a + 0.0001) % 10;//��
	y = c == 0 && d == 0;
	x = c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0;
	if (c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0 || k != 0 || m != 0) {
		if (c == 0 && d == 0) {
			;
		}
		else {
			switch (c) {
				case 9:
					printf("��ʰ");
					break;
				case 8:
					printf("��ʰ");
					break;
				case 7:
					printf("��ʰ");
					break;
				case 6:
					printf("½ʰ");
					break;
				case 5:
					printf("��ʰ");
					break;
				case 4:
					printf("��ʰ");
					break;
				case 3:
					printf("��ʰ");
					break;
				case 2:
					printf("��ʰ");
					break;
				case 1:
					printf("Ҽʰ");
					break;
				case 0:
					break;
			}
			switch (d) {
				case 9:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 7:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 5:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 1:
					printf("Ҽ");
					break;
				case 0:
					break;
			}
			printf("��");
		}
		if (e == 0 && f == 0 && g == 0 && h == 0) {   //0000
			;
		}
		else if (e == 0 && f == 0 && g == 0 && h != 0) { //0001
			if (!y) {
				printf("��");
			}
			else {
				;
			}
			switch (h) {
				case 9:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 7:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 5:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 1:
					printf("Ҽ");
					break;
			}
			printf("��");
		}
		else if (e != 0 && f == 0 && g == 0 && h == 0) { //1000
			switch (e) {
				case 9:
					printf("��Ǫ");
					break;
				case 8:
					printf("��Ǫ");
					break;
				case 7:
					printf("��Ǫ");
					break;
				case 6:
					printf("½Ǫ");
					break;
				case 5:
					printf("��Ǫ");
					break;
				case 4:
					printf("��Ǫ");
					break;
				case 3:
					printf("��Ǫ");
					break;
				case 2:
					printf("��Ǫ");
					break;
				case 1:
					printf("ҼǪ");
					break;
			}
			printf("��");
		}
		else if (e == 0 && f == 0 && g != 0 && h != 0) { //0011
			if (!y) {
				printf("��");
			}
			else {
				;
			}
			switch (g) {
				case 9:
					printf("��ʰ");
					break;
				case 8:
					printf("��ʰ");
					break;
				case 7:
					printf("��ʰ");
					break;
				case 6:
					printf("½ʰ");
					break;
				case 5:
					printf("��ʰ");
					break;
				case 4:
					printf("��ʰ");
					break;
				case 3:
					printf("��ʰ");
					break;
				case 2:
					printf("��ʰ");
					break;
				case 1:
					printf("Ҽʰ");
					break;
			}
			switch (h) {
				case 9:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 7:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 5:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 1:
					printf("Ҽ");
					break;
			}
			printf("��");
		}
		else if (e != 0 && f == 0 && g == 0 && h != 0) { //1001
			switch (e) {
				case 9:
					printf("��Ǫ");
					break;
				case 8:
					printf("��Ǫ");
					break;
				case 7:
					printf("��Ǫ");
					break;
				case 6:
					printf("½Ǫ");
					break;
				case 5:
					printf("��Ǫ");
					break;
				case 4:
					printf("��Ǫ");
					break;
				case 3:
					printf("��Ǫ");
					break;
				case 2:
					printf("��Ǫ");
					break;
				case 1:
					printf("ҼǪ");
					break;
			}
			printf("��");
			switch (h) {
				case 9:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 7:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 5:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 1:
					printf("Ҽ");
					break;
			}
			printf("��");
		}
		else if (e != 0 && f != 0 && g == 0 && h == 0) { //1100
			switch (e) {
				case 9:
					printf("��Ǫ");
					break;
				case 8:
					printf("��Ǫ");
					break;
				case 7:
					printf("��Ǫ");
					break;
				case 6:
					printf("½Ǫ");
					break;
				case 5:
					printf("��Ǫ");
					break;
				case 4:
					printf("��Ǫ");
					break;
				case 3:
					printf("��Ǫ");
					break;
				case 2:
					printf("��Ǫ");
					break;
				case 1:
					printf("ҼǪ");
					break;
			}
			switch (f) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ư�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
					break;
			}
			printf("��");
		}
		else if (e == 0 && f != 0 && g == 0 && h == 0) { //0100
			if (!y) {
				printf("��");
			}
			else {
				;
			}
			switch (f) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ư�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
					break;
			}
			printf("��");
		}
		else if (e == 0 && f == 0 && g != 0 && h == 0) { //0010
			if (!y) {
				printf("��");
			}
			else {
				;
			}
			switch (g) {
				case 9:
					printf("��ʰ");
					break;
				case 8:
					printf("��ʰ");
					break;
				case 7:
					printf("��ʰ");
					break;
				case 6:
					printf("½ʰ");
					break;
				case 5:
					printf("��ʰ");
					break;
				case 4:
					printf("��ʰ");
					break;
				case 3:
					printf("��ʰ");
					break;
				case 2:
					printf("��ʰ");
					break;
				case 1:
					printf("Ҽʰ");
					break;
			}
			printf("��");
		}
		else if (e == 0 && f != 0 && g == 0 && h != 0) { //0101
			if (!y) {
				printf("��");
			}
			switch (f) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ư�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
			}
			printf("��");
			switch (h) {
				case 9:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 7:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 5:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 1:
					printf("Ҽ");
					break;
				case 0:
					break;
			}
			printf("��");
		}
		else if (e == 0 && f != 0 && g != 0 && h == 0) { //0110
			if (!y) {
				printf("��");
			}
			switch (f) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ư�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
			}
			switch (g) {
				case 9:
					printf("��ʰ");
					break;
				case 8:
					printf("��ʰ");
					break;
				case 7:
					printf("��ʰ");
					break;
				case 6:
					printf("½ʰ");
					break;
				case 5:
					printf("��ʰ");
					break;
				case 4:
					printf("��ʰ");
					break;
				case 3:
					printf("��ʰ");
					break;
				case 2:
					printf("��ʰ");
					break;
				case 1:
					printf("Ҽʰ");
					break;
				case 0:
					break;
			}
			printf("��");
		}
		else {
			switch (e) {
				case 9:
					printf("��Ǫ");
					break;
				case 8:
					printf("��Ǫ");
					break;
				case 7:
					printf("��Ǫ");
					break;
				case 6:
					printf("½Ǫ");
					break;
				case 5:
					printf("��Ǫ");
					break;
				case 4:
					printf("��Ǫ");
					break;
				case 3:
					printf("��Ǫ");
					break;
				case 2:
					printf("��Ǫ");
					break;
				case 1:
					printf("ҼǪ");
					break;
				case 0:
					printf("��");
					break;
			}
			switch (f) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ư�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
				case 0:
					printf("��");
					break;
			}
			switch (g) {
				case 9:
					printf("��ʰ");
					break;
				case 8:
					printf("��ʰ");
					break;
				case 7:
					printf("��ʰ");
					break;
				case 6:
					printf("½ʰ");
					break;
				case 5:
					printf("��ʰ");
					break;
				case 4:
					printf("��ʰ");
					break;
				case 3:
					printf("��ʰ");
					break;
				case 2:
					printf("��ʰ");
					break;
				case 1:
					printf("Ҽʰ");
					break;
				case 0:
					break;
			}
			switch (h) {
				case 9:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 7:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 5:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 1:
					printf("Ҽ");
					break;
				case 0:
					break;
			}
			printf("��");
		}
		if (i == 0 && j == 0 && k == 0 && m == 0) {   //0000
			;
		}
		else if (i == 0 && j == 0 && k == 0 && m != 0) { //0001
			if (!x) {
				printf("��");
			}
			else {
				;
			}
			switch (m) {
				case 9:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 7:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 5:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 1:
					printf("Ҽ");
					break;
				case 0:
					break;
			}
		}
		else if (i != 0 && j == 0 && k == 0 && m == 0) { //1000
			switch (i) {
				case 9:
					printf("��Ǫ");
					break;
				case 8:
					printf("��Ǫ");
					break;
				case 7:
					printf("��Ǫ");
					break;
				case 6:
					printf("½Ǫ");
					break;
				case 5:
					printf("��Ǫ");
					break;
				case 4:
					printf("��Ǫ");
					break;
				case 3:
					printf("��Ǫ");
					break;
				case 2:
					printf("��Ǫ");
					break;
				case 1:
					printf("ҼǪ");
					break;
			}
		}
		else if (i == 0 && j == 0 && k != 0 && m != 0) { //0011
			if (!x) {
				printf("��");
			}
			else {
				;
			}
			switch (k) {
				case 9:
					printf("��ʰ");
					break;
				case 8:
					printf("��ʰ");
					break;
				case 7:
					printf("��ʰ");
					break;
				case 6:
					printf("½ʰ");
					break;
				case 5:
					printf("��ʰ");
					break;
				case 4:
					printf("��ʰ");
					break;
				case 3:
					printf("��ʰ");
					break;
				case 2:
					printf("��ʰ");
					break;
				case 1:
					printf("Ҽʰ");
					break;
			}
			switch (m) {
				case 9:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 7:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 5:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 1:
					printf("Ҽ");
					break;
			}
		}
		else if (i != 0 && j == 0 && k == 0 && m != 0) { //1001
			switch (i) {
				case 9:
					printf("��Ǫ");
					break;
				case 8:
					printf("��Ǫ");
					break;
				case 7:
					printf("��Ǫ");
					break;
				case 6:
					printf("½Ǫ");
					break;
				case 5:
					printf("��Ǫ");
					break;
				case 4:
					printf("��Ǫ");
					break;
				case 3:
					printf("��Ǫ");
					break;
				case 2:
					printf("��Ǫ");
					break;
				case 1:
					printf("ҼǪ");
					break;
			}
			printf("��");
			switch (m) {
				case 9:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 7:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 5:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 1:
					printf("Ҽ");
					break;
			}
		}
		else if (i != 0 && j != 0 && k == 0 && m == 0) { //1100
			switch (i) {
				case 9:
					printf("��Ǫ");
					break;
				case 8:
					printf("��Ǫ");
					break;
				case 7:
					printf("��Ǫ");
					break;
				case 6:
					printf("½Ǫ");
					break;
				case 5:
					printf("��Ǫ");
					break;
				case 4:
					printf("��Ǫ");
					break;
				case 3:
					printf("��Ǫ");
					break;
				case 2:
					printf("��Ǫ");
					break;
				case 1:
					printf("ҼǪ");
					break;
			}
			switch (j) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ư�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
					break;
			}
		}
		else if (i == 0 && j != 0 && k == 0 && m == 0) { //0100
			if (!x) {
				printf("��");
			}
			else {
				;
			}
			switch (j) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ư�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
					break;
			}
		}
		else if (i == 0 && j == 0 && k != 0 && m == 0) { //0010
			if (!x) {
				printf("��");
			}
			else {
				;
			}
			switch (k) {
				case 9:
					printf("��ʰ");
					break;
				case 8:
					printf("��ʰ");
					break;
				case 7:
					printf("��ʰ");
					break;
				case 6:
					printf("½ʰ");
					break;
				case 5:
					printf("��ʰ");
					break;
				case 4:
					printf("��ʰ");
					break;
				case 3:
					printf("��ʰ");
					break;
				case 2:
					printf("��ʰ");
					break;
				case 1:
					printf("Ҽʰ");
					break;
			}

		}
		else if (i == 0 && j != 0 && k == 0 && m != 0) { //0101
			if (!x) {
				printf("��");
			}
			switch (j) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ư�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
			}
			printf("��");
			switch (m) {
				case 9:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 7:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 5:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 1:
					printf("Ҽ");
					break;
			}
		}
		else if (i == 0 && j != 0 && k != 0 && m == 0) { //0110
			if (!x) {
				printf("��");
			}
			switch (j) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ư�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
			}
			switch (k) {
				case 9:
					printf("��ʰ");
					break;
				case 8:
					printf("��ʰ");
					break;
				case 7:
					printf("��ʰ");
					break;
				case 6:
					printf("½ʰ");
					break;
				case 5:
					printf("��ʰ");
					break;
				case 4:
					printf("��ʰ");
					break;
				case 3:
					printf("��ʰ");
					break;
				case 2:
					printf("��ʰ");
					break;
				case 1:
					printf("Ҽʰ");
					break;
				case 0:
					break;
			}
		}
		else {
			switch (i) {
				case 9:
					printf("��Ǫ");
					break;
				case 8:
					printf("��Ǫ");
					break;
				case 7:
					printf("��Ǫ");
					break;
				case 6:
					printf("½Ǫ");
					break;
				case 5:
					printf("��Ǫ");
					break;
				case 4:
					printf("��Ǫ");
					break;
				case 3:
					printf("��Ǫ");
					break;
				case 2:
					printf("��Ǫ");
					break;
				case 1:
					printf("ҼǪ");
					break;
				case 0:
					printf("��");
					break;
			}
			switch (j) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ư�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
				case 0:
					printf("��");
					break;
			}
			switch (k) {
				case 9:
					printf("��ʰ");
					break;
				case 8:
					printf("��ʰ");
					break;
				case 7:
					printf("��ʰ");
					break;
				case 6:
					printf("½ʰ");
					break;
				case 5:
					printf("��ʰ");
					break;
				case 4:
					printf("��ʰ");
					break;
				case 3:
					printf("��ʰ");
					break;
				case 2:
					printf("��ʰ");
					break;
				case 1:
					printf("Ҽʰ");
					break;
				case 0:
					printf("��");
			}
			switch (m) {
				case 9:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 7:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 5:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 2:
					printf("��");
					break;
				case 1:
					printf("Ҽ");
					break;
				case 0:
					break;
			}
		}
		printf("Բ");
		if (p == 0) {
			switch (n) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ƽ�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
					break;
				case 0:
					break;
			}
			printf("��");
		}
		else {
			switch (n) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ƽ�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
					break;
				case 0:
					printf("��");
					break;
			}
			switch (p) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�Ʒ�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
					break;
				case 0:
					break;
			}
		}
	}
	else {
		if (n == 0 && p == 0) {
			printf("��Բ��");
		}
		else if (n != 0 && p == 0) {
			switch (n) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ƽ�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
					break;
				case 0:
					break;
			}
			printf("��");
		}
		else {
			switch (n) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�ƽ�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
					break;
				case 0:
					break;
			}
			switch (p) {
				case 9:
					printf("����");
					break;
				case 8:
					printf("�Ʒ�");
					break;
				case 7:
					printf("���");
					break;
				case 6:
					printf("½��");
					break;
				case 5:
					printf("���");
					break;
				case 4:
					printf("����");
					break;
				case 3:
					printf("����");
					break;
				case 2:
					printf("����");
					break;
				case 1:
					printf("Ҽ��");
					break;
				case 0:
					break;
			}
		}
	}
	printf("\n");
	return 0;
	}