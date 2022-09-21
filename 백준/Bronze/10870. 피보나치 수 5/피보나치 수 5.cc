#include <iostream>
using namespace std;

int F(int n);

int main() {
	int n;
	cin >> n;
	cout << F(n);
	return 0;
}

int F(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	return F(n - 1) + F(n - 2);
}