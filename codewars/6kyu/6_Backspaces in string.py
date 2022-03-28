def clean_string(s):
    r = ''
    for x in s:
        if x == '#': r = r[:-1]
        else: r += x
    return r