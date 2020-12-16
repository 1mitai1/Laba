#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Toy {
private:
	string name;
	int amount;
	int price;
	int rest;
public:
	Toy() {
		this->name = " ";
		this->amount = 10;
		this->price = 10;
		this->rest = 10;
	}
	Toy(string name,int amount,int price,int rest) {
		this->name = name;
		this->amount = amount;
		this->price = price;
		this->rest = rest;
	}
	friend ostream& operator<<(ostream& out, const Toy& art);
	friend istream& operator>>(istream& in, Toy& art);
	friend bool operator==(const Toy num1, const Toy num2);

	string get_name();
	int get_amount();
	int get_price();
	int get_rest();

	void set_name(string);
	void set_amount(int);
	void set_price(int);
	void set_rest(int);
};