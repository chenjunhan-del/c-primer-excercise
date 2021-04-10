#pragma once
#include<string>

class Stock_up {
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot() {
		total_val = shares * share_val;
	}

public:
	Stock_up();
	Stock_up(const std::string& co, long n = 0, double pr = 0.0);
	~Stock_up();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
};