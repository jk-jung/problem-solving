def soln(n):
    r = 0
    for i in range(n):
        for j in range(n):
            r = r * 2 + (i == j)
    return r