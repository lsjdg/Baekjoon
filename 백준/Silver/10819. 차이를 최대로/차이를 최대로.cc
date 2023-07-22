#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calc(vector<int> vec) 
{
    int result = 0;
    for (size_t i { 1 }; i < vec.size(); i++) 
    {
        result += abs(vec[i] - vec[i - 1]);
    }
    return result;
}

int main() 
{
    int n, x;
    cin >> n;
    vector<int> v;

    for (int i { 0 }; i < n; i++) 
    {
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int maxDiff{ 0 };
    do 
    {
        int diff = calc(v);
        maxDiff = max(maxDiff, diff);
    } while (next_permutation(v.begin(), v.end()));

    cout << maxDiff;
}
