/* 2351892 陈奕炫 信11 */
#include<iostream>
#include"cmd_console_tools.h"
#include"magic_ball.h"
#include<windows.h>
#include<conio.h>
using namespace std;

int main()
{
	char menu_options;
	srand(unsigned(time(NULL)));
	
	while (true) {
		cct_setconsoleborder(120, 40, 120, 9000);
		cct_setfontsize("新宋体", 18);
		menu_options = menu_input();
		switch (menu_options)
		{
			case '1':
				menu_1();
				break;
			case '2':
				menu_2();
				break;
			case '3':
				menu_3();
				break;
			case '4':
				menu_4();
				break;
			case '5':
				menu_5();
				break;
			case '6':
				menu_6();
				break;
			case '7':
				menu_7();
				break;
			case '8':
				menu_8();
				break;
			case '9':
				menu_9();
				break;
			case '0':
				cct_gotoxy(0, 24);
				cout << "请按任意键继续...";
				_getch();
				cout << endl;
				return 0;
		}
		forwait("本小题结束，请输入End继续");
	}

	cct_setconsoleborder(120, 40, 120, 9000);
	cct_setfontsize("新宋体", 18);
	return 0;
}