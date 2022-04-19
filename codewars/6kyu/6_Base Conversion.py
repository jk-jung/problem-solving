def convert(s, a, b):
    r = 0
    for x in s:
        r = r * len(a) + a.index(x)
    c = ''
    while r:
        c += b[r % len(b)]
        r //= len(b)
    if not c: c = b[0]
    return c[::-1]