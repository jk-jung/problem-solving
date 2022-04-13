def decipher_this(s):
    def f(x):
        t = ''
        x = list(x)
        while x and x[0].isdigit():
            t += x.pop(0)
        if len(x) >= 2: x = [x[-1]] + x[1:-1] + [x[0]]
        return chr(int(t)) + ''.join(x)
    return ' '.join(f(x) for x in s.split(' '))
