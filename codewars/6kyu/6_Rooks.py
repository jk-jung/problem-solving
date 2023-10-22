from math import comb, factorial
def rooks(n, k):
    return comb(n, k) ** 2 * factorial(k)
