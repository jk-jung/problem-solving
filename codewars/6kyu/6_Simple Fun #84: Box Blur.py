def box_blur(v):
    r = []
    for i in range(1, len(v) - 1):
        r.append([])
        for j in range(1, len(v[0]) - 1):
            r[-1].append(0)
            for y in range(-1, 2):
                for x in range(-1, 2):
                    r[-1][-1] += v[i-y][j-x]
            r[-1][-1] = r[-1][-1] // 9
    return r