def encrypt_this(s):
    def f(x):
        if len(x) == 0: return ''
        r = str(ord(x[0]))
        if len(x) > 2: r += x[-1] + x[2:-1] + x[1]
        elif len(x) == 2: r += x[-1]
        return r
    return ' '.join(f(x) for x in s.split(' '))