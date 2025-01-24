from collections import deque

length, steps = map(int, input().split())

circle = deque(range(1, length + 1))
answer = []

while circle:
    circle.rotate(-(steps - 1))
    answer.append(circle.popleft())

print(f"<{', '.join(map(str, answer))}>")
