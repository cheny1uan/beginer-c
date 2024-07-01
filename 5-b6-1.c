/*2351892 ��11 ������*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*����ȫ�ֱ���*/
int top_A, top_B, top_C;//����ָ���������Ӹ��Ե�ջ��+1
int arr_A[10], arr_B[10], arr_C[10];//������ʾ�����һά����
int count=0;//����������ȫ�ֱ���

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
    printf("A: ");
    for (i = 0; i < top_A; i++) {
        printf("%d ", arr_A[i]);
    }
    for (i = 0; i < 10 - top_A; i++) {
        printf("  ");
    }
    printf("B: ");
    for (i = 0; i < top_B; i++) {
        printf("%d ", arr_B[i]);
    }
    for (i = 0; i < 10 - top_B; i++) {
        printf("  ");
    }
    printf("C: ");
    for (i = 0; i < top_C; i++) {
        printf("%d ", arr_C[i]);
    }
    for (i = 0; i < 10 - top_C; i++) {
        printf("  ");
    }
    printf("\n");
}

/***************************************************************************
     �������ƣ�move_disk
     ��    �ܣ��ƶ�����,�ı�ջ��
     ���������char src,dst
     �� �� ֵ��
     ˵    ����
   ***************************************************************************/
void move_disk(char src,char dst)
{
    int disk=0;
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
void arr_initialization(int n,char src)
{
    int i,k;
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
    count++;
    move_disk(src, dst);
    printf("��%4d ��(%2d): %c-->%c ", count, n, src, dst);
    print_pillar();
    hanoi(n - 1, tmp, src, dst);

}


int main()
{
    int n;
    char src, tmp, dst;
    int ret_n;
    char ret_s,ret_d,ch;
    while (1) {
      printf("�����뺺ŵ���Ĳ���(1-10)\n");
        ret_n=scanf("%d",&n);
        while (ch = getchar() != '\n' && ch != EOF);
        if (ret_n!= 1 || n < 1 || n>10) {
            continue;
        }
        else {
            break;
        }
    }
    while (1) {
        printf("��������ʼ��(A-C)\n");
        ret_s = scanf("%c", &src);
        while (ch = getchar() != '\n' && ch != EOF);
        if (src >= 97 && src <= 99) {
            src = src - 32;
        }
        if (ret_s != 1 || src < 'A' || src>'C') {
            continue;
        }
        else {
            break;
        }
    }
    while (1) {
       printf( "������Ŀ����(A-C)\n" );
       ret_d = scanf("%c", &dst);
       while (ch = getchar() != '\n' && ch != EOF);
        if (dst >= 97 && dst <= 99) {
            dst = dst - 32;
        }
        if (ret_d!= 1 || dst < 'A' || dst>'C') {
            continue;
        }
        else if (dst == src) {
            printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n",src,src);
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
    printf("��ʼ:                ");
    print_pillar();
    hanoi(n, src, tmp, dst);
    return 0;
}