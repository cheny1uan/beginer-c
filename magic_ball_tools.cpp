/* 2351892 信11 陈奕炫 */
#include<iostream>
#include<cstring>
#include<conio.h>
#include<Windows.h>
#include"magic_ball.h"
#include"cmd_console_tools.h"
using namespace std;


void forwait(const char* promptMessage)
{
	if (strcmp(promptMessage, "按回车键进行寻找初始可消除项的操作")==0) {
		cout << "按回车键进行寻找初始可消除项的操作...";
		while (_getch() != '\r');
		cout << endl;
	}
	else if (strcmp(promptMessage, "本小题结束，请输入End继续")==0) {
		cout << "本小题结束，请输入End继续..." << endl;
		char ch = 0;
		while (ch = getchar() != '\n' && ch != EOF);
		while (true) {
			char input[50] = { 0 };	
			for (int i = 0; i < 50; i++) {
				input[i] = _getch();

				if (input[i] == '\r') {
					input[i] = 0;
					break;
				}
				cout << input[i];
			}
			if (_stricmp(input, "end") == 0) {
				break;
			}
			else {
				for (unsigned int i = 0; i < strlen(input); i++) {
					cout << '\b' << ' ' << '\b';
				}
				for (int i = 0; i < 50; i++) {
					input[i] = 0;
				}
				cout << "输入错误，请重新输入";
				Sleep(400);
				for (unsigned int i = 0; i < strlen("输入错误，请重新输入"); i++) {
					cout << '\b' << ' ' << '\b';
				}
				
			}
		}
	}
	else if (strcmp(promptMessage, "按回车键进行数组下落除0操作") == 0) {
		cout << "按回车键进行数组下落除0操作...";
		while (_getch() != '\r');
		cout << endl;
	}
	else if (strcmp(promptMessage, "按回车键进行新值填充") == 0) {
		cout << "按回车键进行新值填充...";
		while (_getch() != '\r');
		cout << endl;
	}
	else if (strcmp(promptMessage, "按回车键显示图形") == 0) {
		cout << "按回车键显示图形...";
		while (_getch() != '\r');
		cout << endl;
	}
	else if (strcmp(promptMessage, "按回车键进行消除及下落除0操作") == 0) {
		cout << "按回车键进行消除及下落除0操作...";
		while (_getch() != '\r');
		cout << endl;
	}
	else if (strcmp(promptMessage, "按回车键显示消除提示") == 0) {
		cout << "按回车键显示消除提示...";
		while (_getch() != '\r');
		cout << endl;
	}
}
void input_row_col(int* row, int* col)
{
	while (true) {
		cout << "请输入行数" << endl;
		cin >> *row;
		if (cin.good() && *row >= 5 && *row <= 9) {
			break;
		}
		else {
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	while (true) {
		cout << "请输入列数" << endl;
		cin >> *col;
		if (cin.good() && *col >= 5 && *col <= 9) {
			break;
		}
		else {
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}

	cout << endl;
}
void menu_1()
{
	int row, col;
	input_row_col(&row, &col);
	char ball_arr[9][9] = { 0 };
	bool remove_flag[9][9] = { 0 };
	initArray(ball_arr, row, col);
	cout << "初始数组：" << endl;
	printInternalArray(ball_arr, row, col,remove_flag);
	forwait("按回车键进行寻找初始可消除项的操作");
	check_removable_ball(ball_arr,remove_flag,row,col);
	if (isActiveArray(remove_flag, row, col)) {
		cout << "初始可消除项(不同色标识)：" << endl;
		printInternalArray(ball_arr, row, col, remove_flag);
	}
	else {
		cout << "初始已无可消除项" << endl;
	}
}
void menu_2()
{
	int row, col;
	input_row_col(&row, &col);
	char ball_arr[9][9] = { 0 };
	bool remove_flag[9][9] = { 0 };
	initArray(ball_arr, row, col);
	cout << "初始数组：" << endl;
	printInternalArray(ball_arr, row, col, remove_flag);
	forwait("按回车键进行寻找初始可消除项的操作");
	while (true) {
		check_removable_ball(ball_arr, remove_flag, row, col);
		if (isActiveArray(remove_flag, row, col)) {
			cout << "初始可消除项(不同色标识)：" << endl;
			printInternalArray(ball_arr, row, col, remove_flag);
			
			forwait("按回车键进行数组下落除0操作");
			dropAndFillZero(ball_arr, remove_flag, row, col);
			cout << "下落除0后的数组(不同色标识)：" << endl;
			printInternalArray(ball_arr, row, col, remove_flag);

			forwait("按回车键进行新值填充");
			NewFillZero(ball_arr, remove_flag, row, col);
			cout << "新值填充后的数组(不同色标识)：" << endl;
			printInternalArray(ball_arr, row, col, remove_flag);
			
			initFlag(remove_flag, row, col);//重置标识
			cout << endl;
		}
		else {
			cout << "初始已无可消除项" << endl;
			break;
		}
	}
}
void menu_3()
{
	int row, col;
	input_row_col(&row, &col);
	char ball_arr[9][9] = { 0 };
	bool remove_flag[9][9] = { 0 };
	bool canRemove[9][9] = { 0 };
	initArray(ball_arr, row, col);
	cout << "初始数组：" << endl;
	printInternalArray(ball_arr, row, col, remove_flag);
	forwait("按回车键进行寻找初始可消除项的操作");
	while (true) {
		check_removable_ball(ball_arr, remove_flag, row, col);
		if (isActiveArray(remove_flag, row, col)) {
			cout << "初始可消除项(不同色标识)：" << endl;
			printInternalArray(ball_arr, row, col, remove_flag);

			forwait("按回车键进行数组下落除0操作");
			dropAndFillZero(ball_arr, remove_flag, row, col);
			cout << "下落除0后的数组(不同色标识)：" << endl;
			printInternalArray(ball_arr, row, col, remove_flag);

			forwait("按回车键进行新值填充");
			NewFillZero(ball_arr, remove_flag, row, col);
			cout << "新值填充后的数组(不同色标识)：" << endl;
			printInternalArray(ball_arr, row, col, remove_flag);

			initFlag(remove_flag, row, col);//重置标识
			cout << endl;
		}
		else {
			cout << "初始已无可消除项" << endl;
			break;
		}
	}
	//下面进行假设移动法，来判断移动后可消除的位置
	canRemoveAfterSwap(ball_arr, remove_flag, canRemove, row, col);
	cout << endl;
	cout << "可选择的消除提示(不同色标识)：" << endl;
	printInternalArray(ball_arr, row, col, canRemove);
	cout << endl;
}
void menu_4()
{
	int row, col;
	input_row_col(&row, &col);
	char ball_arr[9][9] = { 0 };
	bool remove_flag[9][9] = { 0 };
	bool canRemove[9][9] = { 0 };
	initArray(ball_arr, row, col);
	cout << "初始数组：" << endl;
	printInternalArray(ball_arr, row, col, remove_flag);
	cout << endl;
	forwait("按回车键显示图形");
	cct_cls();
	
	cct_setfontsize("新宋体", 34);
	cct_setconsoleborder(60, 25);
	cout << "屏幕：" << row + 6 << "行40列" << endl;
	draw_frame(row, col, false);
	draw_balls(ball_arr,remove_flag, row, col,false,false);
	

}
void menu_5()
{
	int row, col;
	input_row_col(&row, &col);
	char ball_arr[9][9] = { 0 };
	bool remove_flag[9][9] = { 0 };
	bool canRemove[9][9] = { 0 };
	initArray(ball_arr, row, col);
	cout << "初始数组：" << endl;
	printInternalArray(ball_arr, row, col, remove_flag);
	cout << endl;
	forwait("按回车键显示图形");
	cct_cls();
	cct_setfontsize("新宋体", 34);
	cct_setconsoleborder(60, 25);
	cout << "屏幕：" << row + 6 << "行40列" << endl;
	draw_frame(row, col, true);
	draw_balls(ball_arr,remove_flag,row, col, true, false);
}
void menu_6()
{
	int row, col;
	input_row_col(&row, &col);
	char ball_arr[9][9] = { 0 };
	bool remove_flag[9][9] = { 0 };
	bool canRemove[9][9] = { 0 };
	initArray(ball_arr, row, col);
	
	cct_cls();
	cct_setfontsize("新宋体", 34);
	cct_setconsoleborder(60, 25);
	cout << "屏幕：" << row + 6 << "行40列" << endl;

	draw_frame(row, col, false);
	check_removable_ball(ball_arr, remove_flag, row, col);
	draw_balls(ball_arr,remove_flag, row, col, false, true);

}
void menu_7()
{
	int row, col;
	input_row_col(&row, &col);
	char ball_arr[9][9] = { 0 };
	bool remove_flag[9][9] = { 0 };
	bool canRemove[9][9] = { 0 };
	initArray(ball_arr, row, col);
	
	cct_cls();
	cct_setfontsize("新宋体", 34);
	cct_setconsoleborder(60, 25);
	cout << "屏幕：" << row + 6 << "行40列" << endl;

	draw_frame(row, col, true);
	check_removable_ball(ball_arr, remove_flag, row, col);
	draw_balls(ball_arr, remove_flag, row, col, true, true);
	forwait("按回车键进行消除及下落除0操作");
	while (true) {
		check_removable_ball(ball_arr, remove_flag, row, col);
		if (isActiveArray(remove_flag, row, col)) {
			draw_eliminate(ball_arr, remove_flag, row, col);
			Sleep(50);
			draw_drop_balls(ball_arr, row, col);
			cct_gotoxy(0, 3 + 2 * row);
			for (int i=0; i < 9; i++) {
				cout << "     ";
			}  
			cct_gotoxy(0, 3 + 2 * row);
			forwait("按回车键进行新值填充");
			draw_fill_balls(ball_arr, row, col);

		}
		else {
			cct_gotoxy(14, 0);
			cout << "(未找到初始可消除项)";
			cct_gotoxy(0, 3 + 2 * row);
			for (int i=0; i < 9; i++) {
				cout << "     ";
			}
			cct_gotoxy(0, 3 + 2 * row);
			forwait("按回车键显示消除提示");
			break;
		}
	}
	canRemoveAfterSwap(ball_arr, remove_flag, canRemove, row, col);
	if (isActiveArray(canRemove, row, col)) {
		draw_can_swap(ball_arr, canRemove, row, col);

		cct_gotoxy(0, 3 + 2 * row);
		for (int i = 0; i < 9; i++) {
			cout << "     ";
		}
		cct_gotoxy(0, 3 + 2 * row);
	}
	else {
		cct_gotoxy(14, 0);
		cout << "(无可消除项，游戏结束！)";
		cct_gotoxy(0, 3 + 2 * row);
	}
}
void menu_8()
{
	int row, col;
	input_row_col(&row, &col);
	char ball_arr[9][9] = { 0 };
	bool remove_flag[9][9] = { 0 };
	bool canRemove[9][9] = { 0 };
	int score = 0;
	initArray(ball_arr, row, col);

	cct_cls();
	cct_setfontsize("新宋体", 34);
	cct_setconsoleborder(60, 25);
	cout << "屏幕：" << row + 6 << "行40列";
	cout << "(当前分数：" << score << " 右键退出)" << endl;

	draw_frame(row, col, true);
	check_removable_ball(ball_arr, remove_flag, row, col);
	draw_balls(ball_arr, remove_flag, row, col, true, true);

	while (true) {
		check_removable_ball(ball_arr, remove_flag, row, col);
		if (isActiveArray(remove_flag, row, col)) {
			draw_eliminate(ball_arr, remove_flag, row, col);
			Sleep(50);
			draw_drop_balls(ball_arr, row, col);
			Sleep(50);
			draw_fill_balls(ball_arr, row, col);

		}
		else {
			break;
		}
	}
	canRemoveAfterSwap(ball_arr, remove_flag, canRemove, row, col);
	if (isActiveArray(canRemove, row, col)) {
		draw_can_swap(ball_arr, canRemove, row, col);
		mouse_ctrl_game(ball_arr, canRemove, row, col,false);
	}
	else {
		cct_gotoxy(9, 0);
		cout << "(无可消除项，游戏结束！)";
		cct_gotoxy(0, 3 + 2 * row);
	}

}
void menu_9()
{
	int row, col;
	input_row_col(&row, &col);
	char ball_arr[9][9] = { 0 };
	bool remove_flag[9][9] = { 0 };
	bool canRemove[9][9] = { 0 };
	int score = 0;
	int action=0;//0为默认，1为进行循环消除，-1为退出
	initArray(ball_arr, row, col);

	cct_cls();
	cct_setfontsize("新宋体", 34);
	cct_setconsoleborder(60, 25);
	cout << "屏幕：" << row + 6 << "行40列";
	cout << "(当前分数：" << score << " 右键退出)                " << endl;

	draw_frame(row, col, true);
	check_removable_ball(ball_arr, remove_flag, row, col);
	draw_balls(ball_arr, remove_flag, row, col, true, true);
	
	while (true) {
		check_removable_ball(ball_arr, remove_flag, row, col);
		if (isActiveArray(remove_flag, row, col)) {
			draw_eliminate(ball_arr, remove_flag, row, col);
			Sleep(50);
			draw_drop_balls(ball_arr, row, col);
			Sleep(50);
			draw_fill_balls(ball_arr, row, col);
		}
		else {
			break;
		}
	}
	
	while (action>=0) {		
		
		canRemoveAfterSwap(ball_arr, remove_flag, canRemove, row, col);
		if (isActiveArray(canRemove, row, col)) {
			draw_can_swap(ball_arr, canRemove, row, col);
			action = 0;
		}
		else {
			draw_can_swap(ball_arr, canRemove, row, col);
			break;//action = -1;
		}
		action = mouse_ctrl_game(ball_arr, canRemove, row, col, true);
		while (action==1) {						
			//先进行消除
			check_removable_ball(ball_arr, remove_flag, row, col);
			score+=draw_eliminate(ball_arr, remove_flag, row, col);
			cct_gotoxy(14, 0);
			cout << "(当前分数：" << score << " 右键退出)                " << endl;
			draw_drop_balls(ball_arr, row, col);
			draw_fill_balls(ball_arr, row, col);
			check_removable_ball(ball_arr, remove_flag, row, col);
			if ((isActiveArray(remove_flag, row, col))) {
				continue;
			}
			else {
				canRemoveAfterSwap(ball_arr, remove_flag, canRemove, row, col);
				if (isActiveArray(canRemove, row, col)) {
					action = 0;
				}
				else {					
					action = -1;					
				}
				draw_can_swap(ball_arr, canRemove, row, col);
			}
		}
		initFlag(remove_flag, row, col);
		initFlag(canRemove, row, col);

	}
	cct_gotoxy(14, 0);
	cout << "(无可消除项，游戏结束！最终得分为：" << score << ")    ";
	cct_gotoxy(0, 3 + 2 * row);
}