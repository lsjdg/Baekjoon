#include <iostream>
using namespace std;

class Node
{
private:
	int value;
	Node* next;

	Node()
	{
		value = 0;
		next = nullptr;
	}
	friend class LinkedList;
	friend class Stack;
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList()
	{
		this->head = new Node;
		this->tail = new Node;
		head->next = tail;
		size = 0;
	}
	bool empty()
	{
		return size == 0;
	}
	void addFront(int x)
	{
		Node* appendNode = new Node;
		appendNode->value = x;
		appendNode->next = this->head->next;
		this->head->next = appendNode;
		size++;
	}
	void deleteFront()
	{
		Node* delNode = this->head->next;
		int delValue = delNode->value;
		this->head->next = delNode->next;
		cout << delValue << '\n';
		size--;
	}
	friend class Stack;
};

class Stack
{
private:
	LinkedList ll;
	int size;
public:
	Stack()
	{
		ll = LinkedList();
		size = 0;
	}
	bool empty()
	{
		return (this->size == 0);
	}
	int top()
	{
		if (empty())
			return -1;
		else
		{
			return ll.head->next->value;
		}
	}
	void push(int x)
	{
		ll.addFront(x);
		size++;
	}
	void pop()
	{
		if (empty())
			cout << -1 << '\n';
		else
		{
			ll.deleteFront();
			size--;
		}
	}
	void sizePrint()
	{
		cout << size << '\n';
	}
};

int main()
{
	int n;
	Stack st = Stack();
	string s;
	cin >> n;
	
	for (int i{ 0 }; i < n; i++)
	{
		cin >> s;
		if (s == "empty")
		{
			if (st.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "top")
		{
			cout << st.top() << '\n';
		}
		else if (s == "push")
		{
			int x;
			cin >> x;
			st.push(x);
		}
		else if (s == "pop")
		{
			st.pop();
		}
		else if (s == "size")
		{
			st.sizePrint();
		}
	}
}