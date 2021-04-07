#include<iostream>
#include "Stock_T.h"

Stock_T::Stock_T() {
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock_T::Stock_T(const std::string& co, long n, double pr) {
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

Stock_T::~Stock_T() {

}

void Stock_T::buy(long num, double price) {
	if (num < 0) {
		std::cout << "购买的股票数不能为负！交易取消！\n";
	}
	else {
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock_T::sell(long num, double price) {
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

void Stock_T::update(double price) {
	share_val = price;
	set_tot();
}

void Stock_T::show() const {
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

const Stock_T& Stock_T::topval(const Stock_T& s) const {
	if (s.total_val > total_val) {
		return s;
	}
	else {
		return *this;
	}
}

