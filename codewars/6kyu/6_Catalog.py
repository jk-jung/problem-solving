def catalog(s, tar):
    r = []
    for x in s.split('\n'):
        x = x.strip()
        if not x: continue
        x = x.split('prx>')
        er = ['<prod><name>', '</name><', '<qty>', '</qty></prod>', '</']
        def f(t):
            for z in er:
                t = t.replace(z, '')
            return t
        x = list(map(f, x))
        if tar in x[0]:
            r.append(x)
    def f2(x):
        return f"{x[0]} > prx: ${x[1]} qty: {x[2]}"
    return '\r\n'.join(f2(x) for x in r) or "Nothing"
