def s2n(m, n):
    return sum(sum(x ** i for i in range(n + 1)) for x in range(m + 1))
