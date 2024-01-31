def min_and_max(l, d, x):
    r = [i for i in range(l, d + 1) if sum(map(int, str(i))) == x]
    return [r[0], r[-1]]
