/* 2351892 ��11 ������ */
#include<iostream>
#include"cmd_console_tools.h"
#include <conio.h>
#include<Windows.h>
using namespace std;
char menu_input()
{
	char input = 0;
	cct_cls();
	cout << "--------------------------------------------------------------" << endl;
	cout << "1.�ڲ����飬���ɳ�ʼ״̬��Ѱ���Ƿ��г�ʼ��������" << endl;
	cout << "2.�ڲ����飬������ʼ����������0�����䲢��0���" << endl;
	cout << "3.�ڲ����飬������ʼ������������������ʾ" << endl;
	cout << "4.n*n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬" << endl;
	cout << "5.n*n�Ŀ��(�зָ���)����ʾ��ʼ״̬" << endl;
	cout << "6.n*n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬����ʼ��������" << endl;
	cout << "7.n*n�Ŀ��(�зָ���)��������ʼ�����������ʾ������ʾ" << endl;
	cout << "8.cmdͼ�ν���������(�зָ��ߣ�����ƶ�ʱ��ʾ���꣬�Ҽ��˳�)" << endl;
	cout << "9.cmaͼ�ν���������" << endl;
	cout << "0.�˳�" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "[��ѡ��:]";
	while (true) {
		input = _getch();
		if (input >= '0' && input <= '9') {
			cout << input;
			Sleep(300);
			
			break;
		}
	}
	if (input != '0') {
		cct_cls();
	}
	return input;
}