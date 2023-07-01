def tops(msg):
    r, p = [], 0
    for i in range(2, 10000000):
        s = p + i + i - 2
        r.append(msg[s:s + i])
        if not r[-1]: break
        p += i * 4 - 3
    return ''.join(r[::-1])
