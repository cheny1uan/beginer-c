/* 2351892 ������ ��11 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 0) {
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    
    cout << setw(2) << n << "# " << src <<resetiosflags(ios::adjustfield)<<"-->" << dst << endl;
    hanoi(n - 1, tmp, src, dst);
    
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int n;
    char src, tmp, dst;
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
        cin >> n;
        cin.ignore(65536, '\n');
        if (cin.good() == 0 || n < 1 || n>16) {
            cin.clear();
            continue;
        }
        else {
            break;
        }
    }
    while (1) {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        cin.ignore(65536, '\n');
        if (src >= 97 && src <= 99) {
            src = src - 32;
        }
        if (cin.good() == 0 || src < 'A' || src>'C') {
            cin.clear();
            continue;
        }
        else {
            break;
        }
    }
    while (1) {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        cin.ignore(65536, '\n');
        if (dst >= 97 && dst <= 99) {
            dst = dst - 32;
        }
        if (cin.good() == 0 || dst < 'A' || dst>'C') {
            cin.clear();
            continue;
        }
        else if (dst == src) {
            cout << "Ŀ����("<<src<<")��������ʼ��("<<src<<")��ͬ" << endl;
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
    cout << "�ƶ�����Ϊ:" << endl;
    hanoi(n, src, tmp, dst);



    return 0;
}