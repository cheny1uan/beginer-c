/* 2351892 信11 陈奕炫*/
#include <iostream>
#include <conio.h>
#include<cstring>
using namespace std;

#include "cmd_console_tools.h"
#include "7-b2.h"
/* 1、按需加入头文件
   2、不允许定义全部变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */




/***************************************************************************
  函数名称：
  功    能：判断最右方的位置
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/
static int the_last_x(int start_x,int width)
{
    int cols, lines, buffer_cols, buffer_lines;
    cct_getconsoleborder(cols, lines, buffer_cols, buffer_lines);
    int tmp = cols > buffer_cols ? cols : buffer_cols;
    int last_x = start_x + 2 + width;
    if (last_x > tmp) {
        last_x = tmp;
    }
    return last_x;
}


/***************************************************************************
  函数名称：
  功    能：打印菜单框架
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/
static void print_frame(int width,int high, const struct PopMenu* original_para)
{
    int frame_mid_len;
    int bg_c = original_para->bg_color;
    int fg_c = original_para->fg_color;
    int current_x= original_para->start_x;
    int current_y = original_para->start_y;
    frame_mid_len = width - strlen(original_para->title);
    if (frame_mid_len % 2 != 0) {
        frame_mid_len--;
    }
    frame_mid_len /= 2;
    cct_setcolor(bg_c, fg_c);
    cct_gotoxy(current_x, current_y);
    cout << "╔";
    for (int i = 0; i < frame_mid_len/2; i++) {
        cout << "═";
    }
    cout << original_para->title;
    if (strlen(original_para->title) % 2 != 0) {
        cout << " ";
    }
    if (frame_mid_len % 2 != 0) {
        frame_mid_len++;
    }
    for (int i = 0; i < frame_mid_len/2; i++) {
        cout << "═";
    }
    cout << "╗";
    for (int i = 0; i < high; i++) {
        current_y++;
        cct_gotoxy(current_x, current_y);
        cout << "║";
        for (int j = 0; j < width; j++) {
            cout << " ";
        }
        cout << "║";
    }
    current_y++;
    cct_gotoxy(current_x, current_y);
    cout << "╚";
    for (int i = 0; i < width / 2; i++) {
        cout << "═";
    }
    cout << "╝";



    cct_setcolor();
}

/***************************************************************************
  函数名称：
  功    能：打印指定项的菜单
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/

static void print_line_of_menu(int option,int position, const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para, int last_x,int width,bool isSelect)
{
    int x = original_para->start_x + 2;
    int y = original_para->start_y + position;
    int bg_c = original_para->bg_color;
    int fg_c = original_para->fg_color;
    cct_gotoxy(x, y);
    if (isSelect) {
        cct_setcolor(fg_c, bg_c);
    }
    else {
        cct_setcolor(bg_c, fg_c);
    }

    int i = 0;
    int len;
    for (len = 0; menu[option - 1][i] != 0&&len!=width;) {
        //为汉字的情况
        if (menu[option - 1][i] >= (char)(0xA1) && menu[option - 1][i] <= (char)(0xFE)) {
            if (x + len + 1==last_x) {
                cout << " ";
                len++;
            }
            else {
                cout << menu[option - 1][i];
                cout << menu[option - 1][i + 1];
                i += 2;
                len += 2;
            }

        }
        else {
             cout << menu[option - 1][i];
             i++;
             len++;
        }
    }
    if (len < width) {
        for (int i = len; i <width; i++) {
            cout << " ";
        }
    }
    cct_setcolor();
}

/***************************************************************************
  函数名称：
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
    int option=1;
    int start_x = original_para->start_x;
    int start_y = original_para->start_y;
    int width = original_para->width;
    int high = original_para->high;
    int bg_c = original_para->bg_color;
    int fg_c = original_para->fg_color; 
    //先确定最终高度
    int menu_num=0;
    while (menu[menu_num][0] != NULL) {
        menu_num++;
    }
    if (high > menu_num) {
        high = menu_num;
    }
    //再确定最终宽度
    if (width <int( strlen(original_para->title))) {
        width = int(strlen(original_para->title));
    }
    if (width % 2 != 0) {
        width++;
    }
    
  
    int last_x, last_y;
    last_x = the_last_x(start_x, width);
    last_y = start_y + 1 + high;

    cct_setcursor(CURSOR_INVISIBLE);//关闭鼠标显示

    //先打印框架
    print_frame(width, high, original_para);
    if (menu_num == 0) {
        return -1;
    }
    //下面打印菜单内容
  
    int current_select = 1;//代表现在选中的菜单项，初始为1
    int current_position = 1;//代表现在选中的项在目前菜单中的相对位置
    bool isSelect;
    //初始第一次打印
    for (int i = 1; i <= high; i++) {
        if (i == current_select) {
            isSelect = true;
        }
        else {
            isSelect = false;
        }
        print_line_of_menu(i, i, menu, original_para, last_x, width, isSelect);
    }
    //之后进行键盘操作
    bool loop = true;
    int X = 0, Y = 0;
    int ret, maction;
    int keycode1, keycode2;
    while (loop) {
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        if (ret == CCT_KEYBOARD_EVENT) {
            switch (keycode1) {
                case 27:	//ESC键
                    loop = 0;
                    current_select=-1;
                    break;
                case 224:
                    switch (keycode2) {
                        case KB_ARROW_UP:
                            if (current_position == 1) {
                                if (current_select == 1) {
                                    ;
                                }
                                else {
                                    current_select--;
                                    for (int i = current_select; i - current_select < high; i++) {
                                        if (i == current_select) {
                                            isSelect = true;
                                        }
                                        else {
                                            isSelect = false;
                                        }
                                        print_line_of_menu(i, i-current_select+1, menu, original_para, last_x, width, isSelect);
                                    }
                                }
                            }
                            else {
                                current_select--;
                                current_position--;
                                print_line_of_menu(current_select,current_position , menu, original_para, last_x, width, true);
                                print_line_of_menu(current_select+1, current_position+1, menu, original_para, last_x, width, false);
                            }
                            break;
                        case KB_ARROW_DOWN:
                            if (current_position == high) {
                                if (current_select == menu_num) {
                                    ;
                                }
                                else {
                                    current_select++;
                                    for (int i =current_select-high+1 ; current_select-i>=0; i++) {
                                        if (i == current_select) {
                                            isSelect = true;
                                        }
                                        else {
                                            isSelect = false;
                                        }
                                        print_line_of_menu(i,i-current_select+high, menu, original_para, last_x, width, isSelect);
                                    }
                                }
                            }
                            else {
                                current_select++;
                                current_position++;
                                print_line_of_menu(current_select, current_position, menu, original_para, last_x, width, true);
                                print_line_of_menu(current_select - 1, current_position - 1, menu, original_para, last_x, width, false);
                            }


                            break;
                        default:
                            break;
                    }
                    break;
                case 13:
                    loop = false;//回车键退出
                    break;
                default:	
                    break;
            }
        }
    }
    return current_select; //按需返回
}
