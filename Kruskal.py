
# Kruskal's Algorithm for College Campus

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

# Create edge list
edges = []
for i in range(len(names)):
    for j in range(i + 1, len(names)):
        if graph[i][j] != 0:
            edges.append((graph[i][j], i, j))

# Sort edges by weight
edges.sort()

# Find function
def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])
    return parent[x]

# Kruskal's Algorithm
parent = list(range(len(names)))
total = 0

print("Minimum Spanning Tree Edges:")
for w, u, v in edges:
    a = find(parent, u)
    b = find(parent, v)

    if a != b:
        print(names[u], "--", names[v], "=", w)
        total += w
        parent[a] = b

print("\nTotal Cost of MST =", total)
