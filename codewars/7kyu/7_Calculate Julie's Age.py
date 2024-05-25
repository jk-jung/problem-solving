def age(x, y):
    # (a + x) == b
    # a * y == b
    # a + x == a * y
    # a = x / (y - 1)
    # == x * y / (y - 1)
    return x * y / (y - 1)
