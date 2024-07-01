/*2351892 ÐÅ11 ³ÂÞÈìÅ*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	double a;
	int b, c, d, e, f, g, h, i, j, k, m, n, p;
	int x, y;
	printf( "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
	scanf("%lf",&a);
	printf("´óÐ´½á¹ûÊÇ:\n") ;
	b = (int)(a / 10);
	a = (a - (double)(b) * 10) * 100;
	c = b / 100000000;//Ê®ÒÚ
	d = b % 100000000 / 10000000;//ÒÚ
	e = b % 10000000 / 1000000;//Ç§Íò
	f = b % 1000000 / 100000;//°ÙÍò
	g = b % 100000 / 10000;//Ê®Íò
	h = b % 10000 / 1000;//Íò
	i = b % 1000 / 100;//Ç§
	j = b % 100 / 10;//°Ù
	k = b % 10;//Ê®
	m = (int)(a / 100);//Ô²
	n = (int)(a + 0.0001) % 100 / 10;//½Ç
	p = (int)(a + 0.0001) % 10;//·Ö
	y = c == 0 && d == 0;
	x = c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0;
	if (c != 0 || d != 0 || e != 0 || f != 0 || g != 0 || h != 0 || i != 0 || j != 0 || k != 0 || m != 0) {
		if (c == 0 && d == 0) {
			;
		}
		else {
			switch (c) {
				case 9:
					printf("¾ÁÊ°");
					break;
				case 8:
					printf("°ÆÊ°");
					break;
				case 7:
					printf("ÆâÊ°");
					break;
				case 6:
					printf("Â½Ê°");
					break;
				case 5:
					printf("ÎéÊ°");
					break;
				case 4:
					printf("ËÁÊ°");
					break;
				case 3:
					printf("ÈþÊ°");
					break;
				case 2:
					printf("·¡Ê°");
					break;
				case 1:
					printf("Ò¼Ê°");
					break;
				case 0:
					break;
			}
			switch (d) {
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
				case 0:
					break;
			}
			printf("ÒÚ");
		}
		if (e == 0 && f == 0 && g == 0 && h == 0) {   //0000
			;
		}
		else if (e == 0 && f == 0 && g == 0 && h != 0) { //0001
			if (!y) {
				printf("Áã");
			}
			else {
				;
			}
			switch (h) {
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			printf("Íò");
		}
		else if (e != 0 && f == 0 && g == 0 && h == 0) { //1000
			switch (e) {
				case 9:
					printf("¾ÁÇª");
					break;
				case 8:
					printf("°ÆÇª");
					break;
				case 7:
					printf("ÆâÇª");
					break;
				case 6:
					printf("Â½Çª");
					break;
				case 5:
					printf("ÎéÇª");
					break;
				case 4:
					printf("ËÁÇª");
					break;
				case 3:
					printf("ÈþÇª");
					break;
				case 2:
					printf("·¡Çª");
					break;
				case 1:
					printf("Ò¼Çª");
					break;
			}
			printf("Íò");
		}
		else if (e == 0 && f == 0 && g != 0 && h != 0) { //0011
			if (!y) {
				printf("Áã");
			}
			else {
				;
			}
			switch (g) {
				case 9:
					printf("¾ÁÊ°");
					break;
				case 8:
					printf("°ÆÊ°");
					break;
				case 7:
					printf("ÆâÊ°");
					break;
				case 6:
					printf("Â½Ê°");
					break;
				case 5:
					printf("ÎéÊ°");
					break;
				case 4:
					printf("ËÁÊ°");
					break;
				case 3:
					printf("ÈþÊ°");
					break;
				case 2:
					printf("·¡Ê°");
					break;
				case 1:
					printf("Ò¼Ê°");
					break;
			}
			switch (h) {
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			printf("Íò");
		}
		else if (e != 0 && f == 0 && g == 0 && h != 0) { //1001
			switch (e) {
				case 9:
					printf("¾ÁÇª");
					break;
				case 8:
					printf("°ÆÇª");
					break;
				case 7:
					printf("ÆâÇª");
					break;
				case 6:
					printf("Â½Çª");
					break;
				case 5:
					printf("ÎéÇª");
					break;
				case 4:
					printf("ËÁÇª");
					break;
				case 3:
					printf("ÈþÇª");
					break;
				case 2:
					printf("·¡Çª");
					break;
				case 1:
					printf("Ò¼Çª");
					break;
			}
			printf("Áã");
			switch (h) {
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
			printf("Íò");
		}
		else if (e != 0 && f != 0 && g == 0 && h == 0) { //1100
			switch (e) {
				case 9:
					printf("¾ÁÇª");
					break;
				case 8:
					printf("°ÆÇª");
					break;
				case 7:
					printf("ÆâÇª");
					break;
				case 6:
					printf("Â½Çª");
					break;
				case 5:
					printf("ÎéÇª");
					break;
				case 4:
					printf("ËÁÇª");
					break;
				case 3:
					printf("ÈþÇª");
					break;
				case 2:
					printf("·¡Çª");
					break;
				case 1:
					printf("Ò¼Çª");
					break;
			}
			switch (f) {
				case 9:
					printf("¾Á°Û");
					break;
				case 8:
					printf("°Æ°Û");
					break;
				case 7:
					printf("Æâ°Û");
					break;
				case 6:
					printf("Â½°Û");
					break;
				case 5:
					printf("Îé°Û");
					break;
				case 4:
					printf("ËÁ°Û");
					break;
				case 3:
					printf("Èþ°Û");
					break;
				case 2:
					printf("·¡°Û");
					break;
				case 1:
					printf("Ò¼°Û");
					break;
			}
			printf("Íò");
		}
		else if (e == 0 && f != 0 && g == 0 && h == 0) { //0100
			if (!y) {
				printf("Áã");
			}
			else {
				;
			}
			switch (f) {
				case 9:
					printf("¾Á°Û");
					break;
				case 8:
					printf("°Æ°Û");
					break;
				case 7:
					printf("Æâ°Û");
					break;
				case 6:
					printf("Â½°Û");
					break;
				case 5:
					printf("Îé°Û");
					break;
				case 4:
					printf("ËÁ°Û");
					break;
				case 3:
					printf("Èþ°Û");
					break;
				case 2:
					printf("·¡°Û");
					break;
				case 1:
					printf("Ò¼°Û");
					break;
			}
			printf("Íò");
		}
		else if (e == 0 && f == 0 && g != 0 && h == 0) { //0010
			if (!y) {
				printf("Áã");
			}
			else {
				;
			}
			switch (g) {
				case 9:
					printf("¾ÁÊ°");
					break;
				case 8:
					printf("°ÆÊ°");
					break;
				case 7:
					printf("ÆâÊ°");
					break;
				case 6:
					printf("Â½Ê°");
					break;
				case 5:
					printf("ÎéÊ°");
					break;
				case 4:
					printf("ËÁÊ°");
					break;
				case 3:
					printf("ÈþÊ°");
					break;
				case 2:
					printf("·¡Ê°");
					break;
				case 1:
					printf("Ò¼Ê°");
					break;
			}
			printf("Íò");
		}
		else if (e == 0 && f != 0 && g == 0 && h != 0) { //0101
			if (!y) {
				printf("Áã");
			}
			switch (f) {
				case 9:
					printf("¾Á°Û");
					break;
				case 8:
					printf("°Æ°Û");
					break;
				case 7:
					printf("Æâ°Û");
					break;
				case 6:
					printf("Â½°Û");
					break;
				case 5:
					printf("Îé°Û");
					break;
				case 4:
					printf("ËÁ°Û");
					break;
				case 3:
					printf("Èþ°Û");
					break;
				case 2:
					printf("·¡°Û");
					break;
				case 1:
					printf("Ò¼°Û");
			}
			printf("Áã");
			switch (h) {
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
				case 0:
					break;
			}
			printf("Íò");
		}
		else if (e == 0 && f != 0 && g != 0 && h == 0) { //0110
			if (!y) {
				printf("Áã");
			}
			switch (f) {
				case 9:
					printf("¾Á°Û");
					break;
				case 8:
					printf("°Æ°Û");
					break;
				case 7:
					printf("Æâ°Û");
					break;
				case 6:
					printf("Â½°Û");
					break;
				case 5:
					printf("Îé°Û");
					break;
				case 4:
					printf("ËÁ°Û");
					break;
				case 3:
					printf("Èþ°Û");
					break;
				case 2:
					printf("·¡°Û");
					break;
				case 1:
					printf("Ò¼°Û");
			}
			switch (g) {
				case 9:
					printf("¾ÁÊ°");
					break;
				case 8:
					printf("°ÆÊ°");
					break;
				case 7:
					printf("ÆâÊ°");
					break;
				case 6:
					printf("Â½Ê°");
					break;
				case 5:
					printf("ÎéÊ°");
					break;
				case 4:
					printf("ËÁÊ°");
					break;
				case 3:
					printf("ÈþÊ°");
					break;
				case 2:
					printf("·¡Ê°");
					break;
				case 1:
					printf("Ò¼Ê°");
					break;
				case 0:
					break;
			}
			printf("Íò");
		}
		else {
			switch (e) {
				case 9:
					printf("¾ÁÇª");
					break;
				case 8:
					printf("°ÆÇª");
					break;
				case 7:
					printf("ÆâÇª");
					break;
				case 6:
					printf("Â½Çª");
					break;
				case 5:
					printf("ÎéÇª");
					break;
				case 4:
					printf("ËÁÇª");
					break;
				case 3:
					printf("ÈþÇª");
					break;
				case 2:
					printf("·¡Çª");
					break;
				case 1:
					printf("Ò¼Çª");
					break;
				case 0:
					printf("Áã");
					break;
			}
			switch (f) {
				case 9:
					printf("¾Á°Û");
					break;
				case 8:
					printf("°Æ°Û");
					break;
				case 7:
					printf("Æâ°Û");
					break;
				case 6:
					printf("Â½°Û");
					break;
				case 5:
					printf("Îé°Û");
					break;
				case 4:
					printf("ËÁ°Û");
					break;
				case 3:
					printf("Èþ°Û");
					break;
				case 2:
					printf("·¡°Û");
					break;
				case 1:
					printf("Ò¼°Û");
				case 0:
					printf("Áã");
					break;
			}
			switch (g) {
				case 9:
					printf("¾ÁÊ°");
					break;
				case 8:
					printf("°ÆÊ°");
					break;
				case 7:
					printf("ÆâÊ°");
					break;
				case 6:
					printf("Â½Ê°");
					break;
				case 5:
					printf("ÎéÊ°");
					break;
				case 4:
					printf("ËÁÊ°");
					break;
				case 3:
					printf("ÈþÊ°");
					break;
				case 2:
					printf("·¡Ê°");
					break;
				case 1:
					printf("Ò¼Ê°");
					break;
				case 0:
					break;
			}
			switch (h) {
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
				case 0:
					break;
			}
			printf("Íò");
		}
		if (i == 0 && j == 0 && k == 0 && m == 0) {   //0000
			;
		}
		else if (i == 0 && j == 0 && k == 0 && m != 0) { //0001
			if (!x) {
				printf("Áã");
			}
			else {
				;
			}
			switch (m) {
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
				case 0:
					break;
			}
		}
		else if (i != 0 && j == 0 && k == 0 && m == 0) { //1000
			switch (i) {
				case 9:
					printf("¾ÁÇª");
					break;
				case 8:
					printf("°ÆÇª");
					break;
				case 7:
					printf("ÆâÇª");
					break;
				case 6:
					printf("Â½Çª");
					break;
				case 5:
					printf("ÎéÇª");
					break;
				case 4:
					printf("ËÁÇª");
					break;
				case 3:
					printf("ÈþÇª");
					break;
				case 2:
					printf("·¡Çª");
					break;
				case 1:
					printf("Ò¼Çª");
					break;
			}
		}
		else if (i == 0 && j == 0 && k != 0 && m != 0) { //0011
			if (!x) {
				printf("Áã");
			}
			else {
				;
			}
			switch (k) {
				case 9:
					printf("¾ÁÊ°");
					break;
				case 8:
					printf("°ÆÊ°");
					break;
				case 7:
					printf("ÆâÊ°");
					break;
				case 6:
					printf("Â½Ê°");
					break;
				case 5:
					printf("ÎéÊ°");
					break;
				case 4:
					printf("ËÁÊ°");
					break;
				case 3:
					printf("ÈþÊ°");
					break;
				case 2:
					printf("·¡Ê°");
					break;
				case 1:
					printf("Ò¼Ê°");
					break;
			}
			switch (m) {
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
		}
		else if (i != 0 && j == 0 && k == 0 && m != 0) { //1001
			switch (i) {
				case 9:
					printf("¾ÁÇª");
					break;
				case 8:
					printf("°ÆÇª");
					break;
				case 7:
					printf("ÆâÇª");
					break;
				case 6:
					printf("Â½Çª");
					break;
				case 5:
					printf("ÎéÇª");
					break;
				case 4:
					printf("ËÁÇª");
					break;
				case 3:
					printf("ÈþÇª");
					break;
				case 2:
					printf("·¡Çª");
					break;
				case 1:
					printf("Ò¼Çª");
					break;
			}
			printf("Áã");
			switch (m) {
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
		}
		else if (i != 0 && j != 0 && k == 0 && m == 0) { //1100
			switch (i) {
				case 9:
					printf("¾ÁÇª");
					break;
				case 8:
					printf("°ÆÇª");
					break;
				case 7:
					printf("ÆâÇª");
					break;
				case 6:
					printf("Â½Çª");
					break;
				case 5:
					printf("ÎéÇª");
					break;
				case 4:
					printf("ËÁÇª");
					break;
				case 3:
					printf("ÈþÇª");
					break;
				case 2:
					printf("·¡Çª");
					break;
				case 1:
					printf("Ò¼Çª");
					break;
			}
			switch (j) {
				case 9:
					printf("¾Á°Û");
					break;
				case 8:
					printf("°Æ°Û");
					break;
				case 7:
					printf("Æâ°Û");
					break;
				case 6:
					printf("Â½°Û");
					break;
				case 5:
					printf("Îé°Û");
					break;
				case 4:
					printf("ËÁ°Û");
					break;
				case 3:
					printf("Èþ°Û");
					break;
				case 2:
					printf("·¡°Û");
					break;
				case 1:
					printf("Ò¼°Û");
					break;
			}
		}
		else if (i == 0 && j != 0 && k == 0 && m == 0) { //0100
			if (!x) {
				printf("Áã");
			}
			else {
				;
			}
			switch (j) {
				case 9:
					printf("¾Á°Û");
					break;
				case 8:
					printf("°Æ°Û");
					break;
				case 7:
					printf("Æâ°Û");
					break;
				case 6:
					printf("Â½°Û");
					break;
				case 5:
					printf("Îé°Û");
					break;
				case 4:
					printf("ËÁ°Û");
					break;
				case 3:
					printf("Èþ°Û");
					break;
				case 2:
					printf("·¡°Û");
					break;
				case 1:
					printf("Ò¼°Û");
					break;
			}
		}
		else if (i == 0 && j == 0 && k != 0 && m == 0) { //0010
			if (!x) {
				printf("Áã");
			}
			else {
				;
			}
			switch (k) {
				case 9:
					printf("¾ÁÊ°");
					break;
				case 8:
					printf("°ÆÊ°");
					break;
				case 7:
					printf("ÆâÊ°");
					break;
				case 6:
					printf("Â½Ê°");
					break;
				case 5:
					printf("ÎéÊ°");
					break;
				case 4:
					printf("ËÁÊ°");
					break;
				case 3:
					printf("ÈþÊ°");
					break;
				case 2:
					printf("·¡Ê°");
					break;
				case 1:
					printf("Ò¼Ê°");
					break;
			}

		}
		else if (i == 0 && j != 0 && k == 0 && m != 0) { //0101
			if (!x) {
				printf("Áã");
			}
			switch (j) {
				case 9:
					printf("¾Á°Û");
					break;
				case 8:
					printf("°Æ°Û");
					break;
				case 7:
					printf("Æâ°Û");
					break;
				case 6:
					printf("Â½°Û");
					break;
				case 5:
					printf("Îé°Û");
					break;
				case 4:
					printf("ËÁ°Û");
					break;
				case 3:
					printf("Èþ°Û");
					break;
				case 2:
					printf("·¡°Û");
					break;
				case 1:
					printf("Ò¼°Û");
			}
			printf("Áã");
			switch (m) {
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
			}
		}
		else if (i == 0 && j != 0 && k != 0 && m == 0) { //0110
			if (!x) {
				printf("Áã");
			}
			switch (j) {
				case 9:
					printf("¾Á°Û");
					break;
				case 8:
					printf("°Æ°Û");
					break;
				case 7:
					printf("Æâ°Û");
					break;
				case 6:
					printf("Â½°Û");
					break;
				case 5:
					printf("Îé°Û");
					break;
				case 4:
					printf("ËÁ°Û");
					break;
				case 3:
					printf("Èþ°Û");
					break;
				case 2:
					printf("·¡°Û");
					break;
				case 1:
					printf("Ò¼°Û");
			}
			switch (k) {
				case 9:
					printf("¾ÁÊ°");
					break;
				case 8:
					printf("°ÆÊ°");
					break;
				case 7:
					printf("ÆâÊ°");
					break;
				case 6:
					printf("Â½Ê°");
					break;
				case 5:
					printf("ÎéÊ°");
					break;
				case 4:
					printf("ËÁÊ°");
					break;
				case 3:
					printf("ÈþÊ°");
					break;
				case 2:
					printf("·¡Ê°");
					break;
				case 1:
					printf("Ò¼Ê°");
					break;
				case 0:
					break;
			}
		}
		else {
			switch (i) {
				case 9:
					printf("¾ÁÇª");
					break;
				case 8:
					printf("°ÆÇª");
					break;
				case 7:
					printf("ÆâÇª");
					break;
				case 6:
					printf("Â½Çª");
					break;
				case 5:
					printf("ÎéÇª");
					break;
				case 4:
					printf("ËÁÇª");
					break;
				case 3:
					printf("ÈþÇª");
					break;
				case 2:
					printf("·¡Çª");
					break;
				case 1:
					printf("Ò¼Çª");
					break;
				case 0:
					printf("Áã");
					break;
			}
			switch (j) {
				case 9:
					printf("¾Á°Û");
					break;
				case 8:
					printf("°Æ°Û");
					break;
				case 7:
					printf("Æâ°Û");
					break;
				case 6:
					printf("Â½°Û");
					break;
				case 5:
					printf("Îé°Û");
					break;
				case 4:
					printf("ËÁ°Û");
					break;
				case 3:
					printf("Èþ°Û");
					break;
				case 2:
					printf("·¡°Û");
					break;
				case 1:
					printf("Ò¼°Û");
				case 0:
					printf("Áã");
					break;
			}
			switch (k) {
				case 9:
					printf("¾ÁÊ°");
					break;
				case 8:
					printf("°ÆÊ°");
					break;
				case 7:
					printf("ÆâÊ°");
					break;
				case 6:
					printf("Â½Ê°");
					break;
				case 5:
					printf("ÎéÊ°");
					break;
				case 4:
					printf("ËÁÊ°");
					break;
				case 3:
					printf("ÈþÊ°");
					break;
				case 2:
					printf("·¡Ê°");
					break;
				case 1:
					printf("Ò¼Ê°");
					break;
				case 0:
					printf("Áã");
			}
			switch (m) {
				case 9:
					printf("¾Á");
					break;
				case 8:
					printf("°Æ");
					break;
				case 7:
					printf("Æâ");
					break;
				case 6:
					printf("Â½");
					break;
				case 5:
					printf("Îé");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 3:
					printf("Èþ");
					break;
				case 2:
					printf("·¡");
					break;
				case 1:
					printf("Ò¼");
					break;
				case 0:
					break;
			}
		}
		printf("Ô²");
		if (p == 0) {
			switch (n) {
				case 9:
					printf("¾Á½Ç");
					break;
				case 8:
					printf("°Æ½Ç");
					break;
				case 7:
					printf("Æâ½Ç");
					break;
				case 6:
					printf("Â½½Ç");
					break;
				case 5:
					printf("Îé½Ç");
					break;
				case 4:
					printf("ËÁ½Ç");
					break;
				case 3:
					printf("Èþ½Ç");
					break;
				case 2:
					printf("·¡½Ç");
					break;
				case 1:
					printf("Ò¼½Ç");
					break;
				case 0:
					break;
			}
			printf("Õû");
		}
		else {
			switch (n) {
				case 9:
					printf("¾Á½Ç");
					break;
				case 8:
					printf("°Æ½Ç");
					break;
				case 7:
					printf("Æâ½Ç");
					break;
				case 6:
					printf("Â½½Ç");
					break;
				case 5:
					printf("Îé½Ç");
					break;
				case 4:
					printf("ËÁ½Ç");
					break;
				case 3:
					printf("Èþ½Ç");
					break;
				case 2:
					printf("·¡½Ç");
					break;
				case 1:
					printf("Ò¼½Ç");
					break;
				case 0:
					printf("Áã");
					break;
			}
			switch (p) {
				case 9:
					printf("¾Á·Ö");
					break;
				case 8:
					printf("°Æ·Ö");
					break;
				case 7:
					printf("Æâ·Ö");
					break;
				case 6:
					printf("Â½·Ö");
					break;
				case 5:
					printf("Îé·Ö");
					break;
				case 4:
					printf("ËÁ·Ö");
					break;
				case 3:
					printf("Èþ·Ö");
					break;
				case 2:
					printf("·¡·Ö");
					break;
				case 1:
					printf("Ò¼·Ö");
					break;
				case 0:
					break;
			}
		}
	}
	else {
		if (n == 0 && p == 0) {
			printf("ÁãÔ²Õû");
		}
		else if (n != 0 && p == 0) {
			switch (n) {
				case 9:
					printf("¾Á½Ç");
					break;
				case 8:
					printf("°Æ½Ç");
					break;
				case 7:
					printf("Æâ½Ç");
					break;
				case 6:
					printf("Â½½Ç");
					break;
				case 5:
					printf("Îé½Ç");
					break;
				case 4:
					printf("ËÁ½Ç");
					break;
				case 3:
					printf("Èþ½Ç");
					break;
				case 2:
					printf("·¡½Ç");
					break;
				case 1:
					printf("Ò¼½Ç");
					break;
				case 0:
					break;
			}
			printf("Õû");
		}
		else {
			switch (n) {
				case 9:
					printf("¾Á½Ç");
					break;
				case 8:
					printf("°Æ½Ç");
					break;
				case 7:
					printf("Æâ½Ç");
					break;
				case 6:
					printf("Â½½Ç");
					break;
				case 5:
					printf("Îé½Ç");
					break;
				case 4:
					printf("ËÁ½Ç");
					break;
				case 3:
					printf("Èþ½Ç");
					break;
				case 2:
					printf("·¡½Ç");
					break;
				case 1:
					printf("Ò¼½Ç");
					break;
				case 0:
					break;
			}
			switch (p) {
				case 9:
					printf("¾Á·Ö");
					break;
				case 8:
					printf("°Æ·Ö");
					break;
				case 7:
					printf("Æâ·Ö");
					break;
				case 6:
					printf("Â½·Ö");
					break;
				case 5:
					printf("Îé·Ö");
					break;
				case 4:
					printf("ËÁ·Ö");
					break;
				case 3:
					printf("Èþ·Ö");
					break;
				case 2:
					printf("·¡·Ö");
					break;
				case 1:
					printf("Ò¼·Ö");
					break;
				case 0:
					break;
			}
		}
	}
	printf("\n");
	return 0;
	}