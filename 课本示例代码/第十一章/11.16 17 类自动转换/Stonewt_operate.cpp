#include<iostream>
#include"Stonewt.h"
using std::cout;

//显示Stonewt类的函数
void display(const Stonewt& st, int n);

//操作Stonewt类的实验函数
void Stonewt_operate();

void Stonewt_operate() {
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);

	cout << "名人操作：";
	incognito.show_stn();
	cout << "侦探操作：";
	wolfe.show_stn();
	cout << "总统操作：";
	taft.show_lbs();

	incognito = 276.8;
	taft = 325;
	cout << "晚饭过后，名人操作：";
	incognito.show_stn();
	cout << "晚饭过后，总统操作：";
	taft.show_lbs();
	display(taft, 2);
	cout << "不知道哪里冒出来一个人！\n";
	display(422, 2);

	cout << "创建一个double值和一个int值！\n";
	int n = taft;
	double m = taft;
	cout << "整型值为：" << n << std::endl;
	cout << "双浮点值为：" << m << std::endl;
}


void display(const Stonewt& st, int n) {
	for (int i = 0; i < n; i++) {
		cout << "太强了！";
		st.show_stn();
	}
}

