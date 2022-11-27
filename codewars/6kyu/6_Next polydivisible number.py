def go(cur, x, idx):
    if len(x) + 1 == idx: return cur
    for i in range(10):
        y = cur * 10 + i
        if y % idx == 0 and y >= int(x[:idx]):
            t = go(y, x, idx + 1)
            if t is not None:
                return t


def next_num(n):
    a = go(0, str(n + 1), 1)
    b = go(0, str(1) + '0' * len(str(n)), 1)
    if not a and not b: return a
    return int(a or b)
