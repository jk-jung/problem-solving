def permuts(n):
    a, b = 1, 1
    for i in range(n):
        c = b + a
        a, b = b, c
    return a
