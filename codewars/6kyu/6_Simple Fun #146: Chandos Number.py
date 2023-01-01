def nth_chandos_number(n):
    r = 0
    for i in range(30):
        if n >> i & 1:
            r += 5 ** (i + 1)
    return r