def linked_sort(a, b, key=None):
    if key is None: key = lambda x: str(x)
    c = sorted(zip(a, b), key=key)
    b.extend([x[1] for x in c])
    a.extend([x[0] for x in c])
    for i in c:
        b.pop(0)
        a.pop(0)
    return a
