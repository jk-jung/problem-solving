def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))
def channelling_primes(n):
    return sum(p(i + 1) * (2 ** i) for i in range(n))