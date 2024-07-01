/* 2351892 信11 陈奕炫 */
#include <iostream>
#include <cstring>
using namespace std;
#define PASSWORDS_NUM 10
#define PASSWORDS_LEN_MAX 16
#define PASSWORDS_LEN_MIN 12
static const char other[] = "~!@#$%^&*()-_=+[],.?";

bool input_num(int num[])
{
	int i;
	for (i = 0; i < 5; i++) {
		cin >> num[i];
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			return false;
		}
	}
	return true;
}
bool check_num(int num[])
{
	//检查密码长度
	if (num[0] < PASSWORDS_LEN_MIN || num[0]>PASSWORDS_LEN_MAX) {
		//cout << "密码长度[" << num[0] << "]不正确" << endl;
		return false;
	}
	//检查大写字母个数
	if (num[1] < 2) {
		//cout << "大写字母个数[" << num[1] << "]不正确" << endl;
		return false;
	}
	//检查小写字母个数
	if (num[2] < 2) {
		//cout << "小写字母个数[" << num[2] << "]不正确" << endl;
		return false;
	}
	//检查数字个数
	if (num[3] < 2) {
		//cout << "数字个数[" << num[3] << "]不正确" << endl;
		return false;
	}
	//检查其他符号个数
	if (num[4] < 2) {
		//cout << "其他符号个数[" << num[4] << "]不正确" << endl;
		return false;
	}
	//检查字符类型之和与总长度
	if (num[1] + num[2] + num[3] + num[4] > num[0]) {
		//cout << "所有字符类型之和[" << num[1] << "+" << num[2] << "+" << num[3] << "+" << num[4] << "]大于总密码长度[" << num[0] << "]" << endl;
		return false;
	}
	return true;
}
bool check_password(int num[])
{
	int num_capital, num_lower, num_figure, num_other;
	int i = 0;
	int j, k;
	char password[PASSWORDS_LEN_MAX + 1] = { 0 };
	while (i < PASSWORDS_NUM) {
		num_capital = 0;
		num_lower = 0;
		num_figure = 0;
		num_other = 0;
		cin >> password;
		for (j = 0; j < num[0]; j++) {
			if (password[j] >= 'A' && password[j] <= 'Z')
				num_capital++;
			if (password[j] >= 'a' && password[j] <= 'z')
				num_lower++;
			if (password[j] >= '0' && password[j] <= '9')
				num_figure++;
			for (k = 0; k < 21; k++) {
				if (password[j] == other[k]) {
					num_other++;
					break;
				}
			}		
		}
		if (num_capital < num[1] || num_lower < num[2] 
		 || num_figure < num[3] || num_other < num[4]
		 ||num_capital+num_lower+num_figure+num_other!=num[0])
		{
			return false;
		}
		i++;
	}
	return true;
}
 
int main()
{
	int num[5];//0-4分别为密码长度，大写字母个数，小写字母个数，数字个数，其它符号个数
	bool is_right;
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
	is_right = input_num(num);
	
	if (!is_right) {
		cout << "错误" << endl;
		return 0;
	}
	else {
		is_right = check_num(num);
		if (!is_right) {
			cout << "错误" << endl;
			return 0;
		}
	}
	if (!check_password(num)) {
		cout << "错误" << endl;
		return 0;
	}
	cout << "正确" << endl;
	return 0;

}