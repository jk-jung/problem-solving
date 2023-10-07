def operator(a, n, b):
    if n == 0: return b + 1
    if n == 1: return a + b
    if n == 2: return a * b
    if n == 3: return a ** b
    if b == 0: return 1
    return a ** operator(a, n, b - 1)