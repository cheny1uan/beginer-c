/* 信11 2351892 陈奕炫 */
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

void daxie(int num, int flag_of_zero)
{
	if (num == 0 && flag_of_zero) {
		result = result + chnstr[0] + chnstr[1];
	}

	if (num != 0) {
		result = result + chnstr[num * 2] + chnstr[num * 2 + 1];
	}

}
void num_daxie(double a)
{
	int b, c, d, e, f, g, h, i, j, k, m, n, p;
	int x, y, z;
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
	z = c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && m == 0;
	int state_1 = 0, state_2 = 0, state_3 = 0;/*定义state_n，初始为0，后一数非零得1*/
	if(a == 0 && b == 0) {
		daxie(m, 1);
		result = result + "圆整";
	}

else {
	//先进行拾亿到亿，state_1恒为0
	daxie(c, state_1);
	if (c != 0) {
		result = result + "拾";
	}
	daxie(d, state_2);
	if (!y) {
		result = result + "亿";
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
		result = result + "仟";
	}
	if (g != 0) {
		state_2 = 1;
	}
	if (y && e == 0) {
		state_2 = 0;
	}
	daxie(f, state_2);

	if (f != 0) {
		result = result + "佰";
	}
	if (h != 0) {
		state_2 = 1;
	}
	if (y && e == 0 && f == 0) {
		state_2 = 0;
	}
	daxie(g, state_2);

	if (g != 0) {
		result = result + "拾";
	}
	daxie(h, 0);
	if (e != 0 || f != 0 || g != 0 || h != 0) {
		result = result + "万";
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
		result = result + "仟";
	}
	if (k != 0) {
		state_3 = 1;
	}
	if (x && i == 0) {
		state_3 = 0;
	}
	daxie(j, state_3);

	if (j != 0) {
		result = result + "佰";
	}
	if (m != 0) {
		state_3 = 1;
	}
	if (x && i == 0 && j == 0) {
		state_3 = 0;
	}
	daxie(k, state_3);

	if (k != 0) {
		result = result + "拾";
	}
	daxie(m, 0);
	if (!z) {
		result = result + "圆";
	}
	//再进行小数位
	if (!z) {
		if (n == 0 && p == 0) {
			result = result + "整";
		}
		else if (n != 0 && p == 0) {
			daxie(n, 0);
			result = result + "角整";
		}
		else if (n == 0 && p != 0) {
			daxie(n, 1);
			daxie(p, 0);
			result = result + "分";
		}
		else {
			daxie(n, 0);
			result = result + "角";
			daxie(p, 0);
			result = result + "分";
		}

	}
	else {
		if (n != 0 && p == 0) {
			daxie(n, 0);
			result = result + "角整";
		}
		else if (n == 0 && p != 0) {
			daxie(n, 0);
			daxie(p, 0);
			result = result + "分";
		}
		else {
			daxie(n, 0);
			result = result + "角";
			daxie(p, 0);
			result = result + "分";
		}

	}
	}
	

}

int main()
{
	/*首先对数字进行分解*/
	double a;
	
	while (1) {
		cout << "请输入[0-100亿)之间的数字:" << endl;
		cin >> a;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else {

			if (a >= 0 && a < 10000000000)
				break;
			else {
				continue;
			}
		}
	}
	num_daxie(a);
	cout << "大写结果是:" << endl;
    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}
