def mult_primefactor_sum(a, b):
    def f(x):
        y = x
        t = 0
        i = 2
        while i * i <= x:
            while x % i == 0:
                x //= i
                t += i
            i += 1
        if t == 0: return 0
        if x != 1: t += x
        return y % t == 0

    return [x for x in range(a, b + 1) if f(x)]
