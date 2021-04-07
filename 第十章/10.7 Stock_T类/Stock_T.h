#pragma once
#include<string>

class Stock_T {
private:
	std::string company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() {
		total_val = shares * share_val;
	}

public:
	Stock_T();
	Stock_T(const std::string& co, long n = 0, double pr = 0.0);
	~Stock_T();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show()const;
	const Stock_T& topval(const Stock_T& s)const;
};