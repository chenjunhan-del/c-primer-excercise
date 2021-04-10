#include "Cd.h"
#include<iostream>
#include<string>

Cd::Cd(const char* s1, const char* s2, int n, double x) {
	strcpy_s(performers, s1);
	strcpy_s(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& cd) {
	strcpy_s(performers, cd.performers);
	strcpy_s(label, cd.label);
	selections = cd.selections;
	playtime = cd.playtime;
}

Cd::Cd() {
	strcpy_s(performers, "No name!");
	strcpy_s(label, "No label!");
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd() {

}

void Cd::Report() const {
	std::cout << "�����ߣ�" << performers
		<< " ��ǩ��" << label
		<< " ����ʱ�䣺" << playtime << std::endl;
}

Cd& Cd::operator=(const Cd& d) {
	if (this == &d) {
		return *this;
	}
	strcpy_s(performers, d.performers);
	strcpy_s(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x) :Cd(s2, s3, n, x) {
	strcpy_s(main_works, s1);
}

Classic::Classic() : Cd() {
	strcpy_s(main_works, "No works");
}

Classic::Classic(const Classic& c1) : Cd(c1) {
	strcpy_s(main_works, c1.main_works);
}

Classic::~Classic() {

}

void Classic::Report() const {
	std::cout << "��Ҫ��ƷΪ��" << main_works
		<< " ";
	Cd::Report();
}

Classic& Classic::operator=(const Classic& c1) {
	if (this == &c1) {
		return *this;
	}
	Cd::operator=(c1);
	strcpy_s(main_works, c1.main_works);
	return *this;
}

void CdOperate() {
	using std::cout;
	using std::cin;
	using std::endl;

	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;

	cout << "ֱ��ʹ�ö�����÷�����\n";
	c1.Report();
	c2.Report();

	cout << "ʹ��ָ����÷�����\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "ʹ���β�Ϊ�������õĺ�����\n";
	Bravo(c1);
	Bravo(c2);

	cout << "ʹ�ø�ֵ�������\n";
	Classic copy;
	copy = c2;
	copy.Report();

	return;
}

void Bravo(const Cd& disk) {
	disk.Report();
}
