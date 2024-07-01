/* 2351892 ��11 ������ */
#pragma once

//����menu����
char menu_input();
//������ͣ�������ʾ��
void forwait(const char* promptMessage);
//���������к���
void input_row_col(int* row, int* col);
//������ͱ�ʶ�ĳ�ʼ��
void initArray(char ball_arr[][9],int row,int col);
void initFlag(bool remove_flag[][9], int row, int col);
//��ӡ�ڲ����飨��ͼ�λ���
void printInternalArray(char ball_arr[][9], int row, int col,bool flag[][9]);
//�ж�һ��bool���������Ƿ����1
bool isActiveArray(const bool remove_flag[][9], int row, int col);
//���ÿһ���ط������Ƿ��������
void check_removable_ball(const char ball_arr[][9], bool remove_flag[][9], int row, int col);
//��������
void swapBall(char* m, char* n);
//�ж�ÿһ��λ�õ����Ƿ������ƶ�
void canRemoveAfterSwap(char ball_arr[][9], bool remove_flag[][9], bool canRemove[][9], int row, int col);
//����������
void dropAndFillZero(char ball_arr[][9], bool remove_flag[][9], int row, int col);
//�����ֵ����
void NewFillZero(char ball_arr[][9], bool remove_flag[][9], int row, int col);
//��ȡĳһλ�õ��������ɫ���������ߺ���
int get_pos(int i, const char basis);
int ballColor(char ch);
//ͼ�λ������õ��ĸ��ֺ���
void draw_frame(int row, int col, bool hasSplitLine);
void draw_balls(char ball_arr[][9],bool remove_flag[][9], int row, int col, bool hasSplitLine, bool isShowisActiveArray);
int draw_eliminate(char ball_arr[][9], bool remove_flag[][9], int row, int col);
void draw_drop_balls(char ball_arr[][9], int row, int col);
void draw_fill_balls(char ball_arr[][9], int row, int col);
void draw_can_swap(char ball_arr[][9], bool canRemove[][9], int row, int col);
int mouse_ctrl_game(char ball_arr[][9], bool canRemove[][9], int row, int col,bool game);
void draw_click(int y, int x, int color, const char* action);
bool draw_swap(char ball_arr[][9], bool hasBeClick[][9], int row, int col);
//��ͬģ��ķ�������
void menu_1();
void menu_2();
void menu_3();
void menu_4();
void menu_5();
void menu_6();
void menu_7();
void menu_8();
void menu_9();