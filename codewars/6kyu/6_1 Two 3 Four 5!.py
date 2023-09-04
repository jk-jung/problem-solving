N = "zero one two three four five six seven eight nine".split(' ')

def conv(n):
    n = str(n)
    r = ''
    for i, x in enumerate(n):
        x = int(x)
        t = N[x]
        if len(n) % 2 == 0 and x % 2 == 0:
            for j in range(i + 1):
                y = t[j % len(t)]
                if j // len(t) % 2 == 0:
                    r += y
                else:
                    r += y.upper()
        elif len(n) % 2 == 1 and x % 2 == 1:
            for j in range(i + 1):
                y = t[j % len(t)]
                if j // len(t) % 2 == 1:
                    r += y
                else:
                    r += y.upper()
        else:
            r += str(x)
    return r
