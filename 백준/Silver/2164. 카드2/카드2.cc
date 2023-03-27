#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int n;
class Node
{
private:
	Node* next;
	Node* prev;
	int value;
public:
	Node()
	{
		this->next = nullptr;
		this->prev = nullptr;
		this->value = 0;
	}
	friend class Queue;
	friend class DoubleLinkedList;
};

class DoubleLinkedList
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	DoubleLinkedList()
	{
		this->head = new Node;
		this->tail = new Node;
		this->head->next = this->tail;
		this->tail->prev = this->head;
		size = 0;
	}
	bool empty()
	{
		return this->size == 0;
	}
	void removeFront()
	{
		if (empty())
			cout << "empty" << '\n';
		else
		{
			Node* removeNode = this->head->next;
			this->head->next = removeNode->next;
			removeNode->next->prev = this->head;
			delete removeNode;
			this->size--;
		}
	}
	void addBack(int x)
	{
		Node* addNode = new Node;
		addNode->value = x;
		addNode->prev = this->tail->prev;
		this->tail->prev->next = addNode;
		addNode->next = this->tail;
		this->tail->prev = addNode;
		this->size++;
	}
	friend class Queue;
};
class Queue
{
private:
	int size;
	DoubleLinkedList dll;
public:
	Queue()
	{
		this->dll = DoubleLinkedList();
		this->size = 0;
	}
	bool empty()
	{
		return this->size == 0;
	}
	int getSize()
	{
		return this->size;
	}
	int front()
	{
		if (empty())
			return -1;
		else
			return dll.head->next->value;
	}
	int rear()
	{
		if (empty())
			return -1;
		else
			return dll.tail->prev->value;
	}
	void enqueue(int x)
	{
		dll.addBack(x);
		this->size++;
	}
	void dequeue()
	{
		if (empty())
			cout << "empty" << '\n';
		else
		{
			dll.removeFront();
			this->size--;
		}
	}
};

int main()
{
	Queue deck = Queue();
	int n;
	cin >> n;
	for (int i{ 1 }; i <= n; i++)
	{
		deck.enqueue(i);
	}
	while (true)
	{
		if (deck.getSize() == 1)
			break;
		deck.dequeue();
		deck.enqueue(deck.front());
		deck.dequeue();
	}
	cout << deck.front();
}