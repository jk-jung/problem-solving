from fractions import Fraction as F

def magicdice(n):
    if n == 0: return (1, 1)
    t = 1 - sum(F(1, 1 << (i + 1)) for i in range(n)) ** 3
    return (t.numerator, t.denominator)
