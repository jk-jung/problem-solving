def pattern(n):
    return '\n'.join([str(x)*x for x in range(2, n + 1, 2)])