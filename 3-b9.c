/*2351892 ÐÅ11 ³ÂÞÈìÅ*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i, j, k=1;//ixj=k
	for (j=1; j < 10; j++) {
		for (i=1; i <= j;i++ ) {
			k = i * j;
			if (k < 10) {
				printf("%dx%d=%d   ", i, j, k);
			}
			else {
				printf("%dx%d=%d  ", i, j, k);
			}	
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
