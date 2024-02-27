#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    int nums, size, n, sum = 0;
    cin >> nums >> size;

    for (int i = 0; i < size; i++) {
        cin >> n;
        sum += n;
        q.push(n);
    }
    int maxSum = sum;

    for (int i = 0; i < nums - size; i++) {
        cin >> n;
        sum = sum - q.front() + n;
        if (sum > maxSum) maxSum = sum;
        q.pop();
        q.push(n);
    }
    
    cout << maxSum;
}