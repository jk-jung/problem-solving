def pattern(n):
    r, s = '', ' ' * (n - 1)
    for i in range(1, n): r += s + str(i % 10) + '\n'
    for i in range(1, n + 1):r += str(i % 10)
    for i in range(n - 1, 0, -1):r += str(i % 10)
    r += '\n'
    for i in range(n - 1, 0, -1): r += s + str(i % 10) + '\n'
    return r
