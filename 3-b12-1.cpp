/* 信11 2351892 陈奕炫 */
#include <iostream>
#include<limits>
using namespace std;

int main()
{
	int x;

	while (1) {
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();//清除输入流的错误标志，以便继续读取输入。
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//忽略输入流中直到行末尾的所有内容，包括换行符('\n')，以确保输入流被清空并准备接受新的输入
		}
		else {

			if (x >= 0 && x <= 100)
				break;
			else {
				continue;
			}
		}
	}

	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1

	return 0;
}

