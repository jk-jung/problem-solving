def only_oddDigPrimes (n):
    def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))
    def f(x):
        return not (set(list(str(x))) & set(list('02468'))) and p(x)

    r = [x for x in range(3, n) if f(x)]
    for i in range(n + 1, n * n):
        if f(i):
            return [len(r), r[-1], i]
