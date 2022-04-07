def cycle(s):
    last = {}
    for i, x in enumerate(s):
        if x in last:
            return [last[x], i - last[x]]
        last[x] = i
    return []