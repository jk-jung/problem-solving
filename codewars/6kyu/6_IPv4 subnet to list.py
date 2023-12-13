import ipaddress

def ipsubnet2list(s):
    v = [int(x) for x in s.replace('/', '.').split('.')]
    if any(x > 255 for x in v[:-1]) or v[-1] > 32: return None
    t = 0
    for x in v[:-1]:
        t = t * 256 + x
    r = []
    t = t >> (32 - v[-1])
    t = t << (32 - v[-1])

    for i in range(1 << (32 - v[-1])):
        k = t + i
        r.append(str(ipaddress.ip_address(k)))
    if len(r) == 2: return r
    return r[1:-1]
