def decrypt(s):
    s = s[::-1]
    r, c = s[0], 0
    for x in s[1:]:
        t = int(x) - int(r[-1]) - c
        c = 0
        if t < 0:
            t += 10
            c = 1
        r += str(t)
    r = r[::-1]
    if r[0] == '0': return 'impossible'
    return r
