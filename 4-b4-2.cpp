/* 2351892 ������ ��11 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ�move_by_ijkl_error()
  ��    �ܣ���ijkl���ƹ��
  ����������Ƿ���ƣ�wrap��
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void move_by_ijkl_error(int wrap)
{
	char input;
	int x = 35, y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	while (1) {
		input = _getch();
		switch (input) {
			case 'j':
			case 'J':
				if (wrap) {
					if (x > 1) {
						gotoxy(hout, x - 1, y);
						x--;
					}
					else {
						// ��껷�ƣ����Ҳ��Ե����
						gotoxy(hout, 69, y);
						x = 69;
					}
				}
				else {
					if (x > 1) {
						gotoxy(hout, x - 1, y);
						x--;
					}
				}
				break;
			case 'i':
			case 'I':
				if (wrap) {
					if (y > 1) {
						gotoxy(hout, x, y - 1);
						y--;
					}
					else {
						// ��껷�ƣ��ӵײ���Ե����
						gotoxy(hout, x, 17);
						y = 17;
					}
				}
				else {
					if (y > 1) {
						gotoxy(hout, x, y - 1);
						y--;
					}
				}
				break;
			case 'k':
			case 'K':
				if (wrap) {
					if (y < 17) {
						gotoxy(hout, x, y + 1);
						y++;
					}
					else {
						// ��껷�ƣ��Ӷ�����Ե����
						gotoxy(hout, x, 1);
						y = 1;
					}
				}
				else {
					if (y < 17) {
						gotoxy(hout, x, y + 1);
						y++;
					}
				}
				break;
			case 'l':
			case 'L':
				if (wrap) {
					if (x < 69) {
						gotoxy(hout, x + 1, y);
						x++;
					}
					else {
						// ��껷�ƣ�������Ե����
						gotoxy(hout, 1, y);
						x = 1;
					}
				}
				else {
					if (x < 69) {
						gotoxy(hout, x + 1, y);
						x++;
					}
				}
				break;
			case ' ':
				cout<<" ";
				gotoxy(hout, x, y);
				break;//ɾ���ô���ĸ��ʹ��걣��ԭ��λ��
			case 'q':
			case 'Q':
				gotoxy(hout, 1, 23);
				cout<<"��Ϸ���������س������ز˵�.";
				// ��ȡ���룬ֱ�����»س�
				while (getchar() != '\n') {}
				break;
			default:
				break;
		}
		if (input == 'q' || input == 'Q') {
			break;
		}
		else {
			continue;
		}
	}

}
/***************************************************************************
  �������ƣ�move_by_ijkl()
  ��    �ܣ���ijkl���ƹ��
  ����������Ƿ���ƣ�wrap��
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void move_by_ijkl(int wrap)
{
	char input;
	int x = 35, y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	while (1) {
		input = _getch();
		switch (input) {
			case 'j':
			case 'J':
				if (wrap) {
					if (x > 1) {
						gotoxy(hout, x - 1, y);
						x--;
					}
					else {
						// ��껷�ƣ����Ҳ��Ե����
						gotoxy(hout, 69, y);
						x = 69;
					}
				}
				else {
					if (x > 1) {
						gotoxy(hout, x - 1, y);
						x--;
					}
				}
				break;
			case 'i':
			case 'I':
				if (wrap) {
					if (y > 1) {
						gotoxy(hout, x, y - 1);
						y--;
					}
					else {
						// ��껷�ƣ��ӵײ���Ե����
						gotoxy(hout, x, 17);
						y = 17;
					}
				}
				else {
					if (y > 1) {
						gotoxy(hout, x, y - 1);
						y--;
					}
				}
				break;
			case 'k':
			case 'K':
				if (wrap) {
					if (y < 17) {
						gotoxy(hout, x, y + 1);
						y++;
					}
					else {
						// ��껷�ƣ��Ӷ�����Ե����
						gotoxy(hout, x, 1);
						y = 1;
					}
				}
				else {
					if (y < 17) {
						gotoxy(hout, x, y + 1);
						y++;
					}
				}
				break;
			case 'l':
			case 'L':
				if (wrap) {
					if (x < 69) {
						gotoxy(hout, x + 1, y);
						x++;
					}
					else {
						// ��껷�ƣ�������Ե����
						gotoxy(hout, 1, y);
						x = 1;
					}
				}
				else {
					if (x < 69) {
						gotoxy(hout, x + 1, y);
						x++;
					}
				}
				break;
			case ' ':
				cout<<" ";
				gotoxy(hout, x, y);
				break;//ɾ���ô���ĸ��ʹ��걣��ԭ��λ��
			case 'q':
			case 'Q':
				gotoxy(hout, 1, 23);
				cout<<"��Ϸ���������س������ز˵�.";
				// ��ȡ���룬ֱ�����»س�
				while (getchar() != '\n') {}
				break;
			case -32:
				input = _getch();
				break;
			default:
				break;
		}
		if (input == 'q' || input == 'Q') {
			break;
		}
		else {
			continue;
		}
	}

}

/***************************************************************************
  �������ƣ�move_by_arrow()
  ��    �ܣ��ü����������Ҽ�ͷ���ƹ��
  ����������Ƿ���ƣ�wrap��
  �� �� ֵ����
  ˵    ����
***************************************************************************/
void move_by_arrow(int wrap)
{
	char input;
	int x = 35, y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	while (1) {
		input = _getch();
		if (input == -32) { // �ж��Ƿ�Ϊ����������룬�����������ʱ_getch����ֵ��������ǰһ��Ϊ����ֵ-32(char)����һ�����Ƕ�Ӧ��ascii��ֵ
			input = _getch();
			switch ((int)(input)) {
				case 72: // �ϼ�ͷ
					if (wrap) {
						if (y > 1) {
							gotoxy(hout, x, y - 1);
							y--;
						}
						else {
							// ��껷�ƣ��ӵײ���Ե����
							gotoxy(hout, x, 17);
							y = 17;
						}
					}
					else {
						if (y > 1) {
							gotoxy(hout, x, y - 1);
							y--;
						}
					}
					break;
				case 80: // �¼�ͷ
					if (wrap) {
						if (y < 17) {
							gotoxy(hout, x, y + 1);
							y++;
						}
						else {
							// ��껷�ƣ��Ӷ�����Ե����
							gotoxy(hout, x, 1);
							y = 1;
						}
					}
					else {
						if (y < 17) {
							gotoxy(hout, x, y + 1);
							y++;
						}
					}
					break;
				case 75: // ���ͷ
					if (wrap) {
						if (x > 1) {
							gotoxy(hout, x - 1, y);
							x--;
						}
						else {
							// ��껷�ƣ����Ҳ��Ե����
							gotoxy(hout, 69, y);
							x = 69;
						}
					}
					else {
						if (x > 1) {
							gotoxy(hout, x - 1, y);
							x--;
						}
					}
					break;
				case 77: // �Ҽ�ͷ
					if (wrap) {
						if (x < 69) {
							gotoxy(hout, x + 1, y);
							x++;
						}
						else {
							// ��껷�ƣ�������Ե����
							gotoxy(hout, 1, y);
							x = 1;
						}
					}
					else {
						if (x < 69) {
							gotoxy(hout, x + 1, y);
							x++;
						}
					}
					break;
				default:
					break;
			}
		}
		else {
			switch (input) {
				case 'q':
				case 'Q':
					gotoxy(hout, 1, 23);
					cout<<"��Ϸ���������س������ز˵�.";
					// ��ȡ���룬ֱ�����»س�
					while (getchar() != '\n') {}
					break;
				case ' ':
					cout<<" ";
					gotoxy(hout, x, y);
					break;
				default:
					break;
			}
		}
		if (input == 'q' || input == 'Q') {
			break;
		}
		else {
			continue;
		}

	}

}

