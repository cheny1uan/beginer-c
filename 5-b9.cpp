/* 2351892 ��11 ������ */

#include <iostream>
#include <iomanip>

using namespace std;

bool sudoku(int board[][9])
{
	int row_sudoku[9][9] = { false };
	int column_sudoku[9][9] = { false };
	int matrix_sudoku[3][3][9] = {false};
	int i, j, num = 0;
	for (i = 0; i < 9;i++) {
		for (j = 0; j < 9; j++) {
			num = board[i][j]-1;
			

			if (row_sudoku[i][num] || column_sudoku[j][num] || matrix_sudoku[i / 3][j / 3][num]) {
				return false;
			}

			row_sudoku[i][num] = true;
			column_sudoku[j][num] = true;
			matrix_sudoku[i / 3][j / 3][num] = true;
		}
	}

	return true;
}

int main()
{
	int board[9][9] = { 0 };
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	int input;
	int i, j;
	bool YorN;

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			
			cin >> input;
			while (input<1||input>9) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(65536, '\n');
									
				}
				cout << "�����������" << i+1 << "��" << j+1 << "��(���о���1��ʼ����)��ֵ" << endl;
				cin >> input;
			}
			board[i][j] = input;
		}
	}
	YorN = sudoku(board);
	if (YorN == true) {
		cout << "�������Ľ�" << endl;
	}
	else {
		cout << "���������Ľ�" << endl;
	}

	return 0;
}