#include<iostream>
#include<cctype>
#include"Stack.h"

void Stack_Operate() {
	using namespace std;
	Stack st;
	char ch;
	unsigned long po;

	cout << "������A�����Ԫ�أ�����P��ɾ��Ԫ��"
		<< "������Q�˳�����\n";
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
			cout << "�����һ�����֣�";
			cin >> po;
			if (st.isfull()) {
				cout << "ջ�Ѷ�����\n";
			}
			else {
				st.push(po);
			}
			break;
			
		case'p':
		case'P':
			if (st.isempty()) {
				cout << "ջ�ѿգ�\n";
			}
			else {
				st.pop(po);
				cout << "ɾ��������Ϊ��" << po << endl;
			}
			break;
		}

		cout << "������A�����Ԫ�أ�����P��ɾ��Ԫ��"
			<< "������Q�˳�����\n";
	}

	cout << "�����ѽ������ټ���\n";
}