def strongest_even(n, m):
    r = 1
    for i in range(33):
        t = 2 ** i
        s = (n + t - 1) // t * t
        if n <= s <= m:
            r = s
    return r
