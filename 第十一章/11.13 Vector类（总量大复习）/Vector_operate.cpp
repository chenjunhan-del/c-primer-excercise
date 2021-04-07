#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Vector.h"

//操作Vector类的实验函数
void Vector_operate() {
	typedef VECTOR::Vector Vec;
	using std::cout;
	using std::cin;

	int x, y;
	cout << "请输入x，y坐标！\n";
	cin >> x >> y;
	cout << "创建Vector对象！\n";
	Vec v1(x, y, VECTOR::Vector::Mode::POL);
	cout << v1;

	cout << "将该向量乘3.4！\n";
	v1 = 3.4 * v1;

}

//酒鬼散步问题
void rand_walk() {
	using namespace std;
	using VECTOR::Vector;

	srand(time(0));
	double direction;//用于指定酒鬼行走的方向
	Vector step;//每次位移的向量
	Vector result(0.0, 0.0);//从原点出发
	unsigned long steps = 0;//走过的总步数
	double target;//要行走的距离
	double dstep;//步长，即一次走多远

	cout << "请输入要行走的距离（q以退出程序）：";
	while (cin >> target) {
		cout << "请输入步长：";
		if (!(cin >> dstep)) {
			break;
		}

		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::Mode::POL);
			result = result + step;//矢量相加
			steps++;
		}

		cout << "经过" << steps << "步，这位酒鬼终于走过"
			<< target << "长的距离，现在他在这个位置：\n";
		cout << result << endl;

		steps = 0;
		result.reset(0.0, 0.0);
		cout << "请输入要行走的距离（q以退出程序）：";
	}

	//清空一些不要的输入
	cout << "再见！\n";
	cin.clear();
	while (cin.get() != '\n') {
		continue;
	}
}