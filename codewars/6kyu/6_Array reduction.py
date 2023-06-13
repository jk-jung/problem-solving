d = list(range(2, 100001))
r = [1]
while d:
    r.append(d[0])
    d = [x for i, x in enumerate(d) if i % r[-1] != 0]

def solve(n):
    s = 0
    for x in r:
        if x <= n: s += x
    return s
