/* 2351892 ��11 ������ */
#include<iostream>
#include<iomanip>
#include<windows.h>
#include"5-b7.h"
#define _CRT_SECURE_NO_WARNINGS


using namespace std;

/*����ȫ�ֱ���*/
int top_A, top_B, top_C;//����ָ���������Ӹ��Ե�ջ��+1
int arr_A[10], arr_B[10], arr_C[10];//������ʾ�����һά����
int counter = 0;//����������ȫ�ֱ���
static int show_or_not;
static int speed;

/***************************************************************************
     �������ƣ�speed_ctrl
     ��    �ܣ����ƶ����ٶ�
     ���������
     �� �� ֵ��
     ˵    ����
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
     �������ƣ�draw_pillar
     ��    �ܣ������������
     ���������
     �� �� ֵ��
     ˵    ����
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
     �������ƣ�print_pillar
     ��    �ܣ��������ӵ����
     ���������
     �� �� ֵ��
     ˵    ����
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
     �������ƣ�move_disk
     ��    �ܣ��ƶ�����,�ı�ջ��
     ���������char src,dst
     �� �� ֵ��
     ˵    ����
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
     �������ƣ�arr_initialization
     ��    �ܣ���ʼ��������
     ���������int n������
               char src[10]����ʼ��
               char tmp[10]���м���
               char dst[10]��Ŀ����
     �� �� ֵ��
     ˵    ����
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
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
            char src����ʼ��
            char tmp���м���
            char dst��Ŀ����
  �� �� ֵ��
  ˵    ����
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
    cout << "��" << setw(4) << setiosflags(ios::right) << counter << " " << "��";
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
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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
        cout << "��������ʼ��(A-C)" << endl;
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
        cout << "������Ŀ����(A-C)" << endl;
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
            cout << "Ŀ����(" << src << ")��������ʼ��(" << src << ")��ͬ" << endl;
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
    cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
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
    cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
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
    //��ʼ����
        cct_cls();
        cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed << "��";
        if (show_or_not == 0) {
            cout << "��";
        }
        cout << "��ʾ�ڲ�����ֵ";
       
        
        if (show_or_not == 1) {
            cct_gotoxy(18, 27);
            cout << "��ʼ:                ";
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
        system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��
    
    return 0;
}



