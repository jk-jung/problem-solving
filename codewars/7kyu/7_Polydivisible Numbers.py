def polydivisible(x):
    return all(int(str(x)[:i + 1]) % (i + 1) == 0 for i, y in enumerate(str(x)))