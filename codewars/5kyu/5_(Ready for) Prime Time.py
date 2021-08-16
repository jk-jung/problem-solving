m = 1000000
d = [0 for _ in range(m + 1)]
r = []
for i in range(2, m + 1):
    if d[i]: continue
    r.append(i)
    for j in range(i + i, m + 1, i):
        d[j] = 1


def prime(n):
    t = []
    for x in r:
        if x > n: break
        t.append(x)
    return t
