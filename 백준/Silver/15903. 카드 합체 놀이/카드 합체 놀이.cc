#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long cards, unite, x, score{0};
    priority_queue<long long, vector<long long>, greater<long long>> deck;

    cin >> cards >> unite;
    while (cards--)
    {
        cin >> x;
        deck.push(x);
    }
    while (unite--)
    {
        long long first = deck.top();
        deck.pop();
        long long second = deck.top();
        deck.pop();
        long long sum = first + second;
        deck.push(sum);
        deck.push(sum);
    }
    while (!deck.empty())
    {
        score += deck.top();
        deck.pop();
    }
    cout << score;
}
