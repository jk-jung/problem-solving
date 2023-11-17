def squares(n):
    return [i * i for i in range(1, n + 1)]

def num_range(n, start, step):
    return [start + i * step for i in range(n)]

def rand_range(n, mn, mx):
    import random
    return random.sample(range(mn, mx + 1) , n)

def primes(n):
    def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))
    r = []
    for i in range(2, 100000000):
        if len(r) == n:break
        if p(i): r.append(i)
    return r
