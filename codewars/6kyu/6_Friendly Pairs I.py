from math import gcd
def friendly_numbers(m, n):
    def f(x):
        return sum(i for i in range(1, x + 1) if x % i == 0)
    def s(x, y):
        g = gcd(x, y)
        if g == y: return str(x)
        return f"{x // g}/{y // g}"

    a, b = f(m), f(n)
    if a * n == b * m: return 'Friendly!'
    return f"{s(a, m)} {s(b, n)}"
