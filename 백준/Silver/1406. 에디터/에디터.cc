#include <iostream>
using namespace std;

class Node
{
public:
	Node* next = nullptr;
	Node* prev = nullptr;
	char value;
};

class Iterator
{
public:
	Node* node;
	Iterator()
	{
		node = nullptr;
	}
};

class Sequence
{
public:
	Node* head;
	Node* tail;
	int size;

	Sequence()
	{
		head = new Node;
		tail = new Node;

		head->next = tail;
		tail->prev = head;
		size = 0;
	}
	Node* begin()
	{
		return head->next;
	}
	Node* end()
	{
		return tail;
	}
	void insert(Iterator& p, char e)
	{
		Node* newNode = new Node();
		newNode->value = e;

		p.node->prev->next = newNode;
		newNode->prev = p.node->prev;
		newNode->next = p.node;
		p.node->prev = newNode;
		this->size++;
	}
	void erase(Iterator& p)
	{
		if (size == 0)
			return;
		else if (p.node == head->next)
			return;
		else
		{
			Node* deleteNode = p.node->prev;
			deleteNode->prev->next = deleteNode->next;
			deleteNode->next->prev = deleteNode->prev;
			//p.node = deleteNode->prev;
			size--;
			delete deleteNode;
		}
	}
	void next(Iterator& p)
	{
		if (p.node == tail)
			return;
		else
			p.node = p.node->next;
	}
	void prev(Iterator& p)
	{
		if (p.node == head->next)
			return;
		else
			p.node = p.node->prev;
	}
	void print()
	{
		if (size == 0)
			cout << "Empty\n";
		else
		{
			Node* curNode = head->next;
			while (curNode != tail)
			{
				cout << curNode->value;
				curNode = curNode->next;
			}
			cout << '\n';
		}
	}
	void find(char e)
	{
		Node* curNode = head->next;
		int index = 0;
		int found{ 0 };
		while (curNode != tail)
		{
			if (curNode->value == e)
			{
				cout << index << ' ';
				found = 1;
			}
			curNode = curNode->next;
			index++;
		}
		if (found == 0)
			cout << "-1";
		cout << '\n';
	}
	void upper(int e)
	{
		Node* curNode = head->next;
		int isUpper{ 0 };
		int idx{ 0 };
		while (curNode != tail)
		{
			if (curNode->value > e)
			{
				cout << idx << ' ';
				isUpper = 1;
			}
			curNode = curNode->next;
			idx++;
		}
		if (isUpper == 0)
			cout << -1;
		cout << '\n';
	}
	int getSize()
	{
		return this->size;
	}
};

int main()
{
	Sequence sq = Sequence();
	string s;
	Iterator p = Iterator();
	p.node = sq.begin();
	cin >> s;
	for (int i{ 0 }; i < s.size(); i++)
	{
		sq.insert(p, s[i]);
	}
	int test;
	cin >> test;
	while (test--)
	{
		string command;
		cin >> command;
		if (command == "L")
		{
			//if (p.node == sq.begin())
				//break;
			sq.prev(p);
		}
		else if (command == "D")
		{
			//if (p.node == sq.end())
				//break;
			sq.next(p);
		}
		else if (command == "B")
		{
			//if (p.node == sq.begin())
				//break;
			sq.erase(p);
		}
		else if (command == "P")
		{
			char c;
			cin >> c;
			sq.insert(p, c);
		}
	}
	sq.print();
}