from decimal import *


def bonus(v, n):
    s = Decimal(0)
    for x in v:
        s += Decimal(v[0]) / Decimal(x)
    x = n / s
    return [round(x * v[0] / i) for i in v]
