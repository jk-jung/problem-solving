# Draw a Sierpiński carpet ^^
def sierpinski_carpet_string(c):
    if c == 0: return '██'
    print(c)
    v = [
        '***',
        '*.*',
        '***',
    ]
    o = v
    while c > 1:
        n, m = len(v), len(v[0])
        e = ['.' * m for i in range(n)]
        t = [[v if o[i][j] == '*' else e for j in range(len(o[0]))] for i in range(len(o))]
        r = []
        for i in range(len(o)):
            for j in range(n):
                r.append(''.join(x[j] for x in t[i]))
        v = r
        c -= 1
    v = '\n'.join(v).replace('.', '  ').replace('*', '██')
    return v
