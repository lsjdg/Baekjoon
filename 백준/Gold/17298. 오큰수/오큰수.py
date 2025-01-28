from collections import deque

nums = int(input())
sequence = list(map(int, input().split()))
output = [-1] * nums  # 결과를 저장할 리스트, 초기값은 -1
stack = deque()  # 스택 초기화

# 배열을 역순으로 탐색
for i in range(nums - 1, -1, -1):
    current = sequence[i]
    # 스택에서 현재 값보다 작거나 같은 값 제거
    while stack and stack[-1] <= current:
        stack.pop()
    # 스택이 비어 있지 않으면, 스택의 맨 위가 오큰수
    if stack:
        output[i] = stack[-1]
    # 현재 값을 스택에 추가
    stack.append(current)

# 결과 출력
print(*output)
