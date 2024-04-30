def strange_math(n, k):
    return sorted(map(str, range(1, n + 1))).index(str(k)) + 1
