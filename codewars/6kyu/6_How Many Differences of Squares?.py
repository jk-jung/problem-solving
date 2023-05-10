from functools import cache

@cache
def f(i):
    #         (x + y) ( x - y)
    #         y = x - k
    #         (2x - k)k
    #         2xk - k^2 == i

    k = 1
    while True:
        t = i + k * k
        if t % (2 * k) == 0:
            return 1
        if t / (2 * k) < k: break
        k += 1
    return 0

def count_squareable(n):
    return sum(f(i) for i in range(1, n + 1))
