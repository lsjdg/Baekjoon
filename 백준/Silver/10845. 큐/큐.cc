
#include <iostream>
using namespace std;

class Node
{
private:
	Node* next;
	int value;
public:
	Node()
	{
		this->next = nullptr;
		value = 0;
	}
	friend class LinkedList;
	friend class Queue;
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
		this->head->next = tail;
		size = 0;
	}
	bool empty()
	{
		return this->size == 0;
	}
	void removeFront()
	{
		Node* removeNode = this->head->next;
		this->head->next = removeNode->next;
		size--;
	}
	void addBack(int x)
	{
		Node* addNode = new Node;
		addNode->value = x;
		Node* curNode = this->head;
		for (int i{ 0 }; i < this->size; i++)
		{
			curNode = curNode->next;
		}
		curNode->next = addNode;
		addNode->next = this->tail;
		size++;
	}
	friend class Queue;
};
class Queue
{
public:
	int arr[10000];
	int frontIdx = 0;
	int rearIdx = -1;
	int size = 0;
	LinkedList ll = LinkedList();

	void printSize()
	{
		cout << this->size << '\n';
	}
	bool empty()
	{
		return this->size == 0;
	}
	void front()
	{
		if (empty())
			cout << -1 << '\n';
		else
			cout << ll.head->next->value << '\n';

	}
	void rear()
	{
		if (empty())
			cout << -1 << '\n';
		else
		{
			Node* curNode = ll.head;
			for (int i{ 0 }; i < this->size; i++)
			{
				curNode = curNode->next;
			}
			cout << curNode->value << '\n';
		}

	}
	void enQueue(int x)
	{
		rearIdx++;
		ll.addBack(x);
		size++;
	}
	void deQueue()
	{
		if (empty())
			cout << -1 << '\n';
		else
		{
			frontIdx++;
			front();
			ll.removeFront();
			size--;
		}
	}
};

int main()
{
	Queue q = Queue();
	int test;
	cin >> test;
	while (test--)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int x;
			cin >> x;
			q.enQueue(x);
		}
		else if (s == "pop")
		{
			q.deQueue();
		}
		else if (s == "size")
		{
			q.printSize();
		}
		else if (s == "empty")
		{
			if (q.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "front")
		{
			q.front();
		}
		else if (s == "back")
		{
			q.rear();
		}

	}
}