#include<iostream>
#include"Stock_T.h"
const int STKS = 4;

//虚假的主函数
void Stock_T_Operate() {
	Stock_T stocks[STKS] = {
		Stock_T("NanoSmart",12,20.0),
		Stock_T("Boffo Objects",200,2.0),
		Stock_T("Monolithic Obelisks",130,3.25),
		Stock_T("Fleep Enterprises",60,6.5)
	};

	std::cout << "展现stocks数组的四个元素：\n";
	int st;
	for (st = 0; st < STKS; st++) {
		stocks[st].show();
	}

	//创建一个Stock_T类的指针，指向第一个元素
	const Stock_T* top = &stocks[0];
	for (st = 1; st < STKS; st++) {
		top = &top->topval(stocks[st]);
	}

	std::cout << "\n总价值最高的股票为：\n";
	top->show();
}