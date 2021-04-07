#include "Vector.h"//已经包含<iostream>
#include<cmath>

namespace VECTOR {
	//将角度转换为弧度
	const double Rad_to_deg = 45.0 / atan(1.0);

	void Vector::set_mag() {
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang() {
		if (x == 0.0 && y == 0.0) {
			ang = 0.0;
		}
		else {
			ang = atan2(y, x);
		}
	}

	void Vector::set_x() {
		x = mag * cos(ang);
	}

	void Vector::set_y() {
		y = mag * sin(ang);
	}

	Vector::Vector() {
		x = y = mag = ang = 0.0;
		mode = Mode::RECT;
	}

	Vector::Vector(double n1, double n2, Mode form) {
		mode = form;
		if (form == Mode::RECT) {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == Mode::POL) {
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else {
			std::cout << "三个常数不合理！所有值将设为0！\n";
			x = y = mag = ang = 0.0;
			mode = Mode::RECT;
		}
	}

	void Vector::reset(double n1, double n2, Mode form) {
		mode = form;
		if (form == Mode::RECT) {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == Mode::POL) {
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else {
			std::cout << "三个常数不合理！所有值将设为0！\n";
			x = y = mag = ang = 0.0;
			mode = Mode::RECT;
		}
	}

	Vector::~Vector() {

	}

	void Vector::polar_mode() {
		mode = Mode::POL;
	}

	void Vector::rect_mode() {
		mode = Mode::RECT;
	}

	Vector Vector::operator+(const Vector& b) const {
		return Vector(x + b.x, y + b.y);
	}

	Vector Vector::operator-(const Vector& b) const {
		return Vector(x - b.x, y - b.y);
	}

	//Vector Vector::operator-() const
	//{
	//	return Vector();
	//}

	Vector Vector::operator*(double n) const {
		return Vector(x * n, y * n);
	}

	Vector operator*(double n, const Vector& a) {
		return Vector(n * a.x, n * a.y);
	}

	std::ostream& operator<<(std::ostream& os, const Vector& V) {
		os << "直角坐标(x,y)：(" << V.x << "," << V.y << ")，"
			<< "极坐标(ρ,θ)：(" << V.mag << "," << V.ang << ")\n";
		return os;
	}
}

