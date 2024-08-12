def odd_not_prime(n):
    def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))
    return len([x for x in range(1, n + 1, 2) if not p(x)])
