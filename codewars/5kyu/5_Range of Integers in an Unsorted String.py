def mystery_range(s, n):
    for x in range(1, 100):
        v = [str(x + i) for i in range(n)]
        ss = ''.join(v)

        if len(ss) != len(s): continue
        if any(k not in s for k in v): continue
        if sorted(ss) != sorted(s): continue
        return [int(v[0]), int(v[-1])]
