/* 2351892 ������ ��11 */
#include<iostream>
using namespace std;

int main()
{
	char binaryInput[40] = { 0 };
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
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