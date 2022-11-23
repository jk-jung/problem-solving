def diagonal(v):
    n = len(v)
    r = []
    for i in range(n + n - 1):
        y = i
        for j in range(n + n - 1):
            if 0 <= y < n and j < len(v[y]):
                r.append(v[y][j])
            y -= 1
    return r[::-1]
