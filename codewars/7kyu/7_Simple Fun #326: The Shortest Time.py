def shortest_time(n, m, s):
    return min((n - 1) * s[-1], (abs(n - m) + n - 1) * s[0] + s[1] * 2 + s[2])
