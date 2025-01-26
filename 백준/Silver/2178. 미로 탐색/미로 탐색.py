def bfs(graph, x, y, visited):
    from collections import deque

    move = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    rows, cols = len(graph), len(graph[0])
    queue = deque([(x, y)])
    visited[x][y] = 1

    while queue:
        cx, cy = queue.popleft()
        for dx, dy in move:
            nx, ny = cx + dx, cy + dy
            if (
                0 <= nx < rows
                and 0 <= ny < cols
                and not visited[nx][ny]
                and graph[nx][ny] == 1
            ):
                queue.append((nx, ny))
                visited[nx][ny] = visited[cx][cy] + 1


rows, cols = map(int, input().split())

graph = [list(map(int, input())) for _ in range(rows)]
visited = [[0] * cols for _ in range(rows)]


bfs(graph, 0, 0, visited)
print(visited[rows - 1][cols - 1])
