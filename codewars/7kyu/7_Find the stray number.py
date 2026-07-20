def stray(a):
    return sum(a) - sorted(a)[1] * (len(a) - 1)
