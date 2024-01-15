def mystery(n):
    return [i for i in range(1, n + 1, 2) if n % i == 0]
