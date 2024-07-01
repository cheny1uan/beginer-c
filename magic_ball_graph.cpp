/* 2351892 ��11 ������ */
#include<iostream>
#include"magic_ball.h"
#include"cmd_console_tools.h"
#include<Windows.h>
#include<cmath>

using namespace std;
void draw_frame(int row, int col, bool hasSplitLine)
{

	cct_setcolor(COLOR_WHITE, COLOR_BLACK);
	if (hasSplitLine) {
		cout<< "�X";
		for (int i = 0; i < col; i++) {
			cout << "�T";
			Sleep(10);
			if (i != col - 1) {
				cout << "�j";
				Sleep(10);
			}
			
		}
		cout << "�[" << endl;;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << "�U  ";
				Sleep(10);
			}
			cout << "�U" << endl;
			if (i != row - 1) {
			cout << "�d";	
			cout << "�T";
			Sleep(10);
				for (int k = 0; k < col - 1; k++) {
					cout << "�p";
					cout << "�T";
					Sleep(10);
				}
				cout << "�g" << endl;
			}
			
		}
		cout << "�^";
		for (int i = 0; i < col; i++) {
			cout << "�T";
			Sleep(10);
			if (i != col - 1) {
				cout << "�m";
				Sleep(10);
			}
		}
		cout << "�a" << endl;;
	}
	else {
		cout << "�X";
		for (int i = 0; i < col; i++) {
			cout << "�T";
			Sleep(10);
		}
		cout << "�[";
		for (int i = 0; i < row; i++) {
			cct_gotoxy(0, i + 2);
			cout << "�U";
			cct_gotoxy(2 * (col + 1), i + 2);
			cout << "�U";
			Sleep(10);
		}
		cout << endl;
		cout << "�^";
		for (int i = 0; i < col; i++) {
			cout << "�T";
			Sleep(10);
		}
		cout << "�a";
	}
	cct_setcolor();

}
void draw_balls(char ball_arr[][9], bool remove_flag[][9],int row, int col, bool hasSplitLine, bool isShowisActiveArray)
{
	if (hasSplitLine==false) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int color = ballColor(ball_arr[i][j]);
				if (isShowisActiveArray && remove_flag[i][j]) {
					cct_showstr(2 * (1 + j), 2 + i, "��", color, COLOR_BLACK, 1);
				}
				else {
					cct_showstr(2 * (1 + j), 2 + i, "��", color, COLOR_BLACK, 1);
				}
				Sleep(10);
			}
		}
		cct_gotoxy(0, 3 + row);
	}
	else {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int color = ballColor(ball_arr[i][j]);
				
				if (isShowisActiveArray && remove_flag[i][j]) {
					cct_showstr(2 + 4 * j, 2 + 2 * i, "��", color, COLOR_BLACK, 1);
				}
				else {
					cct_showstr(2 + 4 * j, 2 + 2 * i, "��", color, COLOR_BLACK, 1);
				}
				Sleep(10);
			}
		}
		cct_gotoxy(0, 3 + 2*row);
	}
	cct_setcolor();
	
}
int get_pos(int i, const char basis)
{
	if (basis == 'X') {
		return 2 + 4 * i;
	}
	if (basis == 'Y') {
		return  2 + 2 * i;
	}
	return 0;
}
int ballColor(char ch)
{
	int color;
	color = ch - '0' + 5;
	if (color == COLOR_WHITE) {
		color = COLOR_BLUE;
	}
	return color;
}
int draw_eliminate(char ball_arr[][9], bool remove_flag[][9], int row, int col)
{
	int score=0;
	//�ȱ��ɫ
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (remove_flag[i][j]) {
				int x = get_pos(j, 'X');
				int y = get_pos(i, 'Y');
				int color = ballColor(ball_arr[i][j]);
				cct_showstr(x, y, "��", color, COLOR_BLACK, 1);
			}
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (remove_flag[i][j]) {
				int x = get_pos(j, 'X');
				int y = get_pos(i, 'Y');
				int color = ballColor(ball_arr[i][j]);
				for (int k = 0; k < 6; k++) {
					cct_showstr(x, y, "��", color, COLOR_BLACK, 1);
					Sleep(40);
					cct_showstr(x,y, "��", color, COLOR_BLACK, 1);
					Sleep(40);
				}
				cct_showstr(x, y, "  ",COLOR_WHITE, COLOR_BLACK, 1);
				ball_arr[i][j] = '0';
				score++;
				remove_flag[i][j] = false;//���ñ�־
			}
		}
	}
	cct_setcolor();
	return score;
}
void draw_drop_balls(char ball_arr[][9], int row, int col)
{
	for (int j = 0; j < col; j++) {//ÿһ�б���
		for (int i = row - 2; i >= 0; i--) {//ÿһ�У��Ҵ������Ͻ���
			if (ball_arr[i][j] != '0') {
				int t = i;//��ÿһ��λ�ÿ�ʼ��������,t����׷�ٵ�ǰ����
				while (t >= 0 && t <= row - 2 && ball_arr[t + 1][j] == '0') {
					int x = get_pos(j, 'X');
					int y = get_pos(t, 'Y');
					int color = ballColor(ball_arr[t][j]);
					ball_arr[t + 1][j] = ball_arr[t][j];
					cct_showstr(x, y + 2, "��", color, COLOR_BLACK, 1);
					ball_arr[t][j] = '0';
					cct_showstr(x, y, "  ", COLOR_WHITE, COLOR_BLACK, 1);
					t++;
					Sleep(60);
				}
			}
		}
	}
	cct_setcolor();
}
void draw_fill_balls(char ball_arr[][9], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (ball_arr[i][j] == '0') {
				ball_arr[i][j] = rand() % 9 + 1 + '0';
				int x = get_pos(j, 'X');
				int y = get_pos(i, 'Y');
				int color = ballColor(ball_arr[i][j]);
				cct_showstr(x, y, "��", color, COLOR_BLACK, 1);
				Sleep(100);
			}
		}
	}
	cct_setcolor();
}
void draw_can_swap(char ball_arr[][9], bool canRemove[][9], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (canRemove[i][j]) {
				int x = get_pos(j, 'X');
				int y = get_pos(i, 'Y');
				int color = ballColor(ball_arr[i][j]);
				cct_showstr(x, y, "��", color, COLOR_BLACK, 1);
			}
			else {
				int x = get_pos(j, 'X');
				int y = get_pos(i, 'Y');
				int color = ballColor(ball_arr[i][j]);
				cct_showstr(x, y, "��", color, COLOR_BLACK, 1);
			}
		}
	}
	cct_setcolor();
}
int mouse_ctrl_game(char ball_arr[][9],bool canRemove[][9],int row,int col,bool game)
{
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	bool loop = true;
	bool hasBeClick[9][9] = { 0 };
	int action = 0;
	char* p1 = 0;
	char* p2 = 0;
	cct_enable_mouse();
	
	cct_setcursor(CURSOR_INVISIBLE);//��겻��ʾ
	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT) {			
			cct_gotoxy(0, 3 + 2 * row);
			int x = X / 4;
			int y = Y / 2 - 1;
			
			if ((((X - 2) % 4 == 0) || (X - 3) % 4 == 0)
				&& (Y > 0) && (Y % 2 == 0)
				&&x>=0&&x<col&&y>=0&&y<row) 
			{
				cout << "[��ǰ���]  "  << char(y+'A') << "��" << x+1<<"��    ";
				cct_gotoxy(0, 3 + 2 * row);
				switch (maction) {
					case MOUSE_LEFT_BUTTON_CLICK:			//�������
							if (canRemove[y][x]&&isActiveArray(hasBeClick,row,col)==false ) {
								cct_gotoxy(0, 3 + 2 * row);
								cout << "��ǰѡ��" << char(y + 'A') << "��" << x + 1 << "��               ";
								Sleep(400);
								if (!game) {
									loop = false;
								}
								else {
									hasBeClick[y][x] = true;
									p1 = &ball_arr[y][x];
								}
								draw_click(y, x,ballColor(ball_arr[y][x]), "ѡȡ"); 
							}
							else if (canRemove[y][x] && isActiveArray(hasBeClick, row, col)&&hasBeClick[y][x]==0) {
								hasBeClick[y][x] = true;
								p2 = &ball_arr[y][x];
								bool isReSelect = false;
								isReSelect = draw_swap(ball_arr, hasBeClick, row, col);
								if (isReSelect) {
									//draw_click(y, x, ballColor(ball_arr[y][x]), "ѡȡ");
									initFlag(hasBeClick, row, col);
									//hasBeClick[y][x]=true;
								}
								else {
									swapBall(p1, p2);
									action = 1;
									initFlag(hasBeClick, row, col);
									loop = false;
								}								
							}
							else if (canRemove[y][x] && isActiveArray(hasBeClick, row, col) && hasBeClick[y][x]) {
								draw_click(y, x, ballColor(ball_arr[y][x]), "ȡ��ѡȡ");
								hasBeClick[y][x] = false;
							}
							else {
								cct_gotoxy(0, 3 + 2 * row);
								cout << "����ѡ��" << char(y + 'A') << "��" << x + 1 << "��                ";
								Sleep(500);
							}
						
				
						break;
					case MOUSE_RIGHT_BUTTON_CLICK:			//�����Ҽ�
						loop = 0;
						action = -1;
						Sleep(100);
						break;
					case MOUSE_NO_ACTION:
					default:
						break;
				}
			}
			else {
				cout << "[��ǰ���]  " << "λ�÷Ƿ�";
				
			}			
			
			

		}
		
	}
	cct_gotoxy(0, 3 + 2 * row);
	cct_disable_mouse();	//�������
	cct_setcursor(CURSOR_VISIBLE_NORMAL);	//�򿪹��
	return action;
}

