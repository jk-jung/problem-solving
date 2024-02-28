def solve(a):
    r = 0
    for x in a:
        if isinstance(x, int):
            if x % 2:r -= 1
            else: r += 1
    return r
