d = {}
def go(x, s=0, c=0):
    if x == 10:
        d[s] = min(d.get(s, 999), c - 1)
    else:
        t = 0
        for i in range(x, 10):
            t = t * 10 + i
            go(i + 1, s + t, c + 1)
            if x != 1:
                go(i + 1, s - t, c + 1)
go(1)


def operator_insertor(n):
    return d.get(n)