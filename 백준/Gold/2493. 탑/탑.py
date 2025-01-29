towers = int(input())
height_list = list(map(int, input().split()))
stack = []
output = [0] * towers

for i in range(towers):
    while stack and stack[-1][0] < height_list[i]:
        stack.pop()

    if stack:
        output[i] = stack[-1][1] + 1

    stack.append((height_list[i], i))

print(*output)
