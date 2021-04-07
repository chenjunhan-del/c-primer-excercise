#pragma once
#include<iostream>

//Time��������ռ�
namespace TIME {
	//���ݳ�Ա����hours��minutes
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
		//�Լ����һ������
		friend TIME::Time operator*(double n, TIME::Time& t);
		friend std::ostream& operator<<(std::ostream& os, const Time& t);
	};	
};