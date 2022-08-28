def is_twinprime(n):
    def f(x):
        if x < 2: return False
        i = 2
        while i * i <= x:
            if x % i == 0:
                return False
            i += 1
        return True
    return f(n) and (f(n - 2) or f(n + 2))