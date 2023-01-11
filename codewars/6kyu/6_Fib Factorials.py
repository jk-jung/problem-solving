from math import factorial
def sum_fib(n):
    r, a, b = 0, 0, 1
    for i in range(n):
        r += factorial(a)
        a, b = b, a + b
    return r
