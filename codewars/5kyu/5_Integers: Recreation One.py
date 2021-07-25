def list_squared(m, n):
    r = []
    for x in range(m, n):
        s = 0
        k = int(x ** 0.5)
        for i in range(1, k + 1):
            if x % i == 0:
                s += i * i
                if i != x // i: s += (x // i) ** 2

        if s == int(s ** 0.5) * int(s ** 0.5):
            r.append([x, s])

    return r
   