def pattern(n):
    r = []
    for i in range(n, 0, -1):
        r.append(''.join([str(n - j) for j in range(i)]))
    return '\n'.join(r)
