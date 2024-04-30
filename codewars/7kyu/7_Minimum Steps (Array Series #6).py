def minimum_steps(v, value):
    r = 0
    c = 0
    for i in sorted(v):
        r += i
        if r >= value:
            return c
        c += 1
