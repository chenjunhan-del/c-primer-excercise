#include<iostream>
#include"Stock_up.h"

//虚假的主函数
void Stock_up_Operate() {
	using std::cout;
	cout << "开始使用构造函数！\n";
	Stock_up stock1("NanoSmart", 12, 20.0);
	stock1.show();
	Stock_up stock2("Boffo Bojects", 2, 2.0);
	stock2.show();

	cout << "\n把stock1的值赋给stock2！\n";
	stock2 = stock1;
	cout << "展现stock1和stock2！\n";
	stock1.show();
	stock2.show();

	cout << "\n显式调用构造函数重新设置stock1！\n";
	stock1 = Stock_up("Nifty Foods", 10, 50.0);
	cout << "重新显示stock1！\n";
	stock1.show();
	cout << "工作已经完成！\n";
}