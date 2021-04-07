#include<iostream>
#include "Stock_up.h"

Stock_up::Stock_up() {
	std::cout << "ʹ��Ĭ�Ϲ��캯����\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock_up::Stock_up(const std::string& co, long n, double pr) {
	std::cout << "ʹ���Զ��幹�캯����\n";
	company = co;

	if (n < 0) {
		std::cout << "���й�Ʊ������Ϊ0����������������Ϊ0��\n";
		shares = 0;
	}
	else {
		shares = n;
	}
	share_val = pr;
	set_tot();
}

Stock_up::~Stock_up() {
	std::cout << "���������ѵ��ã��ټ���\n";
}

void Stock_up::buy(long num, double price) {
	if (num < 0) {
		std::cout << "����Ĺ�Ʊ������Ϊ��������ȡ����\n";
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
		cout << "�����Ĺ�Ʊ������Ϊ��������ȡ����\n";
	}
	else if (num > shares) {
		cout << "�����Ĺ�Ʊ�����ܳ�����ǰ������������ȡ����\n";
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

	cout << "��˾��Ϊ��" << company
		<< "  ���й�Ʊ��Ϊ��" << shares << std::endl;
	cout << "  ��Ʊ����Ϊ��" << share_val;
	cout.precision(2);
	cout << "  �ܼ�ֵΪ��" << total_val << std::endl;

	//���»ָ���֮ǰ����
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}


