def primes_a_p(s, e):
    def f(x): return x > 1 and all(x % i for i in range(2, int(x **.5) + 1))
    v = set([x for x in range(s, e + 1) if f(x)])
    r = []
    for x in v:
        for y in v:
            if x < y:
                d = y - x
                if all((x + d * i) in v for i in range(6)):
                    r.append([(x + d * i) for i in range(6)])
    return sorted(r)
