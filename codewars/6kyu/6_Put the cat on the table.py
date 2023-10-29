def put_the_cat_on_the_table(a, v):
    y, x = a
    n, m = len(v), len(v[0])
    if y < 0 or x < 0 or y >= n or x >= m: return 'NoCat'
    for i in range(n):
        for j in range(m):
            if v[i][j]:
                return abs(i - y) * ('U' if i < y else 'D') + abs(j - x) * ('L' if j < x else 'R')
    return 'NoTable'
