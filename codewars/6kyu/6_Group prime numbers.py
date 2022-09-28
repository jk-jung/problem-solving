p, c = [], [0 for i in range(1000000)]
for i in range(2, 1000000):
    if c[i]: continue
    p.append(i)
    for j in range(i + i, 1000000, i):
        c[j] = 1
def get_primes(n, g=2):
    t = p[:n]
    return (tuple(t[i: i + g] + [None] * g)[:g] for i in range(0, n, g))