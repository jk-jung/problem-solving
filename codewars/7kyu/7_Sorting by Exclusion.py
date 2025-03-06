def sort_by_exclusion(words):
    if type(words) != list:
        words = [x for x in words]
    n = len(words)
    r = [words.pop(0)]
    while words:
        x = words.pop(0)
        i = 0
        while i < len(r) and r[i] < x:
            i += 1
        if i == len(r):
            r.append(x)
        else:
            r[i] = x
    return n - len(r)
