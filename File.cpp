#include "File.h"
#include "Toy.h"
#include "Exception.h"

File& operator<<(File& file, const char* s)
{
	try {
		if (!file.file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	string str = s;
	file.file << str;
	return file;
}

fstream& operator<<(fstream& out, Toy& toy) {
	try {
		if (!out.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	int a = out.tellg();
	string art_name = toy.get_name();
	size_t len1 = art_name.length() + 1;

	int amount = toy.get_amount();
	int price = toy.get_price();
	int rest = toy.get_rest();

	out.write((char*)(&len1), sizeof(len1));
	out.write((char*)(art_name.c_str()), len1);

	out.write((char*)(&amount), sizeof(amount));
	out.write((char*)(&price), sizeof(price));
	out.write((char*)(&rest), sizeof(rest));


	return out;
}

File& operator<<(File& file, Toy& toy)
{
	int pos = 0, a = 0, size = 0;
	try {
		if (!file.file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	if (file.key == txt) {
		file.file << toy.get_name() << " " << toy.get_amount() << " " << toy.get_price() << " " << toy.get_rest() <<  endl;
	}
	else if (file.key == bin) {
		string name = toy.get_name();
		size_t len1 = name.length() + 1;

		int amount = toy.get_amount();
		int price = toy.get_price();
		int rest = toy.get_rest();


		file.file.write((char*)(&len1), sizeof(len1));
		file.file.write((char*)(name.c_str()), len1);

		
		file.file.write((char*)(&amount), sizeof(amount));
		file.file.write((char*)(&price), sizeof(price));
		file.file.write((char*)(&rest), sizeof(rest));

		
	}
	return file;
}



ostream& operator<<(ostream& out, File& file)
{
	int a = 0;
	try {
		if (!file.file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
	}
	if (file.key == txt) {
		string str;
		while (!file.file.eof()) {
			std::getline(file.file, str);
			a = file.file.tellg();
			cout << str << endl;
		}
	}
	else if (file.key == bin) {
		int i = 0;
		int size = 0, step = 0;
		while (i < file.size) {
			int amount;
			int price;
			int rest;

			size_t len;

			file.file.read((char*)(&len), sizeof(len));
			char* name = new char[len];

			file.file.read((char*)(name), len);
			name[len - 1] = '\0';

			file.file.read((char*)(&amount), sizeof(int));
			file.file.read((char*)(&price), sizeof(int));
			file.file.read((char*)(&rest), sizeof(int));


			cout << name << " " << amount << " " << price << " " << rest << endl;

			delete[] name;
			i++;

		}
	}
	return out;
}



void File::edit(int line, Toy ms[])
{
	this->open("wr");

	int a, b;

	try {
		if (!file.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	Toy tmp;
	if (this->key == txt) {
		string temp;
		for (int i = 0; i < line - 1; i++) {
			std::getline(this->file, temp);
		}
		std::getline(this->file, temp, ' ');
		tmp.set_name(temp);
		std::getline(this->file, temp, ' ');
		tmp.set_amount(stoi(temp));
		std::getline(this->file, temp, ' ');
		tmp.set_price(stoi(temp));
		std::getline(this->file, temp, ' ');
		tmp.set_rest(stoi(temp));
	}
	else if (this->key == bin) {
		size_t len;
		for (int i = 0; i < line; i++) {
			this->file.read((char*)(&len), sizeof(len));
			char* n = new char[len];
			string name;
			int amount = 0;
			int price = 0;
			int rest = 0;

			this->file.read((char*)(n), len);
			name = n;
			name[len - 1] = '\0';
			this->file.read((char*)(&amount), sizeof(int));
			this->file.read((char*)(&price), sizeof(int));
			this->file.read((char*)(&rest), sizeof(int));

			this->file.read((char*)(&len), sizeof(len));
			this->file.read((char*)(n), len);

			tmp.set_name(name);
			tmp.set_amount(amount);
			tmp.set_price(price);
			tmp.set_rest(rest);
		}
		a = file.tellg();
	}

	cout << "What do you want to change?\n1 - name\n2-num\n3-year\n4-country\n5-direction" << endl;
	int choice;
	cin >> choice;
	cout << "Put new data: ";
	switch (choice) {
	case 1: {
		string a;
		rewind(stdin);
		cin >> a;
		tmp.set_name(a);
		break;
	}
	case 2: {
		int a;
		cin >> a;
		tmp.set_amount(a);
		break;
	}
	case 3: {
		int a;
		cin >> a;
		tmp.set_price(a);
		break;
	}
	case 4: {
		int a;
		cin >> a;
		tmp.set_rest(a);
		break;
	}

		  a = file.tellg();
		  file.seekg(0, ios_base::end);
		  b = file.tellg();
		  this->file.seekg(0, ios_base::beg);
		  if (this->key == txt) {
			  string temp;
			  for (int i = 0; i < line - 1; i++) {
				  getline(this->file, temp);
			  }
			  int pos = this->file.tellg();
			  this->file.seekg(pos, ios_base::beg);
			  this->file << tmp;
			  return;
		  }
		  else if (this->key == bin) {
			  for (int i = 0; i < line - 1; i++) {

				  size_t len;
				  this->file.read((char*)(&len), sizeof(len));
				  char* n = new char[len];
				  string name;
				  int amount = 0;
				  int price = 0;
				  int rest = 0;
				  this->file.read((char*)(n), len);
				  name = n;
				  name[len] = '\0';
				  this->file.read((char*)(&amount), sizeof(int));
				  this->file.read((char*)(&price), sizeof(int));
				  this->file.read((char*)(&rest), sizeof(int));
				  this->file.read((char*)(n), len);

				  this->file.read((char*)(&len), sizeof(len));
				  this->file.read((char*)(&n), len);

				  delete[]n;
			  }
			  int pos = this->file.tellg();

			  char* last = new char[b - a];
			  this->file.read((char*)last, b - a);

			  this->close();
			  this->open("w");
			  pos = this->file.tellg();
			  file << tmp;
			  for (int i = 0; i < get_size(); i++) {
				  if (i != line - 1)
					  file << ms[i];
				  else {
					  ms[i].set_name(tmp.get_name());
					  ms[i].set_amount(tmp.get_amount());
					  ms[i].set_price(tmp.get_price());
					  ms[i].set_rest(tmp.get_rest());

				  }
			  }
		  }

		  this->close();
	}
}


