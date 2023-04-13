def pattern(n,y=1, *v):
    if n <= 0: return ''
    y = max(1, y)
    last = ''
    def f():
        nonlocal last
        m = n * 2 - 1
        r = []
        for i in range(n):
            s = [' ' for x in range(m)]
            s[i] = s[m -i - 1] = str(i + 1)[-1]
            r.append(''.join(s))
        r = r + r[:-1][::-1]
        last = r.pop()
        return '\n'.join(r)
    return '\n'.join([f() for _ in range(y)]) + '\n' + last
