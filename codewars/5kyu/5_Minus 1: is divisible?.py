def how_many_times(a, b):
    n = max(a, b) - min(a, b)
    if n == 0: return a

    r = 0
    for x in range(1, min(a, b, int(n ** .5)) + 1):
        y = n // x
        if n % x == 0: r += 1
        if y <= min(a, b) and y != x and n % y == 0: r += 1
    return r
