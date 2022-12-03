def longest_sequence(n):
    r, s, x = [], 0, 0
    while x * x <= n:
        x += 1
        r.append(x)
        s += x * x
        while r and s > n:
            s -= r.pop(0) ** 2
        if s == n:
            return r
    return []
