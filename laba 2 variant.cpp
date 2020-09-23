#include <iostream>
#include <string.h>
using namespace std; 

class Result;

class task
{
	int number;
	string name;
	int percent;
public:
	friend Result;
	void vnumber()
	{
		cout << "№"<<endl;
		cin >> number;
	}
	void vname()
	{
		cout << "name" << endl;
		cin >> name;
	}
	task() {
		number = 0;
		name = "";
		percent = 0;
	}
	task(int a, string b)
	{
		number = a;
		name = b;
		percent = 0;
	}
	friend void show(task& a);
	~task();

};

class Result
{
	int result;
public:
	Result()
	{
		result = 1 + rand() % 100;
	}
	void vresult(task &a)
	{
		a.percent = result;
	}
};
void show(task& a)
{
	cout << "number " << a.number << endl << a.name << endl << a.percent<<endl;
}

int main()
{
	int size;
	cin >> size;
	task* a = new task[size];
	Result* r = new Result[size];
	for (int i = 0; i < size;i++)
	{
		cout << "Name:"<<endl;
		string  b;
		cin >> b;
		a[i] = task(i+1, b);
		r[i].vresult(a[i]);
	}
	cout << endl<<endl;

	for (int i = 0; i < size; i++)
	{
		show(a[i]);
	}

	return 0;
}
