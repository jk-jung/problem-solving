b91 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!#$%&()*+,./:;<=>?@[]^_`{|}~"'


def b91decode(s):
    q, n, v = 0, 0, -1
    r = ''
    for x in s:
        x = b91.index(x)
        if v == -1:
            v = x
        else:
            v += x * 91
            q |= v << n
            n += 13 if (v & 8191) > 88 else 14

            while n > 7:
                r += chr(q & 255)
                q >>= 8
                n -= 8
            v = -1
    if v:
        r += chr(q | v << n & 255)
    return r


def b91encode(s):
    q, n = 0, 0
    r = ''
    for x in s:
        q |= ord(x) << n
        n += 8

        if n < 14: continue
        v = q & 8191
        if v > 88:
            q >>= 13
            n -= 13
        else:
            v = q & 16383
            q >>= 14
            n -= 14

        r += b91[v % 91]
        r += b91[v // 91]
    if n:
        r += b91[q % 91]
        if n > 7 or q > 90: r += b91[q // 91]

    return r


