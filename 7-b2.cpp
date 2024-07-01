/* 2351892 ��11 ������*/
#include <iostream>
#include <conio.h>
#include<cstring>
using namespace std;

#include "cmd_console_tools.h"
#include "7-b2.h"
/* 1���������ͷ�ļ�
   2����������ȫ��������������̬ȫ�֣���������const��define
   3����������Ҫ�Ľṹ�塢�����ȣ������ޱ�Դ�����ļ�ʹ�� */




/***************************************************************************
  �������ƣ�
  ��    �ܣ��ж����ҷ���λ��
  ���������
  �� �� ֵ��
  ˵    �����������Դ�����ļ���Ҫ�ĺ���������Ϊstatic����
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
  �������ƣ�
  ��    �ܣ���ӡ�˵����
  ���������
  �� �� ֵ��
  ˵    �����������Դ�����ļ���Ҫ�ĺ���������Ϊstatic����
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
    cout << "�X";
    for (int i = 0; i < frame_mid_len/2; i++) {
        cout << "�T";
    }
    cout << original_para->title;
    if (strlen(original_para->title) % 2 != 0) {
        cout << " ";
    }
    if (frame_mid_len % 2 != 0) {
        frame_mid_len++;
    }
    for (int i = 0; i < frame_mid_len/2; i++) {
        cout << "�T";
    }
    cout << "�[";
    for (int i = 0; i < high; i++) {
        current_y++;
        cct_gotoxy(current_x, current_y);
        cout << "�U";
        for (int j = 0; j < width; j++) {
            cout << " ";
        }
        cout << "�U";
    }
    current_y++;
    cct_gotoxy(current_x, current_y);
    cout << "�^";
    for (int i = 0; i < width / 2; i++) {
        cout << "�T";
    }
    cout << "�a";



    cct_setcolor();
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡָ����Ĳ˵�
  ���������
  �� �� ֵ��
  ˵    �����������Դ�����ļ���Ҫ�ĺ���������Ϊstatic����
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
        //Ϊ���ֵ����
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
  �������ƣ�
  ��    �ܣ��������������õĺ���������������ͷ�ļ���
  ���������
  �� �� ֵ��
  ˵    ����
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
    //��ȷ�����ո߶�
    int menu_num=0;
    while (menu[menu_num][0] != NULL) {
        menu_num++;
    }
    if (high > menu_num) {
        high = menu_num;
    }
    //��ȷ�����տ��
    if (width <int( strlen(original_para->title))) {
        width = int(strlen(original_para->title));
    }
    if (width % 2 != 0) {
        width++;
    }
    
  
    int last_x, last_y;
    last_x = the_last_x(start_x, width);
    last_y = start_y + 1 + high;

    cct_setcursor(CURSOR_INVISIBLE);//�ر������ʾ

    //�ȴ�ӡ���
    print_frame(width, high, original_para);
    if (menu_num == 0) {
        return -1;
    }
    //�����ӡ�˵�����
  
    int current_select = 1;//��������ѡ�еĲ˵����ʼΪ1
    int current_position = 1;//��������ѡ�е�����Ŀǰ�˵��е����λ��
    bool isSelect;
    //��ʼ��һ�δ�ӡ
    for (int i = 1; i <= high; i++) {
        if (i == current_select) {
            isSelect = true;
        }
        else {
            isSelect = false;
        }
        print_line_of_menu(i, i, menu, original_para, last_x, width, isSelect);
    }
    //֮����м��̲���
    bool loop = true;
    int X = 0, Y = 0;
    int ret, maction;
    int keycode1, keycode2;
    while (loop) {
        ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
        if (ret == CCT_KEYBOARD_EVENT) {
            switch (keycode1) {
                case 27:	//ESC��
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
                    loop = false;//�س����˳�
                    break;
                default:	
                    break;
            }
        }
    }
    return current_select; //���践��
}
