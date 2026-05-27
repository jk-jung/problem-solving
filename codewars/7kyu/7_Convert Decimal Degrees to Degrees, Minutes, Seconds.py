def convert(x): 
    x = round(x * 3600)
    a, b = divmod(x, 3600)
    b, c = divmod(b, 60)
    r = [a]
    if c:
        r.extend([b, c])
    elif b:
        r.append(b)
    return r
    