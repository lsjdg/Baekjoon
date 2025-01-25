import math
import heapq

heights = []
pop, height_centi, hammer = map(int, input().split())

for _ in range(pop):
    heapq.heappush(heights, (-1) * int(input()))

hammer_used = 0

for _ in range(hammer):
    if -heights[0] == 1 or -heights[0] < height_centi:
        break
    heapq.heappushpop(heights, -(-heights[0] // 2))
    hammer_used += 1

if -heights[0] >= height_centi:
    print('NO', -heights[0], sep='\n')
else:
    print('YES', hammer_used, sep='\n')