#include <iostream>
using namespace std;

int n = 10000;
class Queue
{
public:
	int arr[10001];
	int frontIdx = 0;
	int rearIdx = -1;
	int size = 0;

	void printSize()
	{
		cout << this->size << '\n';
	}
	bool empty()
	{
		return this->size == 0;
	}
	void updateIndex()
	{
		frontIdx %= n;
		rearIdx %= n;
	}
	void front()
	{
		if (empty())
			cout << -1 << '\n';
		else
			cout << arr[frontIdx] << '\n';

	}
	void rear()
	{
		if (empty())
			cout << -1 << '\n';
		else
			cout << arr[rearIdx] << '\n';
	}
	void enQueue(int x)
	{
		if (this->size >= n)
			cout << "full" << '\n';
		else
		{
			rearIdx++;
			updateIndex();
			arr[rearIdx] = x;
			size++;
		}
	}
	void deQueue()
	{
		if (empty())
			cout << -1 << '\n';
		else
		{
			cout << arr[frontIdx] << '\n';
			frontIdx++;
			updateIndex();
			size--;
		}
	}
};

int main()
{
	Queue q = Queue();
	int n;
	cin >> n;
	while (n--)
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