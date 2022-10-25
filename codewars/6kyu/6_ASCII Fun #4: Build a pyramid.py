def build_pyramid(s, n):
    r = [s]
    for i in range(2, n + 1):
        r.append(''.join(''.join(x) for x in zip(*([r[0]] * i))))
    for i in range(n):
        r[i] = r[i].center(len(r[-1]), ' ').rstrip()
    return '\n'.join(r)
