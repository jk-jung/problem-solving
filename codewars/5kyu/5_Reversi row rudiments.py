def reversi_row(m):
    r = ['.' for _ in range(8)]

    c = '*'
    for x in m:
        r[x] = c
        idx = -1
        for i in range(7, x, -1):
            if r[i] == c: idx = i
            if r[i] == '.': idx = -1
        for i in range(x, idx):
            if r[i] != '.': r[i] = c

        idx = 999
        for i in range(x):
            if r[i] == c: idx = i
            if r[i] == '.': idx = 999

        for i in range(idx, x):
            if r[i] != '.': r[i] = c

        c = 'O' if c == '*' else '*'

    return ''.join(r)
