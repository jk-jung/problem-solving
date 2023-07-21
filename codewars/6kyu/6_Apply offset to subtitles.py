def subs_offset_apply(a, t):
    x, a, y, b = a.split(' ', 3)

    def f(k):
        a, b, c, d = map(int, k.replace(',', ':').split(':'))
        return d + 1000 * (c + 60 * (b + 60 * a)) + t

    def g(x):
        return '%02d:%02d:%02d,%03d' % (x // 3600000, x % 3600000 // 60000, x % 60000 // 1000, x % 1000)
    x, y = f(x), f(y)
    if x < 0 or y < 0 or x >= 360000000 or y >= 360000000: return "Invalid offset"
    x, y = g(x), g(y)
    return ' '.join([x, a, y, b])