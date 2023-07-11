def fizz_buzz_reloaded(s, e, k, f):
    r = []
    for i in range(s, e + (1 if k > 0 else -1), k):
        t = ''.join(k for k, v in f.items() if v(i))
        r.append(t or str(i))
    return ' '.join(r)
