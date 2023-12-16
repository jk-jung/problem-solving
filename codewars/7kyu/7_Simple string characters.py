def solve(s):
    r = [0,0,0,0]
    for x in s:
        if x.islower(): r[1] += 1
        elif x.isupper(): r[0] += 1
        elif x.isdigit(): r[2] += 1
        else: r[3] += 1
    return r
