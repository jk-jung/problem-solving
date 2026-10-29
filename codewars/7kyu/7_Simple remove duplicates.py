def solve(a): 
    r = []
    for x in a[::-1]:
        if x not in r:
            r.append(x)
    return r[::-1]
