/* 2351892 ��11 ������ */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */
void print_space_1(int space)
{
	
	
		if (space == 0) {
			return;
		}
		cout << " ";
		print_space_1(space - 1);
	
	
}
void print_space_0(int prime)
{
	if (prime == 0) {
		return;
	}
	cout << " ";
	print_space_0(prime-1);
}


void print_row_left(char end,char start)
{
	
	if (end < start) {
		return;
	}
	cout << char(end);
	print_row_left(end - 1, start);

}
void print_row_right(char start, char end)
{

	if (end == start) {
		return;
	}
	cout << char(start + 1);
	print_row_right(start + 1, end);
}

   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������start ��ʼ�ַ���end �����ַ���now ��ǰ�ַ���order ������space start����߾���
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��ʾ����һ������order��ָ������/����
   ***************************************************************************/
void print_tower(char start,char end,char now,bool order,int space)
{
	if (order == 1) {
		if (now > end) {
			return;
		}
		print_space_1(space);
		space--;
		print_row_left(now, start);
		print_row_right(start, now);
		cout << endl;
		now++;
		print_tower(start, end, now, order, space);
	}
	else {
		
		if (now+end-'A'<start) {
			return;
		}
		print_space_0(space-(end-'A')+'A'-now);		
		print_row_left(now+end-'A', start);
		print_row_right(start, now+end-'A');
		cout << endl;
		now--;
		print_tower(start, end, now, order, space);
		

	}
	/* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */

	/* ����ʵ�֣������в������κ���ʽ��ѭ����������������������� */

}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout<< setw(2 * (end_ch - 'A') + 2) << setfill('=')<<" "<< resetiosflags(ios::adjustfield) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout <<setw(2 *(end_ch - 'A')+2) << setfill('=') << " " << resetiosflags(ios::adjustfield)<< endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower('A',end_ch,'A',true,end_ch-'A'); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(�м�ΪA) */
	cout << setw(2 * (end_ch - 'A')+2) << setfill('=') << " " <<resetiosflags(ios::adjustfield)<< endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << setw(2 * (end_ch - 'A')+2) << setfill('=') << " " <<resetiosflags(ios::adjustfield)<< endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower('A',end_ch,'A',false,end_ch-'A'); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ��м�ΪA�� */
	cout << setw(2 * (end_ch - 'A')+2) << setfill('=') << " " << resetiosflags(ios::adjustfield) <<endl;/* ����ĸ����������= */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << setw(2 * (end_ch - 'A')+2) << setfill('=') << " " << resetiosflags(ios::adjustfield) << endl;/* ����ĸ����������= */
	print_tower('A',end_ch,'A',true,end_ch-'A');   //��ӡ A~�����ַ��������� 
	print_tower('A',end_ch-1,'A',false,end_ch-'A');   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}