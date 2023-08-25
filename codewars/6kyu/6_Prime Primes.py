from fractions import Fraction
def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))

def prime_primes(n):
    v = [x for x in range(2, n) if p(x)]
    r, c = 0, 0
    for x in v:
        for y in v:
            if x < y:
                r += Fraction(x, y)
                c += 1
    return c, int(r)
