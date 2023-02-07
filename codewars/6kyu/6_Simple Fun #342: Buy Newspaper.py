def buy_newspaper(a, b):
    r, i = 1, 0
    for x in b:
        i = a.find(x, i) + 1
        if i == 0:
            r += 1
            i = a.find(x) + 1
        if i == 0:
            return -1
    return r