bool canSwapInDraw(char ball_arr[][9],bool hasBeClick[][9], int row, int col)
{
	char* p1=0;
	char* p2=0;
	bool p1Yes = false;
	bool canSwap=false;
	bool remove_flag[9][9] = { 0 };
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < col; j++) {
			if (hasBeClick[i][j]) {
				if (p1Yes == false) {
					p1 = &ball_arr[i][j];
					p1Yes = true;
				}
				else {
					p2 = &ball_arr[i][j];
				}
			}
		}
	}
	swapBall(p1, p2);
	check_removable_ball(ball_arr, remove_flag, row, col);
	if (isActiveArray(remove_flag, row, col)) {
		canSwap = true;
	}
	else {
		canSwap = false;
	}
	swapBall(p1, p2);
	initFlag(remove_flag, row, col);

	return canSwap;
}

void draw_click(int y, int x,int color, const char*action)
{
	int Y = get_pos(y, 'Y');
	int X = get_pos(x, 'X');
	if (strcmp(action, "ѡȡ") == 0) {
		cct_showstr(X, Y, "��",color, COLOR_WHITE, 1);
		cct_setcolor();
	}
	else if (strcmp(action, "ȡ��ѡȡ") == 0) {
		cct_showstr(X, Y, "��", color, COLOR_BLACK, 1);
		cct_setcolor();
	}
	

}

