/* 信11 2351892 陈奕炫 */
#include<iostream>
#define LINE_NUM 3
#define COL_LEN 128

using namespace std;

void input_line(char str[][COL_LEN])
{
	char ch;
	int i, j;
	for (i = 1; i <= LINE_NUM; i++) {
		cout << "请输入第"<<i<<"行" << endl;
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
	int result[5] = { 0 };//从0-4依次表示大写，小写，数字，空格，其它的字符个数
	input_line(str);
	output_result(str, result);
	cout << "大写 : " << result[0] << endl;
	cout << "小写 : " << result[1] << endl;
	cout << "数字 : " << result[2] << endl;
	cout << "空格 : " << result[3] << endl;
	cout << "其他 : " << result[4] << endl;
	return 0;
}