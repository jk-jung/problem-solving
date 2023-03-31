def flip(d, a):
    if d == 'R':[x.sort() for x in a]
    elif d == 'L':[x.sort(reverse=True) for x in a]
    else:
        for j in range(len(a[0])):
            t = sorted([a[i][j] for i in range(len(a))], reverse=d == 'U')
            for i in range(len(a)): a[i][j] = t[i]
    return a
