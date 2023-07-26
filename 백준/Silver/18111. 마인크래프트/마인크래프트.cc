#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, b;
    cin >> n >> m >> b;
    vector<vector<int>> map(n, vector<int>(m));

    for (int i{ 0 }; i < n; i++)
    {
        for (int j{ 0 }; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    int minTime{ 100000000 };
    int bestHeight{ 0 };

    for (int height{ 0 }; height <= 256; height++)
    {
        int remove{ 0 };
        int add{ 0 };

        for (int i{ 0 }; i < n; i++)
        {
            for (int j{ 0 }; j < m; j++)
            {
                int diff = map[i][j] - height;
                if (diff > 0)
                {
                    remove += diff;
                }
                else
                {
                    add -= diff;
                }
            }
        }

        int inventory = b + remove;

        if (inventory >= add)
        {
            int time = remove * 2 + add;
            if (time < minTime)
            {
                minTime = time;
                bestHeight = height;
            }
            else if (time == minTime)
            {
                bestHeight = max(bestHeight, height);
            }
        }
    }

    cout << minTime << ' ' << bestHeight;
}
