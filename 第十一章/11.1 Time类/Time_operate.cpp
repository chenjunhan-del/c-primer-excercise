#include<iostream>
#include"Time.h"

//����Time���ʵ�麯��
void Time_operate() {
	using std::cout;
	using std::endl;
	typedef TIME::Time Tim;

	Tim planning;
	Tim coding(2, 40);
	Tim fixing(5, 55);
	Tim total;

	cout << "�ƻ�ʱ��Ϊ��";
	planning.show();

	cout << "����ʱ��Ϊ��";
	coding.show();

	cout << "�޸�ʱ��Ϊ��";
	fixing.show();

	cout << "ʹ��sum������\n";
	total = coding.sum(fixing);
	cout << "������޸���ʱ��Ϊ��";
	total.show();

	cout << "\nʹ�����ؼӷ��������\n";
	total = coding + fixing;
	cout << "������޸���ʱ��Ϊ��";
	total.show();

	cout << "\nʹ�����ؼ����������\n";
	total = coding - fixing;
	cout << "������޸�ʱ��֮��Ϊ��";
	total.show();

	cout << "\nʹ�����س˷��������\n";
	total = total * 3.3;
	cout << "���Ϊ��";
	total.show();
	total = 3.3 * total;
	total.show();

	cout << "\nʹ������<<�������\n";
	cout << total;
}