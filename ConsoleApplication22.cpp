#include <iostream>
#include<string>
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
	ex(string nm, int mr, int id) : name(nm), mark(mr), id(id)
	{

	}

	void output()
	{
		cout << "\nId - " << id << "\nName - " << name << "\nMark - " << mark << endl;
	}
	bool operator< (ex& a) const
	{
		return (name[0] < a.name[0]);
	}
	bool operator> (ex& a) const
	{
		return (name[0] > a.name[0]);
	}
	bool operator== (ex& a) const
	{
		return (name[0] == a.name[0]);
	}
	friend ostream& operator<<(ostream& out, const ex x);
};

ostream& operator<<(ostream& out, const ex x)
{
	out << "\nId - " << x.id << "\nName - " << x.name << "\nPlace - " << x.mark << endl;
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
	Node* next, *prev;
	Node() : data(), next(nullptr), prev(nullptr) { }
	Node(T value) : data(value), next(nullptr),prev(nullptr) { }
};


template<class T>
class List
{
private:
	Node<T>* head,* tail;
	int size;
public:
	List() :head(nullptr), size(0), tail(nullptr) {}
	~List()
	{
		while (head)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
	}
	void push(T data)
	{
		Node<T>* tmp = new Node<T>(data);
		tmp->next = NULL;
		if (head != NULL)
		{
			tmp->prev = tail;
			tail->next = tmp;
			tail = tmp;
			size++;
		}
		else
		{
			tmp->prev = NULL;
			head = tail = tmp;
			size++;
		}
	}
	//void push(T data)
	//{
	//	if (head == nullptr)
	//	{
	//		Node<T>* element = new Node<T>(data);
	//		head = new Node<T>(data);
	//		element->next = nullptr;
	//		temp->prev = tail;
	//		tail->next = temp;
	//		tail = temp;
	//		size++;
	//	}
	//	else
	//	{
	//		Node<T>* tmp = head;
	//		int i = 0;
	//		while (i < size - 1)
	//		{
	//			tmp = tmp->next;
	//			i++;
	//		}
	//		tmp->next = new Node<T>(data);
	//		tmp->next->next = head;
	//		size++;
	//	}
	//}
	void pop()
	{
		if (size == 0)
			throw Exception();
		if (head->next)
		{
			Node<T>* tmp = head;
			head = head->next;
			head->prev = nullptr;
			delete tmp;
			size--;
		}
		else
		{
			head->next = nullptr;
			head = nullptr;
			delete head;
			size = 0;
		}
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
	friend List<T>;
	Iterator(List<T>* element) : cur(0)
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

	void sort()
	{
		if (size == 0)
			throw Exception();
		T tmp;
		for (int i=0;i<size;i++)
		{
			for (int j=0;j<size-i;j++) 
			{
				if ((*this)[j].node->data > (*this)[j + 1].node->data)
				{
					tmp = (*this)[j].node->data;
					(*this)[j].node->data = (*this)[j + 1].node->data;
					(*this)[j + 1].node->data = tmp;
				}
			}
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
	set_terminate(my_terminate);
	set_unexpected(my_unexpected);
	List<ex> list;
	try
	{
		list.output();
	}
	catch (Exception)
	{
		cerr << "\nThe ring is empty\n";
	}
	ex a("t", 2, 5);
	try
	{
		list.push(a);
		list.push(ex("x", 3, 87));
		list.push(ex("r", 1, 100));
	}
	catch (Exception)
	{
		cerr << "\nThe ring is empty\n";
	}
	ex b("John", 4, 1);
	try
	{
		list.push(b);
		list.push(ex("w", 5, 45));
	}
	catch (Exception)
	{
		cerr << "\nThe ring is empty\n";
	}
	list.output();
	Iterator<ex> I(&list);
	cout << endl << "Sorting..." << endl;
	I.begin();
	I.sort();

	list.output();
	list.pop();
	cout << endl << "After poping out the first one" << endl;
	list.output();
	cout << endl << "Searching..." << endl;
	I.begin();
	I.search(b);
	I.search(a);
	return 0;
}



//#include <iostream>
//#include<string>
//using namespace std;
//
//class Olimp
//{
//private:
//	int id;
//	string name;
//	int place;
//
//public:
//
//	Olimp()
//	{
//		id = 0;
//		name = "-";
//		place = 0;
//	}
//	Olimp(string nm, int pl, int id) : name(nm), place(pl), id(id)
//	{
//
//	}
//
//	void output()
//	{
//		cout << "\nId - " << id << "\nName - " << name << "\nPlace - " << place << endl;
//	}
//	bool operator< (Olimp& a) const
//	{
//		return (name[0] < a.name[0]);
//	}
//	bool operator> (Olimp& a) const
//	{
//		return (name[0] > a.name[0]);
//	}
//	bool operator== (Olimp& a) const
//	{
//		return (name[0] == a.name[0]);
//	}
//	friend ostream& operator<<(ostream& out, const Olimp x);
//};
//
//ostream& operator<<(ostream& out, const Olimp x)
//{
//	out << "\nId - " << x.id << "\nName - " << x.name << "\nPlace - " << x.place << endl;
//	return out;
//}
//
//
//class Exception
//{
//public:
//	Exception(const string errorMessage = "Something wrong") : m_ErrorMessage(errorMessage) { }
//	friend ostream& operator<< (ostream& out, const Exception& ex)
//	{
//		out << ex.m_ErrorMessage << '\n'; return out;
//	}
//private:
//	string m_ErrorMessage;
//};
//
//
//void my_terminate()
//{
//	cerr << "\nTerminate handler called" << endl;
//	abort();
//}
//void my_unexpected()
//{
//	cerr << "\nUnexpected exception" << endl;
//	terminate();
//}
//
//
//template <typename T>
//class  Node
//{
//public:
//	T data;
//	Node* next;
//	Node() : data(), next(nullptr) { }
//	Node(T value) : data(value), next(nullptr) { }
//};
//
//
//template<class T>
//class Ring
//{
//private:
//	Node<T>* head;
//	int size;
//public:
//	Ring() :head(nullptr), size(0) {}
//	void push(T data)
//	{
//		if (head == nullptr)
//		{
//			Node<T>* element = new Node<T>(data);
//			head = new Node<T>(data);
//			element->next = head;
//			head = element;
//			size++;
//		}
//		else
//		{
//			Node<T>* tmp = head;
//			int i = 0;
//			while (i < size - 1)
//			{
//				tmp = tmp->next;
//				i++;
//			}
//			tmp->next = new Node<T>(data);
//			tmp->next->next = head;
//			size++;
//		}
//	}
//	void pop()
//	{
//		if (size == 0)
//			throw Exception();
//		Node<T>* tmp = head;
//		head = head->next;
//		delete tmp;
//		size--;
//		Node<T>* temp = head;
//		int i = 0;
//		while (i < size - 1)
//		{
//			temp = temp->next;
//			i++;
//		}
//		temp->next = head;
//	}
//	void output()
//	{
//		if (size == 0)
//			throw Exception();
//		Node<T>* tmp = head;
//		int i = 0;
//		while (i < size)
//		{
//			cout << "   " << tmp->data;
//			tmp = tmp->next;
//			i++;
//		}
//	}
//	Node<T>* get_node() {
//		return head;
//	}
//	int get_size() {
//		return size;
//	}
//	friend ostream& operator<<(ostream& out, const Node<T>& node);
//};
//
//template<class T>
//class Iterator
//{
//private:
//	Node<T>* node;
//	int size;
//	int cur;
//public:
//	friend Ring<T>;
//	Iterator(Ring<T>* element) : cur(0)
//	{
//		node = element->get_node();
//		size = element->get_size();
//	}
//	void begin() //итератор на первый элемент 
//	{
//		if (size == 0)
//			throw Exception();
//		if (cur != 0)
//		{
//			while (cur < size)
//			{
//				cur++;
//				node = node->next;
//			}
//			cur = 0;
//		}
//
//	}
//	void search(T data)
//	{
//		if (size == 0)
//			throw Exception();
//		int i = 0;
//		while (i < size)
//		{
//			if (data == node->data)
//			{
//				cout << "\nElement\n " << data << "\nfound" << endl;
//				return;
//			}
//			if (cur == size - 1)
//				cur = 0;
//			else
//				cur++;
//			node = node->next;
//			i++;
//		}
//		cout << "\nElement\n " << data << " \nnot found" << endl;
//	}
//	void shellsort()
//	{
//		if (size == 0)
//			throw Exception();
//		int gap, i, j;
//		T tmp;
//		for (gap = size / 2; gap > 0; gap /= 2)
//			for (i = gap; i < size; i++)
//				for (j = i - gap; j >= 0 && (*this)[j].node->data > (*this)[j + gap].node->data; j -= gap)
//				{
//					tmp = (*this)[j].node->data;
//					(*this)[j].node->data = (*this)[j + gap].node->data;
//					(*this)[j + gap].node->data = tmp;
//				}
//	}
//	Iterator& operator++()
//	{
//		try
//		{
//			if (size == 0);
//		}
//		catch (Exception)
//		{
//			cerr << "\nThe ring is empty" << endl;
//		}
//		if (size == 1)
//			cur = 0;
//		else
//			cur++;
//		node = node->next;
//		return *this;
//	}
//	T operator*() {
//		return node->data;
//	}
//
//	Iterator& operator[](int index)
//	{
//		if (size == 0)
//			throw Exception();
//		Node<T>* tmp = node;
//		while (1)
//		{
//			if (cur == index)
//			{
//				node = tmp;
//				return *this;
//			}
//			tmp = tmp->next;
//			if (cur == size - 1)
//				cur = 0;
//			else
//				cur++;
//		}
//	}
//
//	void operator = (T value)
//	{
//		try
//		{
//			if (size == 0);
//		}
//		catch (Exception)
//		{
//			cerr << "\nThe ring is empty" << endl;
//		}
//		node->data = value;
//	}
//
//};
//
//
//
//int main()
//{
//	set_terminate(my_terminate);
//	set_unexpected(my_unexpected);
//
//	Ring<Olimp> ring;
//	try
//	{
//		ring.output();
//	}
//	catch (Exception ex)
//	{
//		cerr << ex;
//	}
//	Olimp a("Alex", 2, 5);
//	try
//	{
//		ring.push(a);
//		ring.push(Olimp("Liz", 3, 6));
//		ring.push(Olimp("Max", 1, 12));
//	}
//	catch (Exception ex)
//	{
//		cerr << ex;
//	}
//	Olimp b("John", 4, 1);
//	try
//	{
//		ring.push(b);
//		ring.push(Olimp("Rose", 5, 8));
//	}
//	catch (Exception ex)
//	{
//		cerr << ex;
//	}
//
//	ring.output();
//
//	Iterator<Olimp> I(&ring);
//
//	cout << endl << "Sorting..." << endl;
//
//	I.begin();
//	I.shellsort();
//	ring.output();
//	ring.pop();
//
//	cout << endl << "After poping out the first one" << endl;
//
//	ring.output();
//
//	cout << endl << "Searching..." << endl;
//
//	I.begin();
//	I.search(b);
//	I.search(a);
//	return 0;
//}