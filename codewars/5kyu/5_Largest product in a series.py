def greatest_product(n):
    r = 0
    for i in range(len(n) - 4):
        t = n[i:i+5]
        x = 1
        for y in t: x *= int(y)
        r = max(r, x)
    return r