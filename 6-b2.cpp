/* 2351892 陈奕炫 信11 */
#include <iostream>
using namespace std;

int main()
{
	char input[81];
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(input, 81, stdin);
	char* firstChar, * lastChar;
	firstChar = input;
	lastChar = input;
	while (*lastChar != '\n') {
		lastChar++;
	}//最后退出时，lastChar指向\n
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