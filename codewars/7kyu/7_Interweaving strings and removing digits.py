def interweave(a, b):
    r = ''
    for i in range(max(len(a), len(b))):
        if i < len(a) and not a[i].isdigit():
            r += a[i]
        if i < len(b) and not b[i].isdigit():
            r += b[i]
    return r