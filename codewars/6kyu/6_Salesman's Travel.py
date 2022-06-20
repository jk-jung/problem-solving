def travel(r, z):
    aa, bb = [], []
    for x in r.split(','):
        if z and x.endswith(z):
            a, b = x.replace(z, '').strip().split(' ', 1)
            aa.append(a)
            bb.append(b)
    return z + ':' + ','.join(bb) + '/' + ','.join(aa)
