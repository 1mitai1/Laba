#include <iostream>
#include<string>
#include <ctime>
using namespace std;

class ex
{
private:
	int id;
	string name;
	int mark;

public:

	ex()
	{
		id = 0;
		name = "-";
		mark = 0;
	}
	ex(string nm) : name(nm), mark(rand() % 10), id(rand() % 100)
	{

	}

	void output()
	{
		cout << "\nId - " << id << "\nName - " << name << "\nMark - " << mark << endl;
	}
	bool operator< (ex& a) const
	{
		return (mark < a.mark);
	}
	bool operator> (ex& a) const
	{
		return (mark > a.mark);
	}
	bool operator== (ex& a) const
	{
		return (mark == a.mark);
	}
	friend ostream& operator<<(ostream& out, const ex x);
};

ostream& operator<<(ostream& out, const ex x)
{
	out << "\nId - " << x.id << "\nName - " << x.name << "\nMark - " << x.mark << endl;
	return out;
}


class Exception
{
public:
	Exception(const string errorMessage = "Something wrong") : m_ErrorMessage(errorMessage) { }
	friend ostream& operator<< (ostream& out, const Exception& ex)
	{
		out << ex.m_ErrorMessage << '\n'; return out;
	}
private:
	string m_ErrorMessage;
};


void my_terminate()
{
	cerr << "\nTerminate handler called" << endl;
	abort();
}
void my_unexpected()
{
	cerr << "\nUnexpected exception" << endl;
	terminate();
}


template <typename T>
class  Node
{
public:
	T data;
	Node* next;
	Node() : data(), next(nullptr) { }
	Node(T value) : data(value), next(nullptr) { }
};


template<class T>
class Ring
{
private:
	Node<T>* head;
	int size;
public:
	Ring() :head(nullptr), size(0) {}
	void push(T data)
	{
		if (head == nullptr)
		{
			Node<T>* element = new Node<T>(data);
			head = new Node<T>(data);
			element->next = head;
			head = element;
			size++;
		}
		else
		{
			Node<T>* tmp = head;
			int i = 0;
			while (i < size - 1)
			{
				tmp = tmp->next;
				i++;
			}
			tmp->next = new Node<T>(data);
			tmp->next->next = head;
			size++;
		}
	}
	void pop()
	{
		if (size == 0)
			throw Exception();
		Node<T>* tmp = head;
		head = head->next;
		delete tmp;
		size--;
		Node<T>* temp = head;
		int i = 0;
		while (i < size - 1)
		{
			temp = temp->next;
			i++;
		}
		temp->next = head;
	}
	void output()
	{
		if (size == 0)
			throw Exception();
		Node<T>* tmp = head;
		int i = 0;
		while (i < size)
		{
			cout << "   " << tmp->data;
			tmp = tmp->next;
			i++;
		}
	}
	Node<T>* get_node() {
		return head;
	}
	int get_size() {
		return size;
	}
	friend ostream& operator<<(ostream& out, const Node<T>& node);
};

template<class T>
class Iterator
{
private:
	Node<T>* node;
	int size;
	int cur;
public:
	friend Ring<T>;
	Iterator(Ring<T>* element) : cur(0)
	{
		node = element->get_node();
		size = element->get_size();
	}
	void begin() //итератор на первый элемент 
	{
		if (size == 0)
			throw Exception();
		if (cur != 0)
		{
			while (cur < size)
			{
				cur++;
				node = node->next;
			}
			cur = 0;
		}

	}
	void search(T data)
	{
		if (size == 0)
			throw Exception();
		int i = 0;
		while (i < size)
		{
			if (data == node->data)
			{
				cout << "\nElement\n " << data << "\nfound" << endl;
				return;
			}
			if (cur == size - 1)
				cur = 0;
			else
				cur++;
			node = node->next;
			i++;
		}
		cout << "\nElement\n " << data << " \nnot found" << endl;
	}
	void shellsort()
	{
		if (size == 0)
			throw Exception();
		int gap, i, j;
		T tmp;
		for (gap = size / 2; gap > 0; gap /= 2)
			for (i = gap; i < size; i++)
				for (j = i - gap; j >= 0 && (*this)[j].node->data > (*this)[j + gap].node->data; j -= gap)
				{
					tmp = (*this)[j].node->data;
					(*this)[j].node->data = (*this)[j + gap].node->data;
					(*this)[j + gap].node->data = tmp;
				}
	}
	Iterator& operator++()
	{
		try
		{
			if (size == 0);
		}
		catch (Exception)
		{
			cerr << "\nThe ring is empty" << endl;
		}
		if (size == 1)
			cur = 0;
		else
			cur++;
		node = node->next;
		return *this;
	}
	T operator*() {
		return node->data;
	}

	Iterator& operator[](int index)
	{
		if (size == 0)
			throw Exception();
		Node<T>* tmp = node;
		while (1)
		{
			if (cur == index)
			{
				node = tmp;
				return *this;
			}
			tmp = tmp->next;
			if (cur == size - 1)
				cur = 0;
			else
				cur++;
		}
	}

	void operator = (T value)
	{
		try
		{
			if (size == 0);
		}
		catch (Exception)
		{
			cerr << "\nThe ring is empty" << endl;
		}
		node->data = value;
	}

};



int main()
{
	srand(time(nullptr));
	set_terminate(my_terminate);
	set_unexpected(my_unexpected);

	Ring<ex> ring;
	try
	{
		ring.output();
	}
	catch (Exception ex)
	{
		cerr << ex;
	}
	ex a("A");
	try
	{
		ring.push(a);
		ring.push(ex("L"));
		ring.push(ex("M"));
	}
	catch (Exception ex)
	{
		cerr << ex;
	}
	ex b("H");
	try
	{
		ring.push(b);
		ring.push(ex("R"));
	}
	catch (Exception ex)
	{
		cerr << ex;
	}

	ring.output();

	Iterator<ex> I(&ring);

	cout << endl << "Sort" << endl;

	I.begin();
	I.shellsort();
	ring.output();
	ring.pop();

	cout << endl << "After pop" << endl;

	ring.output();

	cout << endl << "Search" << endl;

	I.begin();
	I.search(b);
	I.search(a);
	return 0;
}