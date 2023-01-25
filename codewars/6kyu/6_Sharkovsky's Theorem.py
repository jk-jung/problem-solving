def sharkovsky(a, b):
    def f(x):
        r = 0
        while x % 2 == 0: x, r = x // 2, r + 1
        if x == 1: x = 0
        return (r, x)
    a, b = f(a), f(b)
    if a[1] and b[1]:
        return a < b
    elif not a[1] and b[1]:
        return False
    elif a[1] and not b[1]:
        return True
    return a[0] > b[0]
