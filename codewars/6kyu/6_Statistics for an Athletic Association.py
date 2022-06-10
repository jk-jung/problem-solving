def stat(s):
    if not s: return ''
    def f(x):
        x = [int(i) for i in x.strip().split('|')]
        return x[0] * 3600 + x[1] * 60 + x[2]

    def t(x):
        return '%02d|%02d|%02d' % (x // 3600, x % 3600 // 60, x % 60)

    v = sorted([f(x) for x in s.split(',')])
    n = len(v)
    a = v[-1] - v[0]
    b = sum(v) // n
    c = v[n // 2] if n % 2 else (v[n // 2] + v[n // 2 - 1]) // 2

    return f"Range: {t(a)} Average: {t(b)} Median: {t(c)}"