/* 2351892 陈奕炫 信11 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：move_by_ijkl_error()
  功    能：用ijkl控制光标
  输入参数：是否回绕（wrap）
  返 回 值：无
  说    明：
***************************************************************************/
void move_by_ijkl_error(int wrap)
{
	char input;
	int x = 35, y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	while (1) {
		input = _getch();
		switch (input) {
			case 'j':
			case 'J':
				if (wrap) {
					if (x > 1) {
						gotoxy(hout, x - 1, y);
						x--;
					}
					else {
						// 光标环绕，从右侧边缘出现
						gotoxy(hout, 69, y);
						x = 69;
					}
				}
				else {
					if (x > 1) {
						gotoxy(hout, x - 1, y);
						x--;
					}
				}
				break;
			case 'i':
			case 'I':
				if (wrap) {
					if (y > 1) {
						gotoxy(hout, x, y - 1);
						y--;
					}
					else {
						// 光标环绕，从底部边缘出现
						gotoxy(hout, x, 17);
						y = 17;
					}
				}
				else {
					if (y > 1) {
						gotoxy(hout, x, y - 1);
						y--;
					}
				}
				break;
			case 'k':
			case 'K':
				if (wrap) {
					if (y < 17) {
						gotoxy(hout, x, y + 1);
						y++;
					}
					else {
						// 光标环绕，从顶部边缘出现
						gotoxy(hout, x, 1);
						y = 1;
					}
				}
				else {
					if (y < 17) {
						gotoxy(hout, x, y + 1);
						y++;
					}
				}
				break;
			case 'l':
			case 'L':
				if (wrap) {
					if (x < 69) {
						gotoxy(hout, x + 1, y);
						x++;
					}
					else {
						// 光标环绕，从左侧边缘出现
						gotoxy(hout, 1, y);
						x = 1;
					}
				}
				else {
					if (x < 69) {
						gotoxy(hout, x + 1, y);
						x++;
					}
				}
				break;
			case ' ':
				cout<<" ";
				gotoxy(hout, x, y);
				break;//删除该处字母并使光标保持原来位置
			case 'q':
			case 'Q':
				gotoxy(hout, 1, 23);
				cout<<"游戏结束，按回车键返回菜单.";
				// 获取输入，直到按下回车
				while (getchar() != '\n') {}
				break;
			default:
				break;
		}
		if (input == 'q' || input == 'Q') {
			break;
		}
		else {
			continue;
		}
	}

}
/***************************************************************************
  函数名称：move_by_ijkl()
  功    能：用ijkl控制光标
  输入参数：是否回绕（wrap）
  返 回 值：无
  说    明：
***************************************************************************/
void move_by_ijkl(int wrap)
{
	char input;
	int x = 35, y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	while (1) {
		input = _getch();
		switch (input) {
			case 'j':
			case 'J':
				if (wrap) {
					if (x > 1) {
						gotoxy(hout, x - 1, y);
						x--;
					}
					else {
						// 光标环绕，从右侧边缘出现
						gotoxy(hout, 69, y);
						x = 69;
					}
				}
				else {
					if (x > 1) {
						gotoxy(hout, x - 1, y);
						x--;
					}
				}
				break;
			case 'i':
			case 'I':
				if (wrap) {
					if (y > 1) {
						gotoxy(hout, x, y - 1);
						y--;
					}
					else {
						// 光标环绕，从底部边缘出现
						gotoxy(hout, x, 17);
						y = 17;
					}
				}
				else {
					if (y > 1) {
						gotoxy(hout, x, y - 1);
						y--;
					}
				}
				break;
			case 'k':
			case 'K':
				if (wrap) {
					if (y < 17) {
						gotoxy(hout, x, y + 1);
						y++;
					}
					else {
						// 光标环绕，从顶部边缘出现
						gotoxy(hout, x, 1);
						y = 1;
					}
				}
				else {
					if (y < 17) {
						gotoxy(hout, x, y + 1);
						y++;
					}
				}
				break;
			case 'l':
			case 'L':
				if (wrap) {
					if (x < 69) {
						gotoxy(hout, x + 1, y);
						x++;
					}
					else {
						// 光标环绕，从左侧边缘出现
						gotoxy(hout, 1, y);
						x = 1;
					}
				}
				else {
					if (x < 69) {
						gotoxy(hout, x + 1, y);
						x++;
					}
				}
				break;
			case ' ':
				cout<<" ";
				gotoxy(hout, x, y);
				break;//删除该处字母并使光标保持原来位置
			case 'q':
			case 'Q':
				gotoxy(hout, 1, 23);
				cout<<"游戏结束，按回车键返回菜单.";
				// 获取输入，直到按下回车
				while (getchar() != '\n') {}
				break;
			case -32:
				input = _getch();
				break;
			default:
				break;
		}
		if (input == 'q' || input == 'Q') {
			break;
		}
		else {
			continue;
		}
	}

}

