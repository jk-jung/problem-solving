def create_octahedron(n):
    if n < 3 or n % 2 == 0: return []
    r = []
    m = n // 2
    for i in range(m + 1):
        t = [[0] * n for _ in range(n)]
        r.append(t)
        for y in range(n):
            for x in range(n):
                if abs(x - m) + abs(y - m) <= i:t[y][x]=1

    return r + r[::-1][1:]
