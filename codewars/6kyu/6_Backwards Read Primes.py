def backwards_prime(s, e):
    def f(x):
        i = 2
        while i * i <= x:
            if x % i == 0:
                return False
            i += 1
        return True
    r = []
    for i in range(max(13, s), e + 1):
        if f(i) and i != int(str(i)[::-1]) and f(int(str(i)[::-1])):
            r.append(i)
    return r