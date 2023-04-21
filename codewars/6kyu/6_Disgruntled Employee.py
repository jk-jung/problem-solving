def off(n):
    def f(x):
        t = 0
        for i in range(1, int(n ** .5) + 1):
            if x % i == 0:
                t += 1
                if x // i != i: t += 1
        return t % 2
    return [x for x in range(1, n + 1) if f(x)]
