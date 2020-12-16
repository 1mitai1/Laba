#include "Toy.h"
#include "Exception.h"

ostream& operator<<(ostream& out, const Toy& toy)
{
	try {
		if (toy.name == " ")
		{
			throw 2;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	out << toy.name << " " << toy.amount << " " << toy.price <<" "<<toy.rest<< endl;
	return out;
}

istream& operator>>(istream& in, Toy& toy)
{
	in >> toy.name;
	in >> toy.amount;
	in >> toy.price;
	in >> toy.rest;
	return in;
}

bool operator==(Toy num1, Toy num2) {
	if (num1.get_name() == num2.get_name() && num1.get_amount() == num2.get_amount() && num1.get_price() == num2.get_price() &&
		num1.get_rest() == num2.get_rest()) {
		return true;
	}
	else {
		return false;
	}
}


string Toy::get_name() {
	return this->name;
}
int Toy::get_amount() {
	return this->amount;
}
int Toy::get_price() {
	return this->price;
}
int Toy::get_rest() {
	return this->rest;
}

void Toy::set_name(string temp) {
	this->name = temp;
}
void Toy::set_amount(int temp) {
	this->amount = temp;
}
void Toy::set_price(int temp) {
	this->price = temp;
}
void Toy::set_rest(int temp) {
	this->rest = temp;
}