/* 2351892 ��11 ������ */
#include<iostream>
#include<cstring>
#include<conio.h>
#include<Windows.h>
#include"magic_ball.h"
#include"cmd_console_tools.h"
using namespace std;


void forwait(const char* promptMessage)
{
	if (strcmp(promptMessage, "���س�������Ѱ�ҳ�ʼ��������Ĳ���")==0) {
		cout << "���س�������Ѱ�ҳ�ʼ��������Ĳ���...";
		while (_getch() != '\r');
		cout << endl;
	}
	else if (strcmp(promptMessage, "��С�������������End����")==0) {
		cout << "��С�������������End����..." << endl;
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
				cout << "�����������������";
				Sleep(400);
				for (unsigned int i = 0; i < strlen("�����������������"); i++) {
					cout << '\b' << ' ' << '\b';
				}
				
			}
		}
	}
	else if (strcmp(promptMessage, "���س����������������0����") == 0) {
		cout << "���س����������������0����...";
		while (_getch() != '\r');
		cout << endl;
	}
	else if (strcmp(promptMessage, "���س���������ֵ���") == 0) {
		cout << "���س���������ֵ���...";
		while (_getch() != '\r');
		cout << endl;
	}
	else if (strcmp(promptMessage, "���س�����ʾͼ��") == 0) {
		cout << "���س�����ʾͼ��...";
		while (_getch() != '\r');
		cout << endl;
	}
	else if (strcmp(promptMessage, "���س������������������0����") == 0) {
		cout << "���س������������������0����...";
		while (_getch() != '\r');
		cout << endl;
	}
	else if (strcmp(promptMessage, "���س�����ʾ������ʾ") == 0) {
		cout << "���س�����ʾ������ʾ...";
		while (_getch() != '\r');
		cout << endl;
	}
}
void input_row_col(int* row, int* col)
{
	while (true) {
		cout << "����������" << endl;
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
		cout << "����������" << endl;
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
	cout << "��ʼ���飺" << endl;
	printInternalArray(ball_arr, row, col,remove_flag);
	forwait("���س�������Ѱ�ҳ�ʼ��������Ĳ���");
	check_removable_ball(ball_arr,remove_flag,row,col);
	if (isActiveArray(remove_flag, row, col)) {
		cout << "��ʼ��������(��ͬɫ��ʶ)��" << endl;
		printInternalArray(ball_arr, row, col, remove_flag);
	}
	else {
		cout << "��ʼ���޿�������" << endl;
	}
}
void menu_2()
{
	int row, col;
	input_row_col(&row, &col);
	char ball_arr[9][9] = { 0 };
	bool remove_flag[9][9] = { 0 };
	initArray(ball_arr, row, col);
	cout << "��ʼ���飺" << endl;
	printInternalArray(ball_arr, row, col, remove_flag);
	forwait("���س�������Ѱ�ҳ�ʼ��������Ĳ���");
	while (true) {
		check_removable_ball(ball_arr, remove_flag, row, col);
		if (isActiveArray(remove_flag, row, col)) {
			cout << "��ʼ��������(��ͬɫ��ʶ)��" << endl;
			printInternalArray(ball_arr, row, col, remove_flag);
			
			forwait("���س����������������0����");
			dropAndFillZero(ball_arr, remove_flag, row, col);
			cout << "�����0�������(��ͬɫ��ʶ)��" << endl;
			printInternalArray(ball_arr, row, col, remove_flag);

			forwait("���س���������ֵ���");
			NewFillZero(ball_arr, remove_flag, row, col);
			cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
			printInternalArray(ball_arr, row, col, remove_flag);
			
			initFlag(remove_flag, row, col);//���ñ�ʶ
			cout << endl;
		}
		else {
			cout << "��ʼ���޿�������" << endl;
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
	cout << "��ʼ���飺" << endl;
	printInternalArray(ball_arr, row, col, remove_flag);
	forwait("���س�������Ѱ�ҳ�ʼ��������Ĳ���");
	while (true) {
		check_removable_ball(ball_arr, remove_flag, row, col);
		if (isActiveArray(remove_flag, row, col)) {
			cout << "��ʼ��������(��ͬɫ��ʶ)��" << endl;
			printInternalArray(ball_arr, row, col, remove_flag);

			forwait("���س����������������0����");
			dropAndFillZero(ball_arr, remove_flag, row, col);
			cout << "�����0�������(��ͬɫ��ʶ)��" << endl;
			printInternalArray(ball_arr, row, col, remove_flag);

			forwait("���س���������ֵ���");
			NewFillZero(ball_arr, remove_flag, row, col);
			cout << "��ֵ���������(��ͬɫ��ʶ)��" << endl;
			printInternalArray(ball_arr, row, col, remove_flag);

			initFlag(remove_flag, row, col);//���ñ�ʶ
			cout << endl;
		}
		else {
			cout << "��ʼ���޿�������" << endl;
			break;
		}
	}
	//������м����ƶ��������ж��ƶ����������λ��
	canRemoveAfterSwap(ball_arr, remove_flag, canRemove, row, col);
	cout << endl;
	cout << "��ѡ���������ʾ(��ͬɫ��ʶ)��" << endl;
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
	cout << "��ʼ���飺" << endl;
	printInternalArray(ball_arr, row, col, remove_flag);
	cout << endl;
	forwait("���س�����ʾͼ��");
	cct_cls();
	
	cct_setfontsize("������", 34);
	cct_setconsoleborder(60, 25);
	cout << "��Ļ��" << row + 6 << "��40��" << endl;
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
	cout << "��ʼ���飺" << endl;
	printInternalArray(ball_arr, row, col, remove_flag);
	cout << endl;
	forwait("���س�����ʾͼ��");
	cct_cls();
	cct_setfontsize("������", 34);
	cct_setconsoleborder(60, 25);
	cout << "��Ļ��" << row + 6 << "��40��" << endl;
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
	cct_setfontsize("������", 34);
	cct_setconsoleborder(60, 25);
	cout << "��Ļ��" << row + 6 << "��40��" << endl;

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
	cct_setfontsize("������", 34);
	cct_setconsoleborder(60, 25);
	cout << "��Ļ��" << row + 6 << "��40��" << endl;

	draw_frame(row, col, true);
	check_removable_ball(ball_arr, remove_flag, row, col);
	draw_balls(ball_arr, remove_flag, row, col, true, true);
	forwait("���س������������������0����");
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
			forwait("���س���������ֵ���");
			draw_fill_balls(ball_arr, row, col);

		}
		else {
			cct_gotoxy(14, 0);
			cout << "(δ�ҵ���ʼ��������)";
			cct_gotoxy(0, 3 + 2 * row);
			for (int i=0; i < 9; i++) {
				cout << "     ";
			}
			cct_gotoxy(0, 3 + 2 * row);
			forwait("���س�����ʾ������ʾ");
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
		cout << "(�޿��������Ϸ������)";
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
	cct_setfontsize("������", 34);
	cct_setconsoleborder(60, 25);
	cout << "��Ļ��" << row + 6 << "��40��";
	cout << "(��ǰ������" << score << " �Ҽ��˳�)" << endl;

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
		cout << "(�޿��������Ϸ������)";
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
	int action=0;//0ΪĬ�ϣ�1Ϊ����ѭ��������-1Ϊ�˳�
	initArray(ball_arr, row, col);

	cct_cls();
	cct_setfontsize("������", 34);
	cct_setconsoleborder(60, 25);
	cout << "��Ļ��" << row + 6 << "��40��";
	cout << "(��ǰ������" << score << " �Ҽ��˳�)                " << endl;

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
			//�Ƚ�������
			check_removable_ball(ball_arr, remove_flag, row, col);
			score+=draw_eliminate(ball_arr, remove_flag, row, col);
			cct_gotoxy(14, 0);
			cout << "(��ǰ������" << score << " �Ҽ��˳�)                " << endl;
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
	cout << "(�޿��������Ϸ���������յ÷�Ϊ��" << score << ")    ";
	cct_gotoxy(0, 3 + 2 * row);
}