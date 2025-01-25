n, m = map(int, input().split())

never_heard = set(input() for _ in range(n))

never_seen_and_heard = sorted(
    name for name in set(input() for _ in range(m)) if name in never_heard
)

print(len(never_seen_and_heard))
print("\n".join(never_seen_and_heard))
