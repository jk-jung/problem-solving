from itertools import cycle
def gen(n, v):
    v = cycle(v)
    q = []
    while True:
        while len(q) < n:q.append(next(v))
        yield tuple(q)
        q.pop(0)