def symmetric_point(p, q):
    return [x * 2 - y for x, y in zip(q, p)]
