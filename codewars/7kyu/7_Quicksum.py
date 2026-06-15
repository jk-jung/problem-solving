def quicksum(a):
    r = 0
    for i, x in enumerate(a):
        if x == " ":
            continue
        if x.isupper():
            r += (ord(x) - ord("A") + 1) * (i + 1)
        else:
            return 0
    return r
