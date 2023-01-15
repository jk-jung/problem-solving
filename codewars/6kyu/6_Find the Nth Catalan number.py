from math import comb
def nth_catalan_number(n):
    return comb(n * 2, n ) // (n + 1)