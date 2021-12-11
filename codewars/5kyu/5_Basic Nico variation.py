def nico(k, s):
    r, n = '', len(k)
    for i in range(0, len(s), n):
        t = [' '] * n
        for j, x in enumerate(k):
            if i + j < len(s):
                t[sorted(k).index(x)] = s[i+j]
        r += ''.join(t)
    return r