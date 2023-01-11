def test_it(v):
    def f(x):
        r = ''
        while x >= 1:
            r += str(x % 10)
            if x <= 2: break
            x = x // 2 if x % 2 == 0 else x * 3 + 1
        return r
    v = [f(x) for x in v]
    n = max(len(x) for x in v)
    r = ''
    for i in range(n + 1):
        r += '|'.join(v[j][i] if i < len(v[j]) else '.' for j in range(len(v))) + '\n'
    return r.strip()
