mod = 1_000_003


def pp(x, n):
    r = 1
    while n:
        if n & 1:
            r = (r * x) % mod
        n //= 2
        x = (x * x) % mod
    return r


def inv(x):
    return pp(x, mod - 2)


def seq(n):
    a = n * (n + 1) // 2

    x = 1
    p = 1
    for _ in range(1, n):
        p = (p * n) % mod
        t = inv(p - 1)
        s = (p * (pp(p, n) - 1) % mod * t % mod - n) % mod
        x = (s * x % mod * t) % mod

    return x * a % mod
