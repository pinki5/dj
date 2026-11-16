
names = ["Main Gate", "Computer Dept", "IT Dept", "Library", "Hostel"]

graph = [
    [0, 10, 8, 0, 0],
    [10, 0, 5, 3, 0],
    [8, 5, 0, 7, 6],
    [0, 3, 7, 0, 4],
    [0, 0, 6, 4, 0]
]

print("Adjacency Matrix of Campus Graph:")
for i in range(len(names)):
    print(names[i], graph[i])

n = len(names)
visited = [False] * n
visited[2] = True  # Start from IT Dept

total = 0

print("Minimum Spanning Tree Edges:")

for _ in range(n - 1):
    minimum = float('inf')

    for i in range(n):
        if visited[i]:
            for j in range(n):
                if not visited[j] and graph[i][j] != 0:
                    if graph[i][j] < minimum:
                        minimum = graph[i][j]
                        u, v = i, j

    print(names[u], "--", names[v], "=", minimum)
    total += minimum
    visited[v] = True

print("Total Cost of MST =", total)
