def squares(x, n):
    if n <= 0: return []
    r = [x]
    for i in range(1,n):r.append(r[-1]*r[-1])
    return r
