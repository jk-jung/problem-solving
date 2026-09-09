def digit_degree(n):
    r = 0
    while len(str(n)) > 1:
        r += 1
        n = sum(map(int, str(n)))
    return r
