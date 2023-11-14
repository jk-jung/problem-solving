def graph(v):
    if not v: return ''
    m = max(v)
    r = []
    for i in range(max(v), -1, -1):
        t = ''
        for x in v:
            if x == i:t += ' ____ '
            elif x < i: t += '......'
            else: t += '|    |'
        t += (' | ' if i != max(v) else ' ^ ') + str(i)
        r.append(t)
    return '\n'.join(r)
