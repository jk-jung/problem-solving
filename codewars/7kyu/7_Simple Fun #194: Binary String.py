def bin_str(s):
    t = '1'
    r = 0
    for x in s:
        if x == t:
            t = '0' if t == '1' else '1'
            r += 1
    return r
