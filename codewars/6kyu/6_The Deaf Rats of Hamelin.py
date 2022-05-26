def count_deaf_rats(v):
    flag = False
    r, i, n = 0, 0, len(v)
    while i < n:
        x = v[i]
        if x == 'P':
            flag = True
        if x == '~' or x == 'O':
            if (x == '~' and flag) or (x == 'O' and not flag):
                r += 1
            i += 1
        i += 1
    return r
