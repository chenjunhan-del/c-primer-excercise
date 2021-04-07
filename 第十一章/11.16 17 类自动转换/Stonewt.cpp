#include "Stonewt.h"
#include<iostream>
using std::cout;

Stonewt::Stonewt(double lbs) {
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn;
	pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs) {
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Stonewt::Stonewt() {
	stone = pounds = pds_left = 0;
}

Stonewt::~Stonewt() {

}

void Stonewt::show_lbs() const {
	cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_stn() const {
	cout << pounds << " pounds\n";
}

Stonewt::operator int() const {
	return int(pounds + 0.5);
}

Stonewt::operator double() const {
	return pounds;
}

