#pragma once
#include<iostream>

//Vector��������ռ�
namespace VECTOR {
	class Vector {
	public:
		//���е�ö�٣�ģʽת����
		enum class Mode { RECT, POL };

	private:
		double x;//ˮƽ����
		double y;//��ֱ����
		double mag;//ʸ����ģ
		double ang;//ʸ���ķ��򣨽Ƕȣ�
		Mode mode;//ָ��ģʽ

		//�趨mag��ֵ
		void set_mag();

		//�趨ang��ֵ
		void set_ang();

		//�趨x��ֵ
		void set_x();

		//�趨y��ֵ
		void set_y();

	public:
		//Ĭ�Ϲ��캯����������ֵ��Ϊ0��ģʽΪֱ������
		Vector();

		//Ĭ��ģʽ��ֱ�����꣬����x��y��ֵ
		Vector(double n1, double n2, Mode form = Mode::RECT);

		//��������x��y��ֵ�Լ�ģʽ
		void reset(double n1, double n2, Mode form = Mode::RECT);

		//��������
		~Vector();

		//����x��ֵ
		double xval()const {
			return x;
		}

		//����y��ֵ
		double yval()const {
			return y;
		}

		//����mag��ֵ
		double magval()const {
			return mag;
		}

		//����ang��ֵ
		double angval()const {
			return ang;
		}

		//��ģʽ�л�Ϊ������
		void polar_mode();

		//��ģʽ�л�Ϊֱ������
		void rect_mode();

		//������������������������
		Vector operator+(const Vector& b)const;

		//������������������������
		Vector operator-(const Vector& b)const;

		////���������������Ч����֪��
		//Vector operator-()const;

		//������������������
		Vector operator*(double n)const;

		//��Ԫ�����������������
		friend Vector operator*(double n, const Vector& a);

		//��Ԫ�����������������
		friend std::ostream& operator<<(std::ostream& os, const Vector& V);
	};
}