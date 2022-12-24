def find_discounted(v):
    if not v: return ''
    v = sorted(map(int, v.split(' ')))
    used = {}
    r = []
    for i, x in enumerate(v):
        z = int(x * .75)
        for j, y in enumerate(v):
            if i != j and i not in used and j not in used and y == z:
                r.append(y)
                used[i] = 1
                used[j] = 1
                break
    return ' '.join(map(str, r))
