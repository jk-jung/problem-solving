def Xbonacci(v,n):
    m = len(v)
    while len(v) < n:
        v.append(sum(v[-m:]))
    return v[:n]