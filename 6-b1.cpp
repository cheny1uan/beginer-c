/* 2351892 ������ ��11 */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p=str;
	int  a[N] = { 0 }, * pnum=a, * pa=a;
	bool is_num;
	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str,255);
	is_num = false;
	
	while ((pnum - pa) != N) {
		if (*p == 0) {			
			break;
		}
		if (*p >= '0' && *p <= '9') {
			is_num = true;
			*pnum = *pnum * 10 + *p - '0';
		}
		else if (is_num == true) {
			is_num = false;
			pnum++;
		}
		p++;
	}	
	if (is_num == true) {//�˴����������һ���ַ��Ƿ������ֵ��������Ȼ���bug
		pnum++;
	}
	
	cout << "����" << pnum - a << "������" << endl;
	while (pa != pnum) {
		cout << *pa << " ";
		pa++;
	}
	cout << endl;
	
	
	return 0;
}