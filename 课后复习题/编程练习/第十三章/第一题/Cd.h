#pragma once
//�����ϰҪ��
//������һ��Classic�࣬�����һ��char��Ա�����ڴ洢ָ��CD����
//Ҫ��Ʒ���ַ������޸�����������ʹ��������к���������ġ������
//������������ĳ������������Ҫ������ɾ������
//ʹ������ĳ���������Ĳ�Ʒ�����CdOperate��

//��ͼ�����к�������Ϊvirtualʱ�����캯�������ƹ��캯��
//�Լ�Ĭ�Ϲ��캯������ʹ��virtual

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