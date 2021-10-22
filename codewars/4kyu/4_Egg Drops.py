d = {}
def max_height(n, m):
    if (n, m) in d: return d[(n, m)]
    if m == 0: return 0
    if n == 1: r = m
    else:
        r = 1
        for i in range(1, m):
            r += max_height(n - 1, m - i) + 1
    d[(n, m)] = r
    return r

def solve(em, base=0):
    n = em.eggs
    m = em.drops

    if m == 0:return base + 1
    if n == 1:
        for i in range(1, m + 1):
            if em.drop(base + i): return base + i
        return base + m + 1

    pos = max_height(n - 1, m - 1) + 1
    if em.drop(base + pos):
        return solve(em, base)
    return solve(em, base + pos)
