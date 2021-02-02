using namespace std;
#include <iostream>

template<typename T>
class List
{
public:
	List();
	~List();
	int size() { return Size; }
	void push_front(T data);  // додати в початок 
	void insert(int index_number, T data); // вставити
	void print_for_begin(); // показати з початку
	void print_for_end();  // показати з кінця
	void remove(int index_number); // видалити елемент
	int find_element(int index_number); // знайти елемент
	void clear();
private:
	int Size;		
	void push_back(T data);
	void pop_back();
	void pop_front();
	template<typename T>
	class Node
	{
	public:
		T Data;
		Node* pNext;
		Node* pPrevious;
		Node(T Data= T(),  Node* pNext = nullptr, Node* pPrevious = nullptr)
		{
			this->pNext = pNext;
			this->pPrevious = pPrevious;
			this->Data = Data;
		}
		~Node()
		{
			this->pNext = nullptr;
			this->pPrevious = nullptr;
		}
	};
	Node<T> *head;
	Node<T> *tail;
};

template<typename T>
List<T>::List()
{
	head = nullptr;
	tail = nullptr;
	Size = 0;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_front(T data)
{
	Node<T>* Temp = new Node<T>(data);
	if (head == nullptr)
	{
		head = Temp;
		tail = Temp;
	}
	else
	{
		head->pNext = Temp;
		Temp->pPrevious = head;
		head = Temp;
	}
	Size++;
}

template<typename T>
void List<T>::push_back(T data)
{
	Node<T>* Temp = new Node<T>(data);
	if (head == nullptr)
	{
		head = Temp;
		tail = Temp;
	}
	else
	{
		tail->pPrevious = Temp;
		Temp->pNext = tail;
		tail = Temp;
	}
	Size++;
}

template<typename T>
void List<T>::insert(int index_number, T data)
{
	if (index_number == 0)
	{
		push_front(data);
	}
	else if (index_number == Size)
	{
		push_back(data);
	}
	else
	{
		Node<T>* Temp = new Node<T>(data);
		Node<T>* Temp_find = head;
		for (int i = 0; i != index_number; i++)
		{
			Temp_find = Temp_find->pPrevious;
		}
		Temp->pNext = Temp_find->pNext;
		Temp->pPrevious = Temp_find;
		Temp_find->pNext->pPrevious = Temp;
		Temp_find->pNext = Temp;
		Size++;
	}
}

template<typename T>
void List<T>::print_for_begin()
{
	if (Size == 0)
	{
		cout << "List is empty! " << endl;
		return;
	}
	Node<T>* Temp = head;
	while (Temp != nullptr)
	{
		cout << Temp->Data << " ";
		Temp = Temp->pPrevious;
	}
	cout << endl;
}

template<typename T>
void List<T>::print_for_end()
{
	if (Size == 0)
	{
		cout << "List is empty! " << endl;
		return;
	}
	Node<T>* Temp = tail;
	while (Temp != NULL)
	{
		cout << Temp->Data << " ";
		Temp = Temp->pNext;
	}
	cout << endl;
}

template<typename T>
void List<T>::pop_back()
{
	Node<T>* Temp = tail;
	tail->pNext->pPrevious = nullptr;
	tail = tail->pNext;
	delete Temp;
	Size--;
}

template<typename T>
void List<T>::pop_front()
{	
	Node<T>* Temp = head;
	if (Size >=2)
	{
	head->pPrevious->pNext = nullptr;
	head = head->pPrevious;
	}
	else
	{
		head = nullptr;
		tail = nullptr;
	}
	delete Temp;
	Size--;
}

template<typename T>
void List<T>::remove(int index_number)
{
	if (index_number == 0)
	{
		pop_front();
	}
	else if (index_number == Size - 1)
	{
		pop_back();
	}
	else
	{
		Node<T>* Temp_find = head;
		for (int i = 0; i != index_number; i++)
		{
			Temp_find = Temp_find->pPrevious;
		}
		Temp_find->pPrevious->pNext = Temp_find->pNext;
		Temp_find->pNext->pPrevious = Temp_find->pPrevious;
		delete Temp_find;
		Size--;
	}
}

template<typename T>
int List<T>::find_element(int index_number)
{
	Node<T>* Temp = head;
	for (int i = 0; i != index_number; i++)
	{
		Temp = Temp->pPrevious;
	}
	return Temp->Data;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

int main()
{
	List<int> lst;
	lst.push_front(1);
	lst.push_front(2);
	lst.push_front(3);
	lst.push_front(10);
	cout << "Size of mass " << lst.size() << endl;
	cout << "This mass from end " << endl;
	lst.print_for_end();
	cout << "Mass from begin : " << endl;
	lst.print_for_begin();
	lst.remove(1);
	cout << "Delete  element with Index 1" << endl;
	cout << "Mass from begin : " << endl;
	lst.print_for_begin();
	cout << "Size of mass " << lst.size() << endl;
	cout << "Now we insert element 77 with index 0. Its first element" << endl;
	lst.insert(0, 77);
	cout << "Mass from begin : " << endl;
	lst.print_for_begin();
	cout << "And insert element 88 with index 3. " << endl;
	lst.insert(3, 88);
	cout << "Mass from begin : " << endl;
	lst.print_for_begin();
	cout << "And insert element 99 with index 5. Its last element" << endl;
	lst.insert(5, 99);
	cout << "Mass from begin : " << endl;
	lst.print_for_begin();
}