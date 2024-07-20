def asterisc_it(n):
    if isinstance(n, list): n = ''.join(map(str, n))
    n = str(n)
    s = ''
    for x in n:
        if s and int(s[-1]) % 2 == 0 and int(x) % 2 == 0:
            s += '*'
        s += x
    return s
