def solve(a):
    return [x for i, x in enumerate(a) if x > max(a[i + 1:] + [0])]
