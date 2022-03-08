def find_nb(m):
    x = 1
    while m > 0:
        m -= x ** 3
        x += 1
    return x - 1 if m == 0 else -1
