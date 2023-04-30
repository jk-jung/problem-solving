def charCheck(t, n, s):
    if not s: t = t.replace(' ', '')
    return [len(t) <= n, t[:n]]
