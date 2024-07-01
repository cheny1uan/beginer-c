/* 2351892 信11 陈奕炫 */
#include<iostream>
#include<iomanip>
#include<windows.h>
#include"5-b7.h"
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

/*定义全局变量*/
int top_A, top_B, top_C;//三者指向三个柱子各自的栈顶+1
int arr_A[10], arr_B[10], arr_C[10];//三个表示数组的一维数组
int counter = 0;//用来计数的全局变量
static int show_or_not;
static int speed;

/***************************************************************************
     函数名称：speed_ctrl
     功    能：控制动画速度
     输入参数：
     返 回 值：
     说    明：
   ***************************************************************************/
void speed_ctrl()
{
    char ch;
    if (speed == 0) {
        while (1) {
            ch = getchar();
            if (ch == '\n') {
                break;
            }
        }
    }
    else if (speed == 1) {
        Sleep(1000);
    }
    else if (speed == 2) {
        Sleep(800);
    }
    else if (speed == 3) {
        Sleep(600);
    }
    else if (speed == 4) {
        Sleep(400);
    }
    else if (speed == 5) {
        Sleep(200);
    }



}
/***************************************************************************
     函数名称：draw_pillar
     功    能：输出纵向柱子
     输入参数：
     返 回 值：
     说    明：
   ***************************************************************************/
void draw_pillar()
{
    int  y = 21;
    int i;
    
    for (i = 0; i < top_A; i++) {
        cct_gotoxy(11, y-i);
        cout << arr_A[i];
    }
    for (i = top_A; i < 10; i++) {
        cct_gotoxy(11, y - i);
        cout << ' ';
    }

    
    for (i = 0; i < top_B; i++) {
        cct_gotoxy(21, y-i);
        cout << arr_B[i];
    }
    for (i = top_B; i < 10; i++) {
        cct_gotoxy(21, y - i);
        cout << ' ';
    }
    
    for (i = 0; i < top_C; i++) {
        cct_gotoxy(31, y-i);
        cout << arr_C[i];
    }
    for (i = top_C; i < 10; i++) {
        cct_gotoxy(31, y - i);
        cout << ' ';
    }
    
}

/***************************************************************************
     函数名称：print_pillar
     功    能：进行柱子的输出
     输入参数：
     返 回 值：
     说    明：
   ***************************************************************************/
void print_pillar()
{
    int i;
   
    cout << "A: ";
    for (i = 0; i < top_A; i++) {
        cout << arr_A[i] << " ";
    }
    for (i = 0; i < 10 - top_A; i++) {
        cout << "  ";
    }
    cout << "B: ";
    for (i = 0; i < top_B; i++) {
        cout << arr_B[i] << " ";
    }
    for (i = 0; i < 10 - top_B; i++) {
        cout << "  ";
    }
    cout << "C: ";
    for (i = 0; i < top_C; i++) {
        cout << arr_C[i] << " ";
    }
    for (i = 0; i < 10 - top_C; i++) {
        cout << "  ";
    }
    cout << endl;
}

/***************************************************************************
     函数名称：move_disk
     功    能：移动盘子,改变栈顶
     输入参数：char src,dst
     返 回 值：
     说    明：
   ***************************************************************************/
void move_disk(char src, char dst)
{
    int disk = 0;
    switch (src) {
        case 'A':
            disk = arr_A[--top_A];
            break;
        case 'B':
            disk = arr_B[--top_B];
            break;
        case 'C':
            disk = arr_C[--top_C];
            break;
    }
    switch (dst) {
        case 'A':
            arr_A[top_A++] = disk;
            break;
        case 'B':
            arr_B[top_B++] = disk;
            break;
        case 'C':
            arr_C[top_C++] = disk;
            break;
    }
}

/***************************************************************************
     函数名称：arr_initialization
     功    能：初始化各数组
     输入参数：int n：层数
               char src[10]：起始柱
               char tmp[10]：中间柱
               char dst[10]：目标柱
     返 回 值：
     说    明：
   ***************************************************************************/
