def min_score(cards, changes):
    for _ in range(changes):
        cards.sort()
        sum = cards[0] + cards[1]
        cards[0] = sum
        cards[1] = sum

    score = 0

    for n in cards:
        score += n

    return score


n, changes = map(int, input().split())
cards = list(map(int, input().split()))

print(min_score(cards, changes))
