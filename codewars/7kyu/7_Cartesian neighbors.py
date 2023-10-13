def cartesian_neighbor(x,y):
    return [(x - i, y - j)for i in range(-1, 2) for j in range(-1, 2) if i or j]