def mormons(a, b, c):
    if a >= c: return 0
    return mormons(a * b + a, b, c) + 1
