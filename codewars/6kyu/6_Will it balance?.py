def will_it_balance(x, y):
    y.append(0)
    cm = sum([i * t for i, t in enumerate(x)]) / sum(x)
    s, e = y.index(1), 0
    for i, k in enumerate(y):
        if k == 1: e = i
    return s <= cm <= e