/***************************************************************************
  函数名称：move_by_arrow()
  功    能：用键盘上下左右箭头控制光标
  输入参数：是否回绕（wrap）
  返 回 值：无
  说    明：
***************************************************************************/
void move_by_arrow(int wrap)
{
	char input;
	int x = 35, y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	while (1) {
		input = _getch();
		if (input == -32) { // 判断是否为特殊键盘输入，特殊键盘输入时_getch返回值有两个，前一个为特殊值-32(char)，后一个才是对应的ascii码值
			input = _getch();
			switch ((int)(input)) {
				case 72: // 上箭头
					if (wrap) {
						if (y > 1) {
							gotoxy(hout, x, y - 1);
							y--;
						}
						else {
							// 光标环绕，从底部边缘出现
							gotoxy(hout, x, 17);
							y = 17;
						}
					}
					else {
						if (y > 1) {
							gotoxy(hout, x, y - 1);
							y--;
						}
					}
					break;
				case 80: // 下箭头
					if (wrap) {
						if (y < 17) {
							gotoxy(hout, x, y + 1);
							y++;
						}
						else {
							// 光标环绕，从顶部边缘出现
							gotoxy(hout, x, 1);
							y = 1;
						}
					}
					else {
						if (y < 17) {
							gotoxy(hout, x, y + 1);
							y++;
						}
					}
					break;
				case 75: // 左箭头
					if (wrap) {
						if (x > 1) {
							gotoxy(hout, x - 1, y);
							x--;
						}
						else {
							// 光标环绕，从右侧边缘出现
							gotoxy(hout, 69, y);
							x = 69;
						}
					}
					else {
						if (x > 1) {
							gotoxy(hout, x - 1, y);
							x--;
						}
					}
					break;
				case 77: // 右箭头
					if (wrap) {
						if (x < 69) {
							gotoxy(hout, x + 1, y);
							x++;
						}
						else {
							// 光标环绕，从左侧边缘出现
							gotoxy(hout, 1, y);
							x = 1;
						}
					}
					else {
						if (x < 69) {
							gotoxy(hout, x + 1, y);
							x++;
						}
					}
					break;
				default:
					break;
			}
		}
		else {
			switch (input) {
				case 'q':
				case 'Q':
					gotoxy(hout, 1, 23);
					cout<<"游戏结束，按回车键返回菜单.";
					// 获取输入，直到按下回车
					while (getchar() != '\n') {}
					break;
				case ' ':
					cout<<" ";
					gotoxy(hout, x, y);
					break;
				default:
					break;
			}
		}
		if (input == 'q' || input == 'Q') {
			break;
		}
		else {
			continue;
		}

	}

}

int menu()
{
	int input_menu;
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右，边界停止" << endl;
	cout << "4.用箭头键控制上下左右，边界回绕" << endl;
	cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止,按左箭头不会向下移动)" << endl;
	cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕,按左箭头不会向下移动)" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-6]";
	input_menu = _getch();

	return input_menu;

}



/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/


int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	srand((unsigned int)(time(0)));//生成伪随机数的种子
	cls(hout);//cls清屏
	int wrap;
	char input_menu;
	int x=35,y=9;

	while (1) {
		input_menu = menu();
		if (input_menu == '0') {
			cout << " 0";
			break;
		}
		else if (input_menu == '1') {
			cls(hout);//cls清屏
			init_border(hout);/* 显示初始的边框及其中的随机字符 */
			gotoxy(hout, 35, 9);
			wrap = 0;
			move_by_ijkl_error(wrap);
			cls(hout);//cls清屏
		}
		else if (input_menu == '2') {
			cls(hout);//cls清屏
			init_border(hout);/* 显示初始的边框及其中的随机字符 */
			gotoxy(hout, 35, 9);
			wrap = 1;
			move_by_ijkl_error(wrap);
			cls(hout);//cls清屏
		}
		else if (input_menu == '3') {
			cls(hout);//cls清屏
			init_border(hout);/* 显示初始的边框及其中的随机字符 */
			gotoxy(hout, 35, 9);
			wrap = 0;
			move_by_arrow(wrap);
			cls(hout);//cls清屏
		}
		else if (input_menu == '4') {
			cls(hout);//cls清屏
			init_border(hout);/* 显示初始的边框及其中的随机字符 */
			gotoxy(hout, 35, 9);
			wrap = 1;
			move_by_arrow(wrap);
			cls(hout);//cls清屏
		}

		/*对于5和6的部分，键盘特殊输入（如此处的方向键）一般是由两个ascii码值组成（方向键前一个都为244，后一个为本身特殊的值），
		而方向左键的后一个特殊值恰好为75，与'K'的值相同。所以在1,2中输入方向左键时即会向下移动。
		而我们只要在switch中对244(char值为-32)这一情况进行特殊判定即可*/


		else if (input_menu == '5') {
			cls(hout);//cls清屏
			init_border(hout);/* 显示初始的边框及其中的随机字符 */
			gotoxy(hout, 35, 9);
			wrap = 0;
			move_by_ijkl(wrap);
			cls(hout);//cls清屏
		}
		else if (input_menu == '6') {
			cls(hout);//cls清屏
			init_border(hout);/* 显示初始的边框及其中的随机字符 */
			gotoxy(hout, 35, 9);
			wrap = 1;
			move_by_ijkl(wrap);
			cls(hout);//cls清屏
		}
		else {
			cls(hout);//cls清屏;
		}

	}
	return 0;
}
/*对伪随机数生成字母小于20的情况的解释：
  1.重复生成相同的坐标：如果rand() % MAX_X + 1和rand() % MAX_Y + 1生成了重复的坐标，那么在相同位置生成的字母会被覆盖，导致实际看到的字母个数少于20个。
这可能发生在MAX_X和MAX_Y的取值范围较小且生成的坐标值有限的情况下。 
  2.生成的坐标超出范围：如果rand() % MAX_X + 1或rand() % MAX_Y + 1生成的坐标超出了有效范围，比如超出了屏幕的宽度或高度，
那么在这些位置生成的字母将不会被显示，导致实际看到的字母个数不足20个。
  3.生成的字母位置重叠：如果随机生成的位置在屏幕上重叠，即多个字母被绘制在同一个位置，那么实际看到的字母个数也会少于20个。*/