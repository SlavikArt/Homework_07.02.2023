#include <iostream>
using namespace std;
struct Element
{
	char data = 0;
	Element* Next = nullptr;
};

class List
{
	Element* Head;
	Element* Tail;
	int Count;
public:
	List();
	~List();

	void AddToHead(char data);
	void Add(char data);
	void AddByIndex(char data, int index);
	
	void Del();
	void DelAll();
	void DelByIndex(int index);

	void PrintHead();
	void Print();
	void Print(int pos);

	int Search(char data);

	int GetCount()const;
};

List::List()
{
	Head = Tail = nullptr;
	Count = 0;
}
List::~List()
{
	DelAll();
}

void List::AddToHead(char data)
{
	Element* el = new Element();

	el->data = data;
	el->Next = Head;

	if (Head == nullptr)
		Tail = el;
	Head = el;
	Count++;
}
void List::Add(char data)
{
	Element* temp = new Element;

	temp->data = data;
	temp->Next = nullptr;

	if (Head != nullptr) 
	{
		Tail->Next = temp;
		Tail = temp;
	}
	else 
	{
		Head = Tail = temp;
	}
	Count++;
}
void List::AddByIndex(char data, int index)
{
	if (index >= Count || index < 0)
		throw "Invalid Index";

	if (index == 0) {
		Element* temp = Head;
		Head = new Element;

		Head->data = data;
		Head->Next = temp;
	}
	else if (index == Count - 1) {
		Element* temp = Tail;
		Tail = new Element;

		Tail->data = data;
		Tail->Next = nullptr;

		temp->Next = Tail;
	}
	else {
		Element* temp = Head;
		for (int i = 1; i < index; i++) 
			temp = temp->Next;

		Element* prev = temp;
		Element* next = temp->Next;
		Element* cur = new Element;

		prev->Next = cur;
		cur->data = data;
		cur->Next = next;
	}
	Count++;
}

void List::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
}
void List::DelAll()
{
	while (Head != nullptr)
		Del();
}
void List::DelByIndex(int index) {
	if (index >= Count || index < 0)
		throw "Invalid Index";

	if (index == 0) {
		Element* temp = Head;
		Head = Head->Next;
		delete temp;
	}
	else if (index == Count - 1) {
		Element* temp = Head;
		for (int i = 1; i < index; i++) 
			temp = temp->Next;
		Tail = temp;
		delete Tail->Next;
		Tail->Next = nullptr;
	}
	else {
		Element* temp = Head;
		for (int i = 1; i < index; i++) 
			temp = temp->Next;

		Element* prev = temp;
		Element* cur = temp->Next;
		Element* next = cur->Next;

		prev->Next = next;
		delete cur;
	}
	Count--;
}

void List::PrintHead()
{
	cout << Head->data << "\n";
}
void List::Print()
{
	Element* temp = Head;

	while (temp != 0)
	{
		cout << temp->data;
		temp = temp->Next;
	}
	cout << "\n";
}
void List::Print(int pos)
{
	if (pos >= Count || pos < 0)
		throw "Invalid Index";

	if (pos == 0) {
		cout << Head->data << "\n";
	}
	else if (pos == Count - 1) {
		cout << Tail->data << "\n";
	}
	else {
		Element* temp = Head;
		for (int i = 0; i < pos; i++)
			temp = temp->Next;
		cout << temp->data << "\n";
	}
}

int List::Search(char data) {
	Element* temp = Head;

	int i = 0;
	while (temp != nullptr)
	{
		if (temp->data == data)
			return i;
		temp = temp->Next;
		i++;
	}
	return 0;
}

inline int List::GetCount()const
{
	return Count;
}

void main()
{
	List lst;

	char s[] = "Hello, World !!!";

	int len = strlen(s);

	for (int i = 0; i < len; i++)
		lst.Add(s[i]);

	lst.Print();
	lst.PrintHead();
	lst.Print(4); // с нуля
	lst.AddToHead('M');
	lst.Print();
	lst.AddByIndex('A', 4);
	lst.Print();
	lst.DelByIndex(4);
	lst.Print();
	cout << lst.Search('d') << "\n";
}
