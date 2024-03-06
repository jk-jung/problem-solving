def rounding(n,m):
    a = n // m * m
    b = (n + m - 1) // m * m

    if n - a == b - n: return n
    return a if n - a < b - n else b
