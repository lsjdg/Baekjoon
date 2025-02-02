from itertools import combinations


def ability(grid, team):
    total = 0
    for i in range(len(team)):
        for j in range(i + 1, len(team)):  # 중복 연산 방지 (i, j)만 더함
            total += grid[team[i]][team[j]] + grid[team[j]][team[i]]
    return total


n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]
players = list(range(n))

min_diff = float('inf')  # 최소값을 무한대로 설정

for team in combinations(players, n // 2):  # 조합 사용 → 중복 계산 방지
    other_team = list(set(players) - set(team))  # 여집합 구하기
    diff = abs(ability(grid, team) - ability(grid, other_team))

    min_diff = min(min_diff, diff)

print(min_diff)
