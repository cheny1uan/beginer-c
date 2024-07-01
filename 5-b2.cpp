/* 2351892 ÐÅ11 ³ÂÞÈìÅ */
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>

using namespace std;

int main()
{
	int a[100], b[100];
	int No=1, i=0, k=0;
	while (No <= 100) {
		a[i] = No;
		No++;
		i++;
	}
	while (k < 100) {
		b[k] = 0;
		k++;
	}
	for (No = 1; No <= 100; No++) {
		for (k = 0; k < 100; k++) {
			if ((k+1) % No == 0) {
				b[k] = b[k] + 1;
			}
		}
	}
	for (i = 0; i < 100; i++) {
		if (b[i] % 2 == 1) {
			if (i != 99) {
				cout << a[i] << " ";
			}
			else {
				cout << a[i];
			}
		}



	}

	cout << endl;
	
}