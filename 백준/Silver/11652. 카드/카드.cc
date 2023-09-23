#include <iostream>
#include <map>
using namespace std;

int main() {
	map <long long, int> num;
	int n;
	long long x;
	cin >> n;
	
	while (n--) {
		cin >> x;
		if (num.find(x) == num.end()) {
			num.insert({x, 1});
		}
		else {
			num[x]++;
		}
	}

	int max = 0;
	long long maxNum = 0;
	for (auto& pair : num) {
		if (pair.second > max) {
			max = pair.second;
			maxNum = pair.first;
		}
	}

	cout << maxNum;
}