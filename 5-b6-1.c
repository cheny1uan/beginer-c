/*2351892 信11 陈奕炫*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*定义全局变量*/
int top_A, top_B, top_C;//三者指向三个柱子各自的栈顶+1
int arr_A[10], arr_B[10], arr_C[10];//三个表示数组的一维数组
int count=0;//用来计数的全局变量

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
     函数名称：move_disk
     功    能：移动盘子,改变栈顶
     输入参数：char src,dst
     返 回 值：
     说    明：
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
     函数名称：arr_initialization
     功    能：初始化各数组
     输入参数：int n：层数
               char src[10]：起始柱
               char tmp[10]：中间柱
               char dst[10]：目标柱
     返 回 值：
     说    明：
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
    count++;
    move_disk(src, dst);
    printf("第%4d 步(%2d): %c-->%c ", count, n, src, dst);
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
      printf("请输入汉诺塔的层数(1-10)\n");
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
        printf("请输入起始柱(A-C)\n");
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
       printf( "请输入目标柱(A-C)\n" );
       ret_d = scanf("%c", &dst);
       while (ch = getchar() != '\n' && ch != EOF);
        if (dst >= 97 && dst <= 99) {
            dst = dst - 32;
        }
        if (ret_d!= 1 || dst < 'A' || dst>'C') {
            continue;
        }
        else if (dst == src) {
            printf("目标柱(%c)不能与起始柱(%c)相同\n",src,src);
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
    printf("初始:                ");
    print_pillar();
    hanoi(n, src, tmp, dst);
    return 0;
}