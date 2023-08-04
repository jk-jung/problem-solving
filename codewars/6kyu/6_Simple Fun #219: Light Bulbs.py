def light_bulbs(v, n):
    for _ in range(n):
        v = [y ^ 1 if x == 1 else y for y, x in zip(v, [v[-1]] + v)]
    return v
