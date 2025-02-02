def min_coins(prices, cnt, balance):
    while balance > 0:
        while prices[-1] > balance:
            del prices[-1]
        cnt += balance // prices[-1]
        balance -= prices[-1] * (balance // prices[-1])
        del prices[-1]

    return cnt


n, balance = map(int, input().split())
prices = []

for _ in range(n):
    price = int(input())
    prices.append(price)

print(min_coins(prices, 0, balance))
