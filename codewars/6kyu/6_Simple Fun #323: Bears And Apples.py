from math import gcd
def how_many_apples(n):
    r = n - 1

    d = (n - 1) ** n
    a = sum(n ** i * (n - 1) ** (n - i) for i in range(1, n)) % d
    b = n ** n % d

    c = d - a
    def find_x(): return (c * pow(b, -1, d)) % d or 1
    x = find_x()
    for i in range(n):
        x = x * n // (n - 1) + 1
    return x