#include<iostream>
#include<cctype>
#include"Stack.h"

void Stack_Operate() {
	using namespace std;
	Stack st;
	char ch;
	unsigned long po;

	cout << "请输入A以添加元素，输入P以删除元素"
		<< "，输入Q退出程序。\n";
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n') {
			continue;
		}
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch (ch) {
		case'A':
		case'a':
			cout << "请添加一个数字：";
			cin >> po;
			if (st.isfull()) {
				cout << "栈已堆满！\n";
			}
			else {
				st.push(po);
			}
			break;
			
		case'p':
		case'P':
			if (st.isempty()) {
				cout << "栈已空！\n";
			}
			else {
				st.pop(po);
				cout << "删除的数字为：" << po << endl;
			}
			break;
		}

		cout << "请输入A以添加元素，输入P以删除元素"
			<< "，输入Q退出程序。\n";
	}

	cout << "程序已结束！再见！\n";
}