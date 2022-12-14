def thue_morse(n):
    r = '0'
    while len(r) <= n:
        t = ''.join('1' if x == '0' else '0' for x in r)
        r += t
    return r[:n]
