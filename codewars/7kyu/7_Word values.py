def name_value(a):
    def f(y):
        return sum(ord(x) - ord("a") + 1 for x in y if x.isalpha())

    r = []
    for i in range(len(a)):
        r.append((i + 1) * f(a[i]))
    return r
