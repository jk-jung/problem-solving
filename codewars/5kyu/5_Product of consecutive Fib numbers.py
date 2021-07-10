def productFib(prod):
    f0 = 0
    f1 = 1
    while True:
        if f0 * f1 >= prod:
            return [f0, f1, f0 * f1 == prod]
        t = f0 + f1
        f0 = f1
        f1 = t
