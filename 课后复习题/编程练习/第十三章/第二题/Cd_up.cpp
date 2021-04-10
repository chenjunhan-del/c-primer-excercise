#include "Cd_up.h"
#include<iostream>
#include<string>

Cd_Up::Cd_Up(const char* s1, const char* s2, int n, double x) {
	int len1 = std::strlen(s1);
	int len2 = std::strlen(s2);
	performers = new char[len1 + 1];
	label = new char[len2 + 1];
	strcpy_s(performers, len1 + 1, s1);
	strcpy_s(label, len2 + 1, s2);

	selections = n;
	playtime = x;
}

Cd_Up::Cd_Up(const Cd_Up& cd) {
	delete[] performers;
	delete[] label;

	int len1 = std::strlen(cd.performers);
	int len2 = std::strlen(cd.label);
	performers = new char[len1 + 1];
	label = new char[len2 + 1];

	strcpy_s(performers, len1 + 1, cd.performers);
	strcpy_s(label, len2 + 1, cd.label);
	selections = cd.selections;
	playtime = cd.playtime;
}

Cd_Up::Cd_Up() {
	performers = new char[9];
	label = new char[10];
	strcpy_s(performers, 9, "No name!");
	strcpy_s(label, 10, "No label!");

	selections = 0;
	playtime = 0.0;
}

Cd_Up::~Cd_Up() {
	delete[] performers;
	delete[] label;
}

void Cd_Up::Report() const {
	std::cout << "表演者：" << performers
		<< " 标签：" << label
		<< " 播放时间：" << playtime << std::endl;
}

Cd_Up& Cd_Up::operator=(const Cd_Up& cd) {
	if (this == &cd) {
		return *this;
	}
	delete[] performers;
	delete[] label;

	int len1 = std::strlen(cd.performers);
	int len2 = std::strlen(cd.label);
	performers = new char[len1 + 1];
	label = new char[len2 + 1];
	strcpy_s(performers, len1 + 1, cd.performers);
	strcpy_s(label, len2 + 1, cd.label);

	selections = cd.selections;
	playtime = cd.playtime;
	return*this;
}

Classic_Up::Classic_Up(const char* s1, const char* s2, const char* s3, int n, double x) :Cd_Up(s2, s3, n, x) {
	int len = std::strlen(s1);
	main_works = new char[len + 1];
	strcpy_s(main_works, len + 1, s1);
}

Classic_Up::Classic_Up() :Cd_Up() {
	main_works = new char[10];
	strcpy_s(main_works, 10, "No works!");
}

Classic_Up::Classic_Up(const Classic_Up& c1) : Cd_Up(c1) {
	delete[] main_works;
	int len = std::strlen(c1.main_works);
	main_works = new char[len + 1];
	strcpy_s(main_works, len + 1, c1.main_works);
}

Classic_Up::~Classic_Up() {
	delete[] main_works;
}

void Classic_Up::Report() const {
	std::cout << "主要作品为：" << main_works
		<< " ";
	Cd_Up::Report();
}

Classic_Up& Classic_Up::operator=(const Classic_Up& c1) {
	if (this == &c1) {
		return *this;
	}
	Cd_Up::operator=(c1);

	delete[] main_works;
	int len = std::strlen(c1.main_works);
	main_works = new char[len + 1];
	strcpy_s(main_works, len + 1, c1.main_works);
	return*this;
}

void Cd_UpOperate() {
	using std::cout;
	using std::cin;
	using std::endl;

	Cd_Up c1("Beatles", "Capitol", 14, 35.5);
	Classic_Up c2 = Classic_Up("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brendel", "Philips", 2, 57.17);
	Cd_Up* pcd = &c1;

	cout << "直接使用对象调用方法：\n";
	c1.Report();
	c2.Report();

	cout << "使用指针调用方法：\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "使用形参为基类引用的函数：\n";
	BravoUp(c1);
	BravoUp(c2);

	cout << "使用赋值运算符：\n";
	Classic_Up copy;
	copy = c2;
	copy.Report();

	return;
}

void BravoUp(const Cd_Up& cd) {
	cd.Report();
}
