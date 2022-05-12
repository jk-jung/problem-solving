def twos_difference(v):
    r = []
    for x in v:
        for y in v:
            if x + 2 == y:
                r.append((x, y))
    return sorted(r)
