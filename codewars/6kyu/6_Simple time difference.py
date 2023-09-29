def solve(a):
    def f(x): return int(x[:2]) * 60 + int(x[3:])
    a = [f(x) for x in sorted(set(a))]
    a.append(a[0] + 24 * 60)
    r = max(y - x  - 1 for x, y in zip(a, a[1:]))
    return f"%02d:%02d" % (r // 60, r % 60)
