def shorten_number(v, b):
    def f(x):
        try:
            x, r = int(x), x + v[0]
            for i in v[1:]:
                x //= b
                if x: r = str(x) + i
            return r
        except: return str(x)
    return f
