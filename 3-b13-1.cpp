/* 信11 2351892 陈奕炫 */
#include <iostream>
#include <iomanip>
#include<limits>
 
using namespace std;

int main()
{
	int nian, yue, days = 0, day1;
	int i, j, k, n = 0;
	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) :";
		cin >> nian >> yue;
		if (cin.fail()) {
			cin.clear();//清除输入流的错误标志，以便继续读取输入。
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//忽略输入流中直到行末尾的所有内容，包括换行符('\n')，以确保输入流被清空并准备接受新的输入
			cout << "输入非法，请重新输入" << endl;
		}
		else {

			if ((nian >= 2000) && (nian <= 2030) && (yue >= 1) && (yue <= 12))
				break;
			else {
				cout << "输入非法，请重新输入" << endl;
				continue;
			}
		}
	}
	while (1) {
		cout << "请输入" << nian << "年" << yue << "月1日的星期(0 - 6表示星期日 - 星期六) :";
		cin >> day1;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
		}
		else {

			if (day1 >= 0 && day1 <= 6)
				break;
			else {
				cout << "输入非法，请重新输入" << endl;
				continue;
			}
		}
	}
	switch (yue) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days = 31;
			break;
		case 2:
			if (nian % 4 == 0 && nian % 100 != 0 || nian % 400 == 0) {
				days = 29;
			}
			else {
				days = 28;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days = 30;

	}

	cout << endl;
	cout << nian << "年" << yue << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	for (i = 0; i < day1; i++) {
		cout << "        ";//8个空格
	}
	for (j = 1; j <= (7 - day1); j++) {
		cout << setiosflags(ios::right) << setw(4) << j << "    ";
	}
	cout << endl;
	for (k = (8 - day1); k <= days; k++) {
		cout << setiosflags(ios::right) << setw(4) << k << "    ";
		n++;
		if (n % 7 == 0 && n != 0) {
			cout << endl;
		}
	}
	//if (days - 7 + day1) {
	//	;
	//}
	//else {
		cout << endl;
	//}


	
		return 0;
}
