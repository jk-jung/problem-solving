from fractions import Fraction

def is_ore(n):
    t = [Fraction(1, i) for i in range(1, n + 1) if n % i == 0]
    return (len(t) / sum(t)).denominator == 1
