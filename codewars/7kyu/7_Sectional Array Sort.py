def sect_sort(a, b=0, c=9999999):
    if c == 0: c = 9999999
    a[b:b+c] = sorted(a[b:b+c])
    return a