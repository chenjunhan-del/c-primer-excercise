#include<iostream>
#include"Stock_up.h"

//��ٵ�������
void Stock_up_Operate() {
	using std::cout;
	cout << "��ʼʹ�ù��캯����\n";
	Stock_up stock1("NanoSmart", 12, 20.0);
	stock1.show();
	Stock_up stock2("Boffo Bojects", 2, 2.0);
	stock2.show();

	cout << "\n��stock1��ֵ����stock2��\n";
	stock2 = stock1;
	cout << "չ��stock1��stock2��\n";
	stock1.show();
	stock2.show();

	cout << "\n��ʽ���ù��캯����������stock1��\n";
	stock1 = Stock_up("Nifty Foods", 10, 50.0);
	cout << "������ʾstock1��\n";
	stock1.show();
	cout << "�����Ѿ���ɣ�\n";
}