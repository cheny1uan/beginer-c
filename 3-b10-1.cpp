/*2351892 ��11 ������*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //ȡϵͳʱ��
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
    int  i, j, k, n = 0;//i,j,kΪ������nΪ����
    int i1, i2, i3, j1, j2, j3, k1, k2, k3;
    for (i = 123; i <= 987; i++) {
        i1 = i / 100;
        i2 = i % 100 / 10;
        i3 = i % 10;
        
        if ((i2!= 0) && (i3 != 0)) {
            ;
        }
        else {
            continue;
        }
        
        if (i1 != i2 && i1 != i3 && i2 != i3) {
            ;
        }
        else {
            continue;
        }
        for (j = 123; j <= 987; j++) {
            j1 = j / 100;
            j2 = j % 100 / 10;
            j3 = j % 10;
            
            if ((j2 != 0) && (j3 != 0)) {
                ;
            }
            else {
                continue;
            }
            
            if (j1 != j2 && j1 != j3 && j2 != j3) {
                ;
            }
            else {
                continue;
            }

            
            for (k = 123; k <= 987; k++) {
               
                if ((i <= j) && (j <= k)) {
                    ;
                }
                else {
                    continue;
                }
                
                k1 = k / 100;
                k2 = k % 100 / 10;
                k3 = k % 10;
                if ((k2 != 0) && (k3 != 0)) {
                    ;
                }
                else {
                    continue;
                }
                if (k1 != k2 && k1 != k3 && k2 != k3) {
                    ;
                }
                else {
                    continue;
                }
                
        



                if (i1 != j1 && i1 != j2 && i1 != j3 && i2 != j1 && i2 != j2 && i2 != j3 && i3 != j1 && i3 != j2 && i3 != j3) {
                    ;
                }
                else {
                    continue;
                }
                if (i1 != k1 && i1 != k2 && i1 != k3 && i2 != k1 && i2 != k2 && i2 != k3 && i3 != k1 && i3 != k2 && i3 != k3) {
                    ;
                }
                else {
                    continue;
                }
                if (j1 != k1 && j1 != k2 && j1 != k3 && j2 != k1 && j2 != k2 && j2 != k3 && j3 != k1 && j3 != k2 && j3 != k3) {
                    ;
                }
                else {
                    continue;
                }

                if (i + k + j == 1953) {
                    n++;
                    cout << "No." << setiosflags(ios::right) << setw(3) << n;
                    cout << resetiosflags(ios::right)<<" : " << i << "+" << j << "+" << k << "=1953" << endl;
                 
                }
                else {
                    continue;
                }

            }

        }
    }
    cout << "total=" << n << endl;
	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}