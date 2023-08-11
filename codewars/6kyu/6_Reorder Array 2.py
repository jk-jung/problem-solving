def reorder(a, b):
    n = a // 2
    r = [(i - b % n + n) % n for i in range(n)]
    return [r, [x + n for x in r]]