int menu()
{
	int input_menu;
	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
	cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
	cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
	cout << "4.�ü�ͷ�������������ң��߽����" << endl;
	cout << "5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ,�����ͷ���������ƶ�)" << endl;
	cout << "6.��I��J��K��L��������������(��Сд���ɣ��߽����,�����ͷ���������ƶ�)" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0-6]";
	input_menu = _getch();

	return input_menu;

}



/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/


int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	srand((unsigned int)(time(0)));//����α�����������
	cls(hout);//cls����
	int wrap;
	char input_menu;
	int x=35,y=9;

	while (1) {
		input_menu = menu();
		if (input_menu == '0') {
			cout << " 0";
			break;
		}
		else if (input_menu == '1') {
			cls(hout);//cls����
			init_border(hout);/* ��ʾ��ʼ�ı߿����е�����ַ� */
			gotoxy(hout, 35, 9);
			wrap = 0;
			move_by_ijkl_error(wrap);
			cls(hout);//cls����
		}
		else if (input_menu == '2') {
			cls(hout);//cls����
			init_border(hout);/* ��ʾ��ʼ�ı߿����е�����ַ� */
			gotoxy(hout, 35, 9);
			wrap = 1;
			move_by_ijkl_error(wrap);
			cls(hout);//cls����
		}
		else if (input_menu == '3') {
			cls(hout);//cls����
			init_border(hout);/* ��ʾ��ʼ�ı߿����е�����ַ� */
			gotoxy(hout, 35, 9);
			wrap = 0;
			move_by_arrow(wrap);
			cls(hout);//cls����
		}
		else if (input_menu == '4') {
			cls(hout);//cls����
			init_border(hout);/* ��ʾ��ʼ�ı߿����е�����ַ� */
			gotoxy(hout, 35, 9);
			wrap = 1;
			move_by_arrow(wrap);
			cls(hout);//cls����
		}

		/*����5��6�Ĳ��֣������������루��˴��ķ������һ����������ascii��ֵ��ɣ������ǰһ����Ϊ244����һ��Ϊ���������ֵ����
		����������ĺ�һ������ֵǡ��Ϊ75����'K'��ֵ��ͬ��������1,2�����뷽�����ʱ���������ƶ���
		������ֻҪ��switch�ж�244(charֵΪ-32)��һ������������ж�����*/


		else if (input_menu == '5') {
			cls(hout);//cls����
			init_border(hout);/* ��ʾ��ʼ�ı߿����е�����ַ� */
			gotoxy(hout, 35, 9);
			wrap = 0;
			move_by_ijkl(wrap);
			cls(hout);//cls����
		}
		else if (input_menu == '6') {
			cls(hout);//cls����
			init_border(hout);/* ��ʾ��ʼ�ı߿����е�����ַ� */
			gotoxy(hout, 35, 9);
			wrap = 1;
			move_by_ijkl(wrap);
			cls(hout);//cls����
		}
		else {
			cls(hout);//cls����;
		}

	}
	return 0;
}
/*��α�����������ĸС��20������Ľ��ͣ�
  1.�ظ�������ͬ�����꣺���rand() % MAX_X + 1��rand() % MAX_Y + 1�������ظ������꣬��ô����ͬλ�����ɵ���ĸ�ᱻ���ǣ�����ʵ�ʿ�������ĸ��������20����
����ܷ�����MAX_X��MAX_Y��ȡֵ��Χ��С�����ɵ�����ֵ���޵�����¡� 
  2.���ɵ����곬����Χ�����rand() % MAX_X + 1��rand() % MAX_Y + 1���ɵ����곬������Ч��Χ�����糬������Ļ�Ŀ�Ȼ�߶ȣ�
��ô����Щλ�����ɵ���ĸ�����ᱻ��ʾ������ʵ�ʿ�������ĸ��������20����
  3.���ɵ���ĸλ���ص������������ɵ�λ������Ļ���ص����������ĸ��������ͬһ��λ�ã���ôʵ�ʿ�������ĸ����Ҳ������20����*/