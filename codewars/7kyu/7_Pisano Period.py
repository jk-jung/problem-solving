def pisano(n):
    a, b, r = 0, 1, 0
    while True:
        a, b = b, (a + b) % n
        r += 1
        if a == 0 and b == 1:
            return r
