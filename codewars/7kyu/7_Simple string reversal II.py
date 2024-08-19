def solve(st,a,b):
    st = list(st)
    st[a:b+1] = st[a:b+1][::-1]
    return ''.join(st)
