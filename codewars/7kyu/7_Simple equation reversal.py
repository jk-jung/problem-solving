def solve(eq):
    c = ''
    r = []
    for x in eq:
        if x in '*+-/':
            r.append(c)
            r.append(x)
            c = ''
        else: c += x
    r.append(c)
    return ''.join(r[::-1])