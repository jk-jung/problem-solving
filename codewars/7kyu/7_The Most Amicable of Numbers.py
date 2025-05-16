def amicable_numbers(n1, n2):
    def f(x): return sum([y for y in range(1, x) if x % y == 0])

    return f(n1) == n2 and f(n2) == n1
