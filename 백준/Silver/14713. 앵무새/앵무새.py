from collections import deque

parrots = int(input())
sentences = []

for _ in range(parrots):
    queue = deque(input().split())
    sentences.append(queue)

test_str = deque(input().split())

isPossible = True

while test_str:
    top_test_word = test_str[0]
    matched = False 

    for i in range(parrots):
        if sentences[i] and sentences[i][0] == top_test_word:  
            test_str.popleft()
            sentences[i].popleft()
            matched = True 
            break

    if not matched: 
        isPossible = False
        break

for queue in sentences:  
    if queue:
        isPossible = False
        break

print("Possible" if isPossible else "Impossible")
