#include<iostream>
#include"Time.h"

//操作Time类的实验函数
void Time_operate() {
	using std::cout;
	using std::endl;
	typedef TIME::Time Tim;

	Tim planning;
	Tim coding(2, 40);
	Tim fixing(5, 55);
	Tim total;

	cout << "计划时间为：";
	planning.show();

	cout << "编码时间为：";
	coding.show();

	cout << "修改时间为：";
	fixing.show();

	cout << "使用sum函数！\n";
	total = coding.sum(fixing);
	cout << "编码和修改总时间为：";
	total.show();

	cout << "\n使用重载加法运算符！\n";
	total = coding + fixing;
	cout << "编码和修改总时间为：";
	total.show();

	cout << "\n使用重载减法运算符！\n";
	total = coding - fixing;
	cout << "编码和修改时间之差为：";
	total.show();

	cout << "\n使用重载乘法运算符！\n";
	total = total * 3.3;
	cout << "结果为：";
	total.show();
	total = 3.3 * total;
	total.show();

	cout << "\n使用重载<<运算符！\n";
	cout << total;
}