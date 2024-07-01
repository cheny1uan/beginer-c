/* 2351892 ��11 ������ */
#include<iostream>
#include"cmd_console_tools.h"
#include"magic_ball.h"
using namespace std;

//��������г�ʼ��
void initArray(char ball_arr[][9],int row,int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j< col; j++) {
			ball_arr[i][j] = rand() % 9 + 1+'0';
		}
	}
}
//�Ա�ʶ��������
void initFlag(bool remove_flag[][9], int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			remove_flag[i][j] = false;
		}
	}
}
//��ӡ����
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
//�жϵ�ǰ״̬�Ƿ��п�������
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
//�ж�����ÿһ��λ���Ƿ������
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
			}//�ж��ϲ�
			if (i < row - 1) {
				if (ball_arr[i][j] == ball_arr[i + 1][j]) {
					count_y++;
					if (i < row - 2) {
						if (ball_arr[i][j] == ball_arr[i + 2][j]) {
							count_y++;
						}
					}
				}
			}//�ж��²�
			if (j > 0) {
				if (ball_arr[i][j] == ball_arr[i][j - 1]) {
					count_x++;
					if (j > 1) {
						if (ball_arr[i][j] == ball_arr[i][j - 2]) {
							count_x++;
						}
					}
				}
			}//�ж����
			if (j < col - 1) {
				if (ball_arr[i][j] == ball_arr[i][j + 1]) {
					count_x++;
					if (j < col - 2) {
						if (ball_arr[i][j] == ball_arr[i][j + 2]) {
							count_x++;
						}
					}
				}
			}//�ж��Ҳ�
			if (count_x >= 3 || count_y >= 3) {
				remove_flag[i][j] = true;
			}

		}
	}
}
//�����0����
void dropAndFillZero(char ball_arr[][9], bool remove_flag[][9], int row, int col)
{
	//���Ƚ�������λ�ò���
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (remove_flag[i][j]) {
				ball_arr[i][j] = '0';
				remove_flag[i][j] = false;//���ñ�־
			}
		}
	}
	//����
	for (int j = 0; j < col; j++) {//ÿһ�б���
		for (int i = row - 2; i >= 0; i--) {//ÿһ�У��Ҵ������Ͻ���
			if (ball_arr[i][j] != '0') {
				int y = i;//��ÿһ��λ�ÿ�ʼ��������
				while (y >= 0 && y <= row - 2&&ball_arr[y+1][j]=='0') {					
						ball_arr[y + 1][j] = ball_arr[y][j];
						ball_arr[y][j] = '0';
						y++;					
				}
			}
		}
	}
	//Ϊ0λ����ʶ
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (ball_arr[i][j] == '0') {
				remove_flag[i][j] = true;
			}
		}
	}
}
//��ֵ���
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
//����λ��
void swapBall(char* m, char* n)
{
	char t;
	t = *m;
	*m = *n;
	*n = t;
}
//�ж����λ���Ƿ��������������λ�ý����������,�����������������������λ�÷ű�ʶ
void canRemoveAfterSwap(char ball_arr[][9], bool remove_flag[][9],bool canRemove[][9], int row, int col)
{

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (j > 0) {//�������󽻻�
				swapBall(&ball_arr[i][j], &ball_arr[i][j - 1]);
				check_removable_ball(ball_arr, remove_flag, row, col);
				if (isActiveArray(remove_flag, row, col)) {
					canRemove[i][j] = true;
					canRemove[i][j - 1] = true;
				}
				swapBall(&ball_arr[i][j], &ball_arr[i][j - 1]);
				initFlag(remove_flag, row, col);
			}
			if (j < col - 1) {//�������ҽ���
				swapBall(&ball_arr[i][j], &ball_arr[i][j + 1]);
				check_removable_ball(ball_arr, remove_flag, row, col);
				if (isActiveArray(remove_flag, row, col)) {
					canRemove[i][j] = true;
					canRemove[i][j + 1] = true;
				}

				swapBall(&ball_arr[i][j], &ball_arr[i][j + 1]);
				initFlag(remove_flag, row, col);
			}
			if (i > 0) {//�������Ͻ���
				swapBall(&ball_arr[i][j], &ball_arr[i - 1][j]);
				check_removable_ball(ball_arr, remove_flag, row, col);
				if (isActiveArray(remove_flag, row, col)) {
					canRemove[i][j] = true;
					canRemove[i - 1][j] = true;
				}

				swapBall(&ball_arr[i][j], &ball_arr[i - 1][j]);
				initFlag(remove_flag, row, col);
			}
			if (i < row - 1) {//�������½���
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