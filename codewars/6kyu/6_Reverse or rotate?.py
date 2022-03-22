def revrot(s, n):
    if n <= 0: return ''
    r = ''
    for i in range(0, len(s) - len(s) % n, n):
        l = s[i:i+n]
        if sum(int(x) ** 3 for x in l) % 2:
            r += l[1:] + l[0]
        else:
            r += ''.join(l[::-1])
    return r