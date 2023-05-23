def shorterest_time(n, m, s):
    r = n * s[3]
    r1 = n * s[0] + s[1] * 2 + s[2] + abs(n - m) * s[0]
    r2 = m * s[0] + s[1] * 2 + s[2] + abs(n - m) * s[3]
    return min(r, r1, r2)
