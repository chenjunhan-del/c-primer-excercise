#include<iostream>
#include"Stock_T.h"
const int STKS = 4;

//��ٵ�������
void Stock_T_Operate() {
	Stock_T stocks[STKS] = {
		Stock_T("NanoSmart",12,20.0),
		Stock_T("Boffo Objects",200,2.0),
		Stock_T("Monolithic Obelisks",130,3.25),
		Stock_T("Fleep Enterprises",60,6.5)
	};

	std::cout << "չ��stocks������ĸ�Ԫ�أ�\n";
	int st;
	for (st = 0; st < STKS; st++) {
		stocks[st].show();
	}

	//����һ��Stock_T���ָ�룬ָ���һ��Ԫ��
	const Stock_T* top = &stocks[0];
	for (st = 1; st < STKS; st++) {
		top = &top->topval(stocks[st]);
	}

	std::cout << "\n�ܼ�ֵ��ߵĹ�ƱΪ��\n";
	top->show();
}