def prime_word(v):
    def p(x): return int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))
    def f(x): return any(p(ord(z) + x[1]) for z in x[0])
    return list(map(f, v))
