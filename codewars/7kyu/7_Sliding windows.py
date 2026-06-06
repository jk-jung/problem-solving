def window(a,b,c):
    t = [c[i:i+a] for i in range(0, len(c), b)]
    t = [x for x in t if len(x) == a]
    if a == 0:
        return [[]] * (len(c) // b + 1)
    return t