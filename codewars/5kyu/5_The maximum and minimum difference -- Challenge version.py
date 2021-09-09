def max_and_min(a, b):
    a.sort()
    b.sort()


    r = abs(a[0] - b[0])
    j = 0
    for x in a:
        while j < len(b) and x > b[j]: j += 1
        if j > 0: r = min(r, abs(x - b[j-1]))
        if j < len(b): r = min(r, abs(x - b[j]))

    return (max(a[-1] - b[0], b[-1] - a[0]), r)