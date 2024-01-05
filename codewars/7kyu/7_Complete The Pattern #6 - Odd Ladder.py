def pattern(n):
    return "\n".join(str(x)*x for x in range(1, n + 1, 2))
