def str_to_hash(s):
    r = {}
    for x in s.split(','):
        if x:
            t = x.strip().split('=')
            r[t[0]] = int(t[1])
    return r
