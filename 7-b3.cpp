/* 2351892 ������ ��11 */
#include <iostream>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ��������壩 */

public:
	Days(int y, int m, int d);
	int calc_days();     //�����ǵ���ĵڼ���

	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ��������� */

};

/* --- �˴��������Ա����������ʵ�� --- */
Days::Days(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
int Days::calc_days()
{
	if (Days::month < 1 || Days:: month > 12) {
		return -1;
	}
	int month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (Days::year % 4 == 0 && Days::year % 100 != 0 || Days::year % 400 == 0) {
		month_days[1] = 29;
	}
	if (Days::day<1 || Days::day>month_days[Days::month - 1]) {
		return -1;
	}
	int days_sum=0;
	for (int i = 0; i < Days::month-1; i++) {
		days_sum += month_days[i];
	}
	days_sum += Days::day;
	return days_sum;
}



/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2020, 3, 18);
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2020, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}
