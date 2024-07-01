/* 2351892 信11 陈奕炫 */
#pragma once

//负责menu输入
char menu_input();
//负责暂停并输出提示语
void forwait(const char* promptMessage);
//负责输入行和列
void input_row_col(int* row, int* col);
//对数组和标识的初始化
void initArray(char ball_arr[][9],int row,int col);
void initFlag(bool remove_flag[][9], int row, int col);
//打印内部数组（非图形化）
void printInternalArray(char ball_arr[][9], int row, int col,bool flag[][9]);
//判断一个bool型数组中是否存在1
bool isActiveArray(const bool remove_flag[][9], int row, int col);
//检查每一个地方的球是否可以消除
void check_removable_ball(const char ball_arr[][9], bool remove_flag[][9], int row, int col);
//交换两球
void swapBall(char* m, char* n);
//判断每一个位置的球是否允许移动
void canRemoveAfterSwap(char ball_arr[][9], bool remove_flag[][9], bool canRemove[][9], int row, int col);
//下落除零操作
void dropAndFillZero(char ball_arr[][9], bool remove_flag[][9], int row, int col);
//填充新值操作
void NewFillZero(char ball_arr[][9], bool remove_flag[][9], int row, int col);
//获取某一位置的坐标和颜色的两个工具函数
int get_pos(int i, const char basis);
int ballColor(char ch);
//图形化界面用到的各种函数
void draw_frame(int row, int col, bool hasSplitLine);
void draw_balls(char ball_arr[][9],bool remove_flag[][9], int row, int col, bool hasSplitLine, bool isShowisActiveArray);
int draw_eliminate(char ball_arr[][9], bool remove_flag[][9], int row, int col);
void draw_drop_balls(char ball_arr[][9], int row, int col);
void draw_fill_balls(char ball_arr[][9], int row, int col);
void draw_can_swap(char ball_arr[][9], bool canRemove[][9], int row, int col);
int mouse_ctrl_game(char ball_arr[][9], bool canRemove[][9], int row, int col,bool game);
void draw_click(int y, int x, int color, const char* action);
bool draw_swap(char ball_arr[][9], bool hasBeClick[][9], int row, int col);
//不同模块的分区函数
void menu_1();
void menu_2();
void menu_3();
void menu_4();
void menu_5();
void menu_6();
void menu_7();
void menu_8();
void menu_9();