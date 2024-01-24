def p(x): return x > 1 and int(all(x % i != 0 for i in range(2, int(x ** .5) + 1)))
def sexy_prime(x, y):
    return abs(x - y) == 6 and p(x) and p(y)
