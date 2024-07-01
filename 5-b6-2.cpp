/*2351892 信11 陈奕炫*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>

using namespace std;
/*定义全局变量*/
int top[3];//表示三个柱子的栈顶
int arr[3][10];//表示三个柱子的二维数组（行表示柱子ABC，列表示盘子）
int counter=0;//用来计数的全局变量

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
    cout<<"A: ";
    for (i = 0; i < top[0]; i++) {
        cout << arr[0][i] << " ";
    }
    for (i = 0; i < 10 - top[0]; i++) {
        cout << "  ";
    }
    cout << "B: ";
    for (i = 0; i < top[1]; i++) {
        cout << arr[1][i] << " ";
    }
    for (i = 0; i < 10 - top[1]; i++) {
        cout << "  ";
    }
    cout << "C: ";
    for (i = 0; i < top[2]; i++) {
        cout << arr[2][i] << " ";
    }
    for (i = 0; i < 10 - top[2]; i++) {
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
            disk = arr[0][--top[0]];
            break;
        case 'B':
            disk = arr[1][--top[1]];
            break;
        case 'C':
            disk = arr[2][--top[2]];
            break;
    }
    switch (dst) {
        case 'A':
            arr[0][top[0]++] = disk;
            break;
        case 'B':
            arr[1][top[1]++] = disk;
            break;
        case 'C':
            arr[2][top[2]++] = disk;
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
            arr[0][i] = k;
            i++;
        }
        top[0] = n;
        for (i = 0; i < 10; i++) {
            arr[1][i] = 0;
        }
        top[1] = 0;
        for (i = 0; i < 10; i++) {
            arr[2][i] = 0;
        }
        top[2] = 0;
    }
    else if (src == 'B') {
        for (i = 0; k > 0; k--) {
            arr[1][i] = k;
            i++;
        }
        top[1] = n;
        for (i = 0; i < 10; i++) {
            arr[0][i] = 0;
        }
        top[0] = 0;
        for (i = 0; i < 10; i++) {
            arr[2][i] = 0;
        }
        top[2] = 0;
    }
    else if (src == 'C') {
        for (i = 0; k > 0; k--) {
            arr[2][i] = k;
            i++;
        }
        top[2] = n;
        for (i = 0; i < 10; i++) {
            arr[0][i] = 0;
        }
        top[0] = 0;
        for (i = 0; i < 10; i++) {
            arr[1][i] = 0;
        }
        top[1] = 0;
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
    cout << "第" << setw(4) << setiosflags(ios::right) << counter << " " << "步";
    cout << "(" << setw(2) << n << "): ";
    cout << setw(0)<< setiosflags(ios::right);
    cout << src << "-->" << dst << " ";
    print_pillar();
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
    arr_initialization(n, src);
    cout<<"初始:                ";
    print_pillar();
    hanoi(n, src, tmp, dst);
    return 0;
}