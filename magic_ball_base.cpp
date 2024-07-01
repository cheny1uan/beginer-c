/* 2351892 信11 陈奕炫 */
#include<iostream>
#include"cmd_console_tools.h"
#include"magic_ball.h"
using namespace std;

//对数组进行初始化
void initArray(char ball_arr[][9],int row,int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j< col; j++) {
			ball_arr[i][j] = rand() % 9 + 1+'0';
		}
	}
}
//对标识进行重置
void initFlag(bool remove_flag[][9], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			remove_flag[i][j] = false;
		}
	}
}
//打印数组
void printInternalArray(char ball_arr[][9], int row, int col,bool flag[][9])
{
	cout << "  | ";
	for (int i = 1; i <= col; i++) {
		cout << " " << i << " ";
	}
	cout << endl;
	cout << "--+-";
	for (int i = 1; i <= col; i++) {
		cout << "---";
	}
	cout << endl;
	for (char j = 'A'; j < 'A' + row; j++) {
		cout << j << " | ";
		for (int k = 0; k < col; k++) {
			cout << " ";
			if (flag[j - 'A'][k] == true) {
				cct_setcolor(COLOR_HYELLOW, COLOR_BLUE);
				cout << ball_arr[j - 'A'][k];
				cct_setcolor();
			}
			else {
				cout << ball_arr[j - 'A'][k];
			}
			cout<< " ";
		}
		cout << endl;
	}
	cout << endl;


}
//判断当前状态是否有可消除的
bool isActiveArray(const bool remove_flag[][9],int row,int col)
{
	for (int i = 0 ; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (remove_flag[i][j] == true) {
				return true;
			}
		}
	}
	return false;
}
//判断填充后每一个位置是否可消除
void check_removable_ball(const char ball_arr[][9], bool remove_flag[][9], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int count_y = 1, count_x = 1;
			if (i > 0) {
				if (ball_arr[i][j] == ball_arr[i - 1][j]) {
					count_y++;
					if (i > 1) {
						if (ball_arr[i][j] == ball_arr[i - 2][j]) {
							count_y++;
						}
					}
				}
			}//判断上侧
			if (i < row - 1) {
				if (ball_arr[i][j] == ball_arr[i + 1][j]) {
					count_y++;
					if (i < row - 2) {
						if (ball_arr[i][j] == ball_arr[i + 2][j]) {
							count_y++;
						}
					}
				}
			}//判断下侧
			if (j > 0) {
				if (ball_arr[i][j] == ball_arr[i][j - 1]) {
					count_x++;
					if (j > 1) {
						if (ball_arr[i][j] == ball_arr[i][j - 2]) {
							count_x++;
						}
					}
				}
			}//判断左侧
			if (j < col - 1) {
				if (ball_arr[i][j] == ball_arr[i][j + 1]) {
					count_x++;
					if (j < col - 2) {
						if (ball_arr[i][j] == ball_arr[i][j + 2]) {
							count_x++;
						}
					}
				}
			}//判断右侧
			if (count_x >= 3 || count_y >= 3) {
				remove_flag[i][j] = true;
			}

		}
	}
}
//下落除0操作
void dropAndFillZero(char ball_arr[][9], bool remove_flag[][9], int row, int col)
{
	//首先将消除后位置补零
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (remove_flag[i][j]) {
				ball_arr[i][j] = '0';
				remove_flag[i][j] = false;//重置标志
			}
		}
	}
	//下落
	for (int j = 0; j < col; j++) {//每一列遍历
		for (int i = row - 2; i >= 0; i--) {//每一行，且从下往上进行
			if (ball_arr[i][j] != '0') {
				int y = i;//从每一个位置开始向下下落
				while (y >= 0 && y <= row - 2&&ball_arr[y+1][j]=='0') {					
						ball_arr[y + 1][j] = ball_arr[y][j];
						ball_arr[y][j] = '0';
						y++;					
				}
			}
		}
	}
	//为0位补标识
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (ball_arr[i][j] == '0') {
				remove_flag[i][j] = true;
			}
		}
	}
}
//新值填充
void NewFillZero(char ball_arr[][9], bool remove_flag[][9], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (remove_flag[i][j]&&ball_arr[i][j]=='0') {
				ball_arr[i][j] = rand() % 9 + 1 + '0';
			}
		}
	}
}
//交换位置
void swapBall(char* m, char* n)
{
	char t;
	t = *m;
	*m = *n;
	*n = t;
}
//判断这个位置是否和上下左右相邻位置交换后可消除,若能消除，则给互换的两个位置放标识
void canRemoveAfterSwap(char ball_arr[][9], bool remove_flag[][9],bool canRemove[][9], int row, int col)
{

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (j > 0) {//假如向左交换
				swapBall(&ball_arr[i][j], &ball_arr[i][j - 1]);
				check_removable_ball(ball_arr, remove_flag, row, col);
				if (isActiveArray(remove_flag, row, col)) {
					canRemove[i][j] = true;
					canRemove[i][j - 1] = true;
				}
				swapBall(&ball_arr[i][j], &ball_arr[i][j - 1]);
				initFlag(remove_flag, row, col);
			}
			if (j < col - 1) {//假如向右交换
				swapBall(&ball_arr[i][j], &ball_arr[i][j + 1]);
				check_removable_ball(ball_arr, remove_flag, row, col);
				if (isActiveArray(remove_flag, row, col)) {
					canRemove[i][j] = true;
					canRemove[i][j + 1] = true;
				}

				swapBall(&ball_arr[i][j], &ball_arr[i][j + 1]);
				initFlag(remove_flag, row, col);
			}
			if (i > 0) {//假如向上交换
				swapBall(&ball_arr[i][j], &ball_arr[i - 1][j]);
				check_removable_ball(ball_arr, remove_flag, row, col);
				if (isActiveArray(remove_flag, row, col)) {
					canRemove[i][j] = true;
					canRemove[i - 1][j] = true;
				}

				swapBall(&ball_arr[i][j], &ball_arr[i - 1][j]);
				initFlag(remove_flag, row, col);
			}
			if (i < row - 1) {//假如向下交换
				swapBall(&ball_arr[i][j], &ball_arr[i + 1][j]);
				check_removable_ball(ball_arr, remove_flag, row, col);
				if (isActiveArray(remove_flag, row, col)) {
					canRemove[i][j] = true;
					canRemove[i + 1][j] = true;
				}
				swapBall(&ball_arr[i][j], &ball_arr[i+1][j]);
				initFlag(remove_flag, row, col);

			}
		}
	}


}