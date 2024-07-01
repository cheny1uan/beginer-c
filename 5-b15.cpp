/* ��11 2351892 ������ */
#include<iostream>
#define LINE_NUM 3
#define COL_LEN 128

using namespace std;

void input_line(char str[][COL_LEN])
{
	char ch;
	int i, j;
	for (i = 1; i <= LINE_NUM; i++) {
		cout << "�������"<<i<<"��" << endl;
		for (j = 0; j < COL_LEN; j++) {
			ch = getchar();
			if (ch == '\n')
				break;
			str[i - 1][j] = ch;
		}
	}
}

void output_result(const char str[][COL_LEN],int result[])
{
	int i, j;
	char ch;
	for (i = 0; LINE_NUM < 3; i++) {
		for (j = 0; j < 128; j++) {
			ch = str[i][j];
			if (ch == 0)
				break;
			else if (ch >= 'A' && ch <= 'Z')
				result[0]++;
			else if (ch >= 'a' && ch <= 'z')
				result[1]++;
			else if (ch >= '0' && ch <= '9')
				result[2]++;
			else if (ch == ' ')
				result[3]++;
			else
				result[4]++;
		}
	}
}

int main()
{
	char str[LINE_NUM][COL_LEN] = { 0 };
	int result[5] = { 0 };//��0-4���α�ʾ��д��Сд�����֣��ո��������ַ�����
	input_line(str);
	output_result(str, result);
	cout << "��д : " << result[0] << endl;
	cout << "Сд : " << result[1] << endl;
	cout << "���� : " << result[2] << endl;
	cout << "�ո� : " << result[3] << endl;
	cout << "���� : " << result[4] << endl;
	return 0;
}