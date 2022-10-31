def div_num(a, b):
    def f(x):
        r, i = 0, 1
        while i * i <= x:
            if x % i == 0: r += 1
            if i != x // i and x % (x // i) == 0: r += 1
            i += 1
        return r
    try:
        return max(range(a, b + 1), key=f)
    except:
        return 'Error'
