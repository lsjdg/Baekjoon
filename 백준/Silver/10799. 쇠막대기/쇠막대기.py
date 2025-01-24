stack = []

shards = 0
seq = input()

for i in range(len(seq)):
    input = seq[i]
    if input == "(":
        stack.append(input)
    if input == ")":
        if prev_input == "(":
            stack.pop()
            shards += len(stack)
        else:
            shards += 1
            stack.pop()
    prev_input = input

print(shards)
