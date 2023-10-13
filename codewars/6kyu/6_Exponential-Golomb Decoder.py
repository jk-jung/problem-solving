def decoder(s):
    r = []
    while s:
        c = 1
        while s and s[0] == '0':
            s = s[1:]
            c += 1

        t, s = s[:c], s[c:]
        r.append(int(t, 2) - 1)
    return r
