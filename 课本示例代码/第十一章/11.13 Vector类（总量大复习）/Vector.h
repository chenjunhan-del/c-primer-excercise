#pragma once
#include<iostream>

//Vector类的命名空间
namespace VECTOR {
	class Vector {
	public:
		//类中的枚举（模式转换）
		enum class Mode { RECT, POL };

	private:
		double x;//水平坐标
		double y;//竖直坐标
		double mag;//矢量的模
		double ang;//矢量的方向（角度）
		Mode mode;//指定模式

		//设定mag的值
		void set_mag();

		//设定ang的值
		void set_ang();

		//设定x的值
		void set_x();

		//设定y的值
		void set_y();

	public:
		//默认构造函数，将所有值设为0，模式为直角坐标
		Vector();

		//默认模式：直角坐标，设置x，y的值
		Vector(double n1, double n2, Mode form = Mode::RECT);

		//重新设置x，y的值以及模式
		void reset(double n1, double n2, Mode form = Mode::RECT);

		//析构函数
		~Vector();

		//返回x的值
		double xval()const {
			return x;
		}

		//返回y的值
		double yval()const {
			return y;
		}

		//返回mag的值
		double magval()const {
			return mag;
		}

		//返回ang的值
		double angval()const {
			return ang;
		}

		//将模式切换为极坐标
		void polar_mode();

		//将模式切换为直角坐标
		void rect_mode();

		//重载运算符，将两个向量相减
		Vector operator+(const Vector& b)const;

		//重载运算符，将两个向量相减
		Vector operator-(const Vector& b)const;

		////重载运算符，具体效果不知道
		//Vector operator-()const;

		//重载运算符，向量标乘
		Vector operator*(double n)const;

		//友元函数，用于向量标乘
		friend Vector operator*(double n, const Vector& a);

		//友元函数，用于输出向量
		friend std::ostream& operator<<(std::ostream& os, const Vector& V);
	};
}