def doubles(s):
    r = '.'
    for x in s:
        if x == r[-1]:r = r[:-1]
        else: r += x
    return r[1:]
