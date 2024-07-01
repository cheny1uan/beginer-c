/* 2351892 信11 陈奕炫 */
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>

using namespace std;

int main()
{
	int a[21] = { 0 };
	int i=0,count=0;//count为数组原来含有数字的个数
	int num,num_new;


	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	while (count < 20) {
		cin >> num;
		
		if (num<= 0) {
			break;
		}
		a[i] = num;
		i++;
		count++;
	}
	if (count == 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	cout << "原数组为：" << endl;
	for (i = 0; i < count; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cin.ignore(65536, '\n');//清除缓冲区，以免影响下面运行
	cout << "请输入要插入的正整数" << endl;
	cin >> num_new;
	a[count] = num_new;
	int insert=count;
	while (insert > 0 && a[insert - 1] > num_new) {
		a[insert] = a[insert - 1];
		insert--;
	}
	a[insert] = num_new;
	cout << "插入后的数组为：" << endl;
	for (i = 0; i <=count;i++) {
		cout << a[i] << " ";
	}
	cout << endl;



	return 0;
}