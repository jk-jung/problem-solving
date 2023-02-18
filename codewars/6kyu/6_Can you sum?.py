m = 1000000007
def f(n):
    return (pow(2, n + 1, m) * ((n - 2) * n + 3) - 6 + m) % m