from math import comb
def calculate_probability(n):
    if n >= 365: return 1
    tot = 365 ** n
    t = 1
    for i in range(n):
        t *= (365 - i)
    return round(1 - t / tot, 2)
