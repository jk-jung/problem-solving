def dominator(a):
    for i in a:
        if a.count(i) >= len(a) // 2 + 1:
            return i
    return -1