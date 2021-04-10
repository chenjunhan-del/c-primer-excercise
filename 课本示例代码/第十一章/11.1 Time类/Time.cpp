#include "Time.h"
#include<iostream>

TIME::Time::Time() {
	hours = minutes = 0;
}

TIME::Time::Time(int h, int m) {
	hours = h;
	minutes = m;
}

void TIME::Time::AddMin(int m) {
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void TIME::Time::AddHr(int h) {
	hours += h;
}

void TIME::Time::Reset(int h, int m) {
	hours = h;
	minutes = m;
}

TIME::Time TIME::Time::sum(const Time& t) const {
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

TIME::Time TIME::Time::operator+(const Time& t) const {
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}

TIME::Time TIME::Time::operator-(const Time& t) const {
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = minutes + 60 * hours;
	diff.minutes = (tot2 - tot1) * 60;
	diff.hours = (tot2 - tot1) / 60;
	return diff;
}

TIME::Time TIME::Time::operator*(double n) const {
	Time result;
	long totalminutes = hours * n * 60 + minutes * n;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

void TIME::Time::show() const {
	std::cout << hours << "小时，" << minutes << "分\n";
}

//友元函数实现
namespace TIME {
	TIME::Time operator*(double n, TIME::Time& t) {
		Time result;
		long totalminutes = t.hours * n * 60 + t.minutes * n;
		result.hours = totalminutes / 60;
		result.minutes = totalminutes % 60;
		return result;
	}

	std::ostream& operator<<(std::ostream& os, const Time& t) {
		os << t.hours << " 小时，" << t.minutes << " 分钟\n";
		return os;
	}
}