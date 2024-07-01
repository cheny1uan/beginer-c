/*2351892 ��11 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>

using namespace std;
/*����ȫ�ֱ���*/
int top[3];//��ʾ�������ӵ�ջ��
int arr[3][10];//��ʾ�������ӵĶ�ά���飨�б�ʾ����ABC���б�ʾ���ӣ�
int counter=0;//����������ȫ�ֱ���

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
    cout << "��" << setw(4) << setiosflags(ios::right) << counter << " " << "��";
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
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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
    arr_initialization(n, src);
    cout<<"��ʼ:                ";
    print_pillar();
    hanoi(n, src, tmp, dst);
    return 0;
}