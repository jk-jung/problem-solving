def bell(n):
    r = [n]
    for i in range(n - 2, 0, -2):
        r.append(r[-1] + i)
    return r + (r if n % 2 == 0 else r[:-1])[::-1]
