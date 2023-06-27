#include <iostream>
#include <vector>
using namespace std;
int s;
class Heap
{
private:
	int* v = new int[s * s];
	int size = 0;
	int rootIdx = 1;
public:
	Heap() { v[0] = -1; }
	void swap(int a, int b)
	{
		v[0] = v[a];
		v[a] = v[b];
		v[b] = v[0];
	}
	void upHeap(int idx)
	{
		if (idx == rootIdx)
			return;
		int parentIdx = idx / 2;
		if (v[parentIdx] < v[idx])
		{
			swap(parentIdx, idx);
			upHeap(parentIdx);
		}
	}
	void downHeap(int idx)
	{
		int left = idx * 2;
		int right = idx * 2 + 1;
		int maxIdx = idx;
		if (left <= size && v[left] > v[maxIdx])
			maxIdx = left;
		if (right <= size && v[right] > v[maxIdx])
			maxIdx = right;
		if (maxIdx != idx)
		{
			swap(maxIdx, idx);
			downHeap(maxIdx);
		}
	}
	void insert(int i)
	{
		size++;
		v[size] = i;
		upHeap(size);
	}
	int getSize() { return size; }
	bool isEmpty() { return size == 0; }
	int top()
	{
		if (isEmpty()) return -1;
		else return v[1];
	}
	void pop()
	{
		if (!isEmpty())
		{
			swap(size, rootIdx);
			v[size] = 0;
			size--;
			downHeap(rootIdx);
		}
	}
};

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> s;
	Heap h = Heap();

	for (int i{ 0 }; i < s * s; i++)
	{
		int x;
		cin >> x;
		h.insert(x);
	}

	for (int i{ 0 }; i < s - 1; i++)
	{
		h.pop();
	}

	cout << h.top();
}
