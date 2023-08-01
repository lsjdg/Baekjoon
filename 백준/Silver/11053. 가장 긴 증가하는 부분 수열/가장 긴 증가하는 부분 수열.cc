#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n;
    vector<int> v;
    v.push_back(0);
    vector<int> dp(n + 1, 1);

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }

    int maxLength = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (v[i] > v[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                maxLength = max(maxLength, dp[i]);
            }
        }
    }

    cout << maxLength;
}