void arr_initialization(int n, char src)
{
    int i, k;
    k = n;

    if (src == 'A') {
        for (i = 0; k > 0; k--) {
            arr_A[i] = k;
            i++;
        }
        top_A = n;
        for (i = 0; i < 10; i++) {
            arr_B[i] = 0;
        }
        top_B = 0;
        for (i = 0; i < 10; i++) {
            arr_C[i] = 0;
        }
        top_C = 0;
    }
    else if (src == 'B') {
        for (i = 0; k > 0; k--) {
            arr_B[i] = k;
            i++;
        }
        top_B = n;
        for (i = 0; i < 10; i++) {
            arr_A[i] = 0;
        }
        top_A = 0;
        for (i = 0; i < 10; i++) {
            arr_C[i] = 0;
        }
        top_C = 0;
    }
    else if (src == 'C') {
        for (i = 0; k > 0; k--) {
            arr_C[i] = k;
            i++;
        }
        top_C = n;
        for (i = 0; i < 10; i++) {
            arr_A[i] = 0;
        }
        top_A = 0;
        for (i = 0; i < 10; i++) {
            arr_B[i] = 0;
        }
        top_B = 0;
    }
}



/***************************************************************************
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
            char src：起始柱
            char tmp：中间柱
            char dst：目标柱
  返 回 值：
  说    明：
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{


    if (n == 0) {
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    counter++;
    move_disk(src, dst);
    
   
    cct_gotoxy(18, 27);
    cout << "第" << setw(4) << setiosflags(ios::right) << counter << " " << "步";
    cout << "(" << setw(2) << n << "): ";
    cout << setw(0) << setiosflags(ios::right);
    cout << src << "-->" << dst << " ";
   
    if (show_or_not == 1) {
        print_pillar();
    }
    
    draw_pillar();
    speed_ctrl();
    hanoi(n - 1, tmp, src, dst);

}


int main()
{
    int n;
    char src, tmp, dst;
   
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        cin.ignore(65536, '\n');
        if (cin.good() == 0 || n < 1 || n>10) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else {
            break;
        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        cin.ignore(65536, '\n');
        if (src >= 97 && src <= 99) {
            src = src - 32;
        }
        if (cin.good() == 0 || src < 'A' || src>'C') {
            cin.clear();
            continue;
        }
        else {
            break;
        }
    }
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.ignore(65536, '\n');
        if (dst >= 97 && dst <= 99) {
            dst = dst - 32;
        }
        if (cin.good() == 0 || dst < 'A' || dst>'C') {
            cin.clear();
            continue;
        }
        else if (dst == src) {
            cout << "目标柱(" << src << ")不能与起始柱(" << src << ")相同" << endl;
            continue;
        }
        else {
            break;
        }
    }
    if (src == 'A') {
        if (dst == 'B') {
            tmp = 'C';
        }
        else {
            tmp = 'B';
        }
    }
    else if (src == 'B') {
        if (dst == 'A') {
            tmp = 'C';
        }
        else {
            tmp = 'A';
        }
    }
    else {
        if (dst == 'A') {
            tmp = 'B';
        }
        else {
            tmp = 'A';
        }
    }
    cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
    while (1) {
        cin >> speed;
        if (cin.good() == 0 || speed < 0 || speed>5) {
            cin.clear();
            cin.ignore(65536, '\n'); 
            continue;
        }
        else {
            break;
        }
    }
    cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
    while (1) {
        cin >> show_or_not;
        if (cin.good() == 0 || show_or_not < 0 || show_or_not>1) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else {
            break;
        }
    }
    cin.ignore(65536, '\n');
    arr_initialization(n, src);
    //初始操作
        cct_cls();
        cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed << "，";
        if (show_or_not == 0) {
            cout << "不";
        }
        cout << "显示内部数组值";
       
        
        if (show_or_not == 1) {
            cct_gotoxy(18, 27);
            cout << "初始:                ";
            print_pillar();
            speed_ctrl();
        }   
        
        cct_gotoxy(9,22);
        cout << "=========================";
        cct_gotoxy(11, 23);
        cout << "A         B         C";
        draw_pillar();

        speed_ctrl();
        
        hanoi(n, src, tmp, dst);
        cct_gotoxy(18, 37);
        system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
    
    return 0;
}



