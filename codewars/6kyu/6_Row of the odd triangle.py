def odd_row(n):
    s = (n * (n - 1)) + 1
    return [s + i * 2 for i in range(n)]
