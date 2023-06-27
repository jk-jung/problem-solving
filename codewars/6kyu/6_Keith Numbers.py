def is_keith_number(n):
    v = list(map(int, str(n)))
    if len(v) == 1: return False
    r = 0
    while True:
        r += 1
        s = sum(v)
        if s == n: return r
        elif s > n * 10: return False
        v = v[1:] + [s]
    return r
