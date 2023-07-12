#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k, count{ 0 };
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    while (k > 0)
    {
        int idx = n - 1;
        while (coins[idx] > k)
        {
            idx--;
        }
        int quo = k / coins[idx];
        count += quo;
        k -= quo * coins[idx];
    }

    cout << count;
}