bool draw_swap(char ball_arr[][9], bool hasBeClick[][9], int row, int col)
{
	int x1=0, y1=0, x2=0, y2=0, color1=0, color2=0;
	int i1=0, j1=0, i2=0, j2=0;
	bool theFirst = false;
	bool isAround=false;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (hasBeClick[i][j]) {
				if (theFirst == false) {
					x1 = get_pos(j, 'X');
					j1 = j;
					y1 = get_pos(i, 'Y');
					i1 = i;
					color1 = ballColor(ball_arr[i][j]);
					theFirst = true;
				}
				else {
					x2 = get_pos(j, 'X');
					j2 = j;
					y2 = get_pos(i, 'Y');
					i2 = i;
					color2 = ballColor(ball_arr[i][j]);
				}
			}
		}
	}
	if (abs(x1 - x2)<=4&&abs(y1-y2)<=2&&abs(x1-x2)+abs(y1-y2)<=4) {
		isAround = true;
	}
	else {
		isAround = false;
	}

	if (isAround) {
		if (canSwapInDraw(ball_arr, hasBeClick, row, col)) {
			
			cct_showstr(x1, y1, "��", color2, COLOR_BLACK, 1);
			cct_showstr(x2, y2, "��", color1, COLOR_BLACK, 1);
			
		}
		else {
			cct_gotoxy(0, 3 + 2 * row);
			cout << "���ܽ���" << char(i1 + 'A') << "��" << j1 + 1 << "��<=>" << char(i2 + 'A') << "��" << j2 + 1 << "��                 ";
			Sleep(500);
			draw_click(i1, j1, color1, "ȡ��ѡȡ");
			draw_click(i2, j2, color2, "ȡ��ѡȡ");
			Sleep(500);
			return true;
		}
	}
	else {
		draw_click(i1, j1, color1, "ȡ��ѡȡ");
		draw_click(i2, j2, color2, "ȡ��ѡȡ");
		cct_gotoxy(0, 3 + 2 * row);
		cout << "���ܽ���" << char(i1 + 'A') << "��" << j1 + 1 << "��<=>" << char(i2 + 'A') << "��" << j2 + 1 << "��                 ";
		Sleep(500);
		return true;
	}

	cct_setcolor();
	return false;
}