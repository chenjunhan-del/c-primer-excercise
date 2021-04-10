#pragma once
#include<iostream>

//Time类的命名空间
namespace TIME {
	//数据成员包括hours和minutes
	class Time {
	private:
		int hours;
		int minutes;

	public:
		Time();
		Time(int h, int m = 0);
		void AddMin(int m);
		void AddHr(int h);
		void Reset(int h = 0, int m = 0);
		Time sum(const Time& t)const;
		Time operator+(const Time& t)const;
		Time operator-(const Time& t)const;
		Time operator*(double n)const;
		void show()const;
		//自己添加一个定义
		friend TIME::Time operator*(double n, TIME::Time& t);
		friend std::ostream& operator<<(std::ostream& os, const Time& t);
	};	
};