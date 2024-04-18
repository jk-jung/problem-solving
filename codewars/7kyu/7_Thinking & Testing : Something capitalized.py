def testit(s):
    def f(x):
        if x:
            x = list(x)
            x[-1] = x[-1].upper()
            return ''.join(x)
        return x
    return ' '.join(f(x) for x in s.split(' '))
