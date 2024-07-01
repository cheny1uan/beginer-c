/* 信11 2351892 陈奕炫 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */


int daxie(int num, int flag_of_zero,int wei)
{
	if (num == 0 && flag_of_zero) {
		result[wei] = chnstr[0];
		result[wei + 1] = chnstr[1];
		return wei + 2;
	}

	if (num != 0) {
		result[wei] = chnstr[num*2];
		result[wei + 1] = chnstr[num*2+1];
		return wei + 2;
	}
	return wei;
}
void num_daxie(double a)
{
	int b, c, d, e, f, g, h, i, j, k, m, n, p;
	int x, y, z;
	const char unit[] = "拾佰仟万亿圆角分整";
	b = (int)(a / 10);
	a = (a - (double)(b) * 10) * 100;
	c = b / 100000000;//十亿
	d = b % 100000000 / 10000000;//亿
	e = b % 10000000 / 1000000;//千万
	f = b % 1000000 / 100000;//百万
	g = b % 100000 / 10000;//十万
	h = b % 10000 / 1000;//万
	i = b % 1000 / 100;//千
	j = b % 100 / 10;//百
	k = b % 10;//十
	m = (int)(a / 100);//圆
	n = (int)(a + 0.0001) % 100 / 10;//角
	p = (int)(a + 0.0001) % 10;//分
	y = c == 0 && d == 0;
	x = c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0;
	z = c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 && j == 0 && k == 0 && m == 0;
	int state_1 = 0, state_2 = 0, state_3 = 0;/*定义state_n，初始为0，后一数非零得1*/
	int wei = 0;
	if (a == 0 && b == 0) {
		wei=daxie(m, 1,wei);
		result[wei] = unit[10];
		result[wei + 1] = unit[11];
		result[wei+2] = unit[16];
		result[wei + 3] = unit[17];
		wei = wei + 4;
	}

	else {
		//先进行拾亿到亿，state_1恒为0
		wei=daxie(c, state_1,wei);
		if (c != 0) {
			result[wei] = unit[0];
			result[wei+1] = unit[1];
			wei=wei + 2;
		}
		wei=daxie(d, state_2,wei);
		if (!y) {
			result[wei] = unit[8];
			result[wei + 1] = unit[9];
			wei=wei + 2;
		}
		//再进行仟万到万，state_2遇非0变1，万位始终为0

		if (f != 0) {
			state_2 = 1;
		}
		if (y) {
			state_2 = 0;
		}
		wei=daxie(e, state_2,wei);
		state_2 = 0;
		if (e != 0) {
			result[wei] = unit[4];
			result[wei + 1] = unit[5];
			wei=wei + 2;
		}
		if (g != 0) {
			state_2 = 1;
		}
		if (y && e == 0) {
			state_2 = 0;
		}
		wei=daxie(f, state_2,wei);

		if (f != 0) {
			result[wei] = unit[2];
			result[wei + 1] = unit[3];
			wei=wei + 2;
		}
		if (h != 0) {
			state_2 = 1;
		}
		if (y && e == 0 && f == 0) {
			state_2 = 0;
		}
		wei=daxie(g, state_2,wei);

		if (g != 0) {
			result[wei] = unit[0];
			result[wei + 1] = unit[1];
			wei=wei + 2;
		}
		wei=daxie(h, 0,wei);
		if (e != 0 || f != 0 || g != 0 || h != 0) {
			result[wei] = unit[6];
			result[wei + 1] = unit[7];
			wei=wei + 2;
		}
		//再进行仟到圆，state_3遇非0变1，圆位始终为0

		if (j != 0) {
			state_3 = 1;
		}
		if (x) {
			state_3 = 0;
		}
		wei=daxie(i, state_3,wei);
		state_3 = 0;
		if (i != 0) {
			result[wei] = unit[4];
			result[wei + 1] = unit[5];
			wei = wei + 2;
		}
		if (k != 0) {
			state_3 = 1;
		}
		if (x && i == 0) {
			state_3 = 0;
		}
		wei=daxie(j, state_3,wei);

		if (j != 0) {
			result[wei] = unit[2];
			result[wei + 1] = unit[3];
			wei = wei + 2;
		}
		if (m != 0) {
			state_3 = 1;
		}
		if (x && i == 0 && j == 0) {
			state_3 = 0;
		}
		wei=daxie(k, state_3,wei);

		if (k != 0) {
			result[wei] = unit[0];
			result[wei + 1] = unit[1];
			wei = wei + 2;
		}
		wei=daxie(m, 0,wei);
		if (!z) {
			result[wei] = unit[10];
			result[wei + 1] = unit[11];
			wei = wei + 2;
		}
		//再进行小数位
		if (!z) {
			if (n == 0 && p == 0) {
				result[wei] = unit[16];
				result[wei + 1] = unit[17];
				wei = wei + 2;
			}
			else if (n != 0 && p == 0) {
				wei=daxie(n, 0,wei);
				result[wei] = unit[14];
				result[wei + 1] = unit[15];
				wei = wei + 2;
				result[wei] = unit[16];
				result[wei + 1] = unit[17];
				wei = wei + 2;
			}
			else if (n == 0 && p != 0) {
				wei=daxie(n, 1,wei);
				wei=daxie(p, 0,wei);
				result[wei] = unit[14];
				result[wei + 1] = unit[15];
				wei = wei + 2;
			}
			else {
				wei=daxie(n, 0,wei);
				result[wei] = unit[12];
				result[wei + 1] = unit[13];
				wei = wei + 2;;
				wei=daxie(p, 0,wei);
				result[wei] = unit[14];
				result[wei + 1] = unit[15];
				wei = wei + 2;
			}

		}
		else {
			if (n != 0 && p == 0) {
				wei=daxie(n, 0,wei);
				result[wei] = unit[12];
				result[wei + 1] = unit[13];
				wei = wei + 2;
				result[wei] = unit[16];
				result[wei + 1] = unit[17];
				wei = wei + 2;
			}
			else if (n == 0 && p != 0) {
				wei=daxie(n, 0,wei);
				wei=daxie(p, 0,wei);
				result[wei] = unit[14];
				result[wei + 1] = unit[15];
				wei = wei + 2;
			}
			else {
				wei=daxie(n, 0,wei);
				result[wei] = unit[12];
				result[wei + 1] = unit[13];
				wei = wei + 2;
				wei=daxie(p, 0,wei);
				result[wei] = unit[14];
				result[wei + 1] = unit[15];
				wei = wei + 2;
			}

		}
	}

}
int main()
{
    
    double a;
	
	while (1) {
		int ret;
		char ch=0;
		printf("请输入[0-100亿)之间的数字:\n");
		ret = scanf("%lf", &a);
		if (ret!=1) {
			while (ch = getchar() != '\n' && ch != EOF);
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
	printf("大写结果是:\n");
    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}
