def lcm_cardinality(n):
    x = 2
    v = []
    while x * x <= n:
        c = 0
        while n % x == 0:
            n //= x
            c += 1
        if c:v.append(c)
        x += 1
    if n != 1: v.append(1)
    r = 1
    for x in v:
        r *= ((x + 1) * 2 - 1)
    return (r + 1) // 2
