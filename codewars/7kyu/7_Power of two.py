def power_of_two(x):
    c = 0
    while x:
        c += x % 2
        x //= 2
    return c == 1
