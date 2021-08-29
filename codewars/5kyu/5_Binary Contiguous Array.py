def binarray(s):
    d = {0: -1}
    diff = 0
    r = 0
    for i, x in enumerate(s):
        diff += 1 if x == 1 else -1

        if diff in d: r = max(r, i - d[diff])
        else: d[diff] = i

    return r