#include<iostream>
#include"Stonewt.h"
using std::cout;

//��ʾStonewt��ĺ���
void display(const Stonewt& st, int n);

//����Stonewt���ʵ�麯��
void Stonewt_operate();

void Stonewt_operate() {
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);

	cout << "���˲�����";
	incognito.show_stn();
	cout << "��̽������";
	wolfe.show_stn();
	cout << "��ͳ������";
	taft.show_lbs();

	incognito = 276.8;
	taft = 325;
	cout << "���������˲�����";
	incognito.show_stn();
	cout << "��������ͳ������";
	taft.show_lbs();
	display(taft, 2);
	cout << "��֪������ð����һ���ˣ�\n";
	display(422, 2);

	cout << "����һ��doubleֵ��һ��intֵ��\n";
	int n = taft;
	double m = taft;
	cout << "����ֵΪ��" << n << std::endl;
	cout << "˫����ֵΪ��" << m << std::endl;
}


void display(const Stonewt& st, int n) {
	for (int i = 0; i < n; i++) {
		cout << "̫ǿ�ˣ�";
		st.show_stn();
	}
}

