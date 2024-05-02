def two_are_positive(*a):
    a = sorted(a)
    return a[0] <= 0 and a[1] > 0
