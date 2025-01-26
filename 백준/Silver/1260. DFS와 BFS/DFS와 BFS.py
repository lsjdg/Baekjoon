def dfs(graph, start, visited=[]):
    visited.append(start)
    for child in sorted(graph[start]):
        if child not in visited:
            dfs(graph, child, visited)

    return visited


def bfs(graph, start):
    from collections import deque

    visited = []
    queue = deque([start])

    while queue:
        top = queue.popleft()
        if top not in visited:
            visited.append(top)
            queue.extend(sorted(graph[top]))

    return visited


from collections import defaultdict

nodes, edges, start = map(int, input().split())
graph = defaultdict(list)

for _ in range(edges):
    left, right = map(int, input().split())
    graph[left].append(right)
    graph[right].append(left)

dfs_output = dfs(graph, start, [])
bfs_output = bfs(graph, start)

print(" ".join(map(str, dfs_output)))
print(" ".join(map(str, bfs_output)))
