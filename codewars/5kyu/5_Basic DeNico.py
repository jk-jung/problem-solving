def de_nico(key, msg):
    r = ''
    for i in range(0, len(msg), len(key)):
        t = msg[i:i + len(key)]
        t = [(key.index(x), y) for x, y in zip(sorted(key), t)]
        r += ''.join(x[1] for x in sorted(t))
    return r.rstrip()