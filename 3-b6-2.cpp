/*2351892 ĞÅ11 ³ÂŞÈìÅ*/
#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	double a;
	int b, c, d, e, f, g, h, i, j, k, m, n, p;
	int x, y;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
	cin >> a;
	cout << "´óĞ´½á¹ûÊÇ:" << endl;
	b = int(a / 10);
	a = (a - double(b) * 10) * 100;
	c = b / 100000000;//Ê®ÒÚ
	d = b % 100000000 / 10000000;//ÒÚ
	e = b % 10000000 / 1000000;//Ç§Íò
	f = b % 1000000 / 100000;//°ÙÍò
	g = b % 100000 / 10000;//Ê®Íò
	h = b % 10000 / 1000;//Íò
	i = b % 1000 / 100;//Ç§
	j = b % 100 / 10;//°Ù
	k = b % 10;//Ê®
	m = int(a / 100);//Ô²
	n = int(a + 0.0001) % 100 / 10;//½Ç
	p = int(a + 0.0001) % 10;//·Ö
	y = c == 0 && d == 0;
	x = c == 0 && d == 0&&e == 0 && f == 0 && g == 0 && h == 0;
	if(c!=0||d!=0||e!=0||f!=0||g!=0||h!=0||i!=0||j!=0||k!=0||m!=0){
		if (c == 0 && d == 0) {
			;
		}
		else {
			switch (c) {
				case 9:
					cout << "¾ÁÊ°";
					break;
				case 8:
					cout << "°ÆÊ°";
					break;
				case 7:
					cout << "ÆâÊ°";
					break;
				case 6:
					cout << "Â½Ê°";
					break;
				case 5:
					cout << "ÎéÊ°";
					break;
				case 4:
					cout << "ËÁÊ°";
					break;
				case 3:
					cout << "ÈşÊ°";
					break;
				case 2:
					cout << "·¡Ê°";
					break;
				case 1:
					cout << "Ò¼Ê°";
					break;
				case 0:
					break;
			}
			switch (d) {
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èş";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
				case 0:
					break;
			}
			cout << "ÒÚ";
		}
		if (e == 0 && f == 0 && g == 0 && h == 0) {   //0000
			;
		}
		else if (e == 0 && f == 0 && g == 0 && h != 0) { //0001
			if (!y) {
				cout << "Áã";
			}
			else {
				;
			}
			switch (h) {
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èş";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			cout << "Íò";
		}
		else if (e != 0 && f == 0 && g == 0 && h == 0) { //1000
			switch (e) {
				case 9:
					cout << "¾ÁÇª";
					break;
				case 8:
					cout << "°ÆÇª";
					break;
				case 7:
					cout << "ÆâÇª";
					break;
				case 6:
					cout << "Â½Çª";
					break;
				case 5:
					cout << "ÎéÇª";
					break;
				case 4:
					cout << "ËÁÇª";
					break;
				case 3:
					cout << "ÈşÇª";
					break;
				case 2:
					cout << "·¡Çª";
					break;
				case 1:
					cout << "Ò¼Çª";
					break;
			}
			cout << "Íò";
		}
		else if (e == 0 && f == 0 && g != 0 && h != 0) { //0011
			if (!y ) {
				cout << "Áã";
			}
			else {
				;
			}
			switch (g) {
				case 9:
					cout << "¾ÁÊ°";
					break;
				case 8:
					cout << "°ÆÊ°";
					break;
				case 7:
					cout << "ÆâÊ°";
					break;
				case 6:
					cout << "Â½Ê°";
					break;
				case 5:
					cout << "ÎéÊ°";
					break;
				case 4:
					cout << "ËÁÊ°";
					break;
				case 3:
					cout << "ÈşÊ°";
					break;
				case 2:
					cout << "·¡Ê°";
					break;
				case 1:
					cout << "Ò¼Ê°";
					break;
			}
			switch (h) {
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èş";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			cout << "Íò";
		}
		else if (e != 0 && f == 0 && g == 0 && h != 0) { //1001
			switch (e) {
				case 9:
					cout << "¾ÁÇª";
					break;
				case 8:
					cout << "°ÆÇª";
					break;
				case 7:
					cout << "ÆâÇª";
					break;
				case 6:
					cout << "Â½Çª";
					break;
				case 5:
					cout << "ÎéÇª";
					break;
				case 4:
					cout << "ËÁÇª";
					break;
				case 3:
					cout << "ÈşÇª";
					break;
				case 2:
					cout << "·¡Çª";
					break;
				case 1:
					cout << "Ò¼Çª";
					break;
			}
			cout << "Áã";
			switch (h) {
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èş";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
			cout << "Íò";
		}
		else if (e != 0 && f != 0 && g == 0 && h == 0) { //1100
			switch (e) {
				case 9:
					cout << "¾ÁÇª";
					break;
				case 8:
					cout << "°ÆÇª";
					break;
				case 7:
					cout << "ÆâÇª";
					break;
				case 6:
					cout << "Â½Çª";
					break;
				case 5:
					cout << "ÎéÇª";
					break;
				case 4:
					cout << "ËÁÇª";
					break;
				case 3:
					cout << "ÈşÇª";
					break;
				case 2:
					cout << "·¡Çª";
					break;
				case 1:
					cout << "Ò¼Çª";
					break;
			}
			switch (f) {
				case 9:
					cout << "¾Á°Û";
					break;
				case 8:
					cout << "°Æ°Û";
					break;
				case 7:
					cout << "Æâ°Û";
					break;
				case 6:
					cout << "Â½°Û";
					break;
				case 5:
					cout << "Îé°Û";
					break;
				case 4:
					cout << "ËÁ°Û";
					break;
				case 3:
					cout << "Èş°Û";
					break;
				case 2:
					cout << "·¡°Û";
					break;
				case 1:
					cout << "Ò¼°Û";
					break;
			}
			cout << "Íò";
		}
		else if (e == 0 && f != 0 && g == 0 && h == 0) { //0100
			if (!y) {
				cout << "Áã";
			}
			else {
				;
			}
			switch (f) {
				case 9:
					cout << "¾Á°Û";
					break;
				case 8:
					cout << "°Æ°Û";
					break;
				case 7:
					cout << "Æâ°Û";
					break;
				case 6:
					cout << "Â½°Û";
					break;
				case 5:
					cout << "Îé°Û";
					break;
				case 4:
					cout << "ËÁ°Û";
					break;
				case 3:
					cout << "Èş°Û";
					break;
				case 2:
					cout << "·¡°Û";
					break;
				case 1:
					cout << "Ò¼°Û";
					break;
			}
			cout << "Íò";
		}
		else if (e == 0 && f == 0 && g != 0 && h == 0) { //0010
			if (!y) {
				cout << "Áã";
			}
			else {
				;
			}
			switch (g) {
				case 9:
					cout << "¾ÁÊ°";
					break;
				case 8:
					cout << "°ÆÊ°";
					break;
				case 7:
					cout << "ÆâÊ°";
					break;
				case 6:
					cout << "Â½Ê°";
					break;
				case 5:
					cout << "ÎéÊ°";
					break;
				case 4:
					cout << "ËÁÊ°";
					break;
				case 3:
					cout << "ÈşÊ°";
					break;
				case 2:
					cout << "·¡Ê°";
					break;
				case 1:
					cout << "Ò¼Ê°";
					break;
			}
			cout << "Íò";
		}
		else if (e == 0 && f != 0 && g == 0 && h != 0) { //0101
			if (!y) {
				cout << "Áã";
			}
			switch (f) {
				case 9:
					cout << "¾Á°Û";
					break;
				case 8:
					cout << "°Æ°Û";
					break;
				case 7:
					cout << "Æâ°Û";
					break;
				case 6:
					cout << "Â½°Û";
					break;
				case 5:
					cout << "Îé°Û";
					break;
				case 4:
					cout << "ËÁ°Û";
					break;
				case 3:
					cout << "Èş°Û";
					break;
				case 2:
					cout << "·¡°Û";
					break;
				case 1:
					cout << "Ò¼°Û";
			}
			cout << "Áã";
			switch (h) {
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èş";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
				case 0:
					break;
			}
			cout << "Íò";
		}
		else if (e == 0 && f != 0 && g != 0 && h == 0) { //0110
			if (!y ) {
				cout << "Áã";
			}
			switch (f) {
				case 9:
					cout << "¾Á°Û";
					break;
				case 8:
					cout << "°Æ°Û";
					break;
				case 7:
					cout << "Æâ°Û";
					break;
				case 6:
					cout << "Â½°Û";
					break;
				case 5:
					cout << "Îé°Û";
					break;
				case 4:
					cout << "ËÁ°Û";
					break;
				case 3:
					cout << "Èş°Û";
					break;
				case 2:
					cout << "·¡°Û";
					break;
				case 1:
					cout << "Ò¼°Û";
			}
			switch (g) {
				case 9:
					cout << "¾ÁÊ°";
					break;
				case 8:
					cout << "°ÆÊ°";
					break;
				case 7:
					cout << "ÆâÊ°";
					break;
				case 6:
					cout << "Â½Ê°";
					break;
				case 5:
					cout << "ÎéÊ°";
					break;
				case 4:
					cout << "ËÁÊ°";
					break;
				case 3:
					cout << "ÈşÊ°";
					break;
				case 2:
					cout << "·¡Ê°";
					break;
				case 1:
					cout << "Ò¼Ê°";
					break;
				case 0:
					break;
			}
			cout << "Íò";
			}
		else {
			switch (e) {
				case 9:
					cout << "¾ÁÇª";
					break;
				case 8:
					cout << "°ÆÇª";
					break;
				case 7:
					cout << "ÆâÇª";
					break;
				case 6:
					cout << "Â½Çª";
					break;
				case 5:
					cout << "ÎéÇª";
					break;
				case 4:
					cout << "ËÁÇª";
					break;
				case 3:
					cout << "ÈşÇª";
					break;
				case 2:
					cout << "·¡Çª";
					break;
				case 1:
					cout << "Ò¼Çª";
					break;
				case 0:
					cout << "Áã";
					break;
			}
			switch (f) {
				case 9:
					cout << "¾Á°Û";
					break;
				case 8:
					cout << "°Æ°Û";
					break;
				case 7:
					cout << "Æâ°Û";
					break;
				case 6:
					cout << "Â½°Û";
					break;
				case 5:
					cout << "Îé°Û";
					break;
				case 4:
					cout << "ËÁ°Û";
					break;
				case 3:
					cout << "Èş°Û";
					break;
				case 2:
					cout << "·¡°Û";
					break;
				case 1:
					cout << "Ò¼°Û";
				case 0:
					cout << "Áã";
					break;
			}
			switch (g) {
				case 9:
					cout << "¾ÁÊ°";
					break;
				case 8:
					cout << "°ÆÊ°";
					break;
				case 7:
					cout << "ÆâÊ°";
					break;
				case 6:
					cout << "Â½Ê°";
					break;
				case 5:
					cout << "ÎéÊ°";
					break;
				case 4:
					cout << "ËÁÊ°";
					break;
				case 3:
					cout << "ÈşÊ°";
					break;
				case 2:
					cout << "·¡Ê°";
					break;
				case 1:
					cout << "Ò¼Ê°";
					break;
				case 0:
					break;
			}
			switch (h) {
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èş";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
				case 0:
					break;
			}
			cout << "Íò";
		}
		if (i == 0 && j == 0 && k == 0 && m == 0) {   //0000
			;
		}
		else if (i == 0 && j == 0 && k == 0 && m != 0) { //0001
			if (!x ) {
				cout << "Áã";
			}
			else {
				;
			}
			switch (m) {
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èş";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
				case 0:
					break;
			}
		}
		else if (i != 0 && j == 0 && k == 0 && m == 0) { //1000
			switch (i) {
				case 9:
					cout << "¾ÁÇª";
					break;
				case 8:
					cout << "°ÆÇª";
					break;
				case 7:
					cout << "ÆâÇª";
					break;
				case 6:
					cout << "Â½Çª";
					break;
				case 5:
					cout << "ÎéÇª";
					break;
				case 4:
					cout << "ËÁÇª";
					break;
				case 3:
					cout << "ÈşÇª";
					break;
				case 2:
					cout << "·¡Çª";
					break;
				case 1:
					cout << "Ò¼Çª";
					break;
			}
		}
		else if (i == 0 && j == 0 && k != 0 && m != 0) { //0011
			if (!x) {
				cout << "Áã";
			}
			else {
				;
			}
			switch (k) {
				case 9:
					cout << "¾ÁÊ°";
					break;
				case 8:
					cout << "°ÆÊ°";
					break;
				case 7:
					cout << "ÆâÊ°";
					break;
				case 6:
					cout << "Â½Ê°";
					break;
				case 5:
					cout << "ÎéÊ°";
					break;
				case 4:
					cout << "ËÁÊ°";
					break;
				case 3:
					cout << "ÈşÊ°";
					break;
				case 2:
					cout << "·¡Ê°";
					break;
				case 1:
					cout << "Ò¼Ê°";
					break;
			}
			switch (m) {
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èş";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
		}
		else if (i != 0 && j == 0 && k == 0 && m != 0) { //1001
			switch (i) {
				case 9:
					cout << "¾ÁÇª";
					break;
				case 8:
					cout << "°ÆÇª";
					break;
				case 7:
					cout << "ÆâÇª";
					break;
				case 6:
					cout << "Â½Çª";
					break;
				case 5:
					cout << "ÎéÇª";
					break;
				case 4:
					cout << "ËÁÇª";
					break;
				case 3:
					cout << "ÈşÇª";
					break;
				case 2:
					cout << "·¡Çª";
					break;
				case 1:
					cout << "Ò¼Çª";
					break;
			}
			cout << "Áã";
			switch (m) {
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èş";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
		}
		else if (i != 0 && j != 0 && k == 0 && m == 0) { //1100
			switch (i) {
				case 9:
					cout << "¾ÁÇª";
					break;
				case 8:
					cout << "°ÆÇª";
					break;
				case 7:
					cout << "ÆâÇª";
					break;
				case 6:
					cout << "Â½Çª";
					break;
				case 5:
					cout << "ÎéÇª";
					break;
				case 4:
					cout << "ËÁÇª";
					break;
				case 3:
					cout << "ÈşÇª";
					break;
				case 2:
					cout << "·¡Çª";
					break;
				case 1:
					cout << "Ò¼Çª";
					break;
			}
			switch (j) {
				case 9:
					cout << "¾Á°Û";
					break;
				case 8:
					cout << "°Æ°Û";
					break;
				case 7:
					cout << "Æâ°Û";
					break;
				case 6:
					cout << "Â½°Û";
					break;
				case 5:
					cout << "Îé°Û";
					break;
				case 4:
					cout << "ËÁ°Û";
					break;
				case 3:
					cout << "Èş°Û";
					break;
				case 2:
					cout << "·¡°Û";
					break;
				case 1:
					cout << "Ò¼°Û";
					break;
			}
		}
		else if (i == 0 && j != 0 && k == 0 && m == 0) { //0100
			if (!x) {
				cout << "Áã";
			}
			else {
				;
			}
			switch (j) {
				case 9:
					cout << "¾Á°Û";
					break;
				case 8:
					cout << "°Æ°Û";
					break;
				case 7:
					cout << "Æâ°Û";
					break;
				case 6:
					cout << "Â½°Û";
					break;
				case 5:
					cout << "Îé°Û";
					break;
				case 4:
					cout << "ËÁ°Û";
					break;
				case 3:
					cout << "Èş°Û";
					break;
				case 2:
					cout << "·¡°Û";
					break;
				case 1:
					cout << "Ò¼°Û";
					break;
			}
		}
		else if (i == 0 && j == 0 && k != 0 && m == 0) { //0010
			if (!x) {
				cout << "Áã";
			}
			else {
				;
			}
				switch (k) {
					case 9:
						cout << "¾ÁÊ°";
						break;
					case 8:
						cout << "°ÆÊ°";
						break;
					case 7:
						cout << "ÆâÊ°";
						break;
					case 6:
						cout << "Â½Ê°";
						break;
					case 5:
						cout << "ÎéÊ°";
						break;
					case 4:
						cout << "ËÁÊ°";
						break;
					case 3:
						cout << "ÈşÊ°";
						break;
					case 2:
						cout << "·¡Ê°";
						break;
					case 1:
						cout << "Ò¼Ê°";
						break;
				}
			
		}
		else if (i == 0 && j != 0 && k == 0 && m != 0) { //0101
			if (!x) {
				cout << "Áã";
			}
			switch (j) {
				case 9:
					cout << "¾Á°Û";
					break;
				case 8:
					cout << "°Æ°Û";
					break;
				case 7:
					cout << "Æâ°Û";
					break;
				case 6:
					cout << "Â½°Û";
					break;
				case 5:
					cout << "Îé°Û";
					break;
				case 4:
					cout << "ËÁ°Û";
					break;
				case 3:
					cout << "Èş°Û";
					break;
				case 2:
					cout << "·¡°Û";
					break;
				case 1:
					cout << "Ò¼°Û";
			}
			cout << "Áã";
			switch (m) {
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èş";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
			}
		}
		else if (i == 0 && j != 0 && k != 0 && m == 0) { //0110
			if (!x) {
				cout << "Áã";
			}
			switch (j) {
				case 9:
					cout << "¾Á°Û";
					break;
				case 8:
					cout << "°Æ°Û";
					break;
				case 7:
					cout << "Æâ°Û";
					break;
				case 6:
					cout << "Â½°Û";
					break;
				case 5:
					cout << "Îé°Û";
					break;
				case 4:
					cout << "ËÁ°Û";
					break;
				case 3:
					cout << "Èş°Û";
					break;
				case 2:
					cout << "·¡°Û";
					break;
				case 1:
					cout << "Ò¼°Û";
			}
			switch (k) {
				case 9:
					cout << "¾ÁÊ°";
					break;
				case 8:
					cout << "°ÆÊ°";
					break;
				case 7:
					cout << "ÆâÊ°";
					break;
				case 6:
					cout << "Â½Ê°";
					break;
				case 5:
					cout << "ÎéÊ°";
					break;
				case 4:
					cout << "ËÁÊ°";
					break;
				case 3:
					cout << "ÈşÊ°";
					break;
				case 2:
					cout << "·¡Ê°";
					break;
				case 1:
					cout << "Ò¼Ê°";
					break;
				case 0:
					break;
			}
			}
		else {
			switch (i) {
				case 9:
					cout << "¾ÁÇª";
					break;
				case 8:
					cout << "°ÆÇª";
					break;
				case 7:
					cout << "ÆâÇª";
					break;
				case 6:
					cout << "Â½Çª";
					break;
				case 5:
					cout << "ÎéÇª";
					break;
				case 4:
					cout << "ËÁÇª";
					break;
				case 3:
					cout << "ÈşÇª";
					break;
				case 2:
					cout << "·¡Çª";
					break;
				case 1:
					cout << "Ò¼Çª";
					break;
				case 0:
					cout << "Áã";
					break;
			}
			switch (j) {
				case 9:
					cout << "¾Á°Û";
					break;
				case 8:
					cout << "°Æ°Û";
					break;
				case 7:
					cout << "Æâ°Û";
					break;
				case 6:
					cout << "Â½°Û";
					break;
				case 5:
					cout << "Îé°Û";
					break;
				case 4:
					cout << "ËÁ°Û";
					break;
				case 3:
					cout << "Èş°Û";
					break;
				case 2:
					cout << "·¡°Û";
					break;
				case 1:
					cout << "Ò¼°Û";
				case 0:
					cout << "Áã";
					break;
			}
			switch (k) {
				case 9:
					cout << "¾ÁÊ°";
					break;
				case 8:
					cout << "°ÆÊ°";
					break;
				case 7:
					cout << "ÆâÊ°";
					break;
				case 6:
					cout << "Â½Ê°";
					break;
				case 5:
					cout << "ÎéÊ°";
					break;
				case 4:
					cout << "ËÁÊ°";
					break;
				case 3:
					cout << "ÈşÊ°";
					break;
				case 2:
					cout << "·¡Ê°";
					break;
				case 1:
					cout << "Ò¼Ê°";
					break;
				case 0:
					cout << "Áã";
			}
			switch (m) {
				case 9:
					cout << "¾Á";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 6:
					cout << "Â½";
					break;
				case 5:
					cout << "Îé";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 3:
					cout << "Èş";
					break;
				case 2:
					cout << "·¡";
					break;
				case 1:
					cout << "Ò¼";
					break;
				case 0:
					break;
			}
		}
		cout << "Ô²";
		if (p == 0) {
			switch (n) {
				case 9:
					cout << "¾Á½Ç";
					break;
				case 8:
					cout << "°Æ½Ç";
					break;
				case 7:
					cout << "Æâ½Ç";
					break;
				case 6:
					cout << "Â½½Ç";
					break;
				case 5:
					cout << "Îé½Ç";
					break;
				case 4:
					cout << "ËÁ½Ç";
					break;
				case 3:
					cout << "Èş½Ç";
					break;
				case 2:
					cout << "·¡½Ç";
					break;
				case 1:
					cout << "Ò¼½Ç";
					break;
				case 0:
					break;
			}
			cout << "Õû";
		}
		else {
			switch (n) {
				case 9:
					cout << "¾Á½Ç";
					break;
				case 8:
					cout << "°Æ½Ç";
					break;
				case 7:
					cout << "Æâ½Ç";
					break;
				case 6:
					cout << "Â½½Ç";
					break;
				case 5:
					cout << "Îé½Ç";
					break;
				case 4:
					cout << "ËÁ½Ç";
					break;
				case 3:
					cout << "Èş½Ç";
					break;
				case 2:
					cout << "·¡½Ç";
					break;
				case 1:
					cout << "Ò¼½Ç";
					break;
				case 0:
					cout << "Áã";
					break;
			}
			switch (p) {
				case 9:
					cout << "¾Á·Ö";
					break;
				case 8:
					cout << "°Æ·Ö";
					break;
				case 7:
					cout << "Æâ·Ö";
					break;
				case 6:
					cout << "Â½·Ö";
					break;
				case 5:
					cout << "Îé·Ö";
					break;
				case 4:
					cout << "ËÁ·Ö";
					break;
				case 3:
					cout << "Èş·Ö";
					break;
				case 2:
					cout << "·¡·Ö";
					break;
				case 1:
					cout << "Ò¼·Ö";
					break;
				case 0:
					break;
			}
		}
	}
	else {
		if (n == 0 && p == 0) {
			cout << "ÁãÔ²Õû";
		}
		else if (n != 0 && p == 0) {
			switch (n) {
				case 9:
					cout << "¾Á½Ç";
					break;
				case 8:
					cout << "°Æ½Ç";
					break;
				case 7:
					cout << "Æâ½Ç";
					break;
				case 6:
					cout << "Â½½Ç";
					break;
				case 5:
					cout << "Îé½Ç";
					break;
				case 4:
					cout << "ËÁ½Ç";
					break;
				case 3:
					cout << "Èş½Ç";
					break;
				case 2:
					cout << "·¡½Ç";
					break;
				case 1:
					cout << "Ò¼½Ç";
					break;
				case 0:
					break;
			}
			cout << "Õû";
		}
		else {
			switch (n) {
				case 9:
					cout << "¾Á½Ç";
					break;
				case 8:
					cout << "°Æ½Ç";
					break;
				case 7:
					cout << "Æâ½Ç";
					break;
				case 6:
					cout << "Â½½Ç";
					break;
				case 5:
					cout << "Îé½Ç";
					break;
				case 4:
					cout << "ËÁ½Ç";
					break;
				case 3:
					cout << "Èş½Ç";
					break;
				case 2:
					cout << "·¡½Ç";
					break;
				case 1:
					cout << "Ò¼½Ç";
					break;
				case 0:
					break;
			}
			switch (p) {
				case 9:
					cout << "¾Á·Ö";
					break;
				case 8:
					cout << "°Æ·Ö";
					break;
				case 7:
					cout << "Æâ·Ö";
					break;
				case 6:
					cout << "Â½·Ö";
					break;
				case 5:
					cout << "Îé·Ö";
					break;
				case 4:
					cout << "ËÁ·Ö";
					break;
				case 3:
					cout << "Èş·Ö";
					break;
				case 2:
					cout << "·¡·Ö";
					break;
				case 1:
					cout << "Ò¼·Ö";
					break;
				case 0:
					break;
			}
		}
	}
	cout << endl;

	return 0;
}