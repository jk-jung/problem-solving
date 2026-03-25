def sum_factorial(a):
    a.sort()
    r, t = 0, 1
    for i in range(1, a[-1] + 1):
        t *= i
        while a and a[0] == i:
            a.pop(0)
            r += t
    return r
