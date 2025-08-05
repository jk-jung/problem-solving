def first_non_consecutive(a):
    for a, b in zip(a, a[1:]):
        if abs(a - b) != 1:
            return b
