def unique_digit_products(a):
    def f(x):
        r = 1
        for i in str(x):
            r *= int(i)
        return r
    return len(set(f(x) for x in a))
