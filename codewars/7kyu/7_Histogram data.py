def histogram(a, b):
    if not a:
        return []
    r = []
    for i in range(0, max(a) + 1, b):
        r.append(len([x for x in a if i <= x < i + b]))
    return r
