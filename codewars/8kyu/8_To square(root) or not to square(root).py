def square_or_square_root(a):
    def f(x):
        if round(x**0.5) ** 2 == x:
            return round(x**0.5)
        return x**2

    return [f(x) for x in a]
