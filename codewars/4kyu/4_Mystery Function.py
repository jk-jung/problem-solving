def mystery(n):
    k, r = 100, 0
    while n > 0:
        t = 2 ** k
        if t <= n:
            r += t
            n = t + t - n - 1
        k -= 1
    return r


def mystery_inv(n):
    k, r = 1, 0
    while n > 0:
        if n & 1:
            r = 2 ** k - r - 1
        k += 1
        n //= 2
    return r


def name_of_mystery():
    return 'Gray code'
