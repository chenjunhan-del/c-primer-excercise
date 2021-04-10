#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Vector.h"

//����Vector���ʵ�麯��
void Vector_operate() {
	typedef VECTOR::Vector Vec;
	using std::cout;
	using std::cin;

	int x, y;
	cout << "������x��y���꣡\n";
	cin >> x >> y;
	cout << "����Vector����\n";
	Vec v1(x, y, VECTOR::Vector::Mode::POL);
	cout << v1;

	cout << "����������3.4��\n";
	v1 = 3.4 * v1;

}

//�ƹ�ɢ������
void rand_walk() {
	using namespace std;
	using VECTOR::Vector;

	srand(time(0));
	double direction;//����ָ���ƹ����ߵķ���
	Vector step;//ÿ��λ�Ƶ�����
	Vector result(0.0, 0.0);//��ԭ�����
	unsigned long steps = 0;//�߹����ܲ���
	double target;//Ҫ���ߵľ���
	double dstep;//��������һ���߶�Զ

	cout << "������Ҫ���ߵľ��루q���˳����򣩣�";
	while (cin >> target) {
		cout << "�����벽����";
		if (!(cin >> dstep)) {
			break;
		}

		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::Mode::POL);
			result = result + step;//ʸ�����
			steps++;
		}

		cout << "����" << steps << "������λ�ƹ������߹�"
			<< target << "���ľ��룬�����������λ�ã�\n";
		cout << result << endl;

		steps = 0;
		result.reset(0.0, 0.0);
		cout << "������Ҫ���ߵľ��루q���˳����򣩣�";
	}

	//���һЩ��Ҫ������
	cout << "�ټ���\n";
	cin.clear();
	while (cin.get() != '\n') {
		continue;
	}
}