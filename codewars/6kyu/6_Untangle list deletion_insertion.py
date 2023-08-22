def find_replaced(v):
    v = sorted(v)
    dif = sum(v) - len(v) * (len(v) + 1) // 2
    for i, x in enumerate(v, start=1):
        if i != x:
            if dif < 0: return x - dif, x
            return i, i + dif
