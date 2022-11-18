def factorsRange(n, m):
    def f(x):
        r = set()
        for i in range(2, int(x**.5) + 1):
            if x % i == 0:
                r.add(i)
                r.add(x // i)
        return sorted(list(r)) or ['None']
    return {k: f(k) for k in range(n, m + 1)}
