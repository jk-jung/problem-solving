def columnize(v, c):
    for i in range(min(c, len(v))):
        m = max(len(v[j]) for j in range(i, len(v), c))
        for j in range(i, len(v), c):
            v[j] = (v[j] + ' ' * m)[:m]
    return '\n'.join(' | '.join(v[i:i + c]) for i in range(0, len(v), c))
