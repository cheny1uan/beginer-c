/* 2351892 ������ ��11 */
#include <iostream>
using namespace std;

int main()
{
	char input[81];
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(input, 81, stdin);
	char* firstChar, * lastChar;
	firstChar = input;
	lastChar = input;
	while (*lastChar != '\n') {
		lastChar++;
	}//����˳�ʱ��lastCharָ��\n
	lastChar--;
	bool isPalindrome = true;
	while (firstChar < lastChar) {
		if (*firstChar != *lastChar) {
			isPalindrome = false;
			break;
		}
		firstChar++;
		lastChar--;
	}
	if (isPalindrome) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	return 0;
}