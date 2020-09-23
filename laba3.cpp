#include <iostream>
using namespace std;

class mdouble
{
	int size;
	double** a;
public:
	mdouble()
	{
		this->size = 0;
		this->a = new double* [size];
		this->a[0] = new double[size];
	}
	mdouble(int s)
	{
		this->size = s;
		this->a = new double* [size];
		for (int i = 0; i < size; i++)
		{
			this->a[i] = new double[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				cout << endl << "[" << i << "] [" << j << "] = ";
				cin >> this->a[i][j];
			/*	a[i][j] = 0;*/
			}
		}
	}
	mdouble(const mdouble& b)
	{
		this->size = b.size;
		this->a = new double* [size];
		for (int i = 0; i < size; i++)
		{
			this->a[i] = new double[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				this->a[i][j]=b.a[i][j];
			}
		}
	}
	~mdouble()
	{
		delete[] a;
	}
	void preobr(mdouble& b)
	{
		double x;
		for(int i =0;i<size;i++)
			for (int j = i + 1; j < size; j++)
			{
				x = this->a[i][j];
				this->a[i][j] = this->a[j][i];
				this->a[j][i] = x;
			}
	}
	friend void show(mdouble& b);
	void operator = (const mdouble &b)
	{
		delete[] this->a;
		this->size = b.size;
		this->a = new double* [size];
		for (int i = 0; i < size; i++)
		{
			this->a[i] = new double[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				this->a[i][j] = b.a[i][j];
			}
		}

	}
	//double* operator [](int x)
	//{
	//	return this->a[x];
	//}
	double* operator[](int r)
	{
		return a[r];
	}

	double const* operator[](int r) const
	{
		return a[r];
	}
	friend void operator -- (mdouble& b);
};

void operator -- (mdouble& b)
{
	b.size = b.size - 1;
	for (int i = 0; i < b.size; i++)
	{
		for (int j = 0; j < b.size; j++)
		{
			if (i == b.size || j == b.size)
				b.a[i][i] = 0;
		}
	}
}

void show(mdouble& b)
{
	for (int i = 0; i < b.size; i++)
	{
		for (int j = 0; j < b.size; j++)
			cout << b.a[i][j] << "  ";
		cout << endl;
	}
}

int main()
{
	int size;
	cin >> size;
	cout << "sosd a:" << endl;
	mdouble a(size);
	cout << "sosd b:" << endl;
	mdouble b(a);
	cout << "sosd c:" << endl;
	mdouble c(size);
	cout << "a:" << endl;
	show(a);
	cout << "b:" << endl;
	show(b);
	cout << "c:" << endl;
	show(c);
	c = a;
	cout << "c=a:" << endl;
	show(c);
	cout << "a[2][1]=0"<< endl;
	int x = 2, y = 1;
	a[y-1][x-1]=0;
	show(a);
	cout << "c--:" << endl;
	--c;
	show(c);
	
	return 0;

}