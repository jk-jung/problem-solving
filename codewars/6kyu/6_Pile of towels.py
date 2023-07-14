def sort_the_pile(a, b):
    for k in b:
        if k:
            a = a[:-k] + sorted(a[-k:])[::-1]
    return a
