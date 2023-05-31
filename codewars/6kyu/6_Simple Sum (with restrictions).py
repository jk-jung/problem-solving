def simple_sum(x,y):
    while y:
        c = x & y
        x = x ^ y
        y = c << 1
    return x
