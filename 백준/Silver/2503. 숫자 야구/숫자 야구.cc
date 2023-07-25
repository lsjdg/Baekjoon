#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

pair<int, int> strikeAndBall(int target, int answer)
{
    bool isUsed[10]{ false };
    int targetDigit[3]{ 0 };
    int answerDigit[3]{ 0 };
    int idx{ 0 }, strike{ 0 }, ball{ 0 };
    while (target >= 1)
    {
        isUsed[target % 10] = true;
        targetDigit[idx] = target % 10;
        target /= 10;
        idx++;
    }
    idx = 0;
    while (answer >= 1)
    {
        answerDigit[idx] = answer % 10;
        answer /= 10;
        idx++;
    }
    for (int i{ 0 }; i < 3; i++)
    {
        if (answerDigit[i] == targetDigit[i])
            strike++;
        else if (isUsed[answerDigit[i]])
            ball++;
    }
    pair<int, int> p = make_pair(strike, ball);
    return p;
}

int main()
{
    int n, count{ 0 };
    cin >> n;
    vector<pair<int, pair<int, int>>> v;
    while (n--)
    {
        int answer, x, y;
        cin >> answer >> x >> y;
        pair<int, int> p = make_pair(x, y);
        v.push_back(make_pair(answer, p));
    }

    for (int i{ 123 }; i <= 987; i++)
    {
        int num = i;
        int digit1 = num % 10;
        num /= 10;
        int digit2 = num % 10;
        num /= 10;
        int digit3 = num;

        if (digit1 != digit2 && digit1 != digit3 && digit2 != digit3 && digit1 != 0 && digit2 != 0 && digit3 != 0)
        {
            int c{ 0 };
            for (auto p : v)
            {
                pair<int, int> check = strikeAndBall(i, p.first);
                if (check.first == p.second.first && check.second == p.second.second)
                    c++;
            }
            if (c == v.size())
                count++;
        }
    }

    cout << count;
}
