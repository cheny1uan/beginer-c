/* 2351892 信11 陈奕炫 */
/* 2352469 左知行 2351114 朱俊泽 2353583 徐云鹏 2353738 姜观博 2352359 陈艺龙 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//首先宏定义扫雷区域的大小
#define MAX_X 10
#define MAX_Y 26
#define NUM_MINES 50

//判断某一非雷区附近地雷的个数，并返回该个数
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
    //读入map
    for (x = 0; x <MAX_X; x++) {
        for (y = 0; y <MAX_Y; y++) {
            scanf("%c ", &map[x][y]);
        }
    }

    //验证地雷个数
    for (x = 0; x < MAX_X; x++) {
        for (y = 0; y < MAX_Y; y++) {
            if (map[x][y] == '*') {
                sum++;
           }
        }
    }
    if (sum != NUM_MINES) {
        printf("错误1\n");
        return 0;
    }
    //验证数字
    for (x = 0; x < MAX_X; x++) {
        for (y = 0; y < MAX_Y; y++) {
            if (map[x][y] != '*') {
                if (map[x][y] != count_round_mines(map, x, y) + '0') {
                    printf("错误2\n");
                    return 0;
                }
             }     
        }
    }
    printf("正确\n");
    return 0;
}
