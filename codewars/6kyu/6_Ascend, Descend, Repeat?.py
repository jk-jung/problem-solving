def ascend_descend(n, s, e):
    if n == 0 or s > e: return ''
    t = [str(x) for x in range(s, e + 1)]
    t += [str(x) for x in range(e - 1, s, -1)]
    return ''.join((t * n))[:n]
