/* 2351892 ��11 ������ */
/* 2352469 ��֪�� 2351114 �쿡�� 2353583 ������ 2353738 ���۲� 2352359 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//���Ⱥ궨��ɨ������Ĵ�С
#define MAX_X 10
#define MAX_Y 26
#define NUM_MINES 50

//�ж�ĳһ�������������׵ĸ����������ظø���
int count_round_mines(char map[][MAX_Y+1], int x, int y)
{
    int num = 0;

    if (x >= 1 && y >= 1)
        if (map[x - 1][y - 1] == '*')
            num++;
    if (x >= 1)
        if (map[x - 1][y] == '*')
            num++;
    if (y >= 1)
        if (map[x][y - 1] == '*')
            num++;
    if (x >= 1 && y < MAX_Y)
        if (map[x - 1][y + 1] == '*')
            num++;
    if (y < MAX_Y)
        if (map[x][y + 1] == '*')
            num++;
    if (x < MAX_X && y >= 1)
        if (map[x + 1][y - 1] == '*')
            num++;
    if (x < MAX_X)
        if (map[x + 1][y] == '*')
            num++;
    if (x < MAX_X && y < MAX_Y)
        if (map[x + 1][y + 1] == '*')
            num++;

    return num;
}

int main()
{
  
    char map[MAX_X+1][MAX_Y+1] = { '0' };
    int sum = 0;
    int x, y;
    //����map
    for (x = 0; x <MAX_X; x++) {
        for (y = 0; y <MAX_Y; y++) {
            scanf("%c ", &map[x][y]);
        }
    }

    //��֤���׸���
    for (x = 0; x < MAX_X; x++) {
        for (y = 0; y < MAX_Y; y++) {
            if (map[x][y] == '*') {
                sum++;
           }
        }
    }
    if (sum != NUM_MINES) {
        printf("����1\n");
        return 0;
    }
    //��֤����
    for (x = 0; x < MAX_X; x++) {
        for (y = 0; y < MAX_Y; y++) {
            if (map[x][y] != '*') {
                if (map[x][y] != count_round_mines(map, x, y) + '0') {
                    printf("����2\n");
                    return 0;
                }
             }     
        }
    }
    printf("��ȷ\n");
    return 0;
}
