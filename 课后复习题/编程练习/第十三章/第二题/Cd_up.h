#pragma once
//�����ϰҪ��
//�����ϰ1������������ʹ�ö�̬�ڴ����
//�����ǳ��ȹ̶�����������¼�ַ�����

class Cd_Up {
private:
	char* performers;
	char* label;
	int selections;
	double playtime;

public:
	Cd_Up(const char* s1, const char* s2, int n, double x);
	Cd_Up(const Cd_Up& cd);
	Cd_Up();
	virtual ~Cd_Up();
	virtual void Report()const;
	virtual Cd_Up& operator=(const Cd_Up& cd);
};

class Classic_Up :public Cd_Up {
private:
	char* main_works;

public:
	Classic_Up(const char* s1, const char* s2, const char* s3, int n, double x);
	Classic_Up();
	Classic_Up(const Classic_Up& c1);
	virtual ~Classic_Up();
	virtual void Report()const;
	virtual Classic_Up& operator=(const Classic_Up& c1);
};

void Cd_UpOperate();

void BravoUp(const Cd_Up& cd);