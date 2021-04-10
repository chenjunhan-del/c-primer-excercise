#pragma once
//编程练习要求：
//派生出一个Classic类，并添加一组char成员，用于存储指出CD中主
//要作品的字符串。修改上述声明，使基类的所有函数都是虚的。如果上
//述定义声明的某个方法并不需要，则请删除它。
//使用下面的程序测试您的产品（请见CdOperate）

//试图将所有函数声明为virtual时，构造函数、复制构造函数
//以及默认构造函数不能使用virtual

class Cd {
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;

public:
	Cd(const char* s1,const char* s2, int n, double x);
	Cd(const Cd& cd);
	Cd();
	virtual ~Cd();
	virtual void Report()const;
	virtual Cd& operator=(const Cd& d);
};

class Classic :public Cd {
private:
	char main_works[100];

public:
	Classic(const char* s1,const char* s2,const char* s3, int n, double x);
	Classic();
	Classic(const Classic& c1);
	virtual ~Classic();
	virtual void Report()const;
	virtual Classic& operator=(const Classic& c1);
};

void CdOperate();
void Bravo(const Cd& disk);