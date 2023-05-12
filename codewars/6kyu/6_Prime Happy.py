def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))
def is_prime_happy(n):
    s = sum([x for x in range(2, n) if p(x)])
    if s == 0 or n == 0: return False
    return s % n == 0