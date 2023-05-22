def sum_nested_numbers(v):
    r = 0
    def f(t, d=1):
        nonlocal r
        for x in t:
            if isinstance(x, int): r += x ** d
            else: f(x, d + 1)
    f(v)
    return r
