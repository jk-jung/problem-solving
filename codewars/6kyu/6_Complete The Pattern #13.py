def pattern(*args):
    n = args[0]
    x = 1 if len(args) == 1 else args[1]
    m = n * 2 - 1
    r = []
    for i in range(n):
        s = [' ' for x in range(m)]
        s[i] = s[m -i - 1] = str(i + 1)[-1]
        s = ''.join(s)
        r.append(s + s[1:] * (x - 1))
    return '\n'.join(r + r[:-1][::-1])
