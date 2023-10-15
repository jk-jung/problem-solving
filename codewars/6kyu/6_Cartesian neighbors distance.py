def cartesian_neighbors_distance(x, y, r):
    t = set()
    for i in range(r + 1):
        for j in range(r + 1):
            t.add((i ** 2 + j ** 2) ** .5)
    return sorted(t)[1:]
