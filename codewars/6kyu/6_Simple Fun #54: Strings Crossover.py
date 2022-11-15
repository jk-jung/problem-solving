def strings_crossover(v, r):
    c = 0
    for i in range(len(v)):
        for j in range(i + 1, len(v)):
            c += 1
            for x, y, z in zip(v[i], v[j], r):
                if x != z and y != z:
                    c -= 1
                    break
    return c