/*2351892 信11 陈奕炫*/
/* 学号 姓名 班级 */
#include <iostream>
#include<limits>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
/*首先对数字进行分解*/
double a;
int b, c, d, e, f, g, h, i, j, k, m, n, p;
int x, y, z;
while (1) {
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	if (cin.fail()) {
		cin.clear();//清除输入流的错误标志，以便继续读取输入。
		cin.ignore(numeric_limits<streamsize>::max(), '\n');//忽略输入流中直到行末尾的所有内容，包括换行符('\n')，以确保输入流被清空并准备接受新的输入
	}
	else {

		if (a >= 0 && a < 10000000000)
			break;
		else {
			continue;
		}
	}
}
cout << "大写结果是:" << endl;
b = int(a / 10);
a = (a - double(b) * 10) * 100;
c = b / 100000000;//十亿
d = b % 100000000 / 10000000;//亿
e = b % 10000000 / 1000000;//千万
f = b % 1000000 / 100000;//百万
g = b % 100000 / 10000;//十万
h = b % 10000 / 1000;//万
i = b % 1000 / 100;//千
j = b % 100 / 10;//百
k = b % 10;//十
m = int(a / 100);//圆
n = int(a + 0.0001) % 100 / 10;//角
p = int(a + 0.0001) % 10;//分
y = c == 0 && d == 0;
x = c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0;
z = c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k==0 && m == 0;
int state_1 = 0, state_2 = 0, state_3 = 0;/*定义state_n，初始为0，后一数非零得1*/
if (a == 0 && b == 0) {
	daxie(m, 1);
	cout << "圆整";
}

else {
	//先进行拾亿到亿，state_1恒为0
	daxie(c, state_1);
	if (c != 0) {
		cout << "拾";
	}
	daxie(d, state_2);
	if (!y) {
		cout << "亿";
	}
	//再进行仟万到万，state_2遇非0变1，万位始终为0

	if (f != 0) {
		state_2 = 1;
	}
	if (y) {
		state_2 = 0;
	}
	daxie(e, state_2);
	state_2 = 0;
	if (e != 0) {
		cout << "仟";
	}
	if (g != 0) {
		state_2 = 1;
	}
	if (y && e == 0) {
		state_2 = 0;
	}
	daxie(f, state_2);
	
	if (f != 0) {
		cout << "佰";
	}
	if (h != 0) {
		state_2 = 1;
	}
	if (y && e == 0&&f==0) {
		state_2 = 0;
	}
	daxie(g, state_2);
	
	if (g != 0) {
		cout << "拾";
	}
	daxie(h, 0);
	if (e != 0 || f != 0 || g != 0 || h != 0) {
		cout << "万";
	}
	//再进行仟到圆，state_3遇非0变1，圆位始终为0

	if (j != 0) {
		state_3 = 1;
	}
	if (x) {
		state_3 = 0;
	}
	daxie(i, state_3);
	state_3 = 0;
	if (i != 0) {
		cout << "仟";
	}
	if (k != 0) {
		state_3 = 1;
	}
	if (x && i == 0) {
		state_3 = 0;
	}
	daxie(j, state_3);

	if (j != 0) {
		cout << "佰";
	}
	if (m != 0) {
		state_3 = 1;
	}
	if (x && i == 0&&j==0) {
		state_3 = 0;
	}
	daxie(k, state_3);

	if (k != 0) {
		cout << "拾";
	}
	daxie(m, 0);
	if (!z) {
		cout << "圆";
	}
	//再进行小数位
	if (!z) {
		if (n == 0 && p == 0) {
			cout << "整";
		}
		else if (n != 0 && p == 0) {
			daxie(n, 0);
			cout << "角整";
		}
		else if (n == 0 && p != 0) {
			daxie(n, 1);
			daxie(p, 0);
			cout << "分";
		}
		else {
			daxie(n, 0);
			cout << "角";
			daxie(p, 0);
			cout << "分";
		}

	}
	else {
		if (n != 0 && p == 0) {
			daxie(n, 0);
			cout << "角整";
		}
		else if (n == 0 && p != 0) {
			daxie(n, 0);
			daxie(p, 0);
			cout << "分";
		}
		else {
			daxie(n, 0);
			cout << "角";
			daxie(p, 0);
			cout << "分";
		}

	}
}
cout << endl;

	/* 按需完成 */
	return 0;
}
