/* 2351892 陈奕炫 信11 */
#include<iostream>
using namespace std;

int main()
{
	char binaryInput[40] = { 0 };
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> binaryInput;
	int dec_result = 0;
	char* p = binaryInput;
	while (*p != 0) {

		dec_result = dec_result * 2 + *p - '0';
		p++;
	}
	cout << dec_result << endl;
	return 0;
}