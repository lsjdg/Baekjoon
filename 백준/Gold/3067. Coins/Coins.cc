#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int type, target, x;
        cin >> type;
        vector<int> coins(type);
        for (int i{ 0 }; i < type; i++)
        {
            cin >> x;
            coins[i] = x;
        }
        cin >> target;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (size_t i{ 0 }; i < coins.size(); i++)
        {
            for (int j{ 1 }; j <= target; j++)
            {
                if (j >= coins[i])
                    dp[j] += dp[j - coins[i]];
            }
        }

        cout << dp[target] << '\n';
    }
}
