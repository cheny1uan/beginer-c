/* 2351892 信11 陈奕炫 */

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
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
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
				cout << "请重新输入第" << i+1 << "行" << j+1 << "列(行列均从1开始计数)的值" << endl;
				cin >> input;
			}
			board[i][j] = input;
		}
	}
	YorN = sudoku(board);
	if (YorN == true) {
		cout << "是数独的解" << endl;
	}
	else {
		cout << "不是数独的解" << endl;
	}

	return 0;
}