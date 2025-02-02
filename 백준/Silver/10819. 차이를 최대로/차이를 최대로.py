def get_sum(seq):
    sum = 0
    for i in range(len(seq) - 1):
        sum += abs(seq[i] - seq[i + 1])

    return sum


from itertools import permutations

n = int(input())

sequence = list(map(int, input().split()))
perms = permutations(sequence)

max = 0
for p in perms:
    sum = get_sum(p)
    if max < sum:
        max = sum

print(max)
