def summationOfPrimes(n):
    def f(x): return all(x % i for i in range(2, int(x **.5) + 1))
    return sum([x for x in range(2, n + 1) if f(x)])
  