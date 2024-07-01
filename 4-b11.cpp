/* 2351892 信11 陈奕炫 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
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
	 函数名称：
	 功    能：打印字母塔
	 输入参数：start 开始字符，end 结束字符，now 当前字符，order 正序倒序，space start到左边距离
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
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
	/* 允许按需定义最多一个静态局部变量（也可以不定义） */

	/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout<< setw(2 * (end_ch - 'A') + 2) << setfill('=')<<" "<< resetiosflags(ios::adjustfield) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout <<setw(2 *(end_ch - 'A')+2) << setfill('=') << " " << resetiosflags(ios::adjustfield)<< endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A',end_ch,'A',true,end_ch-'A'); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << setw(2 * (end_ch - 'A')+2) << setfill('=') << " " <<resetiosflags(ios::adjustfield)<< endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setw(2 * (end_ch - 'A')+2) << setfill('=') << " " <<resetiosflags(ios::adjustfield)<< endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower('A',end_ch,'A',false,end_ch-'A'); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << setw(2 * (end_ch - 'A')+2) << setfill('=') << " " << resetiosflags(ios::adjustfield) <<endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setw(2 * (end_ch - 'A')+2) << setfill('=') << " " << resetiosflags(ios::adjustfield) << endl;/* 按字母塔最大宽度输出= */
	print_tower('A',end_ch,'A',true,end_ch-'A');   //打印 A~结束字符的正三角 
	print_tower('A',end_ch-1,'A',false,end_ch-'A');   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}