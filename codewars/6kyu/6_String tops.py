def tops(msg):
    r, i, c = '', 0, 0
    while i < len(msg):
        c += 1
        i += c
        if c % 2 and i < len(msg):
            r += msg[i]
    return r[::-1]
