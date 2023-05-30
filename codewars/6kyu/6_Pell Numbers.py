from functools import cache

@cache
def f(x):
    return x if x <= 1 else 2 * f(x - 1) + f(x - 2)
    if x <= 1: return x
class Pell(object):
    def get(self, n):
        return f(n)
