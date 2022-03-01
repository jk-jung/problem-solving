def pascals_triangle(n):
    r = [1]
    for i in range(2, n + 1):
        r.append(1)
        for j in range(2, i):
            r.append(r[-i] + r[-i + 1])
        r.append(1)
    return r
