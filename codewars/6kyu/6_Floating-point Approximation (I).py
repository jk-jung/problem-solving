def f(x):
    # a = sqrt(1 + x)
    # b = 1
    # a - b == (a^2 - b^2)/(a + b)
    # (1 + x - 1) / (sqrt(1 + x) + 1)
    return x / (1 + (1 + x)**.5)
