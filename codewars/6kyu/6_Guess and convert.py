def func(l):
    x = int(sum(l) / len(l))
    s = '0123456789abcdefghijklmnop'

    def f(n, b):
        r = ''
        while n:
            r = s[n % b] + r
            n //= b
        return r
    return [x, f(x, 2), f(x, 8), f(x, 16)]
