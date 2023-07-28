#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int type, target, x;
    cin >> type >> target;
    vector<int> coins(type);
    vector<int> dp (target + 1, 0);
    
    for (int i{ 0 }; i < type; i++)
    {
        cin >> x;
        coins[i] = x;
    }
    dp[0] = 1;
    
    for (size_t i{ 0 }; i < coins.size(); i++)
    {
        for (int j{ 1 }; j <= target; j++)
        {
            if (j >= coins[i])
                dp[j] += dp[j - coins[i]];
        }
    }
    
    cout << dp[target];
}
