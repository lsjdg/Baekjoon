#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<bool> isPrime(10001, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i <= sqrt(10000); i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 10000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    int n, x;
    vector<pair<int, int>> gold;
    cin >> n;
    while (n--)
    {
        int diff = 10000;
        int fir, sec;
        cin >> x;
        for (int i = 2; i <= x / 2; i++)
        {
            if (isPrime[i] && isPrime[x - i])
            {
                if (x - (2 * i) < diff)
                {
                    diff = x - (2 * i);
                    fir = i;
                    sec = x - i;
                }
            }
        }
        gold.push_back({ fir, sec });
    }
    for (auto& p : gold)
    {
        cout << p.first << ' ' << p.second << '\n';
    }
}
