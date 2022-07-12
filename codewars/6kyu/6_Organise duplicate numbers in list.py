def group(arr):
    r, s = [], set()
    for x in arr:
        if x in s: continue
        s.add(x)
        r.append([x] * arr.count(x))
    return r