def next_version(v):
    v = list(map(int, v.split('.')))
    v[-1] += 1
    for i in range(len(v) - 1, 0, -1):
        if v[i] > 9:
            v[i] = 0
            v[i - 1] += 1
    return '.'.join(map(str, v))
