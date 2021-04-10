#include<iostream>
#include "Stock_up.h"

Stock_up::Stock_up() {
	std::cout << "使用默认构造函数！\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock_up::Stock_up(const std::string& co, long n, double pr) {
	std::cout << "使用自定义构造函数！\n";
	company = co;

	if (n < 0) {
		std::cout << "持有股票数不能为0！持有数将被设置为0！\n";
		shares = 0;
	}
	else {
		shares = n;
	}
	share_val = pr;
	set_tot();
}

Stock_up::~Stock_up() {
	std::cout << "析构函数已调用！再见！\n";
}

void Stock_up::buy(long num, double price) {
	if (num < 0) {
		std::cout << "购买的股票数不能为负！交易取消！\n";
	}
	else {
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock_up::sell(long num, double price) {
	using std::cout;
	if (num < 0) {
		cout << "卖出的股票数不能为负！交易取消！\n";
	}
	else if (num > shares) {
		cout << "卖出的股票数不能超过当前持有数！交易取消！\n";
	}
	else {
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock_up::update(double price) {
	share_val = price;
	set_tot();
}

void Stock_up::show() {
	using std::cout;
	using std::ios_base;

	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "公司名为：" << company
		<< "  持有股票数为：" << shares << std::endl;
	cout << "  股票单价为：" << share_val;
	cout.precision(2);
	cout << "  总价值为：" << total_val << std::endl;

	//重新恢复到之前设置
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}


