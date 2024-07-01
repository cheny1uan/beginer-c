/* 2351892 信11 陈奕炫 */

#include <iostream>
#include <iomanip>

using namespace std;

//判断是否为闰年
bool is_leap(int a)
{

    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0) {
        return true;
    }

    else {
        return false;
    }
}
//通过年份和月份判断该月总日期
int month_days(int month, bool leap)
{
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (leap) {
        days[1] += 1;
    }

    return days[month - 1];

}
//通过zeller公式判断每月第一天为周几
int zeller(int y, int m, int d=1)
{
	int w, y_, c;//w为星期，y_为年份后两位，c为年份前两位
	if (m == 1 || m == 2) {
		y = y - 1;
		m = m + 12;
	}
	y_ = y % 100;
	c = (y - y_) / 100;
	w = y_ + y_ / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	if (w < 0) {
		while (w < 0) {
			w = w + 7;
		}
	}
	w = w % 7;
	return w;
}
bool is_null(int x,int y,int z,int month[][42])
{
	int i;
	bool null = true;
	for (i = 35; i < 42; i++) {
		if (month[x][i] != 0) {
			null = false;
		}
	}
	for (i = 35; i < 42; i++) {
		if (month[y][i] != 0) {
			null = false;
		}
	}
	for (i = 35; i < 42; i++) {
		if (month[z][i] != 0) {
			null = false;
		}
	}
	return null;

}
//用来打印每个季度的月历
void print_calendar(int x, int y, int z,int month[][42])
{
	int i, j;
	cout << endl;
	cout  << "           "<< setiosflags(ios::right)<<setw(2)<<x+1<<"月                            "<<setw(2)<<y+1<<"月                            "<< setw(2) << z+1<<"月" << endl;
	cout<<resetiosflags(ios::right);

	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	
	for (i = 0; i < 6; i++) {
		if (i == 5&&is_null(x,y,z,month)) {
			return;
		}
		
		
		for (j = 7*i; j < 7*(i+1); j++) {			
			if (month[x][j] != 0) {
				cout << setw(2) << setiosflags(ios::left) << month[x][j];
				
				cout << "  ";
			}
			else {
				cout << "    ";
			}
		}
		cout << "    ";
		for (j = 7 * i; j < 7 * (i + 1); j++) {
			if (month[y][j] != 0) {
				cout << setw(2) << setiosflags(ios::left) << month[y][j];
				
				cout << "  ";
			}
			else {
				cout << "    ";
			}
		}
		cout << "    ";
		for (j = 7 * i; j < 7 * (i + 1); j++) {
			if (month[z][j] != 0) {
				cout << setw(2) << setiosflags(ios::left) << month[z][j];
				
				cout << "  ";
			}
			else {
				cout << "    ";
			}
		}
		cout << endl;
		cout << resetiosflags(ios::left);
	}
}

int main()
{
	int year;
    int month[12][42] = { 0 };
    bool leap;
	int i, j;
	int k;
	while (1) {
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;
		if (year >= 1900 && year <= 2100) {
			break;
		}
		else {
			continue;
		}
	}
	leap = is_leap(year);
	//初始化月历二维数组
	for (i = 0; i < 12; i++) {
		k = 1;
		for (j = zeller(year, i + 1); k <= month_days(i + 1, leap);j++) {
			month[i][j] = k;
			k++;
		}
	}


	cout << year << "年的日历:" << endl;
	print_calendar(0, 1, 2, month);
	print_calendar(3, 4, 5, month);
	print_calendar(6, 7, 8, month);
	print_calendar(9, 10, 11, month);
	cout << endl;
	cout << endl;
	
	

	return 0;
}