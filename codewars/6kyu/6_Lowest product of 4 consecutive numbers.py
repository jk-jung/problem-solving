def lowest_product(s):
    def f(v):
        if len(v) < 4: return 9999
        r = 1
        for x in v: r *= int(x)
        return r

    if not s: return "Number is too small"
    r = min(f(s[i:i + 4]) for i in range(len(s)))
    return "Number is too small" if r == 9999 else r