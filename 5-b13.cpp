/* 2351892 信11 陈奕炫*/
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

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
//初始化地雷区域
void map_initialization(char map[][MAX_Y+1])
{
    srand((unsigned int)(time(0)));
    int x, y;
    int i;
    for (i = 0;i < NUM_MINES; i++)
    {
        x = rand() % MAX_X;
        y = rand() % MAX_Y;
        if (map[x][y] == '*')
        {
            i--;
            continue;
        }
        else {
            map[x][y] = '*';
        }
    }
    for (x = 0; x <MAX_X; x++)
    {
        for (y = 0; y <MAX_Y; y++)
        {
            if (map[x][y] != '*')
            map[x][y] = count_round_mines(map,x, y) + '0';            
        }
    }
}

//打印map
void print_map(char map[][MAX_Y+1])
{
    int i, j;
    for (i = 0; i < MAX_X; i++)
    {
        for (j = 0; j < MAX_Y; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    char map[MAX_X+1][MAX_Y+1] = { '0' };
    map_initialization(map);
    print_map(map);   
    return 0;
}
