#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int> q;
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		q.push(s[i] - '0');
	}

	while (!q.empty()) {
		cout << q.top();
		q.pop();
	}
}