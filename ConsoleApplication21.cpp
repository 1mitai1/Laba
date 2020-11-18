#include <iostream>
using namespace std;

template < typename T >

void sirch(T x, T* array, int size)
{
	int number = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] == x)
			number++;
	}
	cout << number << " - number - " << x << endl;;
}

template < typename T >

T* vvod(T* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		T a;
		cin >> a;
		array[i] = a;
	}
	return array;
}

template < typename T >

void vivod(T* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	int size = 4;
	int* a = new int[size];
	double* b = new double[size];
	char* c = new char[size];

	cout << "int" << endl;
	a = vvod<int>(a, size);
	vivod<int>(a, size);
	cout << "double" << endl;
	b = vvod<double>(b, size);
	vivod<double>(b, size);
	cout << "char" << endl;
	c = vvod<char>(c, size);
	vivod<char>(c, size);

	int x;
	cin >> x;
	sirch<int>(x, a, size);
	double y;
	cin >> y;
	sirch<double>(y, b, size);
	char z;
	cin >> z;
	sirch<char>(z, c, size);
}