def abundant(h):
    for i in range(h, -1, -1):
        t = 1
        for x in range(2, int(i ** .5) + 1):
            if i % x == 0:
                t += x
                if i // x != x: t += i // x
        if t > i:
            return [[i], [t - i]]
