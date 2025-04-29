def comes_after(st, l):
    return ''.join(y if x.lower() == l.lower() and y.isalpha() else '' for x, y in zip(st, st[1:]))