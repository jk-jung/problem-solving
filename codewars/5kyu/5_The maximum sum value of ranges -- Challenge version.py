def max_sum(a, v):
    s = [0 for _ in a]
    for i in range(len(a)):
        s[i] += a[i]
        if i > 0: s[i] += s[i - 1]

    def ss(a, b):
        return s[b] - (0 if a == 0 else s[a - 1])

    return max(ss(*x) for x in v)
