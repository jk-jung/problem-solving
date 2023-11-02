def encode(s):
    def f(x): return x[::-1][1:] + x[-1]
    return ' '.join(f(x) for x in s.split(' '